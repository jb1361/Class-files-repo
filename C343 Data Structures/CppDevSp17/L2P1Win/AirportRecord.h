#pragma once
#include "Wrapper.h"

class AirportRecord {
public:

	Text iata;
	Text name;
	Text city;
	Text country;
	Integer	latDegrees;
	Integer latMinutes;
	Integer latSeconds;
	Text latDirection;
	Integer longDegrees;
	Integer longMinutes;
	Integer longSeconds;
	Text longDirection;
	Integer altitude;


	// Standard Operations

	AirportRecord() {}
	~AirportRecord() {}

	void clear(void)
	{
		iata.clear();
		name.clear();
		city.clear();
		country.clear();
		latDegrees.clear();
		latMinutes.clear();
		latSeconds.clear();
		latDirection.clear();
		longDegrees.clear();
		longMinutes.clear();
		longSeconds.clear();
		longDirection.clear();
		altitude.clear();
	} // clear

	AirportRecord& operator = (AirportRecord& rhs)
	{
		iata = rhs.iata;
		name = rhs.name;
		city = rhs.city;
		country = rhs.country;
		latDegrees = rhs.latDegrees;
		latMinutes = rhs.latMinutes;
		latSeconds = rhs.latSeconds;
		latDirection = rhs.latDirection;
		longDegrees = rhs.longDegrees;
		longMinutes = rhs.longMinutes;
		longSeconds = rhs.longSeconds;
		longDirection = rhs.longDirection;
		altitude = rhs.altitude;

		return *this;
	} // operator =

	void transferFrom(AirportRecord& source)
	{
		iata.transferFrom(source.iata);
		name.transferFrom(source.name);
		city.transferFrom(source.city);
		country.transferFrom(source.country);
		latDegrees.transferFrom(source.latDegrees);
		latMinutes.transferFrom(source.latMinutes);
		latSeconds.transferFrom(source.latSeconds);
		latDirection.transferFrom(source.latDirection);
		longDegrees.transferFrom(source.longDegrees);
		longMinutes.transferFrom(source.longMinutes);
		longSeconds.transferFrom(source.longSeconds);
		longDirection.transferFrom(source.longDirection);
		altitude.transferFrom(source.altitude);

	} // transferFrom

	void addToTextFromInt(Text &s, char* source) {
		char* cPos = source;
		while (*cPos) {
			if (*cPos == ' ') break;
			else s.add(s.size(), *cPos);
			cPos++;
		}
		s.add(s.size(), ',');
		s.add(s.size(), ' ');
	}
	
	void addToTextFromChar(Text &s, Text &source) {
		s.add(s.size(), '"');
		for (int i = 0; i < source.size(); i++) {
			s.add(s.size(), source[i]);
		}
		s.add(s.size(), '"');
		s.add(s.size(), ',');
		s.add(s.size(), ' ');
	}

	void toString(AirportRecord& source, Text &s) {
		s.add(s.size(), '(');
		const int bufferSize = 32;
		char cString[bufferSize];
		int i;
		addToTextFromChar(s, source.iata);	
		addToTextFromChar(s, source.name);
		addToTextFromChar(s, source.city);
		addToTextFromChar(s, source.country);		
		sprintf_s(cString, bufferSize, "%d", (int)source.latDegrees);
		addToTextFromInt(s, cString);
		sprintf_s(cString, bufferSize, "%d", (int)source.latMinutes);
		addToTextFromInt(s, cString);
		sprintf_s(cString, bufferSize, "%d", (int)source.latSeconds);	
		addToTextFromInt(s, cString);
		addToTextFromChar(s, source.latDirection);
		sprintf_s(cString, bufferSize, "%d", (int)source.longDegrees);
		addToTextFromInt(s, cString);
		sprintf_s(cString, bufferSize, "%d", (int)source.longMinutes);
		addToTextFromInt(s, cString);		
		sprintf_s(cString, bufferSize, "%d", (int)source.longSeconds);
		addToTextFromInt(s, cString);
		addToTextFromChar(s, source.longDirection);
		sprintf_s(cString, bufferSize, "%d", (int)source.altitude);
		addToTextFromInt(s, cString);
		//Since the record always ends with altitude there will be a , and a space at the end so we remove those and add a ).
		Character c;
		s.remove(s.size()-1, c);
		s.remove(s.size()-1, c);
		s.add(s.size(), ')');
	}


	friend wostream& operator << (wostream &os, AirportRecord& r)
	{
		os << "(" << r.iata << "," << r.name << "," << r.city << "," << r.country << "," << r.latDegrees << ","
			<< r.latMinutes << "," << r.latSeconds << "," << r.latDirection << "," << r.longDegrees << "," << r.longMinutes << ","
			<< r.longSeconds << "," << r.longDirection << "," << r.altitude << ")";
		return os;
	} // operator <<
};