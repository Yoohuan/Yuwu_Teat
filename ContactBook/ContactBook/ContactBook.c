#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ContactBook.h"



//初始化链表
struct ContactBook* Initialize()
{
	struct ContactBook* header = malloc(sizeof(struct ContactBook));
	header->data;
	header->next = NULL;
	return header;
}

//链表写入文件
void SaveInfo(struct ContactBook* header)
{
	struct ContactBook* pCurrent = header;
	FILE* p_File;
	p_File = fopen("Data.dat", "w");
	if (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
		do
		{
			fprintf(p_File,"%-10s %-12s %-10s\n", pCurrent->data.name, pCurrent->data.tele, pCurrent->data.relat);
			//按特定格式把数据写入文件
			pCurrent = pCurrent->next;
		} while (pCurrent != NULL);
		return;
	}
	fclose(p_File);
}

//读取文件数据到链表
void ReadInfo(struct ContactBook* header)
{
	struct ContactBook* pCurrent = header;
	FILE* p_File;
	p_File = fopen("Data.dat", "r");
	if (p_File == NULL)
	{
		return;
	}
	while (1)
	{
		char ch = fgetc(p_File);
		if (ch == EOF)//检测文件内容
			break;
		fseek(p_File, -1, SEEK_CUR);
		char ch1[10] = { 0 };
		fgets(ch1,10,p_File);
		fseek(p_File, 2, SEEK_CUR);
		char ch2[12] = { 0 };
		fgets(ch2, 12, p_File);
		fseek(p_File, 2, SEEK_CUR);
		char ch3[10] = { 0 };
		fgets(ch3, 10, p_File);
		fseek(p_File, 3, SEEK_CUR);

		struct ContactBook* pLast = header;
		while (1)
		{
			
			if (pLast->next != NULL)
			{
				pLast = pLast->next;
			}
			else
			{
				break;
			}
		}
		struct ContactBook* new = malloc(sizeof(struct ContactBook));
		strcpy(new->data.name, ch1);
		strcpy(new->data.tele, ch2);
		strcpy(new->data.relat, ch3);
		pLast->next = new;
		new->next = NULL;
	}
	fclose(p_File);
}
//增加联系人
void AddInfo(struct ContactBook* header)
{
	struct ContactBook* pLast = header;
	while (1)
	{
		if (pLast->next != NULL)
		{
			pLast = pLast->next;
		}
		else
		{
			break;
		}
	}
	struct ContactBook* new = malloc(sizeof(struct ContactBook));
	strcpy(new->data.name, "\0");
	strcpy(new->data.tele, "\0");
	strcpy(new->data.relat, "\0");
	printf("请输入姓名:>");
	scanf("%s", new->data.name);
	printf("请输入电话:>");
	scanf("%s", new->data.tele);
	printf("请输入关系:>");
	scanf("%s", new->data.relat);
	pLast->next = new;
	new->next = NULL;
	printf("添加成功\n\n");
}

//删除联系人
void DelInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("请输入要删除的联系人:>");
	scanf("%s", person);
	struct ContactBook* pPrev = header;
	struct ContactBook* pCurrent = pPrev->next;
	while (pCurrent != NULL)
	{
		if (strcmp(person, pCurrent->data.name) == 0)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;

	}
	if (pCurrent == NULL)
	{
		printf("不存在该联系人\n\n");
		return;
	}
	pPrev->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	printf("删除成功\n\n");
}

//修改联系人信息
void RedatInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("请输入要修改的联系人:>");
	scanf("%s", person);
	struct ContactBook* pCurrent = header;
	while (pCurrent != NULL)
	{
		if (strcmp(person, pCurrent->data.name) == 0)
		{
			int choose = 0;
			printf("%-10s %-12s %-10s\n", "姓名", "电话", "关系");
			printf("%-10s %-12s %-10s\n", pCurrent->data.name, pCurrent->data.tele, pCurrent->data.relat);
			printf("1.姓名\t2.电话\t3.关系\t4.全部\n");
			printf("请选择要更改的信息:>");
			scanf("%d", &choose);
			switch (choose)
			{
			case 1:
				printf("请输入新的姓名:>");
				scanf("%s", pCurrent->data.name);
				printf("修改成功\n\n");
				break;
			case 2:				
				printf("请输入新的电话:>");
				scanf("%s", pCurrent->data.tele);
				printf("修改成功\n\n");
				break;
			case 3:
				printf("请输入新的关系:>");
				scanf("%s", pCurrent->data.relat);
				printf("修改成功\n\n"); 
				break;
			case 4:
				printf("请输入新的姓名:>");
				scanf("%s", pCurrent->data.name);
				printf("请输入新的电话:>");
				scanf("%s", pCurrent->data.tele);
				printf("请输入新的关系:>");
				scanf("%s", pCurrent->data.relat);
				printf("修改成功\n\n");
				break;
			default:
				printf("选择错误\n\n");
				break;
			}
			break;
		}
		pCurrent = pCurrent->next;

	}
	if (pCurrent == NULL)
	{
		printf("不存在该联系人\n\n");
	}
}

//查找联系人
void SearchInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("请输入要查找的联系人:>");
	scanf("%s", person);
	struct ContactBook* pCurrent = header;
	while (pCurrent != NULL)
	{
		if (strcmp(person, pCurrent->data.name) == 0)
		{
			printf("%-10s %-12s %-10s\n", "姓名", "电话", "关系");
			printf("%-10s %-12s %-10s\n\n", pCurrent->data.name, pCurrent->data.tele, pCurrent->data.relat);
			break;
		}
		pCurrent = pCurrent->next;

	}
	if (pCurrent == NULL)
	{
		printf("不存在该联系人\n\n");
	}
}

//打印所有联系人
void Print(struct ContactBook* header)
{
	struct ContactBook* pCurrent = header;
	printf("%-10s %-12s %-10s\n", "姓名", "电话", "关系");
	if (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
		do
		{
			printf("%-10s %-12s %-10s\n", pCurrent->data.name,pCurrent->data.tele, pCurrent->data.relat);
			pCurrent = pCurrent->next;
		} while (pCurrent != NULL);
		printf("\n");
		return;
	}
	printf("(空)\n\n");

}
