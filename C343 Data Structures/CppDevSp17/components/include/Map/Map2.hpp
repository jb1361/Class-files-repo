#pragma once
// TODO:
// After you are satisfied that your Map2 implementation is working correctly,
// then comment out the #pragma line below and recompile - if you get compiler error messages, then fix them
#pragma warning( disable : 4716)

// author: Justin Butler
#include "StaticArray\StaticArray1.hpp"
#include "Queue\Queue1.hpp"


//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
class Map2
	//! Map2 is modeled by PARTIAL_FUNCTION
	//! math subtype PARTIAL_FUNCTION is finite set of
	//!                  key: K
	//!                  value: V
	//!             exemplar m
	//!             constraint
	//!                for all   key: K, r1, r2: V
	//!                          where (key, r1) is in m
	//!                          and   (key, r2) is in m then (r1 = r2)
	//! 
	//!          math operation DOMAIN(m: PARTIAL_FUNCTION): finite set of K satisfies
	//!                         for all key: K (key is in DOMAIN(m) iff 
	//!                         there exists value: V ((key, value) is in m))

	//! exemplar self
{
public: // standard Operations
	Map2();
	//! replaces self
	//! ensures: self = { }
	~Map2();
	void clear(void);
	//! clears self
	void transferFrom(Map2& source);
	//! replaces self
	//! clears source
	Map2& operator = (Map2& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// Map2 Specific Operations
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
	//! updates self
	//! replaces key, value
	//! requires: |self| > 0
	//! ensures: (key, value) is in #self  and  self = #self \ {(key, value)}
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

	friend wostream & operator<< <K, V, KCompare>(wostream &os, Map2& m);
	//! updates os
	//! restores m

private: // representation

		// MapPairRecord has two data members: keyItem and valueItem
		// These will hold the key and value items that the client wants to add to the Map
		// Once the key and value items have been transfered to a MapPairRecord r, then r 
		// to one of the queues in the array of queues 
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

		void clear(void)
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

private: // internal representation

	enum hashTableBounds {
		 lower = 0,
		 upper = 4,
		 arraySize
	};
	
	typedef Queue1<MapPairRecord> QueueOfMapPair;
	typedef StaticArray1<QueueOfMapPair,lower, upper> ArrayOfQueues;

	ArrayOfQueues map;
	Integer mapSize;

	// Correspondence
	// self = IteratedUnion (b:Integer 0 <= b < arraySize, k:Integer 0 <= k < |map(b)|, map(b)[k,k+1))

private: // disallowed Map2 Operations
	Map2(const Map2& m);
	Map2* operator & (void) { return (this); };
	const Map2* operator & (void) const { return (this); };
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------


template <class K, class V, class KCompare>
Map2<K, V, KCompare>::Map2()
{
	// DONE:
	// The constructors for the data members map and mapSize automatically get called
}	// Map2

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Map2<K, V, KCompare>::~Map2()
{
	// DONE:
	// The destructors for the data members map and mapSize automatically get called
}	// ~Map2

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map2<K, V, KCompare>::transferFrom(Map2& source)
{
	// TODO: finish me
	// This is a "call through" situation
	// If you are not sure what to do here then
	//    reread Week #4's Implementation #1 for Layering a Component instructional materials 
	//    and specifically look at the notes for transferFrom
	map.transferFrom(source);
	mapSize = 0;
} // transferFrom

  //-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Map2<K, V, KCompare>& Map2<K, V, KCompare>::operator = (Map2& rhs)
{
	map = rhs.map;
	mapSize = rhs.mapSize;
} // operator =

  //-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map2<K, V, KCompare>::clear(void)
{
	map.clear();
	mapSize = 0;
}	// clear

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map2<K, V, KCompare>::add(K& key, V& value)
{
	Integer bucket = KCompare::hashCode(key) % hashTableBounds::arraySize;
	MapPairRecord newPair;

	newPair.keyItem.transferFrom(key);
	newPair.valueItem.transferFrom(value);
	map[bucket].enqueue(newPair);
	mapSize++;
}  // add
	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map2<K, V, KCompare>::remove(K& key, K& keyFromMap, V& valueFromMap)
{
	// TODO: finish me

	// Reread Week #7's "Map - Hashing Implementation - Using StaticArray and Queue" instructional material
	// This is a linear search of the bucket for the (keyFromMap, valueFromMap) pair using parameter key
	// You must call the call back operation KCompare::areEqual to compare two key values
	Integer bucket = KCompare::hashCode(key) % hashTableBounds::arraySize;
	for (int i = 0; i < mapSize; i++)
	{

		keyInMap = map[i];
		keyHash = KCompare::hashCode(key) % hashTableBounds::arraySize;
		if (KCompare::areEqual(bucket, keyHash)) {
			keyFromMap = keyInMap;
			valueFromMap = map.items;
		}
	}
}	// remove

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
V& Map2<K, V, KCompare>::value(K& key)
{
	// TODO: finish me

	// Functions must have a return statement to be implemented correctly

	// Reread Week #7's "Map - Hashing Implementation - Using StaticArray and Queue" instructional material
	// This is a linear search of the bucket for the matching (key, value) pair 
	// in the incoming hash table using parameter key
	// You must call the call back operation KCompare::areEqual to compare two key values

	// Reread Week #4's Implementation #1 for Layering a Component instructional materials 
	// for how to return a V& type value

}  // value

   //-----------------------------------------------------------------------

template <class K, class V, class KCompare>
void Map2<K, V, KCompare>::removeAny(K& key, V& value)
{
	// TODO: finish me

	// Reread Week #7's "Map - Hashing Implementation - Using StaticArray and Queue" instructional material
	// This is not a seach based on a 'key' value
	// removeAny must just find any (key, value) pair in the incoming hash table and 
	// produce those values back to the caller through the key and value parameters
	

}	// removeAny

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Boolean Map2<K, V, KCompare>::hasKey(K& key)
{
	// TODO: finish me

	// Functions must have a return statement to be implemented correctly

	// Reread Week #7's "Map - Hashing Implementation - Using StaticArray and Queue" instructional material
	// This is a linear search of the bucket for a matching (key, value) pair 
	// in the incoming hash table using parameter key
	// If a matching (key, value) pair is found, then return true, otherwise return false

	// You must call the call back operation KCompare::areEqual to compare two key values

}	// hasKey

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
Integer Map2<K, V, KCompare>::size(void)
{
	// TODO: finish me

	// Functions must have a return statement to be implemented correctly
	// Utilize the mapSize data member here

}	// size

	//-----------------------------------------------------------------------

template <class K, class V, class KCompare>
wostream & operator<<(wostream &os, Map2<K, V, KCompare>& m)
{
#ifdef NDEBUG
	// Notice that the Release version of operator << calls 6 different Map operations. 
	// So this code operation will display the abstract value of a Map variable
	// only when those 6 operations are working correctly
	Map2<K, V, KCompare> temp;

	os << "{";
	for (int i = 0, z = m.size(), lastItem = z - 1; i < z; i++) {
		K key;
		V value;

		m.removeAny(key, value);
		os << "(" << key << "," << value << ")";
		if (i < lastItem) {
			os << ",";
		} // end if
		temp.add(key, value);
	}	// end for
	os << "}";
	m.transferFrom(temp);
#else
	// For testing and debugging, display the internal representation for the Map
	 os << "(" << m.mapSize << "," << m.map << ")";
#endif

	return (os);
} // operator<<
