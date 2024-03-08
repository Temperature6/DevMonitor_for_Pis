/*
 * SPDX-License-Identifier: MIT
 * Copyright 2023 NXP
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <errno.h>
#include <poll.h>
#include "lvgl.h"
#include "lv_drivers/wayland/wayland.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/
struct pollfd pfd;
uint32_t time_till_next;
int sleep_time;

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static bool close_cb(lv_disp_t * disp);
static void hal_init(void);
static void * tick_thread(void * data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

lv_ui guider_ui;

int main(int argc, char ** argv)
{
    (void) argc;    /*Unused*/
    (void) argv;    /*Unused*/

    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LittlevGL*/
    hal_init();

    /*Create a GUI-Guider app */
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    pfd.fd = lv_wayland_get_fd();
    pfd.events = POLLIN;

    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        time_till_next = lv_wayland_timer_handler();
#if LV_USE_VIDEO
        video_play(&guider_ui);
#endif
        /* Run until the last window closes */
        if (!lv_wayland_window_is_open(NULL)) {
            break;
        }
        /* Wait for something interesting to happen */
        if (time_till_next == LV_NO_TIMER_READY) {
            sleep_time = -1;
        } else if (time_till_next > INT_MAX) {
            sleep_time = INT_MAX;
        } else {
           sleep_time = time_till_next;
        }
        while ((poll(&pfd, 1, sleep_time) < 0) && (errno == EINTR));
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static bool close_cb(lv_disp_t * disp)
{
}

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{
    lv_wayland_init();

    /* Create a display */
    lv_disp_t * disp = lv_wayland_create_window(LV_HOR_RES_MAX, LV_VER_RES_MAX, "GUI Guider", close_cb);

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
     */
    pthread_t tid;
    int err = pthread_create(&tid, NULL, &tick_thread, NULL);
    if (err != 0) {
        printf("\ncan't create thread :[%s]", strerror(err));
        exit(1);
    }
}

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static void * tick_thread(void * data)
{
    (void)data;

    while(1) {
        usleep(5*1000);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }
}
