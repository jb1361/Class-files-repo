#include "Wrapper.h"
#include "AirportRecord.h"
#include "AirportSequence.h"



void doDisplayAirportData(AirportSequence& s);
	//! restores s
	//! ensures: for each record in s, use wcout to display the record 
	//!          on a separate line

void doInputAirportDataFromFile(AirportSequence& s, Text& filename);
//! replaces s
//! restores filename
//! ensures: loads into s all the airport records 
//!          from the airport data file named filename
//!          the order of the records stored in s does not matter



int main(int argc, char* argv[])
{
	AirportSequence s1;
	Text filename = "air15.dat";
	doInputAirportDataFromFile(s1,filename);
	doDisplayAirportData(s1);
	system("pause");
	return 0;
}


void doInputAirportDataFromFile(AirportSequence& s, Text& filename) {

	File input;
	Boolean successful;
	AirportRecord r;
	Integer dataSize;

	input.openFile(filename, File::openForRead, successful);

	if (successful) {
		input.read(dataSize, successful);
		for (int j = 0; j < dataSize; j++) {
			input.read(r.iata, successful);
			input.read(r.name, successful);
			input.read(r.city, successful);
			input.read(r.country, successful);
			input.read(r.latDegrees, successful);
			input.read(r.latMinutes, successful);
			input.read(r.latSeconds, successful);
			input.read(r.latDirection, successful);
			input.read(r.longDegrees, successful);
			input.read(r.longMinutes, successful);
			input.read(r.longSeconds, successful);
			input.read(r.longDirection, successful);
			input.read(r.altitude, successful);
			s.add(0, r);

		} // end for
		input.closeFile(successful);
	} // end if
	else {
		wcout << "File Not Found." << endl;
	}
} // doInputPersonDataFromFile>
  //
void doDisplayAirportData(AirportSequence& s) {
	//! restores s
	//! ensures: for each record in s, use wcout to display the record 
	//!          on a separate line

	AirportRecord r;
	for (int i = 0; i < s.length(); i++) {
		r.iata = s.entry(i).iata;
		r.name = s.entry(i).name;
		r.city = s.entry(i).city;
		r.country = s.entry(i).country;
		r.latDegrees = s.entry(i).latDegrees;
		r.latMinutes = s.entry(i).latMinutes;
		r.latSeconds = s.entry(i).latSeconds;
		r.latDirection = s.entry(i).latDirection;
		r.longDegrees = s.entry(i).longDegrees;
		r.longMinutes = s.entry(i).longMinutes;
		r.longSeconds = s.entry(i).longSeconds;
		r.longDirection = s.entry(i).longDirection;
		r.altitude = s.entry(i).altitude;

		wcout << r << endl;
	}

}


