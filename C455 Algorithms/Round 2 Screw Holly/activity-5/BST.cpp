#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <class T>
class BST
{
private:
	class NodeRecord
	{
	public:
		NodeRecord() {
			left = NULL;
			right = NULL;
			p = NULL;
			key = NULL;
		}
		~NodeRecord() {}
		int *key;
		NodeRecord* p;
		NodeRecord* left;
		NodeRecord* right;	
	};
	NodeRecord *root;
public:
	BST() { root = NULL; }
	~BST() {}

	void generateBST() {		
		NodeRecord *head = new NodeRecord;
		NodeRecord *node = new NodeRecord;
		NodeRecord *node1 = new NodeRecord;
		NodeRecord *node2 = new NodeRecord;
		NodeRecord *node3 = new NodeRecord;
		NodeRecord *node4 = new NodeRecord;
		NodeRecord *node5 = new NodeRecord;
		NodeRecord *node6 = new NodeRecord;
		int val1 = 77;
		int val2 = 66;
		int val3 = 99;
		int val4 = 101;
		int val5 = 89;
		int val6 = 69;
		int val7 = 12;
		int val8 = 50;
		head->key = &val1;
		node->key = &val2;
		node1->key = &val3;		
		node2->key = &val4;		
		node3->key = &val5;		
		node4->key = &val6;		
		node5->key = &val7;		
		node6->key = &val8;		
		root = head;
		cout << "Adding Node: " << *node->key << endl;
		treeInsert(root, node);
		cout << "Adding Node: " << *node1->key << endl;
		treeInsert(root, node1);
		cout << "Adding Node: " << *node2->key << endl;
		treeInsert(root, node2);
		cout << "Adding Node: " << *node3->key << endl;
		treeInsert(root, node3);
		cout << "Adding Node: " << *node4->key << endl;
		treeInsert(root, node4);	
		cout << "Adding Node: " << *node5->key << endl;
		treeInsert(root, node5);
		cout << "Adding Node: " << *node6->key << endl;
		treeInsert(root, node6);
			
		cout << "In Order BST: ";
		inorderTreeWalk(root);
		cout << endl;

		cout << "Checking if 12 is in BST" << endl;
		treeSearch(root, 12);
		cout << "Checking if 15 is in BST" << endl;
		treeSearch(root, 15);
		cout << "Checking if 126 is in BST" << endl;
		treeSearch(root, 126);
		cout << "Checking if 77 is in BST" << endl;
		treeSearch(root, 77);
		cout << "Checking if 101 is in BST" << endl;
		treeSearch(root, 101);
	}

	///*Tree - Insert(NodeRecord *root, NodeRecord z)
	//	--requires: no duplicates
	//	--updates tree
	//	-- ensures: the node z is inserted into tree so that tree maintains
	//	--          the search tree property*/
	void treeInsert(NodeRecord *root, NodeRecord *z)
	{							
		if (*z->key < *root->key) {			
			if (root->left == NULL) root->left = z;
			else treeInsert(root->left, z);
		}
		else if (*z->key > *root->key) {
			if (root->right == NULL) root->right = z;
			else treeInsert(root->right, z);
		}
	}
	///*Inorder - Tree - Walk(x)
	//	--restores x, tree
	//	-- ensures: the values in the tree rooted at 'x' are displayed in - order
	//	if x not equal to NIL
	//		Inorder - Tree - Walk(x.left)
	//		print x.key
	//		Inorder - Tree - Walk(x.right);
	// A utility function to insert a new node with given key in BST*/
	void inorderTreeWalk(NodeRecord *x)
	{				
		if (x != NULL)
		{
			inorderTreeWalk(x->left);
			cout << *x->key << " ";
			inorderTreeWalk(x->right);
		}
	}
	
	///*Recursive - Tree - Search(z, k)
	//	--restores z, tree
	//	-- updates k
	//	-- ensures: if there exists y : Node such that y.key = z then k = z
	//	--          else k = NIL*/
	void treeSearch(NodeRecord *root, int k)
	{			
		if (k < *root->key) {
			if (root->left == NULL) cout << "Node doesnt exist" << endl;
			else treeSearch(root->left, k);
		}
		else if (k > *root->key) {
			if (root->right == NULL) cout << "Node doesnt exist" << endl;
			else treeSearch(root->right, k);
		}
		else cout << k << " is in the BST" << endl;
	}

};
/* Implement the following !!!!RECURSIVE!!!! functions, you may write
			private helper function if necessary.

		 Inorder-Tree-Walk (x)
		 -- restores x, tree
		 -- ensures: the values in the tree rooted at 'x' are displayed in-order
				if x not equal to NIL
				   Inorder-Tree-Walk (x.left)
				   print x.key
				   Inorder-Tree-Walk (x.right);
				   /* A utility function to insert a new node with given key in BST

		---------------------------------------------------------------------------
		 Tree-Insert (z)
		 -- updates tree
		 -- ensures: the node z is inserted into treeso that tree maintains
		 --          the search tree property
		  ----------------------------------------------------------------------------
		  Recursive-Tree-Search (z, k)
		  -- restores z, tree
		  -- updates k
		  -- ensures: if there exists y: Node such that y.key = z then k = z
		  --          else k = NIL
		 */
		 //template<class T>
		 //void BST<T>::inorderTreeWalk(T& x)
		 //{
		 //	if (x != NULL) {
		 //		inorderTreeWalk(*x.left);
		 //		cout << *x.key;
		 //		inorderTreeWalk(x.right);
		 //	}
		 //}

int main()
{	
	BST<int> *bst = new BST<int>();
	bst->generateBST();	
	//string wow = "hmm";
	//bst->inorderTreeWalk(wow);
	return 0;
}
