#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG__TEMP_ALPHA_16X16
#define LV_ATTRIBUTE_IMG__TEMP_ALPHA_16X16
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG__TEMP_ALPHA_16X16 uint8_t _temp_alpha_16x16_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0xff, 0xff, 0xff, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xb7, 0xff, 0xff, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0x92, 0xff, 0xff, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xee, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0xff, 0xff, 0x92, 0xff, 0xee, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0x6d, 0xff, 0xff, 0xff, 0x92, 0xff, 0xee, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xee, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xee, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0xff, 0xff, 0xff, 0xee, 0xff, 0xff, 0xff, 0x25, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0xff, 0xff, 0xed, 0xff, 0xf6, 0xff, 0xff, 0xff, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe9, 0xff, 0xe9, 0xff, 0xe9, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0xf6, 0xff, 0xe9, 0xff, 0xee, 0xff, 0xff, 0xff, 0xb7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0x49, 0xff, 0x92, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0xd7, 0xbd, 0xff, 0x79, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8a, 0x52, 0xff, 0xdb, 0xde, 0xff, 0xd3, 0x9c, 0xff, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xff, 0x55, 0xad, 0xff, 0xff, 0xff, 0xff, 0x30, 0x84, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x34, 0xa5, 0xff, 0x31, 0x8c, 0xff, 0xff, 0xff, 0xff, 0x30, 0x84, 0xff, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0xf7, 0xff, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0x10, 0x8c, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9a, 0xd6, 0xff, 0x96, 0xb5, 0xff, 0xff, 0xff, 0xff, 0x10, 0x8c, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x71, 0x8c, 0xff, 0xec, 0x62, 0xff, 0xff, 0xff, 0xff, 0x10, 0x8c, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0x8c, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x39, 0xce, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0x8c, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x38, 0xc6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4d, 0x6b, 0xff, 0x9e, 0xf7, 0xff, 0x8e, 0xfb, 0xff, 0x9a, 0xfe, 0xff, 0x65, 0x29, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5d, 0xef, 0xff, 0x55, 0xad, 0xff, 0x5d, 0xff, 0xff, 0xeb, 0xf2, 0xff, 0x14, 0xfd, 0xff, 0xdf, 0xff, 0xff, 0xb2, 0x94, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xdb, 0xde, 0xff, 0x69, 0xea, 0xff, 0x49, 0xf2, 0xff, 0x49, 0xf2, 0xff, 0x7e, 0xff, 0xff, 0xf8, 0xc5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7d, 0xef, 0xff, 0xb7, 0xbd, 0xff, 0xf4, 0xfc, 0xff, 0x49, 0xf2, 0xff, 0x4d, 0xfb, 0xff, 0xdf, 0xff, 0xff, 0x14, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xaf, 0x7b, 0xff, 0x1c, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0x9a, 0xd6, 0xff, 0x72, 0x94, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xde, 0xff, 0x34, 0xa5, 0xff, 0x6a, 0x52, 0xff, 0xae, 0x73, 0xff, 0xd7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xbd, 0xd7, 0xff, 0xce, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x52, 0x8a, 0xff, 0xde, 0xdb, 0xff, 0x9c, 0xd3, 0xff, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7b, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0xff, 0xad, 0x55, 0xff, 0xff, 0xff, 0xff, 0x84, 0x30, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa5, 0x34, 0xff, 0x8c, 0x31, 0xff, 0xff, 0xff, 0xff, 0x84, 0x30, 0xff, 0xff, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xff, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x10, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x9a, 0xff, 0xb5, 0x96, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x10, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x71, 0xff, 0x62, 0xec, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x10, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x10, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0xce, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x10, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0xc6, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6b, 0x4d, 0xff, 0xf7, 0x9e, 0xff, 0xfb, 0x8e, 0xff, 0xfe, 0x9a, 0xff, 0x29, 0x65, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x5d, 0xff, 0xad, 0x55, 0xff, 0xff, 0x5d, 0xff, 0xf2, 0xeb, 0xff, 0xfd, 0x14, 0xff, 0xff, 0xdf, 0xff, 0x94, 0xb2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xde, 0xdb, 0xff, 0xea, 0x69, 0xff, 0xf2, 0x49, 0xff, 0xf2, 0x49, 0xff, 0xff, 0x7e, 0xff, 0xc5, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7d, 0xff, 0xbd, 0xb7, 0xff, 0xfc, 0xf4, 0xff, 0xf2, 0x49, 0xff, 0xfb, 0x4d, 0xff, 0xff, 0xdf, 0xff, 0xa5, 0x14, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0x7b, 0xaf, 0xff, 0xe7, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0xd6, 0x9a, 0xff, 0x94, 0x72, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0xdb, 0xff, 0xa5, 0x34, 0xff, 0x52, 0x6a, 0xff, 0x73, 0xae, 0xff, 0xbd, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Alpha 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xee, 0xee, 0xee, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0xca, 0xca, 0xca, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0xd6, 0xd6, 0xd6, 0xff, 0x97, 0x97, 0x97, 0xff, 0xe8, 0xe8, 0xe8, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x75, 0x75, 0x75, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xce, 0xce, 0xce, 0xff, 0xa7, 0xa7, 0xa7, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0x83, 0x83, 0x83, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xa2, 0xa2, 0xa2, 0xff, 0x84, 0x84, 0x84, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x83, 0x82, 0x83, 0xff, 0xde, 0xdf, 0xfc, 0xff, 0xfc, 0xff, 0xf7, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf1, 0xf1, 0xf1, 0xff, 0xe8, 0xe8, 0xe8, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x82, 0x81, 0x85, 0xff, 0x6d, 0x6e, 0xf7, 0xff, 0xcf, 0xd0, 0xfc, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xd0, 0xd0, 0xd0, 0xff, 0xaf, 0xaf, 0xaf, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x82, 0x81, 0x86, 0xff, 0x6d, 0x6e, 0xf6, 0xff, 0xcf, 0xd0, 0xfe, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x8a, 0x8a, 0x8a, 0xff, 0x5d, 0x5d, 0x5d, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x82, 0x81, 0x86, 0xff, 0x6d, 0x6f, 0xf6, 0xff, 0xcf, 0xd0, 0xfe, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x82, 0x81, 0x86, 0xff, 0x6d, 0x6f, 0xf6, 0xff, 0xcf, 0xd0, 0xfe, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x82, 0x81, 0x86, 0xff, 0x6d, 0x6f, 0xf6, 0xff, 0xcf, 0xd0, 0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0x68, 0x68, 0x68, 0xff, 0xf0, 0xf0, 0xf3, 0xff, 0x6c, 0x6f, 0xf6, 0xff, 0xce, 0xd0, 0xfe, 0xff, 0x2a, 0x2a, 0x2a, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xe6, 0xe6, 0xe6, 0xff, 0xa8, 0xa6, 0xa7, 0xff, 0xe4, 0xe7, 0xff, 0xff, 0x5b, 0x5d, 0xf1, 0xff, 0x9e, 0x9f, 0xfc, 0xff, 0xf9, 0xf9, 0xfc, 0xff, 0x92, 0x92, 0x92, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xd7, 0xd8, 0xd5, 0xff, 0x49, 0x4b, 0xe9, 0xff, 0x47, 0x48, 0xf0, 0xff, 0x47, 0x47, 0xf1, 0xff, 0xed, 0xed, 0xfd, 0xff, 0xbc, 0xbc, 0xbc, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xea, 0xea, 0xea, 0xff, 0xb6, 0xb4, 0xb5, 0xff, 0x9c, 0x9a, 0xfa, 0xff, 0x48, 0x47, 0xf1, 0xff, 0x67, 0x67, 0xf9, 0xff, 0xf6, 0xf6, 0xff, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0x75, 0x75, 0x75, 0xff, 0xe0, 0xdf, 0xdf, 0xff, 0xfc, 0xfb, 0xff, 0xff, 0xf1, 0xf3, 0xf2, 0xff, 0xcf, 0xcf, 0xcf, 0xff, 0x8d, 0x8d, 0x8d, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xd6, 0xd6, 0xd6, 0xff, 0xa3, 0xa2, 0xa3, 0xff, 0x4d, 0x4c, 0x4e, 0xff, 0x72, 0x72, 0x72, 0xff, 0xb8, 0xb8, 0xb8, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
#endif
};

const lv_img_dsc_t _temp_alpha_16x16 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 256 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = _temp_alpha_16x16_map,
};