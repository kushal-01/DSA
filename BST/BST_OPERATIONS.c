#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree = NULL;
struct node * insertElement(struct node* , int);
void preorderTraversal(struct node*);
void inorderTraversal(struct node*);
void postorderTraversal(struct node*);
struct node * findSmallestElement(struct node*);
struct node * findLargestElement(struct node*);
struct node * deleteElement(struct node* , int);
int totalNodes(struct node*);
int Height(struct node*);

int main()
{
  int option, val;
  struct node *ptr;
  
  do
  {
    printf("\n ****MAIN MENU****\n");
    printf("\n 1. INSERT ELEMENT");
    printf("\n 2. PREORDER TRAVERSAL");
    printf("\n 3. INORDER TRAVERSAL");
    printf("\n 4. POSTORDER TRAVERSAL");
    printf("\n 5. FIND THE SMALLEST ELEMENT");
    printf("\n 6. FIND THE LARGEST ELEMENT");
    printf("\n 7. DELETE AN ELEMENT");
    printf("\n 8. TOTAL NO. OF NODES");
    printf("\n 9. HEIGHT OF THE TREE");
    printf("\n 10. EXIT");
    printf("\n 1. ENTER YOUR OPTION: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    printf("\nEnter the value of the New Node:");
    scanf("%d", &val);
    tree= insertElement(tree,val);
    break;
     
    case 2:
    printf("\nThe Elements of the Tree are:\n");
    preorderTraversal(tree);
    break;

    case 3:
    printf("\nThe Elements of the Tree are:\n");
    inorderTraversal(tree);
    break;

    case 4:
    printf("\nThe Elements of the Tree are:\n");
    postorderTraversal(tree);
    break;
     
     case 5:
     ptr= findSmallestElement(tree);
    printf("\nThe Smallest Element of the Tree is:%d", ptr->data);
    break;

    case 6:
     ptr= findLargestElement(tree);
    printf("\nThe Largest Element of the Tree is:%d", ptr->data);
    break;

    case 7:
    printf("\nEnter the Element to be deleted:");
    scanf("%d", &val);
    tree=deleteElement(tree,val);
    break;

    case 8:
    printf("\nTotal No. of Nodes=%d", totalNodes(tree));
    break;

    case 9:
    printf("The Height of the Tree= %d", Height(tree));
    break;
}

    

  } while (option!=10);
  getch();
  return 0;
  
}

struct node * insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left= ptr->right= NULL;
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            nodeptr= nodeptr->right;    
        }
        if(val<parentptr->data)
        parentptr->left=ptr;
        else
        parentptr->right= ptr;
    }
    return tree;

   
}

void preorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {   inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {   postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

struct node * findSmallestElement(struct node*tree)
{
    if((tree==NULL)||(tree->left==NULL))
     return tree;
    else
     return  findSmallestElement(tree->left);
    
}

struct node * findLargestElement(struct node*tree)
{
    if((tree==NULL)||(tree->right==NULL))
     return tree;
    else
     return  findLargestElement(tree->right);
    
}

struct node * deleteElement(struct node *tree, int val)
{
    struct node* temp;
    if(tree==NULL)
    {
        printf("Value not found in this Tree.");
    }
    else if(val<tree->data)
     deleteElement(tree->left,val);
    else if(val>tree->data)
     deleteElement(tree->right,val);
    else if((val=tree->data)&&(tree->left!=NULL)&&(tree->right!=NULL))
     {
      temp=findLargestElement(tree->left);
      tree->data=temp->data;
      deleteElement(tree->left, temp->data);
     }
     else
     {
        temp=tree;
        if((tree->left==NULL)&&(tree->right==NULL))
        tree= NULL;
        else if(tree->left!=NULL)
        tree=tree->left;
        else
        tree=tree->right;
     
    
     }
    return tree; 
}

int totalNodes(struct node *tree)
{
 if(tree==NULL)
 return 0;
 else
 {
  return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
 }
     
}
int Height(struct node * tree)
{
    int leftheight,rightheight;
    if(tree==NULL)
    return 0;
    else
    {
      leftheight= Height(tree->left);
      rightheight= Height(tree->right);
      if(leftheight > rightheight)
      return (leftheight + 1);
      else 
      return rightheight + 1;
    }
    
}






