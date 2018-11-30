//坦克大战
//0、提示界面               完成
//1、边框                  完成
//2、指定位置显示自己的坦克         完成
//3、己方坦克随着方向键动起来       完成
	 //getasynkeustae            完成
	 //Sleep(毫秒)                完成   
	 //减少闪烁                    完成
	 //不闪烁                      完成
	 //SetConsoleCursorPosition   完成   
//4、指定位置显示敌方坦克           完成
//5、敌方坦克自己动起来             完成
		//随机动                  完成
		//速度控制                完成
		//旧坦克位置清空           完成


//6、己方坦克，按空格键发子弹       
	  //按空格键 创建子弹          完成
	  //创建子弹链表               完成
	  //删除                      完成
	  //将子弹放到背景上           完成
	  //子弹动起来                 完成
	  //子弹撞边消失               完成
	  //子弹坦克重合bug            解决
//7、敌方坦克自动发子弹
//8、设置自己的boss
//9、设置障碍物
//10、子弹碰撞   死亡判断 
//11、完全不闪的
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define BACK_WIDE   22
#define BACK_HIGHT  22

//方向枚举
enum { enum_east, enum_south, enum_west, enum_north };

//显示提示界面
void StartIU();
//按任意键开始游戏
void StartGame();
//按任意键开始游戏
void ClearIU();

//显示边框
void ShowBackGroud();
//控制坦克方向
void ControlDis();
//将已方坦克新的位置设置在背景上
void SetOurNewPos();
//设置记住新的位置
void RememOurOldPos();
//清空旧的坐标位置
void ClearOurOldPos();
//敌方的坦克自动动起来
void DiTankeRun();
//敌方坦克坐标变化
void SetDiNewPos();
//敌方坦克坐标设置道背景上
void SetDiNewPosToBack();
//清空敌方坦克原来的位置
void ClearDiOldPos();
//记住敌方坦克新的坐标
void RemeDiNewPos();
//创建子弹链表
void CreateDanList(struct Node* *pHead, struct Node* *pEnd, int x, int y, int dis);
//清空链表
void ClearList(struct Node* *pHead, struct Node* *pEnd);
//将子弹放到背景上
void SetDanToBack(struct Node *pHead);
//子弹动起来
void DanRun();
//子弹坐标变化
void DanPosChange(struct Node *pHead);
//子弹旧的位置清空
void ClearDanOldPos(struct Node *pHead);
//删除死亡节点
struct Node* ClearOutDan(struct Node* *pHead, struct Node* *pEnd, struct Node *pTemp);
