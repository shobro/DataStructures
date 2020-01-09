#include<stdio.h>
#include<stdlib.h>
struct node{int data;
struct node *next;
};
struct node* insertbeg(struct node *last){
struct node *temp=(struct node *)malloc(sizeof(struct node *));
printf("Enter the number you want to store : ");
scanf(" %d",&temp->data);
if(last==NULL){
last=temp;
last->next=last;
return last;
}
temp->next=last->next;
last->next=temp;
return last;
}
void print(struct node *last){if(last==NULL){
printf("List is empty \n");
}
    struct node *temp=(struct node *)malloc(sizeof(struct node *));
    temp=last->next;
    printf("%d ",temp->data);
    temp=temp->next;
    while(temp!=last->next){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node *insertafter(struct node * last){struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *p=(struct node *)malloc(sizeof(struct node));
int data;
    printf("Enter the number after which you want to store the no : ");
    scanf(" %d",&data);
    printf("Enter the number : ");
    scanf(" %d",&temp->data);
    p=last->next;
    while(p->data!=data)
    p=p->next;
    temp->next=p->next;
    p->next=temp;
    return last;


}
struct node*insertend(struct node *last){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to store : ");
    scanf(" %d",&temp->data);
    if(last==NULL){
        temp->next=temp;
        last=temp;
        return last;
    }
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}
struct node*insertbefore(struct node *last){int data;
    printf("Enter data before which you want to store the data : ");
    scanf(" %d",&data);
    struct node *p=last->next;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to store after the specified position : ");
    scanf(" %d",&temp->data); 
    while(p->next->data!=data)
    p=p->next;
    temp->next=p->next;
    p->next=temp;
    return last;
}
struct node *delete(struct node *last){struct node *temp=(struct node *)malloc(sizeof(struct node *));
int data;
printf("Enter data to be deleted : ");
scanf(" %d",&data);
    if(last->data==data&&last->next==last){
        temp=last;
        last=NULL;
         free(temp);
        return last;
    }
    if(last->next->data==data)
    {                                     //for starting element
        //struct node *po=last->next;
        temp=last->next;
        //po=po->next;
        last->next=temp->next;
        free(temp);
        return last;
    }
    
    struct node *p=last->next;
    while(p->next!=last)
  {
      if(p->next->data==data)
  {  temp=p->next;
    p->next=temp->next;                                                                                   //for end element
    free(temp);
    return last;
  }
    p=p->next;
  }
  if(last->data==data){
      temp=last;
      p->next=last->next;
      last=p;
      free(temp);
      return last;
  }

}
int main(){
int choice;
struct node*last=NULL;
while(choice!=0){printf("Enter one to insert element in the begining of the list \nEnter two to view the list\nEnter three to insert element in the end\nEnter four store the data in the middle of list after the specified position\nEnter five to store data before the specified position\nTo delete elements in the linked list enter six : ");
scanf(" %d",&choice);
switch(choice){
    case 1 :last=insertbeg(last);
    break;
    case 2 :print(last);
    break;
    case 3 :last=insertend(last);
    break;
    case 4 :last=insertafter(last);
    break;
    case 5 :last=insertbefore(last);
    break;
    case 6 :last=delete(last);
    break;
}
}
return 0;
}