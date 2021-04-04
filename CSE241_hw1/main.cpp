#include <iostream>
#include "library_ahmet.h"
#include <random>

using namespace std;
int main(){
	int size;
	int user_computer;
	int random[2];
	int flag=0;
	cout<<"WELCOME TO HEX GAME!!"<<endl;
	while(flag==0){
		cout<<"PLEASE ENTER THE SIZE"<<endl;
		cout<<"1)6X6\n2)7X7\n3)8X8\n4)9X9\n5)10X10\n6)11X11\n7)12X12"<<endl;
		
		while(1){
			cin>>size;

			if(size<1 || size>7){
				cout<<"INCORRET ENTRY PLEASE TRY AGAIN!!"<<endl;

			}
			else
				break;
		}
		size+=5;
		
		cout<<"PLEASE SELECT\n 1)PLAY WITH COMPUTER \n 2)PLAY WITH USER\n 3)QUIT"<<endl;
		
		cin>>user_computer;
		
		mt19937 generator;
		generator.seed(time(0));
		uniform_int_distribution<uint32_t> dice(0,size-1);
		random[0]=dice(generator);
		random[1]=dice(generator);
		
		if(random[1]==size-1)
			random[1]-=1;
		if(random[1]==0)
			random[1]+=1;

		switch (user_computer){
			case 1:
				cout<<"!!!PLEASE READ FIRST ME!!!\nX->from left to right\nO->from up to down\n\n";
				play_computer(size,random);
				break;
			case 2:
				cout<<"!!!PLEASE READ FIRST ME!!!\nX->from left to right\nO->from up to down\n\n";
				play_user(size);
				break;
			case 3:
				cout<<"\nPROGRAM İS CLOSİNG!!!"<<endl;
				flag=1;
				break;
			default:
				cout<<"İNCORRET ENTRY"<<endl;
				break;
		}
	}

	return 0;

}