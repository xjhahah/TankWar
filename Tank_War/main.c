#include "Tank.h"


int main()
{
	srand((unsigned int)time(NULL));
	//显示提示界面
	//StartIU();
	//按任意键开始游戏
	//StartGame();
	//按任意键开始游戏
	//ClearIU();

	//显示边框
	//ShowBackGroud();

	int sudu = 0;

	while (1)
	{
		if (sudu % 2 == 0)
		{
			//控制坦克方向
			ControlDis();
		}

		if (sudu % 8 == 0)
		{
			//敌人坦克动起来
			DiTankeRun();
		}

		//子弹动起来
		DanRun();

		//清理控制台
		ClearIU();
		//显示新的位置
		ShowBackGroud();

		Sleep(70);
		sudu++;
	}
	//释放链表

	system("pause");
	return 0;
}