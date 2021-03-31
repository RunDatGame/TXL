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
static int Find(struct Contact* ps, char name[MAX_NAME])
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
	printf("请输入要删除联系人的名字:\n");
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

	void SearchContact(struct Contact* ps)
	{
		char name[MAX_NAME];
		printf("请输入你要查找联系人的名字：\n");
		scanf("%s", name);
		int pos = Find(ps, name);
		if (pos == -1)
		{
			printf("没有你要删的这个人哦！\n");
		}
		else
		{
			printf("%-8s\t%-8s\t%-8s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-8s\t%-8d\t%-8s\t%-12s\t%-20s\n", ps->data[pos].name
				, ps->data[pos].age
				, ps->data[pos].sex
				, ps->data[pos].tele
				, ps->data[pos].addr);
		}
	}

	void ModifyContact(struct Contact* ps)
	{
		char name[MAX_NAME];
		printf("请输入你要更改联系人的名字：");
		scanf("%s",name);
		int pos = Find(ps,name);
		if (pos == -1)
			printf("没有你要找的这个人哦！\n");
		else
		{
			printf("请输入名字:>");
			scanf("%s",ps->data[pos].name);
			printf("请输入年龄:>");
			scanf("%d",&(ps->data[pos].age));
			printf("请输入性别:>");
			scanf("%s",ps->data[pos].sex);
			printf("请输入电话:>");
			scanf("%s",ps->data[pos].tele);
			printf("请输入地址:>");
			scanf("%s",ps->data[pos].addr);

		}
	}

	void ShowContact(struct Contact* ps)
	{
		printf("%-8s\t%-8s\t%-8s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (int i = 0; i < ps->size; i++)
		{
			printf("%-8s\t%-8d\t%-8s\t%-12s\t%-20s\n", ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}

	void SortContact(struct Contact* ps)
	{
		if (ps->size == 0)
		{
			printf("通讯录为空！");
		}
		else
		{
			int i, j;
			for (i = 0; i < ps->size; i++)
			{
				for (j = 0; j < ps->size - i; j++);
				{
					if(strcmp(ps->data[j].name,ps->data[j+1].name)>0)
					{ 
						printf("1");
						struct PeoInfo str = ps->data[j];
						ps->data[j] = ps->data[j + 1];
						ps->data[j + 1] = str;
					}
				}
			}
			printf("恭喜你，排序完成！");
		}
	}
	