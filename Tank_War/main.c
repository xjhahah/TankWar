#include "Tank.hpp"


int main(void)
{
	//��ʾ��ʾ����
	StartIU();
	//���������ʼ��Ϸ
	StartGame();
	//���������ʼ��Ϸ
	ClearIU();
	//��ʾ�߿�
	ShowBackGroud();

	while (1)
	{
		//����ı�����
		TanKeRun();
		//����λ��
		TankePosUpdateBack();

		//��տ���̨
		ClearIU();
		//��ʾ�߿�
		ShowBackGroud();
	}

	system("pause");
	return 0;
}