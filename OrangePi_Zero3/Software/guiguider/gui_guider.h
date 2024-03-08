/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_arc_cpu;
	lv_obj_t *screen_arc_mem;
	lv_obj_t *screen_cont_disk;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_bar_disk;
	lv_obj_t *screen_lb_disk;
	lv_obj_t *screen_lb_cpu;
	lv_obj_t *screen_lb_mem;
	lv_obj_t *screen_cont_net_flow;
	lv_obj_t *screen_img_dl;
	lv_obj_t *screen_img_up;
	lv_obj_t *screen_lb_dl;
	lv_obj_t *screen_lb_up;
	lv_obj_t *screen_img_net;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_lb_temp;
	lv_obj_t *screen_cont_net_ip;
	lv_obj_t *screen_lb_cur_net;
	lv_obj_t *screen_lb_ip;
	lv_obj_t *screen_cont_logo;
	lv_obj_t *screen_img_logo;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_download_alpha_16x16);
LV_IMG_DECLARE(_upload_alpha_16x16);
LV_IMG_DECLARE(_flow_alpha_20x20);
LV_IMG_DECLARE(_temp_alpha_16x16);
LV_IMG_DECLARE(_logo_alpha_68x22);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_10)


#ifdef __cplusplus
}
#endif
#endif
