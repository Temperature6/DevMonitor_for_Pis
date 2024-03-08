/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/
#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>
#include "lvgl_support.h"

/*====================
  COLOR SETTINGS
 *====================*/

/*Maximal horizontal resolution*/
#define LV_HOR_RES_MAX (280)

/*Maximal vertical resolution*/
#define LV_VER_RES_MAX (240)

/*Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888)*/
#define LV_COLOR_DEPTH 16

/*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP 0

/*Enable features to draw on transparent background.
 *It's required if opa, and transform_* style properties are used.
 *Can be also used if the UI is above another layer, e.g. an OSD menu or video player.*/
#define LV_COLOR_SCREEN_TRANSP 0

/* Adjust color mix functions rounding. GPUs might calculate color mix (blending) differently.
 * 0: round down, 64: round up from x.75, 128: round up from half, 192: round up from x.25, 254: round up */
#define LV_COLOR_MIX_ROUND_OFS 0

/*Images pixels with this color will not be drawn if they are chroma keyed)*/
#define LV_COLOR_CHROMA_KEY lv_color_hex(0x00ff00)

/*=========================
  MEMORY SETTINGS
 *=========================*/

/*1: use custom malloc/free, 0: use the built-in `lv_mem_alloc()` and `lv_mem_free()`*/
#define LV_MEM_CUSTOM 0
#if LV_MEM_CUSTOM == 0
/*Size of the memory available for `lv_mem_alloc()` in bytes (>= 2kB)*/
#define LV_MEM_SIZE (320U * 1024U)
#else     /* LV_MEM_CUSTOM */
/*Header for the dynamic memory function*/
#define LV_MEM_CUSTOM_INCLUDE <stdlib.h>
/*Name for the memory malloc function*/
#define LV_MEM_CUSTOM_ALLOC malloc
/*Name for the memory free function*/
#define LV_MEM_CUSTOM_FREE free
/*Name for the memory realloc function*/
#define LV_MEM_CUSTOM_REALLOC realloc
#endif    /* LV_MEM_CUSTOM */

/*Number of the intermediate memory buffer used during rendering and other internal processing mechanisms.
 *You will see an error log message if there wasn't enough buffers. */
#define LV_MEM_BUF_MAX_NUM 16

/*Use the standard `memcpy` and `memset` instead of LVGL's own functions. (Might or might not be faster).*/
#define LV_MEMCPY_MEMSET_STD 0

/*====================
  HAL SETTINGS
 *====================*/

/*Default display refresh period in milliseconds. LVG will redraw changed areas with this period time*/
#define LV_DISP_DEF_REFR_PERIOD 30

/*Input device read period in milliseconds*/
#define LV_INDEV_DEF_READ_PERIOD 30

/*Use a custom tick source that tells the elapsed time in milliseconds.
 *It removes the need to manually update the tick with `lv_tick_inc()`)*/
#define LV_TICK_CUSTOM 0
#if LV_TICK_CUSTOM
/*Header for the system time function*/
#define LV_TICK_CUSTOM_INCLUDE "Arduino.h"
/*Expression evaluating to current system time in ms*/
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (millis())
#endif    /* LV_TICK_CUSTOM */

/*Default Dot Per Inch(px/inch). Used to initialize default sizes such as widgets sized, style paddings.
 *(Not so important, you can adjust it to modify default sizes and spaces)*/
#define LV_DPI_DEF 130

/*=======================
 * FEATURE CONFIGURATION
 *=======================*/

/*-------------
 * Drawing
 *-----------*/

/*Enable complex draw engine.
 *Required to draw shadow, gradient, rounded corners, circles, arc, skew lines, image transformations or any masks*/
#define LV_DRAW_COMPLEX 1
#if LV_DRAW_COMPLEX
/*Allow buffering some shadow calculation.
*LV_SHADOW_CACHE_SIZE is the max. shadow size to buffer, where shadow size is `shadow_width + radius`
*Caching has LV_SHADOW_CACHE_SIZE^2 RAM cost*/
#define LV_SHADOW_CACHE_SIZE 0

