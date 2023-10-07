#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "ContactBook.h"

void menu()
{
	printf("***********************************\n");
	printf("*******  1.add     2.del    *******\n");
	printf("*******  3.search  4.redat  *******\n");
	printf("*******  5.print   0.exit   *******\n");
	printf("***********************************\n");
}

enum Choose
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	REDAT,
	PRINT
};

int main()
{
	printf("              ͨѶ¼               \n");
	int input = 0;
	struct ContactBook* header = Initialize();
	ReadInfo(header);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			break;
		case ADD:
			AddInfo(header);
			break;
		case DEL:
			DelInfo(header);
			break;
		case SEARCH:
			SearchInfo(header);
			break;
		case REDAT:
			RedatInfo(header);
			break;
		case PRINT:
			Print(header);
			break;
		default:
			printf("ѡ�����\n\n");
			break;
		}
		
	} while (input);
	SaveInfo(header);
	return 0;
}