#include "Program.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::ifstream;
using std::ofstream;


Program::Program(){
	
	for (int i=0;i<N;i++){
		array;
	}
	counter1=0;
	counter2=0;
	counter3=0;
	counter4=0;
	counter5=0;
	
}


void Program::ReadArray(){
	
	
	for (int i=0;i<N;i++){
		array[i].ReadData();

		if(array[i].getCourse().getSem().getTitleS()==1)
			counter1++;
		else if(array[i].getCourse().getSem().getTitleS()==2)
			counter2++;
		else if(array[i].getCourse().getSem().getTitleS()==3)
			counter3++;
		else if(array[i].getCourse().getSem().getTitleS()==4)
			counter4++;
		else
			counter5++;
	}
		
}

void Program::Data() {

	this->ReadArray();
	string prog[11][5]; //dilwsi pinaka ousiastika to programma pou tha ektipnwete
	int y;//to y einai i kainourgia mera pou tha dinei o xristis otan exoume thema stin kateuthinsi
	int z;//to z einai to kainourgio domatio pou tha dinei o xristis ama einai idies wres idia domatia diaforetika eksamina 

	int counter;
	counter=this->getCounter1(); //counter tis if
	int plus=0; //to plus einai poses fores tha bei stin if gia na ksexwrisoun ta eksamina
	

	for(int i=0;i<N;i++){
		
		
		if(i==counter){	
			//PRINTING STARTS	
			int starting_hour=9;
			cout<<"\n-----------------2015-2016----------------"<<endl;
			cout<<"-----------------For semester "<<plus+2<<"------------------"<<endl;
	
			cout<<"             |MONDAY    TUESDAY    WE/SDAY   TH/SDAY   FRIDAY"<<endl;
			for(int c=0;c<11;c++){
				if(starting_hour+c==9)
					cout<<"0"<<starting_hour<<":00-"<<starting_hour+1<<":00  |";
				else
					cout<<starting_hour+c<<":00-"<<starting_hour+c+1<<":00  |";
				for(int d=0;d<5;d++){
					if(prog[c][d]=="")
						cout<<"        ";
					else
						cout<<prog[c][d];
					cout<<"  ";
				}
				cout<<endl;
			}	
			//PRINTING ENDS
	
			//PRINTING IN TXT STARTS
			ofstream out;
			out.open("table.txt",ios::app);	
	
		//	int starting_hour=9;
			out<<"\n-----------------2015-2016----------------"<<endl;
			out<<"-----------------For semester "<<plus+2<<"------------------"<<endl;

			out<<"             |MONDAY    TUESDAY    WE/SDAY   TH/SDAY   FRIDAY"<<endl;
			for(int c=0;c<11;c++){
				if(starting_hour+c==9)
					out<<"0"<<starting_hour<<":00-"<<starting_hour+1<<":00  |";
				else
					out<<starting_hour+c<<":00-"<<starting_hour+c+1<<":00  |";
				for(int d=0;d<5;d++){
					if(prog[c][d]=="")
						out<<"        ";
					else
						out<<prog[c][d];
					out<<"  ";
				}
				out<<endl;
			}	
	
			out.close();
			//PRINTING TXT ENDS		
					
			for(int h=0;h<11;h++)
				for(int b=0;b<5;b++)
					prog[h][b]="";
		
			plus++;
			if(plus==1)
				counter=counter + this->getCounter2();	
			else if(plus==2)
				counter=counter + this->getCounter3();
			else if(plus==3)
				counter=counter + this->getCounter4();
			else
				counter=counter + this->getCounter5();
		}
		
		
		for(int j=i+1;j<=N;j++){
			if(array[i].getCourse().getProf().getName()==array[j].getCourse().getProf().getName()){ //ousiastika checkaroume an einai idioi kathigites , exoume simfwnisei oti ksekinaei o pinakas ana eksamino , idioi kathigites=ekxwrisi (dn iparxei periptosi lathous apo ton xristi)
				int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
				int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
				int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
				
				for(int w=sl;w<fl;w++){
					prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
				}				
			}
			else{
				if(array[i].getDay()==array[j].getDay()){ //diaforetikos kathigitis idia mera elenxos
					if(array[i].getSh()!=array[j].getSh()){ //diaforetikes wres dn ginete ekxwrisi aparetita prepei na doume an exei endiameso mathima
						if(array[i].getSh()<array[j].getSh()) { //wra enarksis i mikroteri apo wra enarkisi j
							if(array[i].getFh()<=array[j].getSh()) { //wra likseis tou i mikroteri i isi me wra ENARKSIS tou j (no problem :) )
								int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
								int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
								int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
				
								for(int w=sl;w<fl;w++){
									prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
								}
							}
							else {//wra likseis i megaliteri apo wra enarksis tou j ! provlima :( 
								int flag=100000; //flag gia na voithisei se pia if benw
								if(array[i].getCourse().getDirection()==array[j].getCourse().getDirection()&& array[i].getCourse().getDirection()!="0"){ //elenxos ama einai idia kateuthinsi (provlima ama einai :( )
									cout<<"There is a problem !!! Conflict with DIRECTION of course!"<<endl; //xriazete na alaksei mono to direction afou exei thema apo pio nwris dn mas noizei i aithousa (alagi mera gia efkolia ston programatisti)
									cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
									cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
									cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
									cin>>y; //diavasma kainourgias meras
									array[i].setDay(y); //settarei tin kainourgia
									cout<<endl;
									cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
									flag=0;//voitheia flag molis bgw apo if else gia kateuthinsi kanw if an flag=0 i flag=1 gia na ginei i arxikopoihsi me ta kainourgia dedomena
								}
								else { //diaforetiki kateuthinsi alla provlima stin wra !!!Ginete 2 diaforetikoi kathigites na kanoun mathima idia wra ALLA DIAFORETIKES AITHOUSES
									if(array[i].getRoom().getClassN()==array[j].getRoom().getClassN()) { //an einai idia domatia PROVLIMA :( apla alagi domatiou kai ekxwrisi!
										//EDW THA BEI I IF GIA TO IDIO EKSAMINO (apla alazei mera)
										if(array[i].getCourse().getSem().getTitleS()==array[j].getCourse().getSem().getTitleS()) {
											cout<<"An other teacher of the same semester is having a class these hours."<<endl;
											cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
											cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
											cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
											cin>>y; //diavasma kainourgias meras
											array[i].setDay(y); //settarei tin kainourgia
											cout<<endl;
											cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
										}  //endif
										else{ //else (diladi diaforetiko eksamino apla alazei room)
											cout<<"There is a problem with that room the specific hours"<<endl;
											cout<<"You need to enter an other room for course "<<array[i].getCourse().getTitle()<<"!"<<endl;
											cout<<"You entered room number "<<array[i].getRoom().getClassN()<<" before."<<endl;	
											cout<<"Enter an other room (1-Amfitheatro,2-AithousaA,3-AithousaB): "; 
											cin>>z;	//diavazei kainourgio domatio
											cout<<endl;
											array[i].getRoom().setRoom(z); //settarei to new room
											cout<<"The new room is: "<<array[i].getRoom().getClassN()<<endl;
										}//endelse
										flag=1;	
									}		
								}
								if(flag==0){ //AN BIKE stin KATEUTHINSI
									//OUSIASTIKA EKXWRISI COPY PASTE APO PANW
									int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
									int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
									//PROSOXI TO Y EINAI I KAINOURGIA MERA POU DIAVAZW PANW!!!!
									int daycoll=y-1;//KAINOURGIA MERA-1 !!!!PROSOXIIIIIIII
				
									for(int w=sl;w<fl;w++){
										prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
									}
								}
								else if(flag==1){ //AN BIKE sto DOMATIO
									//OUSIASTIKA EKXWRISI COPY PASTE APO PANW
									int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
									int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
									int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
					
									for(int w=sl;w<fl;w++){
										prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
									}
								}
							}
						}
						else{ //wra enarksis i megaliteri apo wra enarksis tou j ELENXOS GIA ENDIAMESO PROVLIMA!!!
							if(array[i].getSh()>array[j].getFh()){ //wra enarksis tou i megaliteri apo wra likseis tou j !!KANENA PROVLIMA EKXWRISI :)
								//OUSIASTIKA EKXWRISI COPY PASTE APO PANW
								int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
								int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
								int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
				
								for(int w=sl;w<fl;w++){
									prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
								}
							}
							else{ //wra enarksis i mikroteri apo wra likseis j PROVLIMA !!!! :(
								int flag=100000; //flag gia na voithisei se pia if benw
								if(array[i].getCourse().getDirection()==array[j].getCourse().getDirection()&& array[i].getCourse().getDirection()!="0"){ //elenxos ama einai idia kateuthinsi (provlima ama einai :( )
									cout<<"There is a problem !!! Conflict with DIRECTION of course!"<<endl; //xriazete na alaksei mono to direction afou exei thema apo pio nwris dn mas noizei i aithousa (alagi mera gia efkolia ston programatisti)
									cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
									cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
									cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
									cin>>y; //diavasma kainourgias meras
									array[i].setDay(y); //settarei tin kainourgia
									cout<<endl;
									cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
									flag=0;//voitheia flag molis bgw apo if else gia kateuthinsi kanw if an flag=0 i flag=1 gia na ginei i arxikopoihsi me ta kainourgia dedomena
								}
								else { //diaforetiki kateuthinsi alla provlima stin wra !!!Ginete 2 diaforetikoi kathigites na kanoun mathima idia wra ALLA DIAFORETIKES AITHOUSES
									if(array[i].getRoom().getClassN()==array[j].getRoom().getClassN()) { //an einai idia domatia PROVLIMA :( apla alagi domatiou kai ekxwrisi!
										//EDW THA BEI I IF GIA TO IDIO EKSAMINO (apla alazei mera)
										if(array[i].getCourse().getSem().getTitleS()==array[j].getCourse().getSem().getTitleS()) {
											cout<<"An other teacher of the same semester is having a class these hours."<<endl;
											cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
											cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
											cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
											cin>>y; //diavasma kainourgias meras
											array[i].setDay(y); //settarei tin kainourgia
											cout<<endl;
											cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
										}//endif
										else{//else (diladi diaforetiko eksamino apla alazei room)
											cout<<"There is a problem with that room the specific hours"<<endl;
											cout<<"You need to enter an other room for course "<<array[i].getCourse().getTitle()<<"!"<<endl;
											cout<<"You entered room number "<<array[i].getRoom().getClassN()<<" before."<<endl;	
											cout<<"Enter an other room (1-Amfitheatro,2-AithousaA,3-AithousaB): "; 
											cin>>z;	//diavazei kainourgio domatio
											cout<<endl;
											array[i].getRoom().setRoom(z); //settarei to new room
											cout<<"The new room is: "<<array[i].getRoom().getClassN()<<endl;
										}//endelse
										flag=1;	
									}		
								}
								if(flag==0){ //AN BIKE stin KATEUTHINSI
									int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
									int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
									int daycoll=y-1;//KAINOURGIA MERA-1 !!!!PROSOXIIIIIIII
				
									for(int w=sl;w<fl;w++){
										prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
									}
								}
								else if(flag==1){ //AN BIKE sto DOMATIO
									int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
									int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
									int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
					
									for(int w=sl;w<fl;w++){
										prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
									}
								}
							}
						}
					}
					else{ //idia wra
						int flag=100000; //flag gia na voithisei se pia if benw
						if(array[i].getCourse().getDirection()==array[j].getCourse().getDirection()&& array[i].getCourse().getDirection()!="0"){ //elenxos ama einai idia kateuthinsi (provlima ama einai :( )
							cout<<"There is a problem !!! Conflict with DIRECTION of course!"<<endl; //xriazete na alaksei mono to direction afou exei thema apo pio nwris dn mas noizei i aithousa (alagi mera gia efkolia ston programatisti)
							cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
							cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
							cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
							cin>>y; //diavasma kainourgias meras
							array[i].setDay(y); //settarei tin kainourgia
							cout<<endl;
							cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
							flag=0;//voitheia flag molis bgw apo if else gia kateuthinsi kanw if an flag=0 i flag=1 gia na ginei i arxikopoihsi me ta kainourgia dedomena
						}
						else { //diaforetiki kateuthinsi alla provlima stin wra !!!Ginete 2 diaforetikoi kathigites na kanoun mathima idia wra ALLA DIAFORETIKES AITHOUSES
							if(array[i].getRoom().getClassN()==array[j].getRoom().getClassN()) { //an einai idia domatia PROVLIMA :( apla alagi domatiou kai ekxwrisi!
								if(array[i].getCourse().getSem().getTitleS()==array[j].getCourse().getSem().getTitleS()) {
									cout<<"An other teacher of the same semester is having a class these hours."<<endl;
									cout<<"You need to change the day of your course "<<array[i].getCourse().getTitle()<<" !"<<endl;//EKTIPWNEI pio course prepei na alaksei mera				
									cout<<"The day you entered before was: "<<array[i].getDay()<<" in the week!"<<endl;
									cout<<"Enter an other day: "; //dinei kainourgia mera logo provlimatos
									cin>>y; //diavasma kainourgias meras
									array[i].setDay(y); //settarei tin kainourgia
									cout<<endl;
									cout<<"The new day is: "<<array[i].getDay()<<endl; //ekripwsi tis kainourgias meras
								}//endif
								else{//else (diladi diaforetiko eksamino apla alazei room)
									cout<<"There is a problem with that room the specific hours"<<endl;
									cout<<"You need to enter an other room for course "<<array[i].getCourse().getTitle()<<"!"<<endl;
									cout<<"You entered room number "<<array[i].getRoom().getClassN()<<" before."<<endl;	
									cout<<"Enter an other room (1-Amfitheatro,2-AithousaA,3-AithousaB): "; 
									cin>>z;	//diavazei kainourgio domatio
									cout<<endl;
									array[i].getRoom().setRoom(z); //settarei to new room
									cout<<"The new room is: "<<array[i].getRoom().getClassN()<<endl;
								}//endelse
								flag=1;	
							}		
						}
						if(flag==0){ //AN BIKE stin KATEUTHINSI
							int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
							int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
							int daycoll=y-1;//KAINOURGIA MERA-1 !!!!PROSOXIIIIIIII
		
							for(int w=sl;w<fl;w++){
								prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
							}
						}
						else if(flag==1){ //AN BIKE sto DOMATIO
							int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
							int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
							int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
				
							for(int w=sl;w<fl;w++){
								prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
							}
						}	
					} 
				}
				else{  //diaforetiki mera
					int sl=array[i].getSh()-9;//arxizei to loop kai ousiastika i thesi tis grammis pou apothikeuetai
					int fl=array[i].getFh()-9;//teleiwnei to loop ousiastika teleutaia thesi tou pinaka tis gramis pou arkipoihtai to string
					int daycoll=array[i].getDay()-1;//tin stili tou distiastatou pinaka (ousiastika -1 giati oi meres ksekinan 1-5 all o pinakas 0-4)
				
					for(int w=sl;w<fl;w++){
						prog[w][daycoll]=array[i].getCourse().getTitle(); //arxikopoihsi pinaka
					}
				}
			}
		}
	}

	//PRINTING STARTS	
	int starting_hour=9;
	cout<<"\n-----------------2015-2016----------------"<<endl;
	cout<<"-----------------For semester "<<plus+2<<"------------------"<<endl;
	
	cout<<"             |MONDAY    TUESDAY    WE/SDAY   TH/SDAY   FRIDAY"<<endl;
	for(int c=0;c<11;c++){
		if(starting_hour+c==9)
			cout<<"0"<<starting_hour<<":00-"<<starting_hour+1<<":00  |";
		else
			cout<<starting_hour+c<<":00-"<<starting_hour+c+1<<":00  |";
		for(int d=0;d<5;d++){
			if(prog[c][d]=="")
				cout<<"        ";
			else
				cout<<prog[c][d];
			cout<<"  ";
		}
		cout<<endl;
	}	
	//PRINTING ENDS
	
	//PRINTING IN TXT STARTS
	ofstream out;
	out.open("table.txt",ios::app);	
	
//	int starting_hour=9;
	out<<"\n-----------------2015-2016----------------"<<endl;
	out<<"-----------------For semester "<<plus+2<<"------------------"<<endl;
		
	out<<"             |MONDAY    TUESDAY    WE/SDAY   TH/SDAY   FRIDAY"<<endl;
	for(int c=0;c<11;c++){
		if(starting_hour+c==9)
			out<<"0"<<starting_hour<<":00-"<<starting_hour+1<<":00  |";
		else
			out<<starting_hour+c<<":00-"<<starting_hour+c+1<<":00  |";
		for(int d=0;d<5;d++){
			if(prog[c][d]=="")
				out<<"        ";
			else
				out<<prog[c][d];
			out<<"  ";
		}
		out<<endl;
	}	
	
	out.close();
	//PRINTING TXT ENDS	
	
	
}
	

