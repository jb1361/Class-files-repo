#pragma once

//
// Checking version of Map 
// author: Dr. Holly
//

template <
	template <class, class, class> class Map,
	class K,
	class V,
	class KCallback
>
class MapChecking1:
	public Map <K, V, KCallback>
{
	typedef Map <K, V, KCallback> MapInstance;
public:

//-------------------------------------------------------------------

void add (K& key, V& value)
{
	// assert that key is not defined in map m
	if (MapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: add\n");
		OutputDebugString (L"Assertion failed: !hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	MapInstance::add (key, value);
}	// add

//-------------------------------------------------------------------

void remove (K& key, K& dCopy, V& value)
{
	// assert that key is defined in map m
	if (!MapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: remove\n");
		OutputDebugString (L"Assertion failed: hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	MapInstance::remove (key, dCopy, value);
}	// remove

//-------------------------------------------------------------------

V& value (K& key)
{
	// assert that key is defined in map m
	if (!MapInstance::hasKey (key)) {
		OutputDebugString (L"Operation: value\n");
		OutputDebugString (L"Assertion failed: hasKey(key)\n");
		DebugBreak ();
	}	// end if 

	return MapInstance::value(key);
}	// value

//-------------------------------------------------------------------

void removeAny (K& key, V& value)
{
	// assert that |m| > 0
	if (MapInstance::size () <= 0) {
		OutputDebugString (L"Operation: removeAny\n");
		OutputDebugString (L"Assertion failed: |m| > 0\n");
		DebugBreak ();
	}	// end if 

	MapInstance::removeAny (key, value);
}	// removeAny
};

