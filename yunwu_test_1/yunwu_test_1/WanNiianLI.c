#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

/************************************************************/
void menu()//��ʼ�˵�
{
	printf("************************************\n");
	printf("************** 1.��ѯ **************\n");
	printf("************** 0.�˳� **************\n");
	printf("************************************\n");
	printf("��ѡ��:>");
}

/************************************************************/

int MonthDay(int year, int month)//�����·�����
{
	int month_day = 0;
	switch (month)//��������
	{
	case 1:
	{
		month_day = 31;
		break;
	}
	case 2://ע��������ƽ��
	{
		if (judgment_year(year))
		{
			month_day = 29;
		}
		else
		{
			month_day = 28;
		}
		break;
	}
	case 3:
	{
		month_day = 31;
		break;
	}
	case 4:
	{
		month_day = 30;
		break;
	}
	case 5:
	{
		month_day = 31;
		break;
	}
	case 6:
	{
		month_day = 30;
		break;
	}
	case 7:
	{
		month_day = 31;
		break;
	}
	case 8:
	{
		month_day = 31;
		break;
	}
	case 9:
	{
		month_day = 30;
		break;
	}
	case 10:
	{
		month_day = 31;
		break;
	}
	case 11:
	{
		month_day = 30;
		break;
	}
	case 12:
	{
		month_day = 31;
		break;
	}
	}
	return month_day;
}

/************************************************************/

int leg(int year, int month, int day)//��������պϷ���
{
	
	if (year < 1)
	{
		return 0;
	}
	else if (month < 1 || month > 12)
	{
		return 0;
	}
	else if (day < 1 || day > MonthDay(year,month))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/************************************************************/

int judgment_year(int year)//�ж�ƽ����
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/************************************************************/

int FirstDay(int year,int month)//�������һ��Ϊ���ڼ�
{
	int sum_day = 0;
	switch (month)
	{
	case 1:
	{
		sum_day = 1;
		break;
	}
	case 2:
	{
		sum_day = 32;
		break;
	}
	case 3:
	{
		sum_day = 60;
		break;
	}
	case 4:
	{
		sum_day = 91;
		break;
	}
	case 5:
	{
		sum_day = 121;
		break;
	}
	case 6:
	{
		sum_day = 152;
		break;
	}
	case 7:
	{
		sum_day = 182;
		break;
	}
	case 8:
	{
		sum_day = 213;
		break;
	}
	case 9:
	{
		sum_day = 244;
		break;
	}
	case 10:
	{
		sum_day = 274;
		break;
	}
	case 11:
	{
		sum_day = 305;
		break;
	}
	case 12:
	{
		sum_day = 335;
		break;
	}
	}
	if (judgment_year(year) && month > 2)
	{
		sum_day++;
	}//��ʼ��������


	for (int i=year - 1; i >= 1; i--)//�ۼ�֮ǰ�������
	{
		if (judgment_year(i))
		{
			sum_day += 366;
		}
		else
		{
			sum_day += 365;
		}
	}
	return sum_day % 7;
}

/************************************************************/

void Run_printf(int year,int month,int day)//ִ�����������
{
	int xingqi = FirstDay(year, month);
	int x = xingqi;
	int y = 7 - x;
	int z = MonthDay(year,month) - y;
	int d = 1;
	printf("\n");
	printf("--------------------------------\n");
	printf("��   һ   ��   ��   ��   ��   ��\n");
	for (x; x > 0; x--)
	{
		printf("     ");
	}
	for (y; y > 0; y--,d++)
	{
		if (d == day)
		{
			printf("%d*   ", d);
		}
		else
		{
			printf("%d    ", d);
		}

	}
	printf("\n");
	y = 1;
	for (z; z > 0; z--,d++)
	{
		if (y < 7)
		{
			if (d < 10)
			{
				if (d == day)
				{
					printf("%d*   ", d);
				}
				else
				{
					printf("%d    ", d);
				}
			}
			else
			{
				if (d == day)
				{
					printf("%d*  ", d);
				}
				else
				{
					printf("%d   ", d);
				}
			}
			y++;
		}
		else
		{
			if (d == day)
			{
				printf("%d*\n", d);
			}
			else
			{
				printf("%d\n", d);
			}
			y = 1;
		}
	}
	printf("\n");
	printf("--------------------------------\n");
	printf("\n");
}

/************************************************************/

int main()
{
	int ch;
	printf("               ������               \n");
	do
	{
		menu();
		scanf("%d", &ch);
		rewind(stdin);//��ջ�����
		switch (ch)
		{
		case 1:
		{
			int year,month,day;
			printf("�������� �� ��:>");
			scanf("%d %d %d",&year,&month,&day);
			rewind(stdin);//��ջ�����
			if (leg(year, month, day))
			{
				Run_printf(year, month, day);
			}
			else
			{
				printf("��������ڲ��Ϸ����޷���ѯ\n");
				printf("\n");
			}
			break; 
		}
		case 0:
		{
			printf("ллʹ��\n");
			break;
		}
		default:
		{
			printf("ѡ�����������ѡ��\n");
			break;
		}
		}
	} while (ch);//ѡ��0ʱ����ѭ������ʹ��
	Sleep(1000);
	return 0;
}