/* Set number of maximally cached circle data.
* The circumference of 1/4 circle are saved for anti-aliasing
* radius * 4 bytes are used per circle (the most often used radiuses are saved)
* 0: to disable caching */
#define LV_CIRCLE_CACHE_SIZE 4
#endif    /* LV_DRAW_COMPLEX */

/**
 * "Simple layers" are used when a widget has `style_opa < 255` to buffer the widget into a layer
 * and blend it as an image with the given opacity.
 * Note that `bg_opa`, `text_opa` etc don't require buffering into layer)
 * The widget can be buffered in smaller chunks to avoid using large buffers.
 *
  * - LV_LAYER_SIMPLE_BUF_SIZE: [bytes] the optimal target buffer size. LVGL will try to allocate it
  * - LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE: [bytes]  used if `LV_LAYER_SIMPLE_BUF_SIZE` couldn't be allocated.
 *
 * Both buffer sizes are in bytes.
  * "Transformed layers" (where transform_angle/zoom properties are used) use larger buffers
  * and can't be drawn in chunks. So these settings affects only widgets with opacity.
 */
#define LV_LAYER_SIMPLE_BUF_SIZE (24U * 1024U)
#define LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE (3U * 1024U)

/*Default image cache size. Image caching keeps the images opened.
 *If only the built-in image formats are used there is no real advantage of caching. (I.e. if no new image decoder is added)
 *With complex image decoders (e.g. PNG or JPG) caching can save the continuous open/decode of images.
 *However the opened images might consume additional RAM.
 *0: to disable caching*/
#define LV_IMG_CACHE_DEF_SIZE 0

/*Number of stops allowed per gradient. Increase this to allow more stops.
 *This adds (sizeof(lv_color_t) + 1) bytes per additional stop*/
#define LV_GRADIENT_MAX_STOPS 2

/*Default gradient buffer size.
 *When LVGL calculates the gradient "maps" it can save them into a cache to avoid calculating them again.
 *LV_GRAD_CACHE_DEF_SIZE sets the size of this cache in bytes.
 *If the cache is too small the map will be allocated only while it's required for the drawing.
 *0 mean no caching.*/
#define LV_GRAD_CACHE_DEF_SIZE 0

/*Allow dithering the gradients (to achieve visual smooth color gradients on limited color depth display)
 *LV_DITHER_GRADIENT implies allocating one or two more lines of the object's rendering surface
 *The increase in memory consumption is (32 bits * object width) plus 24 bits * object width if using error diffusion */
#define LV_DITHER_GRADIENT 0
#if LV_DITHER_GRADIENT
/*Add support for error diffusion dithering.
 *Error diffusion dithering gets a much better visual result, but implies more CPU consumption and memory when drawing.
 *The increase in memory consumption is (24 bits * object's width)*/
#define LV_DITHER_ERROR_DIFFUSION 0
#endif    /* LV_DITHER_GRADIENT */

/*Maximum buffer size to allocate for rotation.
 *Only used if software rotation is enabled in the display driver.*/
#define LV_DISP_ROT_MAX_BUF (10U * 1024U)

/*-------------
 * GPU
 *-----------*/
#if LV_USE_GPU_NXP_PXP
#endif    /* LV_USE_GPU_NXP_PXP */

/*Use SDL renderer API*/
#define LV_USE_GPU_SDL 0
#if LV_USE_GPU_SDL
#define LV_GPU_SDL_INCLUDE_PATH <SDL2/SDL.h>
/*Texture cache size, 8MB by default*/
#define LV_GPU_SDL_LRU_SIZE (1024 * 1024 * 8)
/*Custom blend mode for mask drawing, disable if you need to link with older SDL2 lib*/
#define LV_GPU_SDL_CUSTOM_BLEND_MODE (SDL_VERSION_ATLEAST(2, 0, 6))
#endif    /* LV_USE_GPU_SDL */

/*-------------
 * Logging
 *-----------*/

