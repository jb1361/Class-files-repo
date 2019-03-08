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
				T key;
				NodeRecord* p;
				NodeRecord* left;
				NodeRecord* right;
				// satellite data declarations
		};
		NodeRecord * root;

	public:
		BST(){root = NULL;}
		~BST(){}
	
		void inorderTreeWalk(T& x);	
		void generateBST() {
			NodeRecord head = new NodeRecord();
			root = head;
		}
		/* Implement the following !!!!RECURSIVE!!!! functions, you may writeprivate helper function if necessary.
		Inorder-Tree-Walk (x)-- restores x, tree-- ensures: the values in the tree rooted at 'x' are displayed 
		in-orderif x not equal to NILInorder-Tree-Walk (x.left)print x.keyInorder-Tree-Walk (x.right);
		---------------------------------------------------------------------------Tree-Insert (z)--
		updates tree-- ensures: the node z is inserted into treeso that tree maintains-- 
		the search tree property-----------------------------------------------------------------------
		-----Recursive-Tree-Search (z, k)-- restores z, tree-- updates k-- ensures: if there exists y: Node such that y.key = z then k = z-- 
		else k = NIL*/
};

template<class T>
void BST<T>::inorderTreeWalk(T& x)
{
	if (x != NULL) {
		inorderTreeWalk(*x.left);
		cout << *x.key;
		inorderTreeWalk(x.right);
	}
}
int main() 
{
	BST<string>* bst = new BST<string>();
	bst->generateBST();
	string wow = "hmm";
	bst->inorderTreeWalk(wow);
	return 0;
}
