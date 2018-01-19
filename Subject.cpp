#include "Subject.h"
#include <iostream>


Subject::Subject() {
	
	title = " ";
	prof;
	direction = " ";
	sem;
}


void Subject::readData() {
	
	
	cout<<"Enter the subject's title "<<endl;
	cout<<"Enter (L) at the end of the title if you want to give lab hours: ";
	cin>>title;
	prof.readData();
	cout<<"Enter the subject's direction (0-No Direction,M-math/physics,C-computer,T-telecomunication): ";
	cin>>direction;
	sem.readData();
	
}

void Subject::printData() {
	
	cout<<"The subject's title is: "<<title<<endl;
	prof.printData();
	cout<<"The subject's direction is: "<<direction<<endl;
	sem.printData();
}


