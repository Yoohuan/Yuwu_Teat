#define _CRT_SECURE_NO_WARNINGS 1

#include "Calculation.h"

int main()
{
	printf("该程序仅能进行0-9的整数运算\n");
	printf("可以使用 () 注意为英文括号\n");

	while (1)
	{
		char input[1000] = { 0 };
		int len = 0;
		int num[1000] = { 0 };
		printf("请输入计算式(输入 exit 退出程序):>");
		scanf("%s", input);
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		len = strlen(input);
		int leg = 1;

		for (int i = 0; i < len; i++)//识别数字并转化为整型
		{
			if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '(' && input[i] != ')' && input[i] != '=')
			{
				num[i] = input[i] - '0';
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (input[i] == '(')
			{
				leg=MyPare(&input[i], &num[i],len, i);//括号内运算

			}
		}
		if (leg == 0)
		{
			continue;
		}
		for (int i = 0; i < len; i++)
		{
			if (input[i] == '*')
			{
				MyMul(&input[i], &num[i], len, i);//执行乘法
				i--;
				len = len - 2;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (input[i] == '/')
			{
				leg=MyDiv(&input[i], &num[i], len, i);//执行除法
				i--;
				len = len - 2;
			}
		}
		if (leg == 0)
		{
			continue;
		}
		for (int i = 0; i < len; i++)
		{
			if (input[i] == '+')
			{
				MyPlus(&input[i],&num[i], len, i);//执行加法
				i--;
				len = len - 2;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (input[i] == '-')
			{
				MySub(&input[i], &num[i], len, i);//执行减法
				i--;
				len = len - 2;
			}
		}
		printf("%d\n\n", num[0]);
	}
	return 0;
}