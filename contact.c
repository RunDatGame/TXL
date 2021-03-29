#include"contact.h"


void InitContact(struct Contact* ps)
{
	memset(ps ->data,0,sizeof(ps->data));
	ps->size = 0;//初始化为0；
}

void AddContact(struct Contact* ps)
{
	if (ps->size >= MAX)
	{
		printf("通讯录已满,您的好友太多啦！\n");
	}
	else
	{
		printf("请输入联系人的名字:>\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入联系人的年龄:>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入联系人的性别:>\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入联系人的电话:>\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入联系人的地址:>\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功！！！");

	}
}
int Find(struct Contact* ps, char name[MAX_NAME])
{
	for (int i = 0; i < ps->size; i++)
	{
		if (0==strcmp(name,ps->data[i].name))
		{
			return i;
		}
	}
	return -1;
}
	void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除联系人的名字！\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("没有你要删的这个人哦！\n");
	}
	else
	{
		for (int j = pos; j < ps->size; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功，你再也联系不到他了！\n");
	}
}