/*Enable the log module*/
#define LV_USE_LOG 0
#if LV_USE_LOG
/*How important log should be added:
*LV_LOG_LEVEL_TRACE       A lot of logs to give detailed information
*LV_LOG_LEVEL_INFO        Log important events
*LV_LOG_LEVEL_WARN        Log if something unwanted happened but didn't cause a problem
*LV_LOG_LEVEL_ERROR       Only critical issue, when the system may fail
*LV_LOG_LEVEL_USER        Only logs added by the user
*LV_LOG_LEVEL_NONE        Do not log anything*/
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN

/*1: Print the log with 'printf';
 *0: User need to register a callback with `lv_log_register_print_cb()`*/
#define LV_LOG_PRINTF 0
#define LV_LOG_TRACE_MEM 1
#define LV_LOG_TRACE_TIMER 1
#define LV_LOG_TRACE_INDEV 1
#define LV_LOG_TRACE_DISP_REFR 1
#define LV_LOG_TRACE_EVENT 1
#define LV_LOG_TRACE_OBJ_CREATE 1
#define LV_LOG_TRACE_LAYOUT 1
#define LV_LOG_TRACE_ANIM 1
#endif    /* LV_USE_LOG */

/*-------------
 * Asserts
 *-----------*/

/*Enable asserts if an operation is failed or an invalid data is found.
 *If LV_USE_LOG is enabled an error message will be printed on failure*/

/*Check if the parameter is NULL. (Very fast, recommended)*/
#define LV_USE_ASSERT_NULL 1
/*Checks is the memory is successfully allocated or no. (Very fast, recommended)*/
#define LV_USE_ASSERT_MALLOC 1
/*Check if the styles are properly initialized. (Very fast, recommended)*/
#define LV_USE_ASSERT_STYLE 0
/*Check the integrity of `lv_mem` after critical operations. (Slow)*/
#define LV_USE_ASSERT_MEM_INTEGRITY 0
/*Check the object's type and existence (e.g. not deleted). (Slow)*/
#define LV_USE_ASSERT_OBJ 0

/*Add a custom handler when assert happens e.g. to restart the MCU*/
#define LV_ASSERT_HANDLER_INCLUDE <stdint.h>
/*Halt by default*/
#define LV_ASSERT_HANDLER while(1);

/*-------------
 * Others
 *-----------*/

/*1: Show CPU usage and FPS count*/
#define LV_USE_PERF_MONITOR 0
#if LV_USE_PERF_MONITOR
#define LV_USE_PERF_MONITOR_POS LV_ALIGN_BOTTOM_RIGHT
#endif    /* LV_USE_PERF_MONITOR */

/*1: Show the used memory and the memory fragmentation
 * Requires LV_MEM_CUSTOM = 0*/
#define LV_USE_MEM_MONITOR 0
#if LV_USE_MEM_MONITOR
#define LV_USE_MEM_MONITOR_POS LV_ALIGN_BOTTOM_LEFT
#endif    /* LV_USE_MEM_MONITOR */

/*1: Draw random colored rectangles over the redrawn areas*/
#define LV_USE_REFR_DEBUG 0

/*Change the built in (v)snprintf functions*/
#define LV_SPRINTF_CUSTOM 0
#if LV_SPRINTF_CUSTOM
#define LV_SPRINTF_INCLUDE <stdio.h>
#define lv_snprintf snprintf
#define lv_vsnprintf vsnprintf
#else     /* LV_SPRINTF_CUSTOM */
#define LV_SPRINTF_USE_FLOAT 0
#endif    /* LV_SPRINTF_CUSTOM */

#define LV_USE_USER_DATA 1

/*Garbage Collector settings
 *Used if lvgl is bound to higher level language and the memory is managed by that language*/
#define LV_ENABLE_GC 0
#if LV_ENABLE_GC
/*Include Garbage Collector related things*/
#define LV_GC_INCLUDE "gc.h"
#endif    /* LV_ENABLE_GC */

/*=====================
 *  COMPILER SETTINGS
 *====================*/

/*For big endian systems set to 1*/
#define LV_BIG_ENDIAN_SYSTEM 0

