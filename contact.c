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
	printf("������Ҫɾ����ϵ�˵����֣�\n");
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