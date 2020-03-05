#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct node
{
        struct node *left;
        struct node *right;
        Data data;
}node;
node *create_node(Data key)
{
        node *temp=(node *)malloc(sizeof(node));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
}
int searchindex(Data inorder[],Data search,Data size,Data low)
{
        int i=low;
        for(;i<=size;++i)
        {
                if(inorder[i]==search)
                {
                        return i;
                }
        }
        return 0;
}
node *buildtree(int l,int h,int inorder[],int postorder[],int *postindex)
{
        //printf("no error");
        if(l>h)
        {
                return NULL;
        }
        //printf("no error");
        int search=postorder[--(*postindex)];
        node *element=create_node(search);
        int index=searchindex(inorder,search,h,l);
        //printf("%d ",index);
        element->right=buildtree(index+1,h,inorder,postorder,postindex);
        element->left=buildtree(l,index-1,inorder,postorder,postindex);

        return element;

}
void printinorder(node *root)
{
        if(root==NULL)
                return;
        printinorder(root->left);
        printf("%d ",root->data);
        printinorder(root->right);
}
node *constructtree(Data inorder[],Data postorder[],int size)
{
        //printf("no error");
        return buildtree(0,7,inorder,postorder,&size);
}
int main()
{
        //printf("No error");
        Data inorder[8]={4,2,1,7,5,8,3,6};
        Data postorder[8]={4,2,7,8,5,6,3,1};
        //printf("no error");
        node *root=constructtree(inorder,postorder,8);
        printinorder(root);
        return 0;
}
                                                                                                                                                                                 

