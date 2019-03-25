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
		T *key;
		NodeRecord* p;
		NodeRecord* left;
		NodeRecord* right;
		// satellite data declarations
	};
	NodeRecord *root;
public:
	BST() { root = NULL; }
	~BST() {}
	template<class T> void treeInsert(T& x, NodeRecord *z);
	template<class T> void inorderTreeWalk(T& x);
	/*void inorderTreeWalk(T& x);
	void treeInsert(T& x, NodeRecord z);*/
	void generateBST() {
		NodeRecord *head = new NodeRecord;
		NodeRecord *node = new NodeRecord;
		root = head;
		treeInsert(root, node);
	}
	/*Tree - Insert(T& x, NodeRecord z)
		--requires: Tree not empty and no duplicates
		--updates tree
		-- ensures: the node z is inserted into tree so that tree maintains
		--          the search tree property*/

	void treeInsert(T& x, NodeRecord *z)
	{
		NodeRecord root = x.root;
		if (z->key < root->key)
			root->left = treeInsert(root->left, z);
		else if (z->key > root->key)
			root->right = treeInsert(root->right, z);
		return x;
	}
	void inorderTreeWalk(T& x)
	{
		NodeRecord root = x.root;
		if (x != NULL)
		{
			inorderTreeWalk(*x.left);
			cout << *x.key << ", ";
			inorderTreeWalk(x.right);
		}
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
