#include <string>

using namespace std;

class Proffessor {
	
	private:
		string name;//name of proffessor
	public:
		Proffessor() {name="";};//constructor
		Proffessor(string n) {name=n;};//constructor
		void readData();
		void printData();
		string getName() {return name;};//return name

};
