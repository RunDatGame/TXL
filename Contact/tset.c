#include"contact.h"
void menu()
{
    printf("*********************************************\n");
    printf("***       1.Add                 2.Delete  ***\n");
    printf("***       3.Search              4.Modify  ***\n");
    printf("***       5.Show                6.Sort    ***\n");
    printf("***       0.Exit                          ***\n");
    printf("*********************************************\n");
}
int main()
{
    int input = 0;
    //����ͨѶ¼
    //��ʼ��ͨѶ¼ 
    InitContact(&con);
    //
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf_s("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    } while (input);
    return 0;
}