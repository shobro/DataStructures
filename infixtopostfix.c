# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
typedef char data;
typedef struct stack{
    data value;
    struct stack *next;
}stack;
int isoperand(char a){
   if(a=='+'||a=='-'||a=='*'||a=='/')
    return 1;
}
int p=0;
stack* pop(stack *head){
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    stack *temp=head;
    data val=head->value;
    if(head->next)
    {head=head->next;
    if(temp->value!='(')
    {
        printf("%c",temp->value);
        p=0;
    }
    if(temp->value=='(')
        p=1;
    free(temp);
    return head;
    }
    printf("%c",temp->value);
    head=NULL;
    return head;
}
stack* push(stack *head,data val)
{
    stack *temp=(stack *)malloc(sizeof(stack));
    temp->value=val;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
        //printf("push");
        return head;
    }
    temp->next=head;
    head=temp;
    //printf("push");
    return head;
}
int main()
{
    data temp;
    stack *head=NULL;
    data input[15];
    printf("Enter the string : ");
    scanf("%s",input);
    temp='0';
    for(int i=0;i<strlen(input);++i)
    {
        //printf("1");
        if(input[i]=='(')
        {
           head= push(head,input[i]);
        }
        if(input[i]==')')
        {
            while(p!=0)
                head=pop(head);
        }
        if(isoperand(input[i])==1)
        {
            switch(input[i])
            {
                case '+':{if(temp=='0')
                           head= push(head,input[i]);
                        if(temp=='-'||temp=='/')
                        {
                           head=pop(head);
                           head=push(head,input[i]);
                        }
                        if(temp=='*'||temp=='+')
                        {
                            head=pop(head);
                            head=push(head,input[i]);
                        }
                        break;
                }
                case '-':{if(temp=='0')
                            head=push(head,input[i]);
                         if(temp=='+'||temp=='/'||temp=='*'||temp=='-')
                        {
                            head=pop(head);
                           head= push(head,input[i]);
                        }
                        break;
                        }
                case '*':{
                        if(temp=='0')

                            head=push(head,input[i]);
                        if(temp=='+'||temp=='-')
                           {
                            head= push(head,input[i]);
                           }
                        if(temp=='/'||temp=='*')
                            {
                                head=pop(head);
                                head=push(head,input[i]);
                            }
                            break;
                        }
                case '/':{
                            if(temp=='0')
                              head=  push(head,input[i]);
                            if(temp=='+'||temp=='-'){
                                head=push(head,input[i]);
                            }
                            if(temp=='/'||temp=='*')
                            {
                               head=pop(head);
                            }
                            break;
                        }

            }
            temp=input[i];
        }
        if(isalpha(input[i]))
           {
               printf("%c",input[i]);
           }
        p=0;
    }
   // printf("%p",head);
    while(head)
        head = pop(head);
    //printf("%c",pop(head));
    return 0;
}
