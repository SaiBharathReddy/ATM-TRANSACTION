#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int data1;
    char name;
    struct node * next;
};
int withdraw,deposit;
struct node *head=NULL;
struct node *curNode,*k;
void createlist();
struct node * search();
int main()
{
    int amount,id,access=111,opt,choice,y;
    printf("accounts in a list\n");
       createlist();
       system("cls");
       do
           {
               k=search();
               if(k!=NULL)
               {
                   printf("1.balance enquiry\n2.deposit\n3.withdraw\n4.exit\n");
               printf("enter your choice\n");
               scanf("%d",&opt);
               switch(opt)
               {
                   case 1:printf("amount in your  account\n");
                          printf("%d",k->data1);
                          break;
                case 2:printf("enter amount to deposit\n");
                       scanf("%d",&deposit);
                       k->data1=k->data1+deposit;

                       printf("%d",k->data1);
                       break;
                case 3:printf("enter amount to withdraw\n");
                        scanf("%d",&withdraw);
                        if(withdraw%100!=0)
                        {
                            printf("enter amount in multiples of 100\n");
                        }else if(withdraw>(k->data1-500))
                        {
                            printf("insufficient balance\n");
                        }else{
                            k->data1=k->data1-withdraw;
                            printf("%d",k->data1);
                        }
                        break;
                case 4:printf("thank you for using atm\n");
                       break;

                             }
                             fflush(stdin);
                             printf("if you want to continue press:1\n");
                             scanf("%d",&choice);
               }
           }while(choice==1);
}
void createlist()
{
    struct node *temp;
    int amount,n,pin,i;
    char user[30];
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        printf("enter number of customers\n");
        scanf("%d",&n);
        printf("assign pin to user :1\n");
        scanf("%d",&pin);
        printf("assign the user name:1\n");
        scanf("%s",user);
        printf("enter amount to the user:1\n");
        scanf("%d",&amount);

        head->data=pin;
        head->data1=amount;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("assign pin to user:%d\n",i);
            scanf("%d",&pin);
            printf("assign the user name:%d\n",i);
        scanf("%s",user);
            printf("enter amount to the user:%d\n",i);
            scanf("%d",&amount);
            newnode->data=pin;
            newnode->data1=amount;
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;

        }

    }
}
struct node * search()
{

    int index=0,key;

    printf("please enter your pin\n");
    scanf("%d",&key);
    struct node *curNode,*k;
    curNode = head;
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
        


        
    }

    if(index>1)
    {
        printf("\nenter valid pin\n");


    }else{
    k=curNode;
}    return curNode;
}

