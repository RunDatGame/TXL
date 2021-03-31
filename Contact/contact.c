#include"contact.h"


void InitContact(struct Contact* ps)
{
	memset(ps ->data,0,sizeof(ps->data));
	ps->size = 0;//��ʼ��Ϊ0��
}

void AddContact(struct Contact* ps)
{
	if (ps->size >= MAX)
	{
		printf("ͨѶ¼����,���ĺ���̫������\n");
	}
	else
	{
		printf("��������ϵ�˵�����:>\n");
		scanf("%s", ps->data[ps->size].name);
		printf("��������ϵ�˵�����:>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("��������ϵ�˵��Ա�:>\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("��������ϵ�˵ĵ绰:>\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("��������ϵ�˵ĵ�ַ:>\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�������");

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
	printf("������Ҫɾ����ϵ�˵�����:\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("û����Ҫɾ�������Ŷ��\n");
	}
	else
	{
		for (int j = pos; j < ps->size; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�������Ҳ��ϵ�������ˣ�\n");
	}
}

	void SearchContact(struct Contact* ps)
	{
		char name[MAX_NAME];
		printf("��������Ҫ������ϵ�˵����֣�\n");
		scanf("%s", name);
		int pos = Find(ps, name);
		if (pos == -1)
		{
			printf("û����Ҫɾ�������Ŷ��\n");
		}
		else
		{
			printf("%-8s\t%-8s\t%-8s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("��������Ҫ������ϵ�˵����֣�");
		scanf("%s",name);
		int pos = Find(ps,name);
		if (pos == -1)
			printf("û����Ҫ�ҵ������Ŷ��\n");
		else
		{
			printf("����������:>");
			scanf("%s",ps->data[pos].name);
			printf("����������:>");
			scanf("%d",&(ps->data[pos].age));
			printf("�������Ա�:>");
			scanf("%s",ps->data[pos].sex);
			printf("������绰:>");
			scanf("%s",ps->data[pos].tele);
			printf("�������ַ:>");
			scanf("%s",ps->data[pos].addr);

		}
	}

	void ShowContact(struct Contact* ps)
	{
		printf("%-8s\t%-8s\t%-8s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
			printf("ͨѶ¼Ϊ�գ�");
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
			printf("��ϲ�㣬������ɣ�");
		}
	}
	