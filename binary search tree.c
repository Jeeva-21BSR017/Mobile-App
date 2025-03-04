#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *left;
struct Node *right;
};
struct Node* createNode(int data)
{
 struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=data;
 newNode->left=newNode->right=NULL;
 return newNode;
}
struct Node* insert(struct Node* root,int data)
{
if(root==NULL)
{
    return createNode(data);
}
if(data<root->data)
{

    root->left=insert(root->left,data);
}
else if(data>root->data)
{

    root->right=insert(root->right,data);
}
return root;
}
struct Node* findMin(struct Node* root)
{
 while(root->left!=NULL)
 {
     root=root->left;
 }
 return root;
}
struct Node* deleteNode(struct Node* root,int data)
{

if(root==NULL)
{

    return root;
}
if(data<root->data)
{
  root->left=deleteNode(root->left,data);
}
else if(data>root->data)
{
    root->right=deleteNode(root->right,data);
}
else
{
    if(root->left==NULL)
    {

        struct Node* temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL)
    {

        struct Node* temp=root->left;
        free(root);
        return temp;
    }
    struct Node* temp=findMin(root->right);
    root->data=temp->data;
    root->right=deleteNode(root->right,temp->data);
}
return root;
}
void display(struct Node* root)
{

    if(root!=NULL)
    {
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}
int main()
{

    struct Node* root=NULL;
    int choice,value;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            root=insert(root,value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d",&value);
            root=deleteNode(root,value);
            break;
        case 3:
            printf("Display\n");
            display(root);
            break;
        case 4:
           exit(0);
        default:
            printf("Invalid choice\n");
        }

    }
    return 0;
}
