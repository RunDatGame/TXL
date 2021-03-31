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
    //创建通讯录
    //初始化通讯录 
    InitContact(&con);
    //
    do
    {
        menu();
        printf("请选择:>");
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
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);
    return 0;
}