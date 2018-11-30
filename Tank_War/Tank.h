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

//背景数组
unsigned char g_arrBackGround[BACK_HIGHT][BACK_WIDE] =
{ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 2, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
//己方坦克坐标
unsigned char g_OurPosX = 7;
unsigned char g_OurPosY = 20;

unsigned char g_OurPosTempX = 7;
unsigned char g_OurPosTempY = 20;

//敌人坦克坐标
unsigned char g_1DiPosX = 2;
unsigned char g_1DiPosY = 2;

unsigned char g_1DiPosTempX = 2;
unsigned char g_1DiPosTempY = 2;


unsigned char g_2DiPosX = 19;
unsigned char g_2DiPosY = 2;

unsigned char g_2DiPosTempX = 19;
unsigned char g_2DiPosTempY = 2;

//子弹得节点
struct Node
{
	int m_nX;
	int m_nY;
	int m_nDis;
	struct Node* m_pNext;
};

struct Node *g_pOurHead = NULL;
struct Node *g_pOurEnd = NULL;

int g_nOurDis = 0;

//方向枚举
enum { enum_east, enum_south, enum_west, enum_north };


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