/*Define a custom attribute to `lv_tick_inc` function*/
#define LV_ATTRIBUTE_TICK_INC 

/*Define a custom attribute to `lv_timer_handler` function*/
#define LV_ATTRIBUTE_TIMER_HANDLER 

/*Define a custom attribute to `lv_disp_flush_ready` function*/
#define LV_ATTRIBUTE_FLUSH_READY 

#ifndef LV_ATTRIBUTE_LARGE_CONST
/*Attribute to mark large constant arrays for example font's bitmaps*/
#define LV_ATTRIBUTE_LARGE_CONST 
#endif    /* LV_ATTRIBUTE_LARGE_CONST */

/*Compiler prefix for a big array declaration in RAM*/
#define LV_ATTRIBUTE_LARGE_RAM_ARRAY 

/*Place performance critical functions into a faster memory (e.g RAM)*/
#define LV_ATTRIBUTE_FAST_MEM 

/*Prefix variables that are used in GPU accelerated operations,
 often these need to be placed in RAM sections that are DMA accessible*/
#define LV_ATTRIBUTE_DMA 

/*Export integer constant to binding. This macro is used with constants in the form of LV_<CONST> that
 *should also appear on LVGL binding API such as Micropython.*/
#define LV_EXPORT_CONST_INT(int_value) struct _silence_gcc_warning

/*Extend the default -32k..32k coordinate range to -4M..4M by using int32_t for coordinates instead of int16_t*/
#define LV_USE_LARGE_COORD 0

/*==================
 *   FONT USAGE
 *===================*/

/*Montserrat fonts with ASCII range and some symbols using bpp = 4
 *https://fonts.google.com/specimen/Montserrat*/
#define LV_FONT_MONTSERRAT_8 0
#define LV_FONT_MONTSERRAT_10 0
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_16 0
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

/*Demonstrate special features*/
#define LV_FONT_MONTSERRAT_12_SUBPX 0
/*bpp = 3*/
#define LV_FONT_MONTSERRAT_28_COMPRESSED 0
/*Hebrew, Arabic, Persian letters and all their forms*/
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 0
/*1000 most common CJK radicals*/
#define LV_FONT_SIMSUN_16_CJK 0

/*Pixel perfect monospace fonts*/
#define LV_FONT_UNSCII_8 0
#define LV_FONT_UNSCII_16 0

/*Optionally declare custom fonts here.
 *You can use these fonts as default font too and they will be available globally.
 *E.g. #define LV_FONT_CUSTOM_DECLARE   LV_FONT_DECLARE(my_font_1) LV_FONT_DECLARE(my_font_2)*/
#define LV_FONT_CUSTOM_DECLARE 

/*Always set a default font*/
#define LV_FONT_DEFAULT &lv_font_montserrat_14

/*Enable handling large font and/or fonts with a lot of characters.
 *The limit depends on the font size, font face and bpp.
 *Compiler error will be triggered if a font needs it.*/
#define LV_FONT_FMT_TXT_LARGE 0

/*Enables/disables support for compressed fonts.*/
#define LV_USE_FONT_COMPRESSED 0

/*Enable subpixel rendering*/
#define LV_USE_FONT_SUBPX 0
#if LV_USE_FONT_SUBPX
/*Set the pixel order of the display. Physical order of RGB channels. Doesn't matter with "normal" fonts.*/
#define LV_FONT_SUBPX_BGR 0
#endif    /* LV_USE_FONT_SUBPX */

/*Enable drawing placeholders when glyph dsc is not found*/
#define LV_USE_FONT_PLACEHOLDER 1

/*=================
 *  TEXT SETTINGS
 *=================*/

/**
 * Select a character encoding for strings.
 * Your IDE or editor should have the same character encoding
 * - LV_TXT_ENC_UTF8
 * - LV_TXT_ENC_ASCII
 */
#define LV_TXT_ENC LV_TXT_ENC_UTF8

/*Can break (wrap) texts on these chars*/
#define LV_TXT_BREAK_CHARS " ,.;:-_"

/*If a word is at least this long, will break wherever "prettiest"
 *To disable, set to a value <= 0*/
