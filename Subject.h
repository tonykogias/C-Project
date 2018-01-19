#include <string>
#include "Semister.h"
#include "Proffessor.h"

using namespace std;

class Subject {
	
	private:
		string title; //Subject title
		Semister sem;
		Proffessor prof; //Proffessor subject
		string direction; //Kateuthinsi mathimatos

	public:
		Subject(); //costructor
		void readData();
		void printData();
		string getDirection() {return direction;};
		string getTitle() {return title;};
		Proffessor getProf() {return prof;};
		Semister getSem() {return sem;};
		
		
};
