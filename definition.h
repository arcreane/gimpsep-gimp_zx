#pragma once
#ifndef DEFINITION_H
#define DEFINITION_H

#pragma once
#pragma execution_character_set("utf-8")//display chinese words

//Mat g_srcImage, g_dstImage;
//int g_nTrackbarNumer;//0表示腐蚀erode, 1表示膨胀dilate
//int g_nStructElementSize; //结构元素(内核矩阵)的尺寸
//-----------------------------------【全局函数声明部分】--------------------------------------
// //		描述：全局函数声明
//-----------------------------------------------------------------------------------------------
void Process(int value, void * img);//膨胀和腐蚀的处理函数
void on_TrackbarNumChange(int, void*);//回调函数
void on_ElementSizeChange(int, void*);//回调函数

void ContrastAndBright(int pos, void* data);

#endif