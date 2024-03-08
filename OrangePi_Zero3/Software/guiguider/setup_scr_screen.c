/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 320, 172);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0xd2cdcd), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arc_cpu
	ui->screen_arc_cpu = lv_arc_create(ui->screen);
	lv_arc_set_mode(ui->screen_arc_cpu, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_cpu, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_cpu, 0, 360);
	lv_arc_set_angles(ui->screen_arc_cpu, 0, 0);
	lv_arc_set_rotation(ui->screen_arc_cpu, 90);
	lv_obj_set_pos(ui->screen_arc_cpu, 6, 38);
	lv_obj_set_size(ui->screen_arc_cpu, 90, 90);

	//Write style for screen_arc_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_cpu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_cpu, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_cpu, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_cpu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_cpu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_cpu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_cpu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_cpu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_cpu, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_cpu, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_cpu, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_cpu, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_cpu, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_cpu, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_cpu, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_cpu, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_arc_mem
	ui->screen_arc_mem = lv_arc_create(ui->screen);
	lv_arc_set_mode(ui->screen_arc_mem, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_mem, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_mem, 0, 360);
	lv_arc_set_angles(ui->screen_arc_mem, 0, 0);
	lv_arc_set_rotation(ui->screen_arc_mem, 90);
	lv_obj_set_pos(ui->screen_arc_mem, 103, 38);
	lv_obj_set_size(ui->screen_arc_mem, 90, 90);

	//Write style for screen_arc_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_mem, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_mem, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_mem, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_mem, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_mem, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_mem, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_mem, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_mem, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_mem, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_mem, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_mem, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_mem, lv_color_hex(0xffe200), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_mem, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_mem, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_mem, lv_color_hex(0xffe200), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_mem, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_cont_disk
	ui->screen_cont_disk = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_disk, 6, 135);
	lv_obj_set_size(ui->screen_cont_disk, 309, 32);
	lv_obj_set_scrollbar_mode(ui->screen_cont_disk, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_disk, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_disk, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_disk, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_disk, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_disk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_disk, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_disk);
	lv_label_set_text(ui->screen_label_1, "Disk:");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 9, 8);
	lv_obj_set_size(ui->screen_label_1, 45, 13);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bar_disk
	ui->screen_bar_disk = lv_bar_create(ui->screen_cont_disk);
	lv_obj_set_style_anim_time(ui->screen_bar_disk, 1000, 0);
	lv_bar_set_mode(ui->screen_bar_disk, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screen_bar_disk, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_bar_disk, 54, 8);
	lv_obj_set_size(ui->screen_bar_disk, 153, 14);

	//Write style for screen_bar_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_disk, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_disk, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_disk, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bar_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bar_disk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_disk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_disk, lv_color_hex(0x2FDAAE), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_disk, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_lb_disk
	ui->screen_lb_disk = lv_label_create(ui->screen_cont_disk);
	lv_label_set_text(ui->screen_lb_disk, "0/0G");
	lv_label_set_long_mode(ui->screen_lb_disk, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_disk, 210, 8);
	lv_obj_set_size(ui->screen_lb_disk, 84, 14);

	//Write style for screen_lb_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_disk, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_disk, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_disk, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_disk, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_cpu
	ui->screen_lb_cpu = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_lb_cpu, "0.0%\nCPU");
	lv_label_set_long_mode(ui->screen_lb_cpu, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_cpu, 20, 75);
	lv_obj_set_size(ui->screen_lb_cpu, 66, 22);

	//Write style for screen_lb_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_cpu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_cpu, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_cpu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_cpu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_mem
	ui->screen_lb_mem = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_lb_mem, "0.0%\nMEM");
	lv_label_set_long_mode(ui->screen_lb_mem, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_mem, 116, 75);
	lv_obj_set_size(ui->screen_lb_mem, 67, 22);

	//Write style for screen_lb_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_mem, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_mem, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_mem, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_mem, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_net_flow
	ui->screen_cont_net_flow = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_net_flow, 201, 38);
	lv_obj_set_size(ui->screen_cont_net_flow, 114, 90);
	lv_obj_set_scrollbar_mode(ui->screen_cont_net_flow, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_net_flow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_net_flow, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_net_flow, lv_color_hex(0xff8800), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_net_flow, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_net_flow, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_net_flow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_net_flow, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_net_flow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_dl
	ui->screen_img_dl = lv_img_create(ui->screen_cont_net_flow);
	lv_obj_add_flag(ui->screen_img_dl, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_dl, &_download_alpha_16x16);
	lv_img_set_pivot(ui->screen_img_dl, 50,50);
	lv_img_set_angle(ui->screen_img_dl, 0);
	lv_obj_set_pos(ui->screen_img_dl, 5, 41);
	lv_obj_set_size(ui->screen_img_dl, 16, 16);

	//Write style for screen_img_dl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_dl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_up
	ui->screen_img_up = lv_img_create(ui->screen_cont_net_flow);
	lv_obj_add_flag(ui->screen_img_up, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_up, &_upload_alpha_16x16);
	lv_img_set_pivot(ui->screen_img_up, 50,50);
	lv_img_set_angle(ui->screen_img_up, 0);
	lv_obj_set_pos(ui->screen_img_up, 5, 19);
	lv_obj_set_size(ui->screen_img_up, 16, 16);

	//Write style for screen_img_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_up, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_dl
	ui->screen_lb_dl = lv_label_create(ui->screen_cont_net_flow);
	lv_label_set_text(ui->screen_lb_dl, "0B/s");
	lv_label_set_long_mode(ui->screen_lb_dl, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_dl, 26, 42);
	lv_obj_set_size(ui->screen_lb_dl, 81, 17);

	//Write style for screen_lb_dl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_dl, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_dl, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_dl, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_dl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_dl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_up
	ui->screen_lb_up = lv_label_create(ui->screen_cont_net_flow);
	lv_label_set_text(ui->screen_lb_up, "0B/s");
	lv_label_set_long_mode(ui->screen_lb_up, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_lb_up, 26, 22);
	lv_obj_set_size(ui->screen_lb_up, 81, 17);

	//Write style for screen_lb_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_up, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_up, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_up, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_up, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_net
	ui->screen_img_net = lv_img_create(ui->screen_cont_net_flow);
	lv_obj_add_flag(ui->screen_img_net, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_net, &_flow_alpha_20x20);
	lv_img_set_pivot(ui->screen_img_net, 50,50);
	lv_img_set_angle(ui->screen_img_net, 0);
	lv_obj_set_pos(ui->screen_img_net, 45, -1);
	lv_obj_set_size(ui->screen_img_net, 20, 20);

	//Write style for screen_img_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_net, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen_cont_net_flow);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1, &_temp_alpha_16x16);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
	lv_obj_set_pos(ui->screen_img_1, 4, 61);
	lv_obj_set_size(ui->screen_img_1, 16, 16);

	//Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_temp
	ui->screen_lb_temp = lv_label_create(ui->screen_cont_net_flow);
	lv_label_set_text(ui->screen_lb_temp, "0.0 C");
	lv_label_set_long_mode(ui->screen_lb_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_temp, 31, 64);
	lv_obj_set_size(ui->screen_lb_temp, 73, 17);

	//Write style for screen_lb_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_temp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_net_ip
	ui->screen_cont_net_ip = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_net_ip, 86, 3);
	lv_obj_set_size(ui->screen_cont_net_ip, 229, 29);
	lv_obj_set_scrollbar_mode(ui->screen_cont_net_ip, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_net_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_net_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_net_ip, lv_color_hex(0xff00c6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_net_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_net_ip, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_net_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_net_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_cur_net
	ui->screen_lb_cur_net = lv_label_create(ui->screen_cont_net_ip);
	lv_label_set_text(ui->screen_lb_cur_net, "Wait:");
	lv_label_set_long_mode(ui->screen_lb_cur_net, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_cur_net, 5, 6);
	lv_obj_set_size(ui->screen_lb_cur_net, 42, 13);

	//Write style for screen_lb_cur_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_cur_net, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_cur_net, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_cur_net, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_cur_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_ip
	ui->screen_lb_ip = lv_label_create(ui->screen_cont_net_ip);
	lv_label_set_text(ui->screen_lb_ip, "Waiting");
	lv_label_set_long_mode(ui->screen_lb_ip, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_ip, 57, 6);
	lv_obj_set_size(ui->screen_lb_ip, 136, 15);

	//Write style for screen_lb_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_ip, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_ip, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_logo
	ui->screen_cont_logo = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_logo, 5, 3);
	lv_obj_set_size(ui->screen_cont_logo, 75, 29);
	lv_obj_set_scrollbar_mode(ui->screen_cont_logo, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_logo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_logo, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_logo, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_logo, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_logo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_logo
	ui->screen_img_logo = lv_img_create(ui->screen_cont_logo);
	lv_obj_add_flag(ui->screen_img_logo, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_logo, &_logo_alpha_68x22);
	lv_img_set_pivot(ui->screen_img_logo, 50,50);
	lv_img_set_angle(ui->screen_img_logo, 0);
	lv_obj_set_pos(ui->screen_img_logo, 0, 2);
	lv_obj_set_size(ui->screen_img_logo, 68, 22);

	//Write style for screen_img_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	
}
