#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "library_ahmet.h"
using namespace std;
/*	*******GTU CSE-241 HOMEWORK-2******
	*******AUTHOR=AHMET OKUR*******
*/
int main(){
	int count=0;
	//Hex Games[5]; 
	Hex *Games=new Hex[5];
	Games[0].play_game();	
	while(1){
		
		if(Games[0].what_make.compare("NEXTGAME")==0){
			count++;
			Games[count].play_game();		
					
		}
		else if(Games[0].what_make.compare("BACKGAME")==0){
			count--;
			Games[count].play_game();	
		}
		else if(Games[count].what_make=="COMPARE"){
			if(Games[count-1]==Games[count]){
				cout<<"FIRST GAME IS MORE MARKED THAN THE SECOND GAME"<<endl;
				Games[count].play_game();
			}
			else{
				cout<<"SECOND GAME IS MORE MARKED THAN THE FIRST GAME"<<endl;
				Games[count].play_game();
			}
		}
		else{
			cout<<"CLOSİNG..";
			break;
		}
	}
}