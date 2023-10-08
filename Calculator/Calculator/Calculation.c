#define _CRT_SECURE_NO_WARNINGS 1
#include "Calculation.h"

//加
void MyPlus(char* p,int* n,int len,int i)
{
	int* n1 = n - 1;
	int* n2 = n + 1;
	*n1 = *n1 + *n2;
	int i2 = i;
	for (i; i < len - 2; i++)
	{
		*p = *(p + 2);
		p++;
	}
	*p = 0;
	*(p + 1) = 0;
	for (i2; i2 < len - 2; i2++)
	{
		*n = *(n + 2);
		n++;
	}
	*n = 0;
	*(n + 1) = 0;
}

//减
void MySub(char* p, int* n, int len, int i)
{
	int* n1 = n - 1;
	int* n2 = n + 1;
	*n1 = *n1 - *n2;
	int i2 = i;
	for (i; i < len - 2; i++)
	{
		*p = *(p + 2);
		p++;
	}
	*p = 0;
	*(p + 1) = 0;
	for (i2; i2 < len - 2; i2++)
	{
		*n = *(n + 2);
		n++;
	}
	*n = 0;
	*(n + 1) = 0;
}

//乘
void MyMul(char* p, int* n, int len, int i)
{
	int* n1 = n - 1;
	int* n2 = n + 1;
	*n1 = (*n1) * (*n2);
	int i2 = i;
	for (i; i < len - 2; i++)
	{
		*p = *(p + 2);
		p++;
	}
	*p = 0;
	*(p + 1) = 0;
	for (i2; i2 < len - 2; i2++)
	{
		*n = *(n + 2);
		n++;
	}
	*n = 0;
	*(n + 1) = 0;
}

//除
int MyDiv(char* p, int* n, int len, int i)
{
	int* n1 = n - 1;
	int* n2 = n + 1;
	if (*n2 == 0)
	{
		printf("err\n\n");
		return 0;
	}
	*n1 = (*n1) / (*n2);
	int i2 = i;
	for (i; i < len - 2; i++)
	{
		*p = *(p + 2);
		p++;
	}
	*p = 0;
	*(p + 1) = 0;
	for (i2; i2 < len - 2; i2++)
	{
		*n = *(n + 2);
		n++;
	}
	*n = 0;
	*(n + 1) = 0;

	return 1;
}

//括号
int MyPare(char* p, int* n, int len,int i)
{
	char* p1 = p+1;
	char* p2 = p+1;
	int* n1 = n+1;
	int* n2 = n+1;
	int Parei = i;
	int newi = 0;
	char Pare[1000] = { 0 };
	int Parenum[1000] = { 0 };
	while (*p2 != ')')
	{
		Pare[newi] = *p2;
		Parenum[newi] = *n2;
		p2++;
		n2++;
		Parei++;
		newi++;
		if (Parei == len)
		{
			printf("err\n\n");
			return 0;
		}
	}
	if (Parei -len==1)
	{
		printf("err\n\n");
		return 0;
	}
	Parei--;
	int Parelen = Parei - i +1;
	newi = 0; 
	int startlen = Parelen;
	for (newi = 0; newi < Parelen; newi++)
	{
		if (Pare[newi] == '(')
		{
			MyPare(&Pare[newi], &Parenum[newi], Parelen, newi);//括号内运算
		}
	}
	for (newi = 0; newi < Parelen+1; newi++)
	{
		if (Pare[newi] == '*')
		{
			MyMul(&Pare[newi], &Parenum[newi], Parelen, newi);//执行乘法
			newi--;
			Parelen = Parelen - 2;
		}
	}
	int leg = 1;
	for (newi = 0; newi < Parelen+1; newi++)
	{
		if (Pare[newi] == '/')
		{
			leg = MyDiv(&Pare[newi], &Parenum[newi], Parelen, newi);//执行除法
			newi--;
			Parelen = Parelen - 2;
		}
	}
	if (leg == 0)
	{
		return 0;
	}
	for (newi = 0; newi < Parelen; newi++)
	{
		if (Pare[newi] == '+')
		{
			MyPlus(&Pare[newi], &Parenum[newi], Parelen, newi);//执行加法
			newi--;
			Parelen = Parelen - 2;
		}
	}
	for (newi = 0; newi < Parelen; newi++)
	{
		if (Pare[newi] == '-')
		{
			MySub(&Pare[newi], &Parenum[newi], Parelen, newi);//执行减法
			newi--;
			Parelen = Parelen - 2;
		}
	}
	int starti = i;
	int i2 = i;
	for (i; i < len - (starti + startlen + 2); i++)
	{
		*p1 = *(p1 + (startlen + 1));
		p1++;
	}
	for (int i3 = 0; i3 < (startlen + 1); i3++)
	{
		*(p1 + i3) = 0;
	}
	for (i2; i2 < len - (starti + startlen + 2); i2++)
	{
		*n1 = *(n1 + (startlen + 1));
		n1++;
	}
	for (int i3 = 0; i3 < (startlen + 1); i3++)
	{
		*(n1 + i3) = 0;
	}
	*p = Pare[0];
	*n = Parenum[0];
	return 1;
}