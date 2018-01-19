#include <string>

using namespace std;

class S_class {
	
	private:
		int class_number;//number of class
		string type;//lab or amfitheatro
	public:
		S_class() {class_number=0;type=" ";}; //constructor 
		S_class(int c_c,string t) {class_number=c_c;type=t;}; //contructor
		void readData();
		void printData();
		int getClassN() {return class_number;};
		void setRoom(int x){class_number=x;};
};
