#pragma once
#define MAX_NAME 10
#define MAX_TELE 12
#define MAX_RELAT 10

//��ϵ����Ϣ
typedef struct Infomation
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char relat[MAX_RELAT];
}Info;

//����ڵ�
struct ContactBook
{
	Info data;
	struct ContacBook* next;

};

//��ʼ������
struct ContactBook* Initialize();


//����д���ļ�
void SaveInfo(struct ContactBook* header);

//��ȡ�ļ����ݵ�����
void ReadInfo(struct ContactBook* header);

//������ϵ��
void AddInfo(struct ContactBook* header);


//ɾ����ϵ��
void DelInfo(struct ContactBook* header);


//�޸���ϵ����Ϣ
void RedatInfo(struct ContactBook* header);


//������ϵ��
void SearchInfo(struct ContactBook* header);


//��ӡ������ϵ��
void Print(struct ContactBook* header);
