#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
struct node
{
    char data1[max];
    char data2[max];
    char data3[max];
    char data4[max];
    struct node*link;
};
typedef struct node* NODE;
struct node1
{
    char data5[max];
    char data6[max];
    char data7[max];
    char data8[max];
    struct node1*link;
};
typedef struct node1* NODE1;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE1 getnode1()
{
    NODE1 x;
    x=(NODE1)malloc(sizeof(struct node1));
    return x;
}
NODE1 insert(NODE1 first,char d1[max],char d2[max],char d3[max],char d4[max])
{
    NODE1 temp;
    temp=getnode1();
    strcpy(temp->data5,d1);
    strcpy(temp->data6,d2);
    strcpy(temp->data7,d3);
    strcpy(temp->data8,d4);
    temp->link=first;
    return temp;
}
NODE copy(NODE first,char d5[max],char d6[max],char d7[max],char d8[max] )
{
    NODE temp;
    temp=getnode();
    strcpy(temp->data1,d5);
    strcpy(temp->data2,d6);
    strcpy(temp->data3,d7);
    strcpy(temp->data4,d8);
    temp->link=first;
    return temp;
}
NODE delete(NODE first)
{
     NODE temp; 
     if(first==NULL)
     {
        printf("no data to present to delete \n");
        return first;
     }
     temp=first->link;
     printf("Data deleted from system is:\t %s\t%s\t%s\t%s\n",first->data1,first->data2,first->data3,first->data4);
     free(first);
     return temp;
}
NODE1 delete1(NODE1 first)
{
     NODE1 temp; 
     if(first==NULL)
     {
        printf("no data to migrate \n");
        return first;
     }
     temp=first->link;
     printf("Data migrated from database is:\t %s\t%s\t%s\t%s\n",first->data5,first->data6,first->data7,first->data8);
     free(first);
     return temp;
}
void display(NODE first)
{
     NODE temp; 
     if(first==NULL)
     {
        printf("no data to present to delete \n");
     }
     temp=first;
     printf("data in system is:\n");
     while(temp!=NULL)
     {
         printf("%s\t%s\t%s\t%s\t",temp->data1,temp->data2,temp->data3,temp->data4);
         temp=temp->link;
     }
}
int main()
{
    NODE first=NULL;
    NODE1 first1=NULL;
    char d1[max],d2[max],d3[max],d4[max];
    char d5[max],d6[max],d7[max],d8[max];
    int ch;
    for(;;)
    {
        printf("Enter choice: \n 1Enter data in database:\n 2.Migrate data from database to system \n3.Delete data from system\n4.Display migrated data\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter d5,d6,d7,d8 from data base:\n");
            scanf("%s%s%s%s",d5,d6,d7,d8);
            first1=insert(first1,d5,d6,d7,d8);
            break;
            case 2:
            first=copy(first,d5,d6,d7,d8);
            first1=delete1(first1);
            break;
            case 3:
            first=delete(first);
            break;
            case 4:
            display(first);
            break;
            default:
            exit(0);
        }
    }
}
