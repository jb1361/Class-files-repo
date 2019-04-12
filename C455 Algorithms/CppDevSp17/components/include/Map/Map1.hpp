#pragma once

//
// Realization of Map layered on Chain Position
// author: Dr. Holly
//

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
class Map1
		//! is modeled by PARTIAL_FUNCTION
		//! math subtype PARTIAL_FUNCTION is finite set of
		//!                 key: K
		//!                 value: V
		//!            exemplar m
		//!            constraint
		//!               for all key: K
		//!               (for all r1, r2: V
		//!                         (((key, r1) is in m
		//!                         and  (key, r2) is in m) implies (r1 = r2)))
		//! 
		//!          math operation DOMAIN(m: PARTIAL_FUNCTION): finite set of K satisfies
		//!                        for all key: K (key is in DOMAIN(m) iff 
		//!                        there exists value: V ((key, value) is in m))

		//! exemplar self
{
public: // Standard Operations
	Map1 ();
		//! replaces self
		//! ensures: self = { }
	~Map1 ();
	void clear (void);
		//! clears self
	void transferFrom (Map1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Map1& operator = (Map1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Map1 Specific Operations
	void add (K& key, V& value);
		//! updates self
		//! clears key, value
		//! requires: key is not in DOMAIN(self)
		//! ensures: self = #self  union  {(#key, #value)}
	void remove (K& key, K& keyFromMap, V& valueFromMap);
		//! updates self
		//! restores key
		//! replaces  keyFromMap, valueFromMap
		//! requires: key is in DOMAIN(self)
		//! ensures: (key, valueFromMap) is in #self  and
		//!          self = #self \ {(keyFromMap, valueFromMap)}  and  keyFromMap = key
	V& value (K& key);
		//! restores self, key
		//! requires: key is in DOMAIN(self)
		//! ensures: (key, value) is in self
	void removeAny (K& key, V& value);
		//! updates self
		//! replaces key, value
		//! requires: |self| > 0
		//! ensures: (key, value) is in #self  and  self = #self \ {(key, value)}
	Boolean hasKey (K& key);
		//! restores  self
		//! restores key
		//! ensures: hasKey = (key is in DOMAIN(self))
	Integer size (void);
		//! restores self
		//! ensures: size = |self|

	friend wostream& operator<< <K, V, KCallback>(wostream& os, Map1& m);
		//! updates os
		//! restores q

private: // Representation
	class MapPairRecord {
	public:
		K keyItem; 
		V valueItem;

		MapPairRecord() {}
		MapPairRecord(K& key, V& value) 
		{
			keyItem.transferFrom(key);
			valueItem.transferFrom(value);
		} // MapPairRecord
		~MapPairRecord() {}

		void clear (void)
		{
			keyItem.clear();
			valueItem.clear();
		} // clear
		MapPairRecord& operator = (MapPairRecord& rhs)
		{
			keyItem = rhs.keyItem;
			valueItem = rhs.valueItem;
			return *this;
		} // operator =
		void transferFrom(MapPairRecord& source) 
		{
			keyItem.transferFrom(source.keyItem);
			valueItem.transferFrom(source.valueItem);
		}

		friend wostream& operator <<(wostream& os, MapPairRecord& r)
		{
			os << L"(" << r.keyItem << L"," << r.valueItem << L")";
			return os;
		}
	};

private: // Representation
	typedef ChainPosition1 <MapPairRecord> ChainPositionOfMapPair;

	ChainPositionOfMapPair chain;
	Integer mapSize;

private: // Disallowed Map1 Operations
	Map1 (const Map1& s);
	Map1* operator & (void) {return this;};
	const Map1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

// convention: chain == smartPosition

template <class K, class V, class KCallback>
Map1<K, V, KCallback>::Map1 ()
{
	ChainPositionOfMapPair smartPosition;
	MapPairRecord label;

	smartPosition.labelNew (label);
	chain.transferFrom(smartPosition);
}	// Map1

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
Map1<K, V, KCallback>::~Map1 ()
{
}	// ~Map1

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
void Map1<K, V, KCallback>::clear(void)
{
	ChainPositionOfMapPair smartPosition;
	MapPairRecord label;

	chain.clear();
	smartPosition.labelNew(label);
	chain.transferFrom(smartPosition);
	mapSize = 0;
}	// clear

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
void Map1<K, V, KCallback>::transferFrom(Map1& source)
{
	chain.transferFrom(source.chain);
	mapSize.transferFrom(source.mapSize);
} // transferFrom

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
Map1<K, V, KCallback>& Map1<K, V, KCallback>::operator = (Map1& rhs)
{
	ChainPositionOfMapPair newPos, oldPos, current;
	MapPairRecord x;

	current.labelNew (x);
	chain = current;

	oldPos = rhs.chain;
	oldPos.applyTarget ();
	while (!oldPos.isZero ()) {
		x = oldPos.label();
		newPos.labelNew (x);
		current.swapWithTarget (newPos);
		current.applyTarget ();
		oldPos.applyTarget ();
	} // end while
	mapSize = rhs.mapSize;

	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
void Map1<K, V, KCallback>::add (K& key, V& value)
{
	MapPairRecord newPair (key, value);
	ChainPositionOfMapPair newPosition;
	ChainPositionOfMapPair firstPosition;

	chain.swapWithTarget (firstPosition);

	newPosition.labelNew (newPair);
	newPosition.swapWithTarget (firstPosition);
	chain.swapWithTarget (newPosition);

	mapSize++;
}	// add

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
void Map1<K, V, KCallback>::remove (K& key, K& keyFromMap, V& valueFromMap)
{
	ChainPositionOfMapPair trailingPosition;
	ChainPositionOfMapPair currentPosition;
	MapPairRecord existingPair;

	trailingPosition = chain;
	currentPosition = trailingPosition;
	currentPosition.applyTarget ();

	while (!KCallback::areEqual (key, currentPosition.label().keyItem)) {
		trailingPosition = currentPosition;
		currentPosition.applyTarget ();
	}  // end while
	currentPosition.replaceLabel (existingPair);

	currentPosition.applyTarget ();
	trailingPosition.swapWithTarget (currentPosition);

	keyFromMap.transferFrom(existingPair.keyItem);
	valueFromMap.transferFrom(existingPair.valueItem);

	mapSize--;
}	// remove

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
V& Map1<K, V, KCallback>::value (K& key)
{
	ChainPositionOfMapPair currentPosition;

	currentPosition = chain;
	currentPosition.applyTarget ();

	while (!KCallback::areEqual (key, currentPosition.label().keyItem)) {
		currentPosition.applyTarget ();
	}  // end while
	return currentPosition.label().valueItem;
}  // value

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
void Map1<K, V, KCallback>::removeAny (K& key, V& value)
{
	ChainPositionOfMapPair position;
	MapPairRecord existingPair;

	position = chain;
	position.applyTarget ();

	position.replaceLabel (existingPair);
	position.applyTarget ();
	chain.swapWithTarget (position);

	key.transferFrom(existingPair.keyItem);
	value.transferFrom(existingPair.valueItem);

	mapSize--;
}	// removeAny

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
Boolean Map1<K, V, KCallback>::hasKey (K& key)
{
	ChainPositionOfMapPair position;

	position = chain;
	position.applyTarget ();

	while (!position.isZero () && !KCallback::areEqual (key, position.label().keyItem)) {
		position.applyTarget ();
	}	// end while

	return !position.isZero ();
}	// hasKey

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
Integer Map1<K, V, KCallback>::size (void)
{
	return mapSize;
}	// size

//-----------------------------------------------------------------------

template <class K, class V, class KCallback>
wostream& operator<<(wostream& os, Map1<K, V, KCallback>& m)
{
	Map1<K, V, KCallback> temp;

	os << L"{";
	for (int k = 0, z = m.size(), lastItem = z - 1; k < z; k++) {
		K key;
		V value;

		m.removeAny (key, value);
		os << L"(" << key << L"," << value << L")";
		if (k < lastItem) {
			os << L",";
		} // end if
		temp.add (key, value);
	}	// end for
	os << L"}";
	m.transferFrom(temp);

	return os;
} // operator<<
