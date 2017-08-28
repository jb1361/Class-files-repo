#pragma once
/*
	Realization of Queue using raw nodes & pointers
	Author: Dr. Holly
*/

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Queue0
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Queue0 ();
		//! replaces self
		//! ensures: self = <>
	~Queue0 ();
	void clear (void);
		//! clears self
	void transferFrom (Queue0& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Queue0& operator = (Queue0& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Queue0 Specific Operations
	void enqueue (T& x);
		//! updates self
		//! clears x
		//! ensures: self = #self + <#x>
	void dequeue (T& x);
		//! updates self
		//! replaces x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and  
		//!          self = #self[1,|#self|)
	void replaceFront (T& x);
		//! updates self, x
		//! requires: self /= <>
		//! ensures: x is prefix of #self and
		//!          self = <#x> * #self[1,|#self|)
	T& front(void);
		//! restores self
		//! requires: self /= <>
		//! ensures: <front> is prefix of self
	Integer length (void);
		//! restores self
		//! ensures: length = |self|

	friend wostream& operator<< <T>(wostream& os, Queue0<T>& q);
		//! updates os
		//! restores q

private: // Representation

	class NodeRecord {
	public:
		T value;
		NodeRecord* next;
	};

	NodeRecord* head;

private: // Local Operations
	Integer countNodes (NodeRecord* p);
	void copyNodes (NodeRecord*& toHead, NodeRecord* fromHead);
	void reclaimAllNodes (NodeRecord*& p);
	void displayRep (wostream& os);

private: // Disallowed Queue0 Operations
	Queue0 (const Queue0& s);
	Queue0* operator & (void) {return this;};
	const Queue0* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

template <class T>
Integer Queue0<T>::countNodes (NodeRecord* p)
	// ensures: countNodes = number of nodes in linked list starting with node located at address p;
{
	if (p != NULL) {
		return countNodes(p->next) + 1;
	} else {
		return 0;
	} // end if
}	// countNodes

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::copyNodes (NodeRecord*& toP, NodeRecord* fromP)
{
	if (fromP == NULL) {
		toP = NULL;
	} else {
		toP = new NodeRecord;

		toP->value = fromP->value;
		copyNodes(toP->next, fromP->next);
	} // end if
} // copyNodes

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::reclaimAllNodes (NodeRecord*& p)
	// ensures: p = NULL;
{
	if (p != NULL) {
		reclaimAllNodes(p->next);
		delete p;
	} // end if
}	// reclaimAllNodes

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::displayRep (wostream& os)
{
	NodeRecord* p;
	Integer c;

	os << L"&head: " << &head << endl;
	os << L" head: " <<  head << endl;
	c = 1;
	p = head;
	while (p != NULL) {
		os << L" Node: #" << c;
		os << L" Address: " << p;
		os << L"\t(" << p->value;
		os << L", " << p->next << L")" << endl;
		p = p->next;
		c++;
	}	// end while
}	// displayRep

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Queue0<T>::Queue0 ()
{
	head = NULL;
}	// Queue0

//-----------------------------------------------------------------------

template <class T>
Queue0<T>::~Queue0 ()
{
	reclaimAllNodes(head);
}	// ~Queue0

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::clear(void)
{
	reclaimAllNodes(head);
	head = NULL;
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::transferFrom(Queue0& source)
{
	reclaimAllNodes(head);
	head = source.head;
	source.head = NULL;
}	// transferFrom

//-----------------------------------------------------------------------

template <class T>
Queue0<T>& Queue0<T>::operator = (Queue0& rhs)
{
	reclaimAllNodes(head);
	copyNodes(head, rhs.head);
	return *this;
}	// operator =

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::enqueue (T& x)
{
	NodeRecord* newNode = new NodeRecord;

	newNode->value.transferFrom(x);
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	} else {
		NodeRecord* p;

		p = head;
		while (p->next != NULL) {
			p = p->next;
		}	// end while
		p->next = newNode;
	} // end if
}	// enqueue

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::dequeue (T& x)
{
	NodeRecord* existingNode;

	existingNode = head;
	x.transferFrom(existingNode->value);
	head = existingNode->next;
	delete existingNode;
}	// dequeue

//-----------------------------------------------------------------------

template <class T>
void Queue0<T>::replaceFront(T& x)
{
	T temp;

	temp.transferFrom(head->value);
	head->value.transferFrom(x);
	x.transferFrom(temp);
}	// replaceFront

//-----------------------------------------------------------------------

template <class T>
T& Queue0<T>::front(void)
{
	return head->value;
}  // front

//-----------------------------------------------------------------------

template <class T>
Integer Queue0<T>::length (void)
{
	return countNodes(head);
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, Queue0<T>& q)
{
#ifdef NDEBUG
	Queue0<T> temp;

	os << L"<";

	for (int k = 0, z = q.length(), lastItem = z - 1; k < z; k++) {
		T x;

		q.dequeue(x);
		os << x;
		temp.enqueue(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";
	q.transferFrom(temp);
#else
	q.displayRep(os);
#endif
	return os;
}

