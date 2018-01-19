#include <iostream>
#include <string>
#include "Semister.h"

using namespace std;

Semister::Semister() {

	title=0;
}

void Semister::readData() {
	
	
	cout<<"Enter the semister (1-second,2-fourth,3-sixth,4-eighth): ";
	cin>>title;
	

}

void Semister::printData() {
	
	cout<<"The "<<title<<" semister: "<<endl;

}

