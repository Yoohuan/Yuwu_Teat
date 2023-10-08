#pragma once
#define MAX_NAME 10
#define MAX_TELE 12
#define MAX_RELAT 10

//联系人信息
typedef struct Infomation
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char relat[MAX_RELAT];
}Info;

//链表节点
struct ContactBook
{
	Info data;
	struct ContacBook* next;

};

//初始化链表
struct ContactBook* Initialize();


//链表写入文件
void SaveInfo(struct ContactBook* header);

//读取文件数据到链表
void ReadInfo(struct ContactBook* header);

//增加联系人
void AddInfo(struct ContactBook* header);


//删除联系人
void DelInfo(struct ContactBook* header);


//修改联系人信息
void RedatInfo(struct ContactBook* header);


//查找联系人
void SearchInfo(struct ContactBook* header);


//打印所有联系人
void Print(struct ContactBook* header);
