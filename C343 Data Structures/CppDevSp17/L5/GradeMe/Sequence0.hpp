#pragma once
// TODO:
// After you are satisfied that your Sequence0 implementation is working correctly,
// then comment out the #pragma line below and recompile - if you get compiler error messages, then fix them
#pragma warning( disable : 4716)

//
// realization of Sequence Template implemented using raw C++ nodes & pointers
// author: TODO: *** put your name here ***
//


//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Sequence0
	//! is modeled by string(T)
	//!   exemplar self
{
public: // standard Operations
	Sequence0();
	//! replaces self
	//! ensures: self = <>
	~Sequence0();
	void clear(void);
	//! clears self
	void transferFrom(Sequence0& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	Sequence0& operator = (Sequence0& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// Sequence0 Specific Operations
	void add(Integer pos, T& x);
	//! updates self
	//! restores pos
	//! clears x
	//! requires: 0 <= pos <= |self|
	//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
	void remove(Integer pos, T& x);
	//! updates self
	//! restores pos
	//! replaces x
	//! requires: 0 <= pos < |self|
	//! ensures: <x> = #self[pos, pos+1) and
	//!          self = #self[0, pos) * #self[pos+1, |#self|)
	void replaceEntry(Integer pos, T& x);
	//! updates self, x
	//! restores pos
	//! requires: 0 <= pos < |self|
	//! ensures: <x> = #self[pos, pos+1)  and
	//!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
	T& entry(Integer pos);
	//! restores self, pos
	//! requires: 0 <= pos < |self|
	//! ensures: <entry> = self[pos, pos+1)
	void append(Sequence0& sToAppend);
	//! updates self
	//! clears sToAppend
	//! ensures: self = #self * sToAppend
	void split(Integer pos, Sequence0& receivingS);
	//! updates self
	//! restores pos
	//! replaces receivingS
	//! requires: 0 <= pos <= |self|
	//! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
	Integer length(void);
	//! restores self
	//! ensures: length = |self|

	friend wostream& operator<< <T>(wostream& os, Sequence0& s);
	//! updates os
	//! restores s

private: // representation
	class NodeRecord{
		public:
			T value;
			NodeRecord* next;
		};
	NodeRecord* head;

private: // local Operations
	void displayRep(wostream &os);
	void reclaimAllNodes (NodeRecord* h);
	void copyNodes(NodeRecord*& toP, NodeRecord* fromP);


private: // disallowed Sequence0 Operations
	Sequence0* operator & (void) {return (this);};
	const Sequence0* operator & (void) const {return (this);};
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// local Operations
//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::displayRep(wostream &os)
//! ensures: displays the linked list like L5SolD.exe does
{	
	NodeRecord* p = new NodeRecord;
	p = head;
	while (p != NULL) {
		os << "Address: " << p;
		os << " Value: " << p->value;
		os << " Next Address: " << p->next << endl;
		p = p->next;
	}

} // displayRep

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::reclaimAllNodes (NodeRecord* h)
	// requires: Alive(h) || Null(h)
	// ensures: all storage allocated to nodes in the linked list are reclaimed
	//          starting with the node addressed by h
	//          Must use iteration, not recursion
{
	if (h != NULL) {
		reclaimAllNodes(h->next);
		delete (h);
	}
} // reclaimAllNodes

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::copyNodes(NodeRecord*& toP, NodeRecord* fromP)
// produces: toP
// requires: Alive(fromP) || Null(fromP)
// ensures: a deep copy of the linked list addressed by fromP is created
//          the address of the 1st node in the new linked list is produced through toP
//          fromP's linked list is left unchanged
//          Use the assignment operator to copy the value found in the node's value field
//          Must use iteration, not recursion
{
	if (fromP == NULL) {
		toP = NULL;
	}
	else {
		toP = new NodeRecord;

		toP->value = fromP->value;
		copyNodes(toP->next, fromP->next);
	} // end if
} // copyNodes

 
//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
Sequence0<T>::Sequence0 ()
	// assume: Dead(head)
{
	head = NULL;
}	// Sequence0

//-----------------------------------------------------------------------

template <class T>
Sequence0<T>::~Sequence0 ()
	// assume: Alive(head)
{
	reclaimAllNodes(head);
}	// ~Sequence0

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::transferFrom(Sequence0& source)
{
	reclaimAllNodes(head);
	head = source.head;
	source.head = NULL;
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Sequence0<T>& Sequence0<T>::operator = (Sequence0& rhs)
{
	reclaimAllNodes(head);
	copyNodes(head, rhs.head);
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::clear (void)
{
	reclaimAllNodes(head);
	head = NULL;
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::add (Integer pos, T& x)
{
	NodeRecord* newNode = new NodeRecord;
	newNode->value.transferFrom(x);
	newNode->next = NULL;

	if (head == NULL) head = newNode;
	else {
		//go to node at pos
		NodeRecord* t;
		t = head;
		Integer len = 0;
		//getitng the length
		while (t != NULL) {
			t = t->next;
			len++;
		}
		
		NodeRecord* p = head;
		Integer i = 0;
		pos = len - pos;
		
		while (i < pos-1) {
			p = p->next;
			i++;
		}
		NodeRecord* h;
		h = p->next;
		newNode->next = h;
		p->next = newNode;
		

	}//end else
}	// add

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::remove (Integer pos, T& x)
{
	NodeRecord* t;
	t = head;
	Integer len = 0;
	//getitng the length
	while (t != NULL) {
		t = t->next;
		len++;
	}
	NodeRecord* p = head;
	NodeRecord* newNode = new NodeRecord;
	newNode->next = NULL;
	Integer i = 0;
	pos = (len - pos) - 1;
	while (i < pos) {
		if ((pos - i) == 1) newNode = p;
		p = p->next;
		i++;
	}
	if (i == 0) {
		x.transferFrom(head->value);
		head = head->next;
		delete p;
	}
	else {
		x.transferFrom(p->value);
		p = p->next;
		newNode->next = p;
	}
}	// remove

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::replaceEntry (Integer pos, T& x)
{
	NodeRecord* t;
	t = head;
	Integer len = 0;
	//getitng the length
	while (t != NULL) {
		t = t->next;
		len++;
	}
	NodeRecord* p;
	p = head;
	Integer i = 0;
	pos = (len - pos) - 1;
	while (i < pos) {
		p = p->next;
		i++;
	}
	T temp;

	temp.transferFrom(p->value);
	p->value.transferFrom(x);
	x.transferFrom(temp);
}	// replaceEntry

//-----------------------------------------------------------------------

template <class T>
T& Sequence0<T>::entry (Integer pos)
{
	NodeRecord* t;
	t = head;
	Integer len = 0;
	//getitng the length
	while (t != NULL) {
		t = t->next;
		len++;
	}
	NodeRecord* p;
	p = head;
	Integer i = 0;
	pos = (len - pos) - 1;
	while (i < pos) {
		p = p->next;
		i++;
	}
	return p->value;
}	// entry

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::append (Sequence0& sToAppend)
{
	NodeRecord* p;
	if (head == NULL) {
		head = sToAppend.head;	
	}
	else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = sToAppend.head;

	}
	sToAppend.head = NULL;
}	// append

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::split (Integer pos, Sequence0& receivingS)
{
	NodeRecord* t;
	t = head;
	Integer len = 0;
	//getitng the length
	while (t != NULL) {
		t = t->next;
		len++;
	}
	NodeRecord* p;
	p = head;
	Integer i = 0;
	
	pos = (len - pos);
	while (i < pos) {
		receivingS.add(0,p->value);
		p = p->next;
		head = p;
		i++;
	}


}	// split

//-----------------------------------------------------------------------

template <class T>
Integer Sequence0<T>::length (void)
{
	NodeRecord* p;
	p = head;
	Integer i;
	i = 0;
	while (p != NULL) {
		p = p->next;
		i++;
	}
	return i;
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, Sequence0<T>& s)
{
#ifdef NDEBUG
	os << "<";
	for (int p = 0, z = s.length(), lastItem = z - 1; p < z; p++) {
		T x;

		s.remove(p, x);
		os << x;
		s.add(p, x);
		if (p < lastItem) {
			os << ",";
		} // end if
	} // end for
	os << ">";
#else
	s.displayRep(os);
#endif

	return (os);
} // operator<<