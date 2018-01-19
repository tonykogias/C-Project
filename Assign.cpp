#include "Assign.h"
#include <iostream>



Assign::Assign() {
	
	course;
	room;
	sh=0;
	fh=0;
	day=0;
}

void Assign::ReadData() {
	
	
	cout<<"For the subject: "<<endl;
	course.readData();
	cout<<"For the room:"<<endl;
	room.readData();
	cout<<"Enter the hour you want your course to start!:";
	cin>>sh;
	cout<<"Enter the hour you want your course to finish!:";
	cin>>fh;
	cout<<"Enter the day for the course(1-Monday,2-Thusday-.....,5-Friday) ";
	cin>>day;
	
}
	
