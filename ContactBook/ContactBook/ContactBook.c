#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ContactBook.h"



//��ʼ������
struct ContactBook* Initialize()
{
	struct ContactBook* header = malloc(sizeof(struct ContactBook));
	header->data;
	header->next = NULL;
	return header;
}

//����д���ļ�
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
			//���ض���ʽ������д���ļ�
			pCurrent = pCurrent->next;
		} while (pCurrent != NULL);
		return;
	}
	fclose(p_File);
}

//��ȡ�ļ����ݵ�����
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
		if (ch == EOF)//����ļ�����
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
//������ϵ��
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
	printf("����������:>");
	scanf("%s", new->data.name);
	printf("������绰:>");
	scanf("%s", new->data.tele);
	printf("�������ϵ:>");
	scanf("%s", new->data.relat);
	pLast->next = new;
	new->next = NULL;
	printf("��ӳɹ�\n\n");
}

//ɾ����ϵ��
void DelInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("������Ҫɾ������ϵ��:>");
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
		printf("�����ڸ���ϵ��\n\n");
		return;
	}
	pPrev->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	printf("ɾ���ɹ�\n\n");
}

//�޸���ϵ����Ϣ
void RedatInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ��:>");
	scanf("%s", person);
	struct ContactBook* pCurrent = header;
	while (pCurrent != NULL)
	{
		if (strcmp(person, pCurrent->data.name) == 0)
		{
			int choose = 0;
			printf("%-10s %-12s %-10s\n", "����", "�绰", "��ϵ");
			printf("%-10s %-12s %-10s\n", pCurrent->data.name, pCurrent->data.tele, pCurrent->data.relat);
			printf("1.����\t2.�绰\t3.��ϵ\t4.ȫ��\n");
			printf("��ѡ��Ҫ���ĵ���Ϣ:>");
			scanf("%d", &choose);
			switch (choose)
			{
			case 1:
				printf("�������µ�����:>");
				scanf("%s", pCurrent->data.name);
				printf("�޸ĳɹ�\n\n");
				break;
			case 2:				
				printf("�������µĵ绰:>");
				scanf("%s", pCurrent->data.tele);
				printf("�޸ĳɹ�\n\n");
				break;
			case 3:
				printf("�������µĹ�ϵ:>");
				scanf("%s", pCurrent->data.relat);
				printf("�޸ĳɹ�\n\n"); 
				break;
			case 4:
				printf("�������µ�����:>");
				scanf("%s", pCurrent->data.name);
				printf("�������µĵ绰:>");
				scanf("%s", pCurrent->data.tele);
				printf("�������µĹ�ϵ:>");
				scanf("%s", pCurrent->data.relat);
				printf("�޸ĳɹ�\n\n");
				break;
			default:
				printf("ѡ�����\n\n");
				break;
			}
			break;
		}
		pCurrent = pCurrent->next;

	}
	if (pCurrent == NULL)
	{
		printf("�����ڸ���ϵ��\n\n");
	}
}

//������ϵ��
void SearchInfo(struct ContactBook* header)
{
	char person[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ��:>");
	scanf("%s", person);
	struct ContactBook* pCurrent = header;
	while (pCurrent != NULL)
	{
		if (strcmp(person, pCurrent->data.name) == 0)
		{
			printf("%-10s %-12s %-10s\n", "����", "�绰", "��ϵ");
			printf("%-10s %-12s %-10s\n\n", pCurrent->data.name, pCurrent->data.tele, pCurrent->data.relat);
			break;
		}
		pCurrent = pCurrent->next;

	}
	if (pCurrent == NULL)
	{
		printf("�����ڸ���ϵ��\n\n");
	}
}

//��ӡ������ϵ��
void Print(struct ContactBook* header)
{
	struct ContactBook* pCurrent = header;
	printf("%-10s %-12s %-10s\n", "����", "�绰", "��ϵ");
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
	printf("(��)\n\n");

}
