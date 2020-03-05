# include <stdio.h>
# include <stdlib.h>
typedef int Data;
typedef struct node
{
        struct node *left;
        struct node *right;
        Data data;
}node;
struct node *createnode(int key)
{
        node *temp=(node *)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=key;
        return temp;
}
node *createtree(node *root,int key)
{
        node*p=root;
        if(root==NULL)
        {
                root=createnode(key);
                return root;
        }
        if(p->data>key)
                p->left=createtree(p->left,key);
        else
                p->right=createtree(p->right,key);
        return root;
}
void inorder(node *root)
{
        if(root==NULL)
                return;
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
}
void postorder(node *root)
{
        if(root==NULL)
                return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
}
void preorder(node *root)
{
        if(root==NULL)
                return;
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
}
int main()
{
        int n=1,element;
        node *root=NULL;
        for(;n!=0;)
        {
                printf("Enter the data you want to enter : ");
                scanf(" %d",&element);
                root=createtree(root,element);
                printf("Do you want to continue press 1 continue and 0 to exit : ");
                scanf(" %d",&n);
        }
        printf("The inorder traversal is : ");
        inorder(root);
        printf("\nThe postorder traversal is : ");
        postorder(root);
        printf("\nThe preorder traversal is : ");
        preorder(root);
        return 0;
}

