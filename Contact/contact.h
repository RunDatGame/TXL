#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>

enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ���
} con;

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);