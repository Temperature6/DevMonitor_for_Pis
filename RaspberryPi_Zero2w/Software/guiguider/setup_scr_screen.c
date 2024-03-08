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
	lv_obj_set_size(ui->screen, 280, 240);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0xdbdbdb), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_disk
	ui->screen_cont_disk = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_disk, 5, 198);
	lv_obj_set_size(ui->screen_cont_disk, 270, 37);
	lv_obj_set_scrollbar_mode(ui->screen_cont_disk, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_disk, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_disk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_disk, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_disk, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_disk, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_disk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_disk, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bar_disk
	ui->screen_bar_disk = lv_bar_create(ui->screen_cont_disk);
	lv_obj_set_style_anim_time(ui->screen_bar_disk, 1000, 0);
	lv_bar_set_mode(ui->screen_bar_disk, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screen_bar_disk, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_bar_disk, 50, 8);
	lv_obj_set_size(ui->screen_bar_disk, 135, 17);

	//Write style for screen_bar_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_disk, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_disk, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_disk, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bar_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bar_disk, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bar_disk, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bar_disk, lv_color_hex(0x00ffb6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bar_disk, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_lb_disk
	ui->screen_lb_disk = lv_label_create(ui->screen_cont_disk);
	lv_label_set_text(ui->screen_lb_disk, "0 / 0G");
	lv_label_set_long_mode(ui->screen_lb_disk, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_disk, 191, 10);
	lv_obj_set_size(ui->screen_lb_disk, 76, 16);

	//Write style for screen_lb_disk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_disk, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_disk, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_disk, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_disk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_disk);
	lv_label_set_text(ui->screen_label_1, "Disk:");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, -23, 10);
	lv_obj_set_size(ui->screen_label_1, 100, 32);

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

	//Write codes screen_cont_cpu_mem
	ui->screen_cont_cpu_mem = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_cpu_mem, 4, 87);
	lv_obj_set_size(ui->screen_cont_cpu_mem, 181, 107);
	lv_obj_set_scrollbar_mode(ui->screen_cont_cpu_mem, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_cpu_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_cpu_mem, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_cpu_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_cpu_mem, lv_color_hex(0xffab00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_cpu_mem, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_cpu_mem, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_cpu_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_cpu_mem, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_cpu_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_cpu_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_cpu_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_cpu_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_cpu_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arc_mem
	ui->screen_arc_mem = lv_arc_create(ui->screen_cont_cpu_mem);
	lv_arc_set_mode(ui->screen_arc_mem, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_mem, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_mem, 0, 360);
	lv_arc_set_angles(ui->screen_arc_mem, 0, 0);
	lv_arc_set_rotation(ui->screen_arc_mem, 90);
	lv_obj_set_pos(ui->screen_arc_mem, 96, 14);
	lv_obj_set_size(ui->screen_arc_mem, 75, 75);

	//Write style for screen_arc_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_mem, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_mem, lv_color_hex(0xc3c3c3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_mem, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_mem, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_mem, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_mem, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_mem, lv_color_hex(0xd0ff00), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_mem, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_mem, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_mem, lv_color_hex(0xd0ff00), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_mem, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_arc_cpu
	ui->screen_arc_cpu = lv_arc_create(ui->screen_cont_cpu_mem);
	lv_arc_set_mode(ui->screen_arc_cpu, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->screen_arc_cpu, 0, 100);
	lv_arc_set_bg_angles(ui->screen_arc_cpu, 0, 360);
	lv_arc_set_angles(ui->screen_arc_cpu, 0, 0);
	lv_arc_set_rotation(ui->screen_arc_cpu, 90);
	lv_obj_set_pos(ui->screen_arc_cpu, 6, 14);
	lv_obj_set_size(ui->screen_arc_cpu, 75, 75);

	//Write style for screen_arc_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_arc_cpu, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_cpu, lv_color_hex(0xc3c3c3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arc_cpu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arc_cpu, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_arc_cpu, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_arc_cpu, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_arc_cpu, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_arc_cpu, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arc_cpu, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arc_cpu, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen_arc_cpu, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_lb_cpu
	ui->screen_lb_cpu = lv_label_create(ui->screen_cont_cpu_mem);
	lv_label_set_text(ui->screen_lb_cpu, "0.0%\nCPU");
	lv_label_set_long_mode(ui->screen_lb_cpu, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_cpu, 6, 42);
	lv_obj_set_size(ui->screen_lb_cpu, 77, 26);

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
	ui->screen_lb_mem = lv_label_create(ui->screen_cont_cpu_mem);
	lv_label_set_text(ui->screen_lb_mem, "0.0%\nMEM");
	lv_label_set_long_mode(ui->screen_lb_mem, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_mem, 95, 42);
	lv_obj_set_size(ui->screen_lb_mem, 77, 26);

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

	//Write codes screen_cont_clk
	ui->screen_cont_clk = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_clk, 189, 87);
	lv_obj_set_size(ui->screen_cont_clk, 85, 39);
	lv_obj_set_scrollbar_mode(ui->screen_cont_clk, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_clk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_clk, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_clk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_clk, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_clk, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_clk, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_clk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_clk, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_clk
	ui->screen_lb_clk = lv_label_create(ui->screen_cont_clk);
	lv_label_set_text(ui->screen_lb_clk, "12:00");
	lv_label_set_long_mode(ui->screen_lb_clk, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_clk, 5, 6);
	lv_obj_set_size(ui->screen_lb_clk, 71, 24);

	//Write style for screen_lb_clk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_clk, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_clk, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_clk, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_clk, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_clk, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_clk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_net
	ui->screen_cont_net = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_net, 94, 3);
	lv_obj_set_size(ui->screen_cont_net, 180, 79);
	lv_obj_set_scrollbar_mode(ui->screen_cont_net, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_net, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_net, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_net, lv_color_hex(0x005cff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_net, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_net, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_net, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_3
	ui->screen_img_3 = lv_img_create(ui->screen_cont_net);
	lv_obj_add_flag(ui->screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_3, &_web_35x35);
	lv_img_set_pivot(ui->screen_img_3, 50,50);
	lv_img_set_angle(ui->screen_img_3, 0);
	lv_obj_set_pos(ui->screen_img_3, 8, 30);
	lv_obj_set_size(ui->screen_img_3, 35, 35);

	//Write style for screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cb_is_wifi
	ui->screen_cb_is_wifi = lv_checkbox_create(ui->screen_cont_net);
	lv_checkbox_set_text(ui->screen_cb_is_wifi, "WIFI");
	lv_obj_set_pos(ui->screen_cb_is_wifi, 6, 4);

	//Write style for screen_cb_is_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_cb_is_wifi, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cb_is_wifi, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_cb_is_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_cb_is_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cb_is_wifi, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cb_is_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cb_is_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_cb_is_wifi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cb_is_wifi, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cb_is_wifi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cb_is_wifi, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cb_is_wifi, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cb_is_wifi, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cb_is_wifi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cb_is_wifi, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_lb_net_ip
	ui->screen_lb_net_ip = lv_label_create(ui->screen_cont_net);
	lv_label_set_text(ui->screen_lb_net_ip, "Waiting");
	lv_label_set_long_mode(ui->screen_lb_net_ip, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_lb_net_ip, 57, 3);
	lv_obj_set_size(ui->screen_lb_net_ip, 111, 18);

	//Write style for screen_lb_net_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_net_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_net_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_net_ip, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_net_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_net_ip, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_net_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_lb_net_ip, lv_color_hex(0xe7e7e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_net_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_net_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_up_speed
	ui->screen_lb_up_speed = lv_label_create(ui->screen_cont_net);
	lv_label_set_text(ui->screen_lb_up_speed, "0.0 B/s");
	lv_label_set_long_mode(ui->screen_lb_up_speed, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_lb_up_speed, 74, 27);
	lv_obj_set_size(ui->screen_lb_up_speed, 85, 18);

	//Write style for screen_lb_up_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_up_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_up_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_up_speed, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_up_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_up_speed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_up_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_lb_up_speed, lv_color_hex(0xe7e7e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_up_speed, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_up_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_dl_speed
	ui->screen_lb_dl_speed = lv_label_create(ui->screen_cont_net);
	lv_label_set_text(ui->screen_lb_dl_speed, "0.0B/s");
	lv_label_set_long_mode(ui->screen_lb_dl_speed, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_lb_dl_speed, 74, 52);
	lv_obj_set_size(ui->screen_lb_dl_speed, 85, 18);

	//Write style for screen_lb_dl_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_dl_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_dl_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_dl_speed, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_dl_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_dl_speed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_dl_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_lb_dl_speed, lv_color_hex(0xe7e7e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_dl_speed, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_dl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen_cont_net);
	lv_label_set_text(ui->screen_label_2, "");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_label_2, 57, 27);
	lv_obj_set_size(ui->screen_label_2, 23, 18);

	//Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_montserratMedium_8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_2, lv_color_hex(0xe7e7e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_up
	ui->screen_img_up = lv_img_create(ui->screen_cont_net);
	lv_obj_add_flag(ui->screen_img_up, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_up, &_upload_alpha_11x11);
	lv_img_set_pivot(ui->screen_img_up, 50,50);
	lv_img_set_angle(ui->screen_img_up, 0);
	lv_obj_set_pos(ui->screen_img_up, 63, 30);
	lv_obj_set_size(ui->screen_img_up, 11, 11);

	//Write style for screen_img_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_up, 129, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen_cont_net);
	lv_label_set_text(ui->screen_label_3, "");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_CLIP);
	lv_obj_set_pos(ui->screen_label_3, 57, 52);
	lv_obj_set_size(ui->screen_label_3, 23, 18);

	//Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_montserratMedium_8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_3, lv_color_hex(0xe7e7e7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen_cont_net);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1, &_download_alpha_11x11);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
	lv_obj_set_pos(ui->screen_img_1, 63, 57);
	lv_obj_set_size(ui->screen_img_1, 11, 11);

	//Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_1, 129, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_img
	ui->screen_cont_img = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_img, 189, 131);
	lv_obj_set_size(ui->screen_cont_img, 85, 63);
	lv_obj_set_scrollbar_mode(ui->screen_cont_img, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_img, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_img, lv_color_hex(0xcd2355), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_img, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_img, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_img, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_rpi_logo
	ui->screen_img_rpi_logo = lv_img_create(ui->screen_cont_img);
	lv_obj_add_flag(ui->screen_img_rpi_logo, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_rpi_logo, &_rpi_logo_e7_16bit_alpha_55x55);
	lv_img_set_pivot(ui->screen_img_rpi_logo, 50,50);
	lv_img_set_angle(ui->screen_img_rpi_logo, 0);
	lv_obj_set_pos(ui->screen_img_rpi_logo, 14, 2);
	lv_obj_set_size(ui->screen_img_rpi_logo, 55, 55);

	//Write style for screen_img_rpi_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_rpi_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_temp
	ui->screen_cont_temp = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_temp, 4, 3);
	lv_obj_set_size(ui->screen_cont_temp, 86, 79);
	lv_obj_set_scrollbar_mode(ui->screen_cont_temp, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_temp, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_temp, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_temp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_temp
	ui->screen_img_temp = lv_img_create(ui->screen_cont_temp);
	lv_obj_add_flag(ui->screen_img_temp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_temp, &_temp_alpha_30x30);
	lv_img_set_pivot(ui->screen_img_temp, 50,50);
	lv_img_set_angle(ui->screen_img_temp, 0);
	lv_obj_set_pos(ui->screen_img_temp, 26, 5);
	lv_obj_set_size(ui->screen_img_temp, 30, 30);

	//Write style for screen_img_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lb_temp
	ui->screen_lb_temp = lv_label_create(ui->screen_cont_temp);
	lv_label_set_text(ui->screen_lb_temp, "00.0 C");
	lv_label_set_long_mode(ui->screen_lb_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_lb_temp, 5, 46);
	lv_obj_set_size(ui->screen_lb_temp, 72, 22);

	//Write style for screen_lb_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_lb_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_lb_temp, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_lb_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_lb_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_lb_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	
}
