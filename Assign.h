#include "S_class.h"
#include "Subject.h"

class Assign {
	
	private:
		Subject course;
		S_class room;
		int sh;//starting hour
		int fh;//finishing hour
		int day;
	public:
		Assign();
		void ReadData();
		Subject getCourse(){return course;};
		S_class getRoom(){return room;};
		int getSh(){return sh;};
		int getFh(){return fh;};
		int getDay(){return day;};
		void setDay(int x){day=x;};

};
