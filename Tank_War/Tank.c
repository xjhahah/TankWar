#include "Tank.hpp"


//��¼̹������
void RemberTankePos()
{
	g_ucOuerTankePosTempX = g_ucOuerTankePosX;
	g_ucOuerTankePosTempY = g_ucOuerTankePosY;
}
//���̹�˾ɵ�λ��
void ClearTankeOldPos()
{
	g_arrBackGround[g_ucOuerTankePosTempY][g_ucOuerTankePosTempX] = 0;
}

//���µ�̹��λ�����õ�����
void TankePosUpdateBack()
{
	g_arrBackGround[g_ucOuerTankePosY][g_ucOuerTankePosX] = 2;
	//���̹�˾ɵ�λ��
	ClearTankeOldPos();
	//��¼̹������
	RemberTankePos();
}

//�ѷ�̹�˶�����
void TanKeRun()
{
	char cKetDis = _getch();
	if ('w' == cKetDis || 'W' == cKetDis)  //��
	{
		g_ucOuerTankePosY--;
	}
	if ('a' == cKetDis || 'A' == cKetDis)  //��
	{
		g_ucOuerTankePosX--;
	}
	if ('s' == cKetDis || 'S' == cKetDis)  //��
	{
		g_ucOuerTankePosY++;
	}
	if ('d' == cKetDis || 'D' == cKetDis)  //��
	{
		g_ucOuerTankePosX++;
	}
}

//��ʾ�߿�
void ShowBackGroud()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < BACK_HIGHT; i++)
	{
		for (j = 0; j < BACK_WIDE; j++)
		{
			switch (g_arrBackGround[i][j])
			{
			case 0: //�ո�
				printf("  ");
				break;
			case 1: //�߿�
				printf("��");
				break;
			case 2:  //����̹��
				printf("��");
				break;
			case 3:  //�з�̹��
				printf("��");
				break;
			case 4: // �ҷ�boss 
				printf("��");
				break;
			}
		}

		//����
		printf("\n");
	}
}



//���������ʼ��Ϸ
void ClearIU()
{
	system("cls");
}

//���������ʼ��Ϸ
void StartGame()
{
	_getch(); //��������ȡ
}

//��ʾ��ʾ����
void StartIU()
{
	printf("\n\n\n\t\t\t  �� ��ӭ����̹�˴�ս ��\n\n");
	printf("\t\t\t�� W S A D ����̹���н� ��\n\n");
	printf("\t\t\t    �� �ո����ӵ� ��\n\n");
	printf("\t\t\t  �� ���������ʼ��Ϸ ��\n\n");
}