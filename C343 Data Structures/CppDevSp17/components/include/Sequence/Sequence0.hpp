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
	//TODO: displayRep - using iteration, make it work like L5SolD.exe
	// Reference "Walking an Entire List" from Week #10's Instructional Materials

	// Notice:
	// displayRep is called by operator << when in Debug configuration (see below)

	// Write a loop to walk the linked list and display the following 3 items for each node:
	//    node's address, value field, next field
	//    for example:   os << p->value << p->next;
	// Use data member 'head' to obtain the address of the first node of the linked list
	// For example, to display the address in head use the following:
	//    os << head;
	
	NodeRecord* p;
	p = head;
	while (p != NULL) {
		os << p << p->value << p->next;
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
	//TODO: reclaimAllNodes using iteration
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// Reference "Walking an Entire List" from Week #10's Instructional Materials


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
	//TODO: copyNodes using iteration
	// Reference "Walking to the Last Node and Stopping" from Week #10's Instructional Materials

} // copyNodes

 
//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
Sequence0<T>::Sequence0 ()
	// assume: Dead(head)
{
	//TODO: Sequence0 - default constructor
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials

}	// Sequence0

//-----------------------------------------------------------------------

template <class T>
Sequence0<T>::~Sequence0 ()
	// assume: Alive(head)
{
	//TODO: ~Sequence0 - destructor
	// Utilize private operation reclaimAllNodes 

}	// ~Sequence0

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::transferFrom(Sequence0& source)
{
	//TODO: transferFrom
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials

} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Sequence0<T>& Sequence0<T>::operator = (Sequence0& rhs)
{
	//TODO: operator =
	// Utilize private operations reclaimAllNodes and copyNodes 

} // operator =

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::clear (void)
{
	//TODO: clear
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials

}	// clear

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::add (Integer pos, T& x)
{
	//TODO: add
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// add works similar to Queue's enqueue, except enqueue always adds new node at the end of the linked list

}	// add

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::remove (Integer pos, T& x)
{
	//TODO: remove
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// remove works similar to Queue's dequeue, except dequeue always removes the existing node from the front of the linked list

}	// remove

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::replaceEntry (Integer pos, T& x)
{
	//TODO: replaceEntry
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// replaceEntry works similar to Queue's replaceFront, except replaceFront always works with the first node of the linked list

}	// replaceEntry

//-----------------------------------------------------------------------

template <class T>
T& Sequence0<T>::entry (Integer pos)
{
	//TODO: entry
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// replaceEntry works similar to Queue's entry, except entry always accesses the first node of the linked list

}	// entry

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::append (Sequence0& sToAppend)
{
	//TODO: append
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// Run L5SolD.exe and have it append two sequences:
	//    Use the display operation before and after to see how the internal representation of both sequences change
	//    You have to pay close attention to the addresses of the nodes and where they end up

}	// append

//-----------------------------------------------------------------------

template <class T>
void Sequence0<T>::split (Integer pos, Sequence0& receivingS)
{
	//TODO: append
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// Run L5SolD.exe and have it split a sequence:
	//    Use the display operation before and after to see how the internal representation of both sequences change
	//    You have to pay close attention to the addresses of the nodes and where they end up

}	// split

//-----------------------------------------------------------------------

template <class T>
Integer Sequence0<T>::length (void)
{
	//TODO: length
	// Reference "Implementing a Component Using Nodes & Pointers" from Week #10's Instructional Materials
	// Reference "Walking an Entire List" from Week #10's Instructional Materials

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