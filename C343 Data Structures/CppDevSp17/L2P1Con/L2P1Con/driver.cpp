#include "Wrapper.h"
#include "AirportRecord.h"
#include "AirportSequence.h"


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
int main(int argc, char* argv[])
{

	
	AirportSequence s1;
	Text filename = "air15.dat";
//	// load data from a file
	doInputAirportDataFromFile(s1,filename);

	//wcout << s1 << endl;

	return 0;
}