#define LV_TXT_LINE_BREAK_LONG_LEN 0

/*Minimum number of characters in a long word to put on a line before a break.
 *Depends on LV_TXT_LINE_BREAK_LONG_LEN.*/
#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN 3

/*Minimum number of characters in a long word to put on a line after a break.
 *Depends on LV_TXT_LINE_BREAK_LONG_LEN.*/
#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN 3

/*The control character to use for signalling text recoloring.*/
#define LV_TXT_COLOR_CMD "#"

/*Support bidirectional texts. Allows mixing Left-to-Right and Right-to-Left texts.
 *The direction will be processed according to the Unicode Bidirectional Algorithm:
 *https://www.w3.org/International/articles/inline-bidi-markup/uba-basics*/
#define LV_USE_BIDI 0
#if LV_USE_BIDI
/*Set the default direction. Supported values:
*`LV_BASE_DIR_LTR` Left-to-Right
*`LV_BASE_DIR_RTL` Right-to-Left
*`LV_BASE_DIR_AUTO` detect texts base direction*/
#define LV_BIDI_BASE_DIR_DEF LV_BIDI_DIR_AUTO
#endif    /* LV_USE_BIDI */

/*Enable Arabic/Persian processing
 *In these languages characters should be replaced with an other form based on their position in the text*/
#define LV_USE_ARABIC_PERSIAN_CHARS 0

/*==================
 *  WIDGET USAGE
 *================*/

/*Documentation of the widgets: https://docs.lvgl.io/latest/en/html/widgets/index.html*/
#define LV_USE_ARC 1

#define LV_USE_BAR 1

#define LV_USE_BTN 0

#define LV_USE_BTNMATRIX 0

#define LV_USE_CANVAS 0

#define LV_USE_CHECKBOX 1

#define LV_USE_DROPDOWN 0

#define LV_USE_IMG 1

#define LV_USE_LABEL 1
#if LV_USE_LABEL
/*Enable selecting text of the label*/
#define LV_LABEL_TEXT_SELECTION 1
/*Store some extra info in labels to speed up drawing of very long texts*/
#define LV_LABEL_LONG_TXT_HINT 1
#endif    /* LV_USE_LABEL */

#define LV_USE_LINE 0

#define LV_USE_ROLLER 0
#if LV_USE_ROLLER
/*Number of extra "pages" when the roller is infinite*/
#define LV_ROLLER_INF_PAGES 7
#endif    /* LV_USE_ROLLER */

#define LV_USE_SLIDER 0

#define LV_USE_SWITCH 0

#define LV_USE_TEXTAREA 0
#if LV_USE_TEXTAREA
#define LV_TEXTAREA_DEF_PWD_SHOW_TIME 1500
#endif    /* LV_USE_TEXTAREA */

#define LV_USE_TABLE 0

/*==================
 * EXTRA COMPONENTS
 *==================*/

/*-----------
 * Widgets
 *----------*/

#define LV_USE_ANALOGCLOCK 0

#define LV_USE_ANIMIMG 0

#define LV_USE_CALENDAR 0
#if LV_USE_CALENDAR
#define LV_CALENDAR_WEEK_STARTS_MONDAY 0
#if LV_CALENDAR_WEEK_STARTS_MONDAY == 0
#define LV_CALENDAR_DEFAULT_DAY_NAMES {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"}
#endif    /* LV_CALENDAR_WEEK_STARTS_MONDAY */
#define LV_CALENDAR_DEFAULT_MONTH_NAMES {"January", "February", "March",  "April", "May",  "June", "July", "August", "September", "October", "November", "December"}
#define LV_USE_CALENDAR_HEADER_ARROW 1
#define LV_USE_CALENDAR_HEADER_DROPDOWN 1
#endif    /* LV_USE_CALENDAR */

#define LV_USE_CAROUSEL 0

#define LV_USE_CHART 0

#define LV_USE_COLORWHEEL 0

#define LV_USE_DCLOCK 0

#define LV_USE_IMGBTN 0

#define LV_USE_KEYBOARD 0

