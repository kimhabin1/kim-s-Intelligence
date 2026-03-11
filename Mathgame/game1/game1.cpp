#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int Life, num, round = 1, ran, count = 0, wm = 0, regame;
	srand((unsigned int)time(NULL));
	ran = rand() % 1000 + 1;
	//printf("%d\n", ran);
	printf("ROUND : %d\n", round);
	printf("숫자 맞추기 게임입니다. 0을 입력하면 종료하며, 1001을 입력하면 힌트가 제공됩니다.\n");
	for (;;) 
	{
		if (round < 4) Life = 20;
		else if (round >= 4 && round < 7) Life = 15;
		else if (round >= 7 && round < 10) Life = 10;
		else Life = 5;
		printf("1부터 1000까지의 숫자 중 하나를 입력하세요. (남은 기회 : %d) ", Life - count);
		scanf("%d", &num);
		count++;
		if (ran == num)
		{
			printf("정답입니다!!");
			Sleep(3000);
			system("cls");
			round++;
			count = 0;
			wm = 0;
			ran = rand() % 1000 + 1;
			//printf("%d\n", ran);
			printf("ROUND : %d\n", round);
		}
		else if (num == 0)
		{
			printf("게임을 종료합니다. ");
			Sleep(2000);
			break;
		}
		else if (num == 1001)
		{
			if (ran % 2 == 1) printf("정답인 수는 나누어떨어지지 않습니다.\n");
			else printf("정답인 수는 나누어떨어집니다.\n");
		}
		else if (ran > num && num < 1002 && num > 0) printf("더 높은 수를 입력하세요!!\n");
		else if (ran < num && num < 1002 && num > 0) printf("더 낮은 수를 입력하세요!!\n");
		else
		{
			printf("입력할 수 있는 값이 아닙니다. 경고가 추가됩니다. \n");
			Sleep(1000);
			wm++;
			printf("경고 : %d회 \n", wm);
			Sleep(1000);
			if (wm == 3)
			{
				printf("경고 3회로 실격 처리되어 게임이 종료됩니다.");
				Sleep(2000);
				break;
			}
		}
		if (Life - count == 0)
		{
				printf("기회를 모두 소진하였습니다!! 정답은 %d입니다!!\n", ran);
				Sleep(2000);
				printf("계속하시려면 1을 종료하려면 아무 숫자나 입력해주세요. ");
				scanf("%d", &regame);
				if (regame == 1) {
					Sleep(2000);
					system("cls");
					count = 0;
					round = 1;
					wm = 0;
					printf("ROUND : %d\n", round);
					ran = rand() % 1000 + 1;
				}
				else 
				{
					printf("게임을 종료합니다. ");
					Sleep(2000);
					break;
				}
		}
	}
	return 0;
}