#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct AddressList
{
char name[25];
long long mobilePhone;
long long telePhone;
char company[40];
char city[25];
struct AddressList *next;
}ADDRESS;
ADDRESS *AddContacts(ADDRESS *head);//增加
ADDRESS *DeleteContacts(ADDRESS *head,ADDRESS *delete_address);//删除
ADDRESS *ReviseContacts(ADDRESS *head,ADDRESS *revise_address);//修改
ADDRESS *SeekContacts(ADDRESS *head,char name[]); //查找找到返回地址，没找到返回空指针,链表为空返回空指针
ADDRESS *SortContacts(ADDRESS *head); //对列链表按name进行排序
void WriteContacts(ADDRESS *head);//将链表中的联系人输出到屏幕上
void WritetoFile(ADDRESS *head); //将链表的存入文件
void DeleteMemory(ADDRESS *head);//当用户输入0,将链表保存到文件中，统一释放链表内存
void FuzzySearch(ADDRESS *head);//模糊查找
int main()
{
    ADDRESS *head = NULL,*delete_address = NULL,*revise_address = NULL,*seek_address = NULL;
    int count = 0,order;
    int ret;
    char Delete_name[25],Revise_name[25],Seek_name[25];
    printf("Hellow!(^_^)Dear little cute！！!You have opened the specialist address book,and you are the specialist person in the world!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("*         [remind]                 *\n");
    printf("* Input         Order              *\n");
    printf("*   1         Add contacts         *\n");
    printf("*   2         Delete contacts      *\n");
    printf("*   3         Revise contacts      *\n");
    printf("*   4         Seek contects        *\n");
    printf("*   5         Sort contacts        *\n");//排完顺序,不将链表保存到文件
    printf("*   6         Show sorted contacts *\n");
    printf("*   7         Fuzzy search         *\n");
    printf("*   0          END                 *\n"); //要想结束运行，必须按0，否则程序一直运行，这样就避免了中途退出程序是造成内存的泄露
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Please input your order number :");
    ret = scanf("%d",&order);
    PD:while(ret != 1)
    {
        while(getchar() != '\n');
        printf("Please input your order number between 0 and 7 :");
        ret = scanf("%d",&order);
    }
    while(order != 0)
    {
        if(order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6)
        {
            printf("Please input your order number between 0 and 7 :");
            ret = scanf("%d",&order);
        }
        if(order == 1) //添加
        {
            head = AddContacts(head);
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        if(order == 2) //删除
        {
            printf("Please input the contact's name to delete :");
            scanf("%s",Delete_name);
            if(SeekContacts(head,Delete_name) != NULL)
            {
                delete_address = SeekContacts(head,Delete_name);
                head = DeleteContacts(head,delete_address);
            }
            printf("Please input your order number :");
            ret = scanf("%d",&order);

        }
        if(order == 3) //修改
        {
            printf("Please input the contact's name to revise :");
            scanf("%s",Revise_name);
            if(SeekContacts(head,Revise_name) != NULL)
            {
                revise_address = SeekContacts(head,Revise_name);
                head = ReviseContacts(head,revise_address);
            }
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        if(order == 4) //查找
        {
            printf("Please input the contact's name to seek :");
            scanf("%s",Seek_name);
            if(SeekContacts(head,Seek_name) != NULL)
            {
                seek_address = SeekContacts(head,Seek_name);
                printf("%s %I64d %I64d %s %s\n",seek_address->name, seek_address->mobilePhone, seek_address->telePhone, seek_address->company, seek_address->city);
            }
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        if(order == 5)//排序
        {
            head = SortContacts(head);
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        if(order == 6)//显示
        {
            head = SortContacts(head);
            WriteContacts(head);
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        if(order == 7)//模糊查找
        {
            FuzzySearch(head);
            printf("Please input your order number :");
            ret = scanf("%d",&order);
        }
        count++;
        if(ret != 1)
        {
            goto PD;
        }
    }
    if(order == 0)
    {
        WritetoFile(head);
        DeleteMemory(head);
        printf("(@_@)*~Thanks for using!!GOOODBYE, little cute!Your address book has been put in to <address_book.txt> !\n");
    }
    return 0;
}

ADDRESS *AddContacts(ADDRESS *head)
//函数功能：增加联系人
//函数参数：链表头指针
//返回值：链表头指针
{
    ADDRESS *p1 = NULL, *pr = head;
    p1 = (ADDRESS *)malloc(sizeof(ADDRESS));
    if(p1 == NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    if(head == NULL)
    {
        head = p1;
    }
    else
    {
        while(pr->next != NULL)
        {
            pr = pr->next;
        }
        pr->next = p1;
    }

        printf("Please input a new contact's name :");
        scanf("%s",p1->name);
        printf("Please input a new contact's mobilePhone :");
        scanf("%I64d",&p1->mobilePhone);
        printf("Please input a new contact's telePhone :");
        scanf("%I64d",&p1->telePhone);
        printf("Please input a new contact's company :");
        scanf("%s",p1->company);
        printf("Please input a new contact's city :");
        scanf("%s",p1->city);
        p1->next = NULL;
        WritetoFile(head);  //此处不能释放动态内存。
        return head;
}
ADDRESS *DeleteContacts(ADDRESS *head,ADDRESS *delete_address)
//函数功能：删除联系人
//函数参数：链表头指针，待删除联系人的地址
//返回值：链表头指针
{
    ADDRESS *p = head, *pr = head;
    while(p != delete_address && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if(p == delete_address)
    {
        if(p == head)
        {
            head = p->next;
        }
        else
        {
            pr->next = p->next;
        }
        free(p);
    }
    return(head);
}
ADDRESS *ReviseContacts(ADDRESS *head,ADDRESS *revise_address)
//函数功能：修改联系人
//函数参数：链表头指针，待修改联系人地址
//返回值：链表头指针
{
    ADDRESS *p = head,*pr = head,*p2 = NULL;
    p2 = (ADDRESS *)malloc(sizeof(ADDRESS));
    if(p2 == NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    while(p != revise_address && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if(p == revise_address)
    {
        if(p == head)
        {
            head = p2;
            p2->next = p->next;
        }
        else if(p->next == NULL)
        {
           pr->next = p2;
           p2->next = NULL;
        }
        else
        {
            pr->next = p2;
            p2->next = p->next;
        }
    }
    printf("Please input the revise name :");
    scanf("%s",p2->name);
    printf("Please input a new contact's mobilePhone :");
    scanf("%I64d",&p2->mobilePhone);
    printf("Please input a new contact's telePhone :");
    scanf("%I64d",&p2->telePhone);
    printf("Please input a new contact's company :");
    scanf("%s",p2->company);
    printf("Please input a new contact's city :");
    scanf("%s",p2->city);
    free(p);
    return(head);
}
ADDRESS *SeekContacts(ADDRESS *head,char name[])
//函数功能：查找联系人
//函数参数：链表头指针，查找的联系人姓名
//返回值：如果查找到，返回该联系人所在节点地址；如果未查找到，返回NULL
{
    ADDRESS *p = head;
    if(head == NULL)
    {
        printf("The address book is empty !\n");
        return(NULL);
    }
    while(strcmp(p->name, name) != 0 && p->next != NULL)
    {
        p = p->next;
    }
    if(strcmp(p->name,name) == 0)
    {
        return(p);
    }
    else
    {
        printf("This contact has not been found !\n");
        return(NULL);
    }
}
void WriteContacts(ADDRESS *head)
//函数功能：输出链表
//函数参数：链表头指针
//返回值：void
{
    ADDRESS *p = NULL;
    int j = 0;
    head = SortContacts(head);
    p = head;
    while(p != NULL)
    {
        printf("%s %I64d %I64d %s %s\n",p->name, p->mobilePhone, p->telePhone, p->company, p->city);
        p = p->next;
        j++;
    }
}
ADDRESS *SortContacts(ADDRESS *head)
//函数功能：排序通讯录
//函数参数：链表头指针
//返回值：链表头指针
{
   int i,j,n = 0;
   ADDRESS *p = head,*temp =NULL,*pr = NULL, *pn = NULL;
   while(p != NULL)
   {
       p = p->next;
       n++;
   }
   temp = (ADDRESS *)malloc(sizeof(ADDRESS));
   if(temp == NULL)
   {
       printf("No enough memory to allocate!\n");
       exit(0);
   }
   temp->next = head;
   head = temp;
   for(i = 1;i < n;i++)
   {
       pr = head;
       p = pr->next;
       pn = p->next;
       for(j = 0;j < n-i;j++)
       {
           if(strcmp(p->name ,pn->name) > 0)
           {
              p->next = pn->next;
              pr->next = pn;
              pn->next = p;
           }
           pr = pr->next;
           pn = p->next;
       }
   }
   head = head->next;
   free(temp);
   return(head);
}
void FuzzySearch(ADDRESS *head)
//函数功能：模糊查找
//函数参数：链表头指针
//返回值：viod
{
    ADDRESS *p = head;
    char string[25];
    printf("Please input a string to fuzzy search :");
    scanf("%s",string);
    if(head == NULL)
    {
        printf("The address book is empty !\n");
        exit(0);
    }
    while(p != NULL)
    {
        if(strstr(p->name,string) != NULL)
        {
            printf("%s %I64d %I64d %s %s\n",p->name, p->mobilePhone, p->telePhone, p->company, p->city);
        }
        p = p->next;
    }
}
void WritetoFile(ADDRESS *head)
//函数功能：存入文件
//函数参数：链表头指针
//返回值：void
{
    FILE *fp;
    ADDRESS *p = head;
    int i = 0;
    if((fp = fopen("address_book.txt","w")) == NULL)
    {
        printf("Failure to open address_book.txt !\n");
        exit(0);
    }
    while(p != NULL)
    {
        fprintf(fp,"%s %I64d %I64d %s %s\n",p->name, p->mobilePhone, p->telePhone, p->company, p->city);
        p = p->next;
        i++;
    }
}
void DeleteMemory(ADDRESS *head)
//函数功能：释放内存
//函数参数：链表头指针
//返回值：viod
{
    ADDRESS *p =head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}



