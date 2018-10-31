#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
}*start=NULL;

void main()
{
    int choice=1,n,p,pos;
    do
    {
        create();
        printf("\nDo you wish to continue: If yes, press 1\n Else press 0\n");
        printf("Choice: ");
        scanf("%d",&choice);
    }
    while(choice==1);
        display();

    printf("\n\nDo you want to insert information: If yes, press 1\n Else press 0\n");
    printf("Choice: ");
    scanf("%d",&n);

    if(n==1)
    {
        printf("\nEnter the position: ");
        printf("\nPress 1 for insertion at the beginning");
        printf("\nPress 2 for insertion in middle");
        printf("\nPress 3 for insertion at the end");
        scanf("%d,",&p);

        switch(p)

    {case 1:
        insertion();
        break;

    case 2:
        insertion();
        break;

    case 3:
        insertion();
        break;

    default:
         printf("Invalid Pass");
    }
        display();
    }
}

create()
{
    struct node *temp, *ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter info: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;

        ptr->link=temp;
    }
}

display()
{
    struct node *ptr;
    if(start==NULL)
        printf("List is empty");

    else
    { ptr=start;
    printf("\n\nThe linked list is: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->link;
    }
    }
}

insertion()
{
    struct node *temp,*ptr;
    int count=1,pos;

    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter info: ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
        start=temp;

    printf("\nEnter the position: ");
        scanf("%d",&pos);

    ptr=start;

    if(start==NULL  ||  pos==1)
    {
        temp->link=start;
        start=temp;
    }

    else
    {
        ptr=start;

        while(ptr->link!=NULL  &&  count<pos-1)
        {
            ptr=ptr->link;
            count++;

            if(count==pos-1)
            {
                temp->link=ptr->link;
                ptr->link=temp;
            }
            else
                printf("Invalid Pass");
        }
    }
}
