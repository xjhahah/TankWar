#include "Tank.hpp"


int main(void)
{
	//显示提示界面
	StartIU();
	//按任意键开始游戏
	StartGame();
	//按任意键开始游戏
	ClearIU();
	//显示边框
	ShowBackGroud();

	while (1)
	{
		//方向改变坐标
		TanKeRun();
		//设置位置
		TankePosUpdateBack();

		//清空控制台
		ClearIU();
		//显示边框
		ShowBackGroud();
	}

	system("pause");
	return 0;
}