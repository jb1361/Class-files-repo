#pragma once

//
// Checking version of BoundedMap 
// author: Dr. Holly
//

template <
	template <class, class, class, int> class BoundedMap,
	class K,
	class V,
	class KCallback,
	int maxSize
>
class BoundedMapChecking1:
	public BoundedMap <K, V, KCallback, maxSize>
{
	typedef BoundedMap <K, V, KCallback, maxSize> BoundedMapInstance;
public:

//-------------------------------------------------------------------

void add (K& key, V& value)
{
	// assert that |m| + 1 <= maxSize
	if (BoundedMapInstance::size() + 1 > maxSize) {
		OutputDebugString(L"Operation: add\n");
		OutputDebugString(L"Assertion failed: |m| + 1 <= maxSize\n");
		DebugBreak();
	}	// end if 

	// assert that key is not defined in map m
	if (BoundedMapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: add\n");
		OutputDebugString (L"Assertion failed: !hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	BoundedMapInstance::add (key, value);
}	// add

//-------------------------------------------------------------------

void remove (K& key, K& dCopy, V& value)
{
	// assert that key is defined in map m
	if (!BoundedMapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: remove\n");
		OutputDebugString (L"Assertion failed: hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	BoundedMapInstance::remove (key, dCopy, value);
}	// remove

//-------------------------------------------------------------------

V& value (K& key)
{
	// assert that key is defined in map m
	if (!BoundedMapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: value\n");
		OutputDebugString (L"Assertion failed: hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	return BoundedMapInstance::value(key);
}	// value

//-------------------------------------------------------------------

void removeAny (K& key, V& value)
{
	// assert that |m| > 0
	if (BoundedMapInstance::size () <= 0) {
		OutputDebugString (L"Operation: removeAny\n");
		OutputDebugString (L"Assertion failed: |m| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedMapInstance::removeAny (key, value);
}	// removeAny
};

