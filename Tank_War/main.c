#include "Tank.h"


int main()
{
	srand((unsigned int)time(NULL));
	//��ʾ��ʾ����
	//StartIU();
	//���������ʼ��Ϸ
	//StartGame();
	//���������ʼ��Ϸ
	//ClearIU();

	//��ʾ�߿�
	//ShowBackGroud();

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