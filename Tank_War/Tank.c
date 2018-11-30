#include "Tank.h"


//子弹动起来
void DanRun()
{
	//将旧的位置清空
	ClearDanOldPos(g_pOurHead);
	//子弹坐标改变
	DanPosChange(g_pOurHead);
	//将子弹设置再背景
	SetDanToBack(g_pOurHead);
}
//子弹旧的位置清空
void ClearDanOldPos(struct Node *pHead)
{
	struct Node* pTemp = pHead;

	while (pTemp != NULL)
	{
		if (pTemp->m_nY != g_OurPosY || pTemp->m_nX != g_OurPosX)
			g_arrBackGround[pTemp->m_nY][pTemp->m_nX] = 0;
		pTemp = pTemp->m_pNext;
	}
}

//删除死亡节点
struct Node* ClearOutDan(struct Node* *pHead, struct Node* *pEnd, struct Node *pTemp)
{
	struct Node* pT = pTemp->m_pNext;

	//只有一个节点
	if (pTemp == *pEnd && *pEnd == *pHead)
	{
		free(*pHead);
		*pHead = NULL;
		*pEnd = NULL;
	}
	else if (*pEnd == (*pHead)->m_pNext)
	{
		if (pTemp == *pEnd)
		{
			free(*pEnd);
			(*pHead)->m_pNext = NULL;
			*pEnd = *pHead;
		}
		else if (pTemp == *pHead)
		{
			free(*pHead);
			*pHead = *pEnd;
		}
	}
	else
	{
		if (pTemp == *pEnd)
		{
			//找到倒数第二个节点
			struct Node *p = *pHead;
			while (p->m_pNext != *pEnd)
				p = p->m_pNext;
			//释放尾节点
			free(*pEnd);
			//尾节点 为 新的尾巴
			*pEnd = p;
			//尾节点得下一个赋值NULL
			p->m_pNext = NULL;
		}
		else if (pTemp == *pHead)
		{
			struct Node *p = *pHead;
			*pHead = (*pHead)->m_pNext;
			free(p);
		}
		else
		{
			struct Node *p = *pHead;
			while (p != NULL)
			{
				if (pTemp == p->m_pNext)
				{
					struct Node *pp = p->m_pNext;
					p->m_pNext = p->m_pNext->m_pNext;
					free(pp);
				}
				p = p->m_pNext;
			}
		}
	}
	return pT;
}

//子弹坐标变化
void DanPosChange(struct Node *pHead)//532767531
{
	struct Node* pTemp = pHead;

	while (pTemp != NULL)
	{
		switch (pTemp->m_nDis)
		{
		case enum_east:
			pTemp->m_nX++;
			if (21 == pTemp->m_nX)
			{
				//删除节点
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_north:
			pTemp->m_nY--;
			if (0 == pTemp->m_nY)
			{
				//删除节点
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_south:
			pTemp->m_nY++;
			if (21 == pTemp->m_nY)
			{
				//删除节点
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_west:
			pTemp->m_nX--;
			if (0 == pTemp->m_nX)
			{
				//删除节点
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		}
		pTemp = pTemp->m_pNext;
	}
}

//将子弹放到背景上
void SetDanToBack(struct Node *pHead)
{
	struct Node* pTemp = pHead;

	while (pTemp != NULL)
	{
		if (pTemp->m_nY != g_OurPosY || pTemp->m_nX != g_OurPosX)
			g_arrBackGround[pTemp->m_nY][pTemp->m_nX] = 5;
		pTemp = pTemp->m_pNext;
	}
}

//清空链表
void ClearList(struct Node* *pHead, struct Node* *pEnd)
{
	struct Node* pTemp = *pHead;

	while (pTemp != NULL)
	{
		struct Node* pTemp1 = pTemp;
		pTemp = pTemp->m_pNext;
		free(pTemp1);
	}
}
//创建子弹链表
void CreateDanList(struct Node* *pHead, struct Node* *pEnd, int x, int y, int dis)
{
	//创建节点
	struct Node *pTemp = (struct Node *)malloc(sizeof(struct Node));

	//节点成员赋值
	pTemp->m_nX = x;
	pTemp->m_nY = y;
	pTemp->m_nDis = dis;
	pTemp->m_pNext = NULL;

	//节点加入链表
	if (NULL == g_pOurHead)
	{
		(*pHead) = pTemp;
		//g_pOurEnd = pTemp;
	}
	else
	{
		(*pEnd)->m_pNext = pTemp;
		//g_pOurEnd = pTemp;
	}
	(*pEnd) = pTemp;
}

//敌方坦克坐标变化
void SetDiNewPos()
{
	//
	int nDis = rand() % 4;
	//坐标变化敌方坦克1
	switch (nDis)
	{
	case enum_east:
		g_1DiPosX++;
		if (21 == g_1DiPosX)
			g_1DiPosX--;
		break;
	case enum_south:
		g_1DiPosY++;
		if (21 == g_1DiPosY)
			g_1DiPosY--;
		break;
	case enum_west:
		g_1DiPosX--;
		if (0 == g_1DiPosX)
			g_1DiPosX++;
		break;
	case enum_north:
		g_1DiPosY--;
		if (0 == g_1DiPosY)
			g_1DiPosY++;
		break;
	}

	nDis = rand() % 4;
	//坐标变化敌方坦克1
	switch (nDis)
	{
	case enum_east:
		g_2DiPosX++;
		if (21 == g_2DiPosX)
			g_2DiPosX--;
		break;
	case enum_south:
		g_2DiPosY++;
		if (21 == g_2DiPosY)
			g_2DiPosY--;
		break;
	case enum_west:
		g_2DiPosX--;
		if (0 == g_2DiPosX)
			g_2DiPosX++;
		break;
	case enum_north:
		g_2DiPosY--;
		if (0 == g_2DiPosY)
			g_2DiPosY++;
		break;
	}
}
//敌方坦克坐标设置道背景上
void SetDiNewPosToBack()
{
	g_arrBackGround[g_2DiPosY][g_2DiPosX] = 3;
	g_arrBackGround[g_1DiPosY][g_1DiPosX] = 3;
}
//敌方的坦克自动动起来
void DiTankeRun()
{
	//产生新的位置
	SetDiNewPos();
	//将心的坦克的位置设置道背景上
	SetDiNewPosToBack();
	//清空原来位置
	ClearDiOldPos();
	//记忆心得坦克位置
	RemeDiNewPos();
}

//清空敌方坦克原来的位置
void ClearDiOldPos()
{
	g_arrBackGround[g_1DiPosTempY][g_1DiPosTempX] = 0;
	g_arrBackGround[g_2DiPosTempY][g_2DiPosTempX] = 0;
}
//记住敌方坦克新的坐标
void RemeDiNewPos()
{
	g_1DiPosTempY = g_1DiPosY;
	g_1DiPosTempX = g_1DiPosX;

	g_2DiPosTempY = g_2DiPosY;
	g_2DiPosTempX = g_2DiPosX;
}

//清空旧的坐标位置
void ClearOurOldPos()
{
	g_arrBackGround[g_OurPosTempY][g_OurPosTempX] = 0;
}
//设置记住
void RememOurOldPos()
{
	g_OurPosTempY = g_OurPosY;
	g_OurPosTempX = g_OurPosX;
}
//将已方坦克新的位置设置在背景上
void SetOurNewPos()
{
	g_arrBackGround[g_OurPosY][g_OurPosX] = 2;
	//清空旧的位置
	ClearOurOldPos();
	//记住新的坐标
	RememOurOldPos();
}
//控制坦克方向
void ControlDis()
{
	if (GetAsyncKeyState('W') || GetAsyncKeyState('w'))
	{
		g_OurPosY--;
		if (0 == g_OurPosY)
			g_OurPosY++;
		g_nOurDis = enum_north;
	}
	if (GetAsyncKeyState('S') || GetAsyncKeyState('s'))
	{
		g_OurPosY++;
		if (21 == g_OurPosY)
			g_OurPosY--;
		g_nOurDis = enum_south;
	}
	if (GetAsyncKeyState('A') || GetAsyncKeyState('a'))
	{
		g_OurPosX--;
		if (0 == g_OurPosX)
			g_OurPosX++;
		g_nOurDis = enum_west;
	}
	if (GetAsyncKeyState('D') || GetAsyncKeyState('d'))
	{
		g_OurPosX++;
		if (21 == g_OurPosX)
			g_OurPosX--;
		g_nOurDis = enum_east;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		CreateDanList(&g_pOurHead, &g_pOurEnd, g_OurPosX, g_OurPosY, g_nOurDis);
	}

	//判断 按没按 方向键
	if (g_OurPosTempX != g_OurPosX || g_OurPosTempY != g_OurPosY)
	{
		//按了
		SetOurNewPos();
	}
}

//显示边框
//void ShowBackGroud1()
//{
//	int i = 0;
//	int j = 0;
//
//	char strBackTemp[1024] = { 0 };
//
//	//COORD rd = { g_OurPosX, g_OurPosY };
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
//	//printf("★");
//
//}
