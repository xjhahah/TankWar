#include "Tank.h"


//��ʾ��ʾ����
void StartIU()
{
	printf("\n\n\n\t\t\t  �� ��ӭ����̹�˴�ս ��\n\n");
	printf("\t\t\t�� W S A D ����̹���н� ��\n\n");
	printf("\t\t\t    �� �ո����ӵ� ��\n\n");
	printf("\t\t\t  �� ���������ʼ��Ϸ ��\n\n");
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
void ShowBackGroud()
{
	int i = 0;
	int j = 0;

	char strBackTemp[1024] = { 0 };

	for (i = 0; i < BACK_HIGHT; i++)
	{
		for (j = 0; j < BACK_WIDE; j++)
		{
			switch (g_arrBackGround[i][j])
			{
			case 0: //�ո�
				///printf("  ");
				strcat(strBackTemp, "  ");
				break;
			case 1: //�߿�
				//printf("��");
				strcat(strBackTemp, "��");
				break;
			case 2:  //����̹��
				//printf("��");
				strcat(strBackTemp, "��");
				break;
			case 3:  //�з�̹��
				//printf("��");
				strcat(strBackTemp, "��");
				break;
			case 4: // �ҷ�boss      
				//printf("��");
				strcat(strBackTemp, "��");
				break;
			case 5: // �ҷ�boss      
				//printf("��");
				strcat(strBackTemp, "��");
				break;
			}
		}
		//����
		//printf("\n");
		strcat(strBackTemp, "\n");
	}

	printf("%s", strBackTemp);
}


int main()
{
	srand((unsigned int)time(NULL));
	//��ʾ��ʾ����
	StartIU();
	//���������ʼ��Ϸ
	StartGame();
	//���������ʼ��Ϸ
	ClearIU();

	//��ʾ�߿�
	ShowBackGroud();

	int sudu = 0;

	while (1)
	{
		if (sudu % 2 == 0)
		{
			//����̹�˷���
			ControlDis();
		}

		if (sudu % 8 == 0)
		{
			//����̹�˶�����
			DiTankeRun();
		}

		//�ӵ�������
		DanRun();

		//�������̨
		ClearIU();
		//��ʾ�µ�λ��
		ShowBackGroud();

		Sleep(70);
		sudu++;
	}
	//�ͷ�����

	system("pause");
	return 0;
}