#define LV_USE_LED 0

#define LV_USE_LIST 0

#define LV_USE_MENU 0

#define LV_USE_METER 0

#define LV_USE_MSGBOX 0

#define LV_USE_RADIOBTN 0

#define LV_USE_SPAN 0
#if LV_USE_SPAN
/*A line text can contain maximum num of span descriptor */
#define LV_SPAN_SNIPPET_STACK_SIZE 64
#endif    /* LV_USE_SPAN */

#define LV_USE_SPINBOX 0

#define LV_USE_SPINNER 0

#define LV_USE_TABVIEW 0

#define LV_USE_TILEVIEW 0

#define LV_USE_VIDEO 0

#define LV_USE_WIN 0

#define LV_USE_ZH_KEYBOARD 0
#if LV_USE_ZH_KEYBOARD
#define LV_ZH_KEYBOARD_MINI 0
#endif    /* LV_USE_ZH_KEYBOARD */

/*-----------
 * Themes
 *----------*/

/*A simple, impressive and very complete theme*/
#define LV_USE_THEME_DEFAULT 1
#if LV_USE_THEME_DEFAULT
/*0: Light mode; 1: Dark mode*/
#define LV_THEME_DEFAULT_DARK 0
/*1: Enable grow on press*/
#define LV_THEME_DEFAULT_GROW 1
/*Default transition time in [ms]*/
#define LV_THEME_DEFAULT_TRANSITION_TIME 80
#endif    /* LV_USE_THEME_DEFAULT */

/*A very simple theme that is a good starting point for a custom theme*/
#define LV_USE_THEME_BASIC 1

/*A theme designed for monochrome displays*/
#define LV_USE_THEME_MONO 1

/*-----------
 * Layouts
 *----------*/

/*A layout similar to Flexbox in CSS.*/
#define LV_USE_FLEX 1

/*A layout similar to Grid in CSS.*/
#define LV_USE_GRID 1

/*---------------------
 * 3rd party libraries
 *--------------------*/

/*File system interfaces for common APIs */

/*API for fopen, fread, etc*/
#define LV_USE_FS_STDIO 0
#if LV_USE_FS_STDIO
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#define LV_FS_STDIO_LETTER '\0'
/*Set the working directory. File/directory paths will be appended to it.*/
#define LV_FS_STDIO_PATH ""
/*>0 to cache this number of bytes in lv_fs_read()*/
#define LV_FS_STDIO_CACHE_SIZE 0
#endif    /* LV_USE_FS_STDIO */

/*API for open, read, etc*/
#define LV_USE_FS_POSIX 0
#if LV_USE_FS_POSIX
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#define LV_FS_POSIX_LETTER '\0'
/*Set the working directory. File/directory paths will be appended to it.*/
#define LV_FS_POSIX_PATH ""
/*>0 to cache this number of bytes in lv_fs_read()*/
#define LV_FS_POSIX_CACHE_SIZE 0
#endif    /* LV_USE_FS_POSIX */

/*API for CreateFile, ReadFile, etc*/
#define LV_USE_FS_WIN32 0
#if LV_USE_FS_WIN32
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#define LV_FS_WIN32_LETTER '\0'
/*Set the working directory. File/directory paths will be appended to it.*/
#define LV_FS_WIN32_PATH ""
/*>0 to cache this number of bytes in lv_fs_read()*/
#define LV_FS_WIN32_CACHE_SIZE 0
#endif    /* LV_USE_FS_WIN32 */

/*API for FATFS (needs to be added separately). Uses f_open, f_read, etc*/
#define LV_USE_FS_FATFS 0
#if LV_USE_FS_FATFS
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#define LV_FS_FATFS_LETTER 'S'
/*>0 to cache this number of bytes in lv_fs_read()*/
#define LV_FS_FATFS_CACHE_SIZE 0
#endif    /* LV_USE_FS_FATFS */

/*API for RAWFS (needs to be added separately).*/
#define LV_USE_FS_RAWFS 0
#if LV_USE_FS_RAWFS
/*Set an upper cased letter on which the drive will accessible (e.g. 'A')*/
#define LV_FS_RAWFS_LETTER 'F'
/*use the XIP flash*/
#define LV_FS_RAWFS_XIP 0
#if LV_FS_RAWFS_XIP
/*the XIP flash address where the image binary is placed*/
#define LV_FS_RAWFS_XIP_BASE_ADDR 
#endif    /* LV_FS_RAWFS_XIP */
#endif    /* LV_USE_FS_RAWFS */

/*PNG decoder library*/
#define LV_USE_PNG 0

/*BMP decoder library*/
#define LV_USE_BMP 0

/* JPG + split JPG decoder library.
 * Split JPG is a custom format optimized for embedded systems. */
#define LV_USE_SJPG 0

/*GIF decoder library*/
#define LV_USE_GIF 0

/*QR code library*/
#define LV_USE_QRCODE 0

/*FreeType library*/
#define LV_USE_FREETYPE 0
#if LV_USE_FREETYPE
/*Memory used by FreeType to cache characters [bytes] (-1: no caching)*/
#define LV_FREETYPE_CACHE_SIZE (16U * 1024U)
#if LV_FREETYPE_CACHE_SIZE >= 0
/* 1: bitmap cache use the sbit cache, 0:bitmap cache use the image cache. */
/* sbit cache:it is much more memory efficient for small bitmaps(font size < 256) */
/* if font size >= 256, must be configured as image cache */
#define LV_FREETYPE_SBIT_CACHE 0
/* Maximum number of opened FT_Face/FT_Size objects managed by this cache instance. */
/* (0:use system defaults) */
#define LV_FREETYPE_CACHE_FT_FACES 0
#define LV_FREETYPE_CACHE_FT_SIZES 0
#endif    /* LV_FREETYPE_CACHE_SIZE */
#endif    /* LV_USE_FREETYPE */

/*Rlottie library*/
#define LV_USE_RLOTTIE 0

/*FFmpeg library for image decoding and playing videos
 *Supports all major image formats so do not enable other image decoder with it*/
#define LV_USE_FFMPEG 0
#if LV_USE_FFMPEG
/*Dump input information to stderr*/
#define LV_FFMPEG_DUMP_FORMAT 0
#endif    /* LV_USE_FFMPEG */

/*-----------
 * Others
 *----------*/

/*1: Enable API to take snapshot for object*/
#define LV_USE_SNAPSHOT 0

/*1: Enable Monkey test*/
#define LV_USE_MONKEY 0

/*1: Enable grid navigation*/
#define LV_USE_GRIDNAV 0

/*1: Enable lv_obj fragment*/
#define LV_USE_FRAGMENT 0

/*1: Support using images as font in label or span widgets */
#define LV_USE_IMGFONT 0

/*1: Enable a published subscriber based messaging system */
#define LV_USE_MSG 0

/*1: Enable Pinyin input method. Requires: lv_keyboard*/
#define LV_USE_IME_PINYIN 0
#if LV_USE_IME_PINYIN
/*1: Use default thesaurus*/
/*If you do not use the default thesaurus, be sure to use `lv_ime_pinyin` after setting the thesauruss*/
#define LV_IME_PINYIN_USE_DEFAULT_DICT 1
/*Set the maximum number of candidate panels that can be displayed*/
/*This needs to be adjusted according to the size of the screen*/
#define LV_IME_PINYIN_CAND_TEXT_NUM 6

/*Use 9 key input(k9)*/
#define LV_IME_PINYIN_USE_K9_MODE 1
#if LV_IME_PINYIN_USE_K9_MODE
#define LV_IME_PINYIN_K9_CAND_TEXT_NUM 3
#endif    /* LV_IME_PINYIN_USE_K9_MODE */
#endif    /* LV_USE_IME_PINYIN */
/*Enable the text progress bar*/
#define LV_USE_TEXTPROGRESS 0
/*Enable the barcode*/
#define LV_USE_BARCODE 0

#define LV_USE_GUIDER_SIMULATOR 0
#include "lv_conf_ext.h"

#endif