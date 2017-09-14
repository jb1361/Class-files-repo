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

	friend wostream& operator << (wostream &os, AirportRecord& r)
	{
		os << "(" << r.iata << "," << r.name << "," << r.city << "," << r.country << "," << r.latDegrees << ","
			<< r.latMinutes << "," << r.latSeconds << "," << r.latDirection << "," << r.longDegrees << "," << r.longMinutes << ","
			<< r.longSeconds << "," << r.longDirection << "," << r.altitude << ")";
		return os;
	} // operator <<
};