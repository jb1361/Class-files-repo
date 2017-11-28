#pragma once
// TODO:
// After you are satisfied that your Map3 implementation is working correctly,
// then comment out the #pragma line below and recompile - if you get compiler error messages, then fix them
#pragma warning( disable : 4716)


//
// Realization #4 of Map Template layered on binary search tree
// author: TODO: put your name here
//

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
class Map3
	//! Map3 is modeled by PARTIAL_FUNCTION
	//! math subtype PARTIAL_FUNCTION is finite set of
	//!                  k: K
	//!                  v: V
	//!             exemplar m
	//!             constraint
	//!                for all   k: K, r1, r2: V
	//!                          where (k, r1) is in m
	//!                          and   (k, r2) is in m then (r1 = r2)
	//! 
	//!          math operation DEFINED_IN (
	//!                   m: PARTIAL_FUNCTION
	//!                   k: K
	//!                ): boolean
	//! 
	//!          definition   DEFINED_IN (m, k)  iff
	//!                            there exists v: V, ((k, v) is in m)
	//! exemplar self
{
public: // standard Operations
	Map3();
	//! replaces self
	//! ensures: self = { }
	~Map3();
	void clear(void);

	void transferFrom(Map3& source);
	//! replaces self
	//! clears source
	Map3& operator = (Map3& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// Map3 Specific Operations
	void add(K& key, V& value);
	//! updates self
	//! clears key, value
	//! requires: key is not in DOMAIN(self)
	//! ensures: self = #self  union  {(#key, #value)}
	void remove(K& key, K& keyFromMap, V& valueFromMap);
	//! updates self
	//! restores key
	//! replaces  keyFromMap, valueFromMap
	//! requires: key is in DOMAIN(self)
	//! ensures: (key, valueFromMap) is in #self  and
	//!          self = #self \ {(keyFromMap, valueFromMap)}  and  keyFromMap = key
	V& value(K& key);
	//! restores self, key
	//! requires: key is in DOMAIN(self)
	//! ensures: (key, value) is in self
	void removeAny(K& key, V& value);
	//! updates self
	//! replaces key, value
	//! requires: |self| > 0
	//! ensures: (key, value) is in #self  and  self = #self \ {(key, value)}
	Boolean hasKey(K& key);
	//! restores  self
	//! restores key
	//! ensures: hasKey = (key is in DOMAIN(self))
	Integer size(void);
	//! restores self
	//! ensures: size = |self|

	friend wostream & operator<< <K, V, KCompare>(wostream &os, Map3& m);
	//! updates os
	//! restores m

private: // representation
	class TreeNodeRecord {
	public:
		K keyItem; 
		V valueItem;
		TreeNodeRecord* leftSubtree;
		TreeNodeRecord* rightSubtree;
	};

	TreeNodeRecord* root;

private:
	// Headers for all private member functions
	Integer countNodes(TreeNodeRecord* p);
	void copyTree(TreeNodeRecord* fromP, TreeNodeRecord*& toP);
	void displayRep (wostream &os, TreeNodeRecord*& p);
	void deleteNodes (TreeNodeRecord* p);
	void extractFromTree(TreeNodeRecord*& p, K& k, TreeNodeRecord*& extracted);
	void insertInTree(TreeNodeRecord*& p, K& k, V& v);
	Boolean inTree (TreeNodeRecord*& p, K& k);
	void removeLargestFromTree (TreeNodeRecord*& p, TreeNodeRecord*& largest);
	V& treeAccessor (TreeNodeRecord*& p, K& k);

	// disallowed Map3 Operations
	Map3 (const Map3& s);
	Map3* operator & (void) {return (this);};
	const Map3* operator & (void) const {return (this);};
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::displayRep (wostream &os, TreeNodeRecord*& p)
	// requires: Alive(p)  or  NULL(p)
	//  ensures: the tree rooted at 'p' is unchanged  and  an in-order traversal 
	//           is performed displaying the keyItem encountered at each node visited
{
	// Done

	// Performs an in-order traversal of tree, displays as a list of lists
	// Displays only the keyItem when visiting a node's value
	if (p != NULL) {
		os << "(";
		displayRep(os, p->leftSubtree);
		os << ",";
		os << p->keyItem;
		os << ",";
		displayRep(os, p->rightSubtree);
		os << ")";
	}
	else {
		// Empty tree
		os << "E";
	} // end if
} // displayRep

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Integer Map3<K, V, KCompare>::countNodes (TreeNodeRecord* p)
	// requires: Alive(p)  or  NULL(p)
	//  ensures: countNodes() = number of nodes in the tree rooted at 'p' 
{
	//TODO: finish countNodes
} // countNodes

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::deleteNodes (TreeNodeRecord* p)
	// requires: Alive(p)  or  NULL(p)
	//  ensures: all nodes in tree rooted at 'p' are deleted
{
	//TODO: finish deleteNodes
} // deleteNodes

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::copyTree (TreeNodeRecord* fromP, TreeNodeRecord*& toP)
	// requires: Alive(fromP)  or  NULL(fromP)
	//  ensures: if NULL(fromP) then NULL(toP),  otherwise
	//       performs a deep copy of the tree rooted at fromP  and 
	//       toP holds the root of a tree that is the exact duplicate of the tree rooted at fromP
{
	//TODO: finish copyTree
} // copyTree

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Boolean Map3<K, V, KCompare>::inTree (TreeNodeRecord*& p, K& k)
	// requires: Alive(p)  or  NULL(p)  and
	//           if Alive(p) then the tree rooted at 'p' possesses the binary search tree property
	//  ensures: the tree rooted at 'p' has not been changed  and
	//           inTree() = true iff there exists a node with pointer 'x' in the tree rooted at 'p' 
	//           where x->keyItem == k
{
	//TODO: finish inTree recursive version
} // inTree

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::insertInTree (TreeNodeRecord*& p, K& k, V& v)
	// requires: (Alive(p)  or  NULL(p)) and  
	//           the tree rooted at 'p' possesses the binary search tree property
	//  ensures: the outgoing tree rooted at 'p' = the incoming tree rooted at 'p' with a new node
	//           containing k and v added at the frontier of the tree
{
	//TODO: finish insertInTree
} // insertInTree

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::removeLargestFromTree (TreeNodeRecord*& p, TreeNodeRecord*& largest)
	// requires: Alive(p) and  |the tree rooted at 'p'| > 0  and  
	//           the tree rooted at 'p' possesses the binary search tree property
	//  ensures: largest->keyItem is the largest K in the tree (as determined by KCompare::areOrdered)  and 
	//       the outgoing tree rooted at 'p' = the incoming tree rooted at 'p' with the node referenced by 'largest' removed  and
	//       the tree rooted at 'p' possesses the binary search tree property

{
	//TODO: finish removeLargestFromTree
} // removeLargestFromTree

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::extractFromTree (TreeNodeRecord*& p, K& k, TreeNodeRecord*& extracted)
	// requires: Alive(p) and  the tree rooted at 'p' possesses the binary search tree property  and 
	//       there exists a node with pointer 'x' in the tree rooted at 'p' 
	//       where x->keyItem == k
	//  ensures: the outgoing tree rooted at 'p' = the incoming tree rooted at 'p' with the node referenced by pointer 'x' removed  and
	//       the tree rooted at 'p' possesses the binary search tree property  and
	//       extracted = 'x'
{
	//TODO: finish extractFromTree
	/*
	After navigating to the node to be extracted, there are 4 cases for the 'extracted' node:
	1) it is a leaf node                               -- tested by UT06RemoveV2
	2) it is a node with only a left subchild          -- tested by UT06RemoveV3
	3) it is a node with only a right subchild         -- tested by UT06RemoveV4
	4) it is an interior node                          -- tested by UT06RemoveV5

	Recommendation:
	a) Supply code to handle each of the 4 cases
	b) For case #4 utilize the operation removeLargestFromTree in order to find a suitable node to replace the one being extracted
	*/
} // extractFromTree

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
V& Map3<K, V, KCompare>::treeAccessor (TreeNodeRecord*& p, K& k)
	// requires: Alive(p)  and  the tree rooted at 'p' possesses the binary search tree property  and
	//       there exists a node with pointer 'x' in the tree rooted at 'p' where 
	//       x->keyItem == k
	//  ensures: treeAccessor() = &x->valueItem   and   the tree rooted at 'p' has not been changed
{
	//TODO: finish treeAccessor
} // treeAccessor

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

// convention: the tree rooted at root is a Binary Search Tree

template <class K, class V, class KCompare>
Map3<K, V, KCompare>::Map3 ()
{
	//TODO: finish constructor
}	// Map3

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Map3<K, V, KCompare>::~Map3 ()
{
	//TODO: finish destructor
}	// ~Map3

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::transferFrom (Map3& source)
{
	//TODO: finish transferFrom
}	// transferFrom

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Map3<K, V, KCompare>& Map3<K, V, KCompare>::operator = (Map3& rhs)
{
	//TODO: finish operator =
} // operator =

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::clear (void)
{
	//TODO: finish clear
}	// clear

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::add (K& k, V& v)
{
	//TODO: finish add
}	// add

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::remove (K& k, K& dCopy, V& v)
{
	//TODO: finish remove
}	// remove

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
V& Map3<K, V, KCompare>::value (K& k)
{
	//TODO: finish value
}  // value

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map3<K, V, KCompare>::removeAny (K& k, V& v)
{
	//TODO: finish removeAny
}	// removeAny

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Boolean Map3<K, V, KCompare>::hasKey (K& k)
{
	//TODO: finish hasKey
}	// hasKey

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Integer Map3<K, V, KCompare>::size (void)
{
	//TODO: finish size
}	// size

//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
wostream & operator<<(wostream &os, Map3<K, V, KCompare>& m)
{
#ifdef NDEBUG
	Map3<K, V, KCompare> temp;
	os << "{";
	for (int i = 0, z = m.size(), lastItem = z - 1; i < z; i++) {
		K key;
		V value;

		m.removeAny (key, value);
		os << "(" << key << "," << value << ")";
		if (i < lastItem) {
			os << ",";
		} // end if
		temp.add (key, value);
	}	// end for
	os << "}";
	m.transferFrom(temp);

#else
	m.displayRep(os, m.root);
#endif

	return (os);
} // operator<<