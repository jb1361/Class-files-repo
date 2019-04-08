//Implement following functions of a RBT in a proper C++ program.
//You should write your main function to test all other functions.
//Turn in your working code with outputs. Outputs should show
//inorder traversal of the RBT including color of the node. 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


class Tree
{
private:
	
	class Node
	{
	public:
		Node() {
			colour = black;
			item = NULL;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
		~Node() {}
		enum {red, black} colour;
		int *item;
		Node *left, *right, *parent;
	};
	Node *root;

public:
	Tree() { root = NULL; }
	~Tree() {}

	void createRBT() 
	{
		Tree *tree = new Tree();		
		Node *head = new Node;
		Node *node = new Node;
		Node *node1 = new Node;
		Node *node2 = new Node;
		Node *node3 = new Node;
		Node *node4 = new Node;
		Node *node5 = new Node;
		Node *node6 = new Node;
		int val1 = 77;
		int val2 = 66;
		int val3 = 99;
		int val4 = 101;
		int val5 = 89;
		int val6 = 69;
		int val7 = 12;
		int val8 = 50;
		tree->root = head;
		tree->root->item = &val1;
		node->item = &val2;
		node1->item = &val3;
		node2->item = &val4;
		node3->item = &val5;
		node4->item = &val6;
		node5->item = &val7;
		node6->item = &val8;
		
		cout << "Adding Node: " << *node->item << endl;
		rb_insert(tree, node);
		cout << "Adding Node: " << *node1->item << endl;
		rb_insert(tree, node1);
		cout << "Adding Node: " << *node2->item << endl;
		rb_insert(tree, node2);
		cout << "Adding Node: " << *node3->item << endl;
		rb_insert(tree, node3);
		cout << "Adding Node: " << *node4->item << endl;
		rb_insert(tree, node4);
		cout << "Adding Node: " << *node5->item << endl;
		rb_insert(tree, node5);
		cout << "Adding Node: " << *node6->item << endl;
		rb_insert(tree, node6);
		cout << "test" << endl;
	}

	void tree_insert(Node *root, Node *z)
	{	
		if (*z->item < *root->item) {
			if (root->left == NULL) {
				root->left = z;
				z->parent = root;
			}
			else tree_insert(root->left, z);
		}
		else if (*z->item > *root->item) {
			if (root->right == NULL) 
			{
				root->right = z;
				z->parent = root;
			}
			else tree_insert(root->right, z);
		}
	}
	void rb_insert( Tree *T, Node *x ) {
		/* Insert in the tree in the usual way */
		tree_insert( T->root , x );
		/* Now restore the red-black property */
		x->colour = Node::red;
		Node *y;
		while ( (x != T->root) && (x->parent->colour == Node::red) ) {
			if ( x->parent == x->parent->parent->left ) {
				/* If x's parent is a left, y is x's right 'uncle' */
				
				y = x->parent->parent->right;
				if ( y->colour == Node::red ) {
					/* case 1 - change the colours */
					x->parent->colour = Node::black;
					y->colour = Node::black;
					x->parent->parent->colour = Node::red;
					/* Move x up the tree */
					x = x->parent->parent;
				}
				else {
					/* y is a black node */
					if ( x == x->parent->right ) {
						/* and x is to the right */
						/* case 2 - move x up and rotate */
						x = x->parent;
						left_rotate( T, x );
					}
					/* case 3 */
					x->parent->colour = Node::black;
					x->parent->parent->colour = Node::red;
					right_rotate( T, x->parent->parent );
				}
			}
			else {
				/* repeat the "if" part with right and left
				 exchanged */
			}
		}
		/* Colour the root black */
		T->root->colour = Node::black;
	}

	void left_rotate(Tree *T, Node *x)
	{
		Node *y;
		y = x->right;
		/* Turn y's left sub-tree into x's right sub-tree */
		x->right = y->left;
		if (y->left != NULL)
			y->left->parent = x;
		/* y's new parent was x's parent */
		y->parent = x->parent;
		/* Set the parent to point to y instead of x */
		/* First see whether we're at the root */
		if (x->parent == NULL) T->root = y;
		else
			if (x == (x->parent)->left)
				/* x was on the left of its parent */
				x->parent->left = y;
			else
				/* x must have been on the right */
				x->parent->right = y;
		/* Finally, put x on y's left */
		y->left = x;
		x->parent = y;
	}
	void right_rotate(Tree *T, Node *x)
	{
		Node *y;
		y = x->left;
		/* Turn y's right sub-tree into x's right sub-tree */
		x->left = y->right;
		if (y->right != NULL)
			y->right->parent = x;
		/* y's new parent was x's parent */
		y->parent = x->parent;
		/* Set the parent to point to y instead of x */
		/* First see whether we're at the root */
		if (x->parent == NULL) T->root = y;
		else
			if (x == (x->parent)->right)
				/* x was on the right of its parent */
				x->parent->right = y;
			else
				/* x must have been on the left */
				x->parent->left = y;
		/* Finally, put x on y's left */
		y->right = x;
		x->parent = y;
	}

};
int main() {
	Tree *rbt = new Tree();
	//rbt->createRBT();
	return 0;
}
