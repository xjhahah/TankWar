#include "Tank.h"


//显示提示界面
void StartIU()
{
	printf("\n\n\n\t\t\t  《 欢迎来到坦克大战 》\n\n");
	printf("\t\t\t《 W S A D 控制坦克行进 》\n\n");
	printf("\t\t\t    《 空格发射子弹 》\n\n");
	printf("\t\t\t  《 按任意键开始游戏 》\n\n");
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
			case 0: //空格
				///printf("  ");
				strcat(strBackTemp, "  ");
				break;
			case 1: //边框
				//printf("■");
				strcat(strBackTemp, "■");
				break;
			case 2:  //己方坦克
				//printf("★");
				strcat(strBackTemp, "★");
				break;
			case 3:  //敌方坦克
				//printf("☆");
				strcat(strBackTemp, "☆");
				break;
			case 4: // 乙方boss      
				//printf("◆");
				strcat(strBackTemp, "◆");
				break;
			case 5: // 乙方boss      
				//printf("◆");
				strcat(strBackTemp, "●");
				break;
			}
		}
		//换行
		//printf("\n");
		strcat(strBackTemp, "\n");
	}

	printf("%s", strBackTemp);
}


int main()
{
	srand((unsigned int)time(NULL));
	//显示提示界面
	StartIU();
	//按任意键开始游戏
	StartGame();
	//按任意键开始游戏
	ClearIU();

	//显示边框
	ShowBackGroud();

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