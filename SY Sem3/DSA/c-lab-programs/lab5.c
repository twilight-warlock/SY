#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

}*root,*pnode,*dnode,*rnode;
int flag=0; //GLOBAL VARIABLE

// ---------------------Functions---------------------

void createBST(){
    root=NULL;
}
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
   
struct node* insert(struct node* node, int data) 
{ 
    if (node == NULL) return newNode(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    

    return node; 
}
int search(int val)
{
    pnode= NULL;
  if(root!=NULL){
        dnode = root;
        while(dnode!=NULL){
            if(dnode->data > val){
                pnode = dnode;
                dnode = dnode->left;
            }else if(dnode->data < val){
                pnode = dnode;
                dnode = dnode->right;
            }else if(dnode->data == val){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return 1;
        }else{
            return 0;
        }
    }else{
        return -1;
    }
}
void delete(int val){

    if(search(val)==1){
        
        // ------------Leaf node------------
        if(dnode->left==NULL && dnode->right==NULL){
            if(pnode==NULL){
                root = NULL;
                // free(dnode);
            }
            else if(pnode->left == dnode)
                pnode->left = NULL;
            else if(pnode->right == dnode)
                pnode->right = NULL;
            free(dnode);
        }
        // -----------One child node----------
        else if(dnode-> left !=NULL && dnode-> right ==NULL){
            if(pnode==NULL){
                root = dnode-> left;
                // free(dnode);
            }
            else if(pnode->left == dnode)
                pnode->left = dnode-> left;
            else if(pnode->right == dnode)
                pnode->right = dnode-> left;
            free(dnode);
            
        }
        else if(dnode-> left ==NULL && dnode-> right !=NULL){
            if(pnode==NULL){
                root = dnode->right;
                // free(dnode);
            }
            else if(pnode->left == dnode)
                pnode->left = dnode-> right;
            else if(pnode->right == dnode)
                pnode->right = dnode-> right;
            free(dnode);
        }
        // ------------2 child node------------
        else if(dnode-> left !=NULL && dnode-> right !=NULL){
            struct node *min =  (struct node *)malloc(sizeof(struct node));
            min = dnode->right;
            while(min->left!=NULL){
                rnode = min;
                min = min->left;
            }
            dnode->data = min->data;
            if(min->right!=NULL){
                rnode->left = min->right;
            }
            free(min);
        }
        printf("\nThe value deleted is : %d",val);
    }else if(search(val)==0){
        printf("\nElement not found");
    }else{
        printf("\nEmpty BST");
    }
}

void getParent(int val){
    if(root->data==val){
        printf("\nThis is the root node");
    }
    if(search(val)==1){
        printf("\nThe parent node is : %d",pnode->data);
    }
}

int main()
{
    root=NULL;
    int ch=0;
    int ele,val;
    printf("\n======= Binary Search Trees Implementation =======\n");
    while (ch != 7)
    {
        printf("\n\n1. Create a BST");
        printf("\n2. Insert");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Get Parent element");
        printf("\n6. Display inorder elements");
        printf("\n7. Exit");
        printf("\nEnter your choice from 1-7: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createBST();
            printf("\nNew BST created");
            break;
        case 2:
            printf("\nPlease enter element: ");
            scanf("%d",&ele);
            root=insert(root,ele);
            printf("\nElement inserted");
            break;
        case 3:
            printf("\nPlease enter element to be searched: ");
            scanf("%d",&ele);
            val = search(ele);
            if(val==0)
            {
                printf("\nElement not found");
            }
            else if(val==1){
                printf("\nElement found");
            }else{
                printf("\nEmpty BST");
            }

            break;
        case 4:
            printf("\nPlease enter element to be deleted: ");
            scanf("%d",&ele);
            delete(ele);
            break;
        case 5:
            printf("\nPlease enter child element to be searched: ");
            scanf("%d",&ele);
            getParent(ele);
            break;
        case 6:
            if(root==NULL){
                printf("\nEmpty BST");
            }else{
                inorder(root);   
            }
            break;
        default:
            printf("\nEnter your choice from 1-7 only");
            break;
        }
    }
    printf("\nThank you");
    return 0;
}