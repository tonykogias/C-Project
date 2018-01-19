#include <iostream>
#include <string>
#include "S_class.h"

using namespace std;

void S_class::readData() {
	
	cout<<"Enter the type of the class(L-lab , T-theory): ";
	cin>>type;
	if(type=="T"){
		cout<<"Enter the room (1-Amfitheatro,2-AithousaA,3-AithousaB,4-AithousaC): ";
		cin>>class_number;
	}
	else {
		cout<<"Enter the room (1-ErgastirioA,2-ErgastirioB,3-ErgastirioC,4-ErgastirioIlektron): ";
		cin>>class_number;
	}
}

void S_class::printData() {
	
	cout<<"The number of classes is: "<<class_number<<endl;
	cout<<"The class type is: "<<type<<endl;
	
}

