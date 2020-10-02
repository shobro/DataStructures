# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    struct node *next;
    int value;
}node;

int pop(node ***s1)
{
    
    node *temp=(node *)malloc(sizeof(node *));
    
    if(**s1==NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    
    temp=**s1;
    int val=temp->value;
    **s1=(**s1)->next;
    free(temp);
    
    return val;
}

void push(node ***s1,int val)
{
    
    node *temp=(node *)malloc(sizeof(node *));
    temp->value=val;
    
    if(**s1==NULL)
    {
        temp->next=NULL;
        **s1=temp;
        return; //temp->value=val;
    }
    
    temp->next=**s1;
    **s1=temp;
    
    return;
}

void enqueue(node **s1,node **s2,int v)
{
    
    push(&s1,v);
    
    return;
}

void print(node **s1,node**s2)
{
    
    while(*s1)
    {
        push(&s2,pop(&s1));
    }
    
    node *p=*s2;
    
    while(p)
    {
        printf("%d->",p->value);
        p=p->next;
    }
    
    printf("\n");
    
    while(*s2)
    {
        push(&s1,pop(&s2));
    }
    
    return;
}

void dequeue(node **s1,node **s2)
{
    
    if(*s1==NULL)
    {
        printf("List is empty");
        return;
    }
    
    while((*s1)->next)
    {
        push(&s2,pop(&s1));
    }
   
    node *temp=(node *)malloc(sizeof(node));
    temp=*s1;
    free(temp);
    *s1=(*s1)->next;
    
    while(*s2)
    {
        push(&s1,pop(&s2));
    }
    
    return;
}

int main()
{
    //tail nodes for the two stacks
    node *s1=NULL;
    node *s2=NULL;
    int choice=1;
    int v;
    while(choice)
    {
        //choices for operations
        printf("1. enter one to enqueue\n");
        printf("2. enter two to dequeue\n");
        printf("3. enter three to print\n");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1 : 
                     printf("Value you want to enter : ");
                     //printf("error");
                     scanf(" %d",&v);
                     enqueue(&s1,&s2,v);
                        break;
            case 2 :dequeue(&s1,&s2);
                    break;
            case 3 : print(&s1,&s2);
                     break;
            default:
                    printf("Enter some valid operation code\n");
        }
    }
}
