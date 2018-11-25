#include "Tank.hpp"


//记录坦克坐标
void RemberTankePos()
{
	g_ucOuerTankePosTempX = g_ucOuerTankePosX;
	g_ucOuerTankePosTempY = g_ucOuerTankePosY;
}
//清空坦克旧的位置
void ClearTankeOldPos()
{
	g_arrBackGround[g_ucOuerTankePosTempY][g_ucOuerTankePosTempX] = 0;
}

//将新的坦克位置设置到背景
void TankePosUpdateBack()
{
	g_arrBackGround[g_ucOuerTankePosY][g_ucOuerTankePosX] = 2;
	//清空坦克旧的位置
	ClearTankeOldPos();
	//记录坦克坐标
	RemberTankePos();
}

//已方坦克动起来
void TanKeRun()
{
	char cKetDis = _getch();
	if ('w' == cKetDis || 'W' == cKetDis)  //上
	{
		g_ucOuerTankePosY--;
	}
	if ('a' == cKetDis || 'A' == cKetDis)  //左
	{
		g_ucOuerTankePosX--;
	}
	if ('s' == cKetDis || 'S' == cKetDis)  //下
	{
		g_ucOuerTankePosY++;
	}
	if ('d' == cKetDis || 'D' == cKetDis)  //右
	{
		g_ucOuerTankePosX++;
	}
}

//显示边框
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
			case 0: //空格
				printf("  ");
				break;
			case 1: //边框
				printf("■");
				break;
			case 2:  //己方坦克
				printf("★");
				break;
			case 3:  //敌方坦克
				printf("☆");
				break;
			case 4: // 乙方boss 
				printf("◆");
				break;
			}
		}

		//换行
		printf("\n");
	}
}



//按任意键开始游戏
void ClearIU()
{
	system("cls");
}

//按任意键开始游戏
void StartGame()
{
	_getch(); //不阻塞读取
}

//显示提示界面
void StartIU()
{
	printf("\n\n\n\t\t\t  《 欢迎来到坦克大战 》\n\n");
	printf("\t\t\t《 W S A D 控制坦克行进 》\n\n");
	printf("\t\t\t    《 空格发射子弹 》\n\n");
	printf("\t\t\t  《 按任意键开始游戏 》\n\n");
}