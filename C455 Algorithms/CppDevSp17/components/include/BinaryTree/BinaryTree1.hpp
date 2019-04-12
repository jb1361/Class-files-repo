#pragma once

/*
	Realization of BinaryTree using 2WayDagPosition
	Author: Dr. Holly
*/

#include "DAGPosition\DAGPosition1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class BinaryTree1
	//! BinaryTree1 is modeled by tuple of
	//!      label: T
	//!      leftSubtree: BinaryTree1
	//!      rightSubtree: BinaryTree1
	//! exemplar self
{
public: // Standard Operations
	BinaryTree1 ();
		//! replaces self
		//! ensures: self = EMPTY
	~BinaryTree1 ();
	void clear (void);
		//! clears self
	void transferFrom (BinaryTree1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	BinaryTree1& operator = (BinaryTree1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// BinaryTree1 Specific Operations
	void compose (T& x, BinaryTree1& left, BinaryTree1& right);
		//! replaces self
		//! clears x, left, right
		//! ensures: self = (#x, #left, #right)
	void decompose (T& x, BinaryTree1& left, BinaryTree1& right);
		//! clears self
		//! replaces x, left, right
		//! requires: self /= EMPTY
		//! ensures: #self = (x, left, right)
	T& label (void);
		//! restores self
		//! requires: self /= EMPTY
		//! ensures: label = self.label
	Integer size (void);
		//! restores self
		//! ensures: size = |self|
	Integer height (void);
		//! restores self
		//! ensures: height = height of self

	friend wostream& operator<< <T>(wostream& os, BinaryTree1& x);
		//! updates os
		//! restores x

private: // Representation
	enum {leftSubtree = 0, rightSubtree = 1};

	// Create BinaryTree's label
	class TreeLabelRecord {
	public:
		T item;
		Integer size;
		Integer height;

		TreeLabelRecord() {}
		~TreeLabelRecord() {}

		void clear(void) {
			item.clear();
			size.clear();
			height.clear();
		} // clear
		void transferFrom(TreeLabelRecord& source) {
			item.transferFrom(source.item);
			size.transferFrom(source.size);
			height.transferFrom(source.height);
		} // transferFrom

		TreeLabelRecord& operator = (TreeLabelRecord& rhs) {
			item = rhs.item;
			size = rhs.size;
			height = rhs.height;
			return *this;
		} // operator =

		friend wostream& operator<< <T>(wostream& os, TreeLabelRecord& r) {
			os << "(" << r.item << "," << r.size << "," << r.height << ")";
			return os;
		} // operator <<
	};

	typedef DagPosition1 <TreeLabelRecord, 2> TwoWayDagPosition;
	TwoWayDagPosition node;

private: // Local Operations
	inline Integer treeSize (void);
	inline Integer treeHeight (void);
	void copy (TwoWayDagPosition& from, TwoWayDagPosition& to);
	void displayRepInOrder (wostream& os, TwoWayDagPosition& root);

private: // Disallowed BinaryTree1 Operations

	BinaryTree1 (const BinaryTree1& s);
	BinaryTree1* operator & (void) {return this;};
	const BinaryTree1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

template <class T>
inline Integer BinaryTree1<T>::treeSize (void)
{
	return node.label().size;
}   // treeSize

//-----------------------------------------------------------------------

template <class T>
inline Integer BinaryTree1<T>::treeHeight (void)
{
   return node.label().height;
}   // treeHeight

//-----------------------------------------------------------------------

template <class T>
void BinaryTree1<T>::copy (
		TwoWayDagPosition& from,
		TwoWayDagPosition& to
	)
	// pre: to.label() = (T.init, 0, 0)
{
	if (!from.isZero()) {
		TreeLabelRecord label;
		TwoWayDagPosition left, right, leftCopy, rightCopy;

		from.swapWithTarget(leftSubtree, left);
		from.swapWithTarget(rightSubtree, right);
		copy(left, leftCopy);
		copy(right, rightCopy);
		from.swapWithTarget(leftSubtree, left);
		from.swapWithTarget(rightSubtree, right);

		label = from.label();
		to.labelNew(label);
		to.swapWithTarget(leftSubtree, leftCopy);
		to.swapWithTarget(rightSubtree, rightCopy);
	} // end if
} // copy

//------------------------------------------------------------

template <class T>
void BinaryTree1<T>::displayRepInOrder (wostream& os, TwoWayDagPosition& root)
{
	if (!root.isZero()) {
		Integer height = root.label().height;
		TwoWayDagPosition left = root;
		left.applyTarget(leftSubtree);
		displayRepInOrder(os, left);
		os << L" H:" << right << setw(2) << height;
		os << setw(height) << L" ";
		os << root.label() << endl;
		TwoWayDagPosition right = root;
		right.applyTarget(rightSubtree);
		displayRepInOrder(os, right);
	} // end if
}	// displayRepInOrder

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
BinaryTree1<T>::BinaryTree1 ()
{
}   // BinaryTree1

//-----------------------------------------------------------------------

template <class T>
BinaryTree1<T>::~BinaryTree1 ()
{
}   // ~BinaryTree1

//-----------------------------------------------------------------------

template <class T>
void BinaryTree1<T>::transferFrom(BinaryTree1& source)
{
	node.transferFrom(source.node);
}   // transferFrom

//-----------------------------------------------------------------------

template <class T>
BinaryTree1<T>& BinaryTree1<T>::operator = (BinaryTree1& rhs)
{
	node.clear();
	copy(rhs.node, node);
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void BinaryTree1<T>::clear (void)
{
   node.clear();
}   // clear

//-----------------------------------------------------------------------

template <class T>
void BinaryTree1<T>::compose (T& x, BinaryTree1& left, BinaryTree1& right)
{
   TreeLabelRecord label;
   Integer leftHeight, rightHeight;

   label.item.transferFrom(x);
   leftHeight = left.treeHeight();
   rightHeight = right.treeHeight();
   label.height =
      ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
   label.size = left.treeSize() + right.treeSize() + 1;
   node.labelNew(label);

   node.swapWithTarget(leftSubtree, left.node);
   node.swapWithTarget(rightSubtree, right.node);
}   // compose

//-----------------------------------------------------------------------

template <class T>
void BinaryTree1<T>::decompose (T& x, BinaryTree1& left, BinaryTree1& right)
{
   TreeLabelRecord label;

   node.replaceLabel(label);
   x.transferFrom(label.item);
   node.swapWithTarget(leftSubtree, left.node);
   node.swapWithTarget(rightSubtree, right.node);
   node.clear();
}   // decompose

//-----------------------------------------------------------------------

template <class T>
T& BinaryTree1<T>::label (void)
{
   return node.label().item;
}  // label

//-----------------------------------------------------------------------

template <class T>
Integer BinaryTree1<T>::size (void)
{
   return self.treeSize();
}   // size

//-----------------------------------------------------------------------

template <class T>
Integer BinaryTree1<T>::height (void)
{
   return self.treeHeight();
}   // height

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, BinaryTree1<T>& root)
{
#ifdef NDEBUG
	root.displayRepInOrder(os, root.node);
#else
	os << root.node << endl;
#endif
	return os;
} // operator<<
