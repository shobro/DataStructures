#include<stdio.h>
#include <stdlib.h>
typedef struct {
    int data;
    struct node *next
}node;

//push funtion in the stack
node * push(node *top){
    node *temp=(node *)malloc(sizeof(node));
    printf("Enter the data you want to store : ");
    scanf(" %d",&temp->data);
    if(top==NULL){
        top=temp;
        temp->next=NULL;
        return top;
    }
    temp->next=top;
    top=temp;
    return top;
}

//display the contents of the stack
void display(node * top){
    node *p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//pop the topmost element of the stack
node *pop(node *top){
    node *temp=(node *)malloc(sizeof(node));
    temp=top;
    top=top->next;
    free(temp);
    return top;
}

int main(){
    node *top=NULL;
    int choice=1;
    while(choice){
    printf("Enter one to insert elements in the stack\nEnter two to display elements in the stack\nEnter three to pop elements : ");
    scanf(" %d",&choice);
    switch(choice){
        case 1 :top=push(top);
        break;
        case 2 :display(top);
        break;
        case 3 :top=pop(top);
        break;
        default:
            printf("Enter a valid number to perform a function\n");
        }
    }
    return 0;
}
