/*
 * @Author: Jinqi Xu 
 * @Date: 2021-04-28 16:09:35 
 * @Last Modified by: Jinqi Xu
 * @Last Modified time: 2021-04-28 17:56:06
 */
//
// Created by 15573 on 2021/4/28.
//

#ifndef BANKER_BANKER_H
#define BANKER_BANKER_H

#define M 5 //进程数
#define N 3 //资源种类

extern int Available[N];           //系统剩余资源
extern int Request[M];             //进程请求资源
extern int Max[M][N];              //进程最大资源需求量
extern int Allocation[M][N];       //当前系统进程已有资源
extern int Need[M][N];             //进程仍需要的资源
extern bool Finish[M];             //进程可否拥有足够资源完成运行
extern int Work[M][N];

void Print();                      //输出系统进程信息
void SafePrint();                  //输出安全性信息
bool isSafe();                     //安全性检查
#endif                             //BANKER_BANKER_H
