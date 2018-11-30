#include "Tank.h"


//�ӵ�������
void DanRun()
{
	//���ɵ�λ�����
	ClearDanOldPos(g_pOurHead);
	//�ӵ�����ı�
	DanPosChange(g_pOurHead);
	//���ӵ������ٱ���
	SetDanToBack(g_pOurHead);
}
//�ӵ��ɵ�λ�����
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

//ɾ�������ڵ�
struct Node* ClearOutDan(struct Node* *pHead, struct Node* *pEnd, struct Node *pTemp)
{
	struct Node* pT = pTemp->m_pNext;

	//ֻ��һ���ڵ�
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
			//�ҵ������ڶ����ڵ�
			struct Node *p = *pHead;
			while (p->m_pNext != *pEnd)
				p = p->m_pNext;
			//�ͷ�β�ڵ�
			free(*pEnd);
			//β�ڵ� Ϊ �µ�β��
			*pEnd = p;
			//β�ڵ����һ����ֵNULL
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

//�ӵ�����仯
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
				//ɾ���ڵ�
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_north:
			pTemp->m_nY--;
			if (0 == pTemp->m_nY)
			{
				//ɾ���ڵ�
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_south:
			pTemp->m_nY++;
			if (21 == pTemp->m_nY)
			{
				//ɾ���ڵ�
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		case enum_west:
			pTemp->m_nX--;
			if (0 == pTemp->m_nX)
			{
				//ɾ���ڵ�
				pTemp = ClearOutDan(&g_pOurHead, &g_pOurEnd, pTemp);
				continue;
			}
			break;
		}
		pTemp = pTemp->m_pNext;
	}
}

//���ӵ��ŵ�������
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

//�������
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
//�����ӵ�����
void CreateDanList(struct Node* *pHead, struct Node* *pEnd, int x, int y, int dis)
{
	//�����ڵ�
	struct Node *pTemp = (struct Node *)malloc(sizeof(struct Node));

	//�ڵ��Ա��ֵ
	pTemp->m_nX = x;
	pTemp->m_nY = y;
	pTemp->m_nDis = dis;
	pTemp->m_pNext = NULL;

	//�ڵ��������
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

//�з�̹������仯
void SetDiNewPos()
{
	//
	int nDis = rand() % 4;
	//����仯�з�̹��1
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
	//����仯�з�̹��1
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
//�з�̹���������õ�������
void SetDiNewPosToBack()
{
	g_arrBackGround[g_2DiPosY][g_2DiPosX] = 3;
	g_arrBackGround[g_1DiPosY][g_1DiPosX] = 3;
}
//�з���̹���Զ�������
void DiTankeRun()
{
	//�����µ�λ��
	SetDiNewPos();
	//���ĵ�̹�˵�λ�����õ�������
	SetDiNewPosToBack();
	//���ԭ��λ��
	ClearDiOldPos();
	//�����ĵ�̹��λ��
	RemeDiNewPos();
}

//��յз�̹��ԭ����λ��
void ClearDiOldPos()
{
	g_arrBackGround[g_1DiPosTempY][g_1DiPosTempX] = 0;
	g_arrBackGround[g_2DiPosTempY][g_2DiPosTempX] = 0;
}
//��ס�з�̹���µ�����
void RemeDiNewPos()
{
	g_1DiPosTempY = g_1DiPosY;
	g_1DiPosTempX = g_1DiPosX;

	g_2DiPosTempY = g_2DiPosY;
	g_2DiPosTempX = g_2DiPosX;
}

//��վɵ�����λ��
void ClearOurOldPos()
{
	g_arrBackGround[g_OurPosTempY][g_OurPosTempX] = 0;
}
//���ü�ס
void RememOurOldPos()
{
	g_OurPosTempY = g_OurPosY;
	g_OurPosTempX = g_OurPosX;
}
//���ѷ�̹���µ�λ�������ڱ�����
void SetOurNewPos()
{
	g_arrBackGround[g_OurPosY][g_OurPosX] = 2;
	//��վɵ�λ��
	ClearOurOldPos();
	//��ס�µ�����
	RememOurOldPos();
}
//����̹�˷���
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

	//�ж� ��û�� �����
	if (g_OurPosTempX != g_OurPosX || g_OurPosTempY != g_OurPosY)
	{
		//����
		SetOurNewPos();
	}
}

//��ʾ�߿�
//void ShowBackGroud1()
//{
//	int i = 0;
//	int j = 0;
//
//	char strBackTemp[1024] = { 0 };
//
//	//COORD rd = { g_OurPosX, g_OurPosY };
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
//	//printf("��");
//
//}
