#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *rev(struct node *start){struct node *p1,*p2;
p1=start;
p2=start->next;
p1->next=NULL;
p1->prev==p2;
while(p2!=NULL){p2->prev=p2->next;
p2->next=p1;
p1=p2;
p2=p2->prev;
}
start=p1;
return start;
}
struct node *delete(struct node *start){//printf(" flag");
//struct node *p=start;
struct node *temp=(struct node *)malloc(sizeof(struct node));
int data1;
printf("Enter the data you want to delete from the list : ");
scanf("%d", &data1);
//printf(" flag");
if(start->next==NULL)
{
    temp=start;
    start=NULL;
    free(temp);
    return start;
}
else if(start->data==data1)
{
    temp=start;
    start=start->next;
    start->prev= NULL;
    free(temp);
    return start;
}
temp=start->next;
while(temp->next!=NULL){if(temp->data==data1){
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
free(temp);
return start;
}
temp=temp->next;
}
if(temp->data==data1){printf(" k");
temp->prev->next=NULL;
free(temp);
return start;
}
}
void insertafter(struct node *start){int data;
struct node *p,*temp;
p=start;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the number after which you want to add your number : ");
scanf(" %d",&data);
printf("Enter the data which you want to enter in the list : ");
scanf(" %d",&temp->data);
while(p!=NULL){if(p->data==data){temp->next=p->next;
temp->prev=p;
p->next->prev=temp;
p->next=temp;
return;
}
p=p->next;
}
}
void insertbefore(struct node *start){int data;
struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *p=start;
printf("Enter number before which you want to add the data : ");
scanf(" %d",&data);
printf("Enter number you want to enter in the list : ");
scanf(" %d",&temp->data);
while(p!=NULL){if(p->next->data==data){temp->next=p->next;
temp->prev=p;
p->next->prev=temp;
p->next=temp;
return;
}
p=p->next;
}
}
void insertend(struct node* start){struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *p=start;
printf("Enter data to be entered : ");
scanf(" %d",&temp->data);
if(start==NULL)
{
    temp->next=NULL;
    temp->prev=NULL;
    start=temp;
}
while(p->next!=NULL)
p=p->next;
p->next=temp;
temp->next=NULL;
}
struct node *insertbeg(struct node *start){struct node*temp=(struct node *)malloc(sizeof(struct node));
printf("Enter the data you want to store in the data structure : ");
scanf(" %d",&temp->data);
if(start==NULL){temp->prev=NULL;
temp->next=NULL;
start=temp;
return start;
}
temp->next=start;
temp->prev=NULL;
start=temp;
return start;
}
void display(struct node *start)
{
    struct node *p=start;
    if(p==NULL)
    {printf("List is empty");
    return;
    }
    while(p!=NULL){printf("%d ",p->data);
    p=p->next;
    }
    return;
}
int main()
{
    struct node*start=NULL;
    int choice=1;
    while(choice)
    {
        printf("To display the doubly linked list press 1\nTo insert elements at the begining of the doubly linked list press two\nTo insert elements in the end of the list enter three\nTo indert element after the specicfied number press four\nTo insert elemnet before the entererd number in the list press five\nTo delete elements in the list press six\nTo reverse the list press seven  : ");
        scanf(" %d",&choice);
        switch(choice){
            case 1 : display(start);
            break;
            case 2 : start=insertbeg(start);
            break;
            case 3 : insertend(start);
            break;
            case 4 : insertafter(start);
            break;
            case 5 : insertbefore(start);
            break;
            case 6 : start=delete(start);
            break;
            case 7 : start=rev(start);
            break;
        }
        printf("\n");
    }
}