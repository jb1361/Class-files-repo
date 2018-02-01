/* C program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int

/* A binary tree node has data, pointer to left child
 and a pointer to right child */

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Returns the height of a binary tree */
int height(struct node* node);

/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
    
    /* If tree is empty then return true */
    if(root == NULL)
        return 1;
    
    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);
    
    if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
        return 1;
    
    /* If we reach here then tree is not height-balanced */
    return 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */
int max(int a, int b)
{
    return (a >= b)? a: b;
}

/*  The function Compute the "height" of a tree. Height is the
 number of nodes along the longest path from the root node
 down to the farthest leaf node.*/
int height(struct node* node)
{
    /* base case tree is empty */
    if(node == NULL)
        return 0;
    
    /* If tree is not empty then height = 1 + max of left
     height and right heights */
    return 1 + max(height(node->left), height(node->right));
}
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}
int treeSize(struct node* root,int size){
	if(root == NULL) return size;
	size = (1+ treeSize(root->left,size) + treeSize(root->right,size));
	return size*;
}

int getInorderArray(struct node* root){
	int size = treeSize;
	//int arr[size];
	//if(root == NULL) return;
	//if(root->left != NULL) getInorderArray(root->left);
	//arr.append(root->data);
	//getInorderArray(root->right);
	return 1;
}

void  balanceTree(struct node* &root,int ar[],int firstIndex,int lastIndex){
	//if(root != NULL) {
	//	ar.append(root->data);
	//	balanceTree(root)
	//}
}


void printInorder(struct node* root){
	if(root == NULL) return;
	if(root->left != NULL) printInorder(root->left);
	printf("%d\n", root->data);
	printInorder(root->right);
}
void insertNode(struct node* &root, int x){
	if(root == NULL) root = newNode(x);
	else if (x < root->data) insertNode(root->left,x);
	else if (x > root->data) insertNode(root->right,x);
	else return;
}
int main()
{
    struct node *root = NULL;
    insertNode(root,4);
	insertNode(root,1);
	insertNode(root,5);
	insertNode(root,8);
	printInorder(root);
	printf("%d\n",treeSize(root,0));
    if(isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    
    getchar();
    return 0;
}