#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next; 
};
struct node *reverse(struct node *start){struct node *ptr,*prev,*next;
prev=NULL;
ptr=start;
while(ptr->next!=NULL)
{
    next=ptr->next;
    ptr->next=prev;
    prev=ptr;
    ptr=next;
}
start=prev;
return start;
}
struct node *delete(struct node *start){int data;
struct node*p=start;
struct node *temp=(struct node *)malloc(sizeof(struct node));
printf("Enter the value you want to delete : ");
scanf(" %d",&data);
if(start->data==data){temp=start;
    start=start->next;
    free(temp);
    return start;
}
while(p->next!=NULL){if(p->next->data==data){
temp=p->next;
p->next=temp->next;
free(temp);
return start;
}
p=p->next;
}
return start;
} 
struct node *insertbefore(struct node *start){int data,flag=1;
struct node *p=start;
struct node *temp=(struct node *)malloc(sizeof(struct node));
printf("Enter the value before you want to enter : ");
scanf(" %d",&data);
printf("Enter the value you want to enter : ") ;
scanf(" %d",&temp->data);
while(flag){
if(p->next->data==data)
{
  temp->next=p->next;
  p->next=temp;
  flag=0;
}
p=p->next;
}
return start;
}
struct node *insertbetween(struct node *start){int data,flag=1;
struct node *temp=(struct node*)malloc(sizeof(struct node));
struct node *p=start;
printf("Enter the value after which to insert the nodes : ");
scanf(" %d",&data); 
printf("Enter the data to you want to enter in the linked list : ");
scanf(" %d",&temp->data);
if(start==NULL)
{
    temp->next=NULL;
    start=temp;
    return start;
}
while(flag)
{   if(p->data==data)
    {temp->next=p->next;
    p->next=temp;
    flag=0;
    }
    p=p->next;
}
return start;
}
struct node *insertend(struct node *start){struct node *temp=(struct node*)malloc(sizeof(struct node));
struct node *p=start;
printf("Enter the value you want to store : ");
scanf(" %d",&temp->data);
if(start==NULL)
{
    temp->next=NULL;
    start=temp;
    return start;
}
while(p->next!=NULL)
   p=p->next;
p->next=temp;
temp->next=NULL;
return start;
}
struct node *insert(struct node *start){struct node *temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the value you want to store: ");
scanf(" %d",&temp->data);
if(start==NULL)
{//printf("silly");
 temp->next=NULL;  
  start=temp;
}
else{temp->next=start;
//printf("silly");
start=temp;
}
return start;
}
void display(struct node *start){struct node *p=start;
if(p==NULL)
{printf("List is empty\n");
return;
}
while(p!=NULL)
{
    printf("%d ",p->data);
    p=p->next;
}
printf("\n");
return;
}
int main()
{
    struct node*start=NULL;
    int choice;
    //printf("Enter 1 to insert elements in the begining of linked list : \nEnter two to dispaly the value in data structure : \n");
    while(choice){printf("Enter one to insert elements in the begining of linked list\nEnter two to dispaly the value in data structure\nEnter three to enter data in end of the linklist\nEnter four to insert in between the nodes after the netered position\nEnter five to insert before the specified value\nEnter six to delete a node\nEnter seven to reverse the list : ");
        scanf(" %d",&choice);
        switch(choice){
            case 1: start=insert(start);
            break;
            case 2: display(start);
            break;
            case 3: start=insertend(start);
            break;
            case 4: start=insertbetween(start);
            break;
            case 5: start=insertbefore(start);
            break;
            case 6: start=delete(start);
            break;
            case 7: start=reverse(start);
            break;
        }
    }
    return 0;
}