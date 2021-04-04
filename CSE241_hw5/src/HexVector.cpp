#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include "HexVector.h"
using namespace std;
namespace ahmet_vector{
	HexVector::HexVector(){
	}

	HexVector::HexVector(int size_){
	}
	void HexVector::play_game(){
		int m;
		char a;
		int i,j;
		bool flag=true;
		int row;
		char column;
		string str;
		cout<<"GAME=VECTOR!!"<<endl;
		cout<<"WELCOME TO HEX GAME!!"<<endl;
				while(1){
					cout<<"PLEASE ENTER THE SIZE"<<endl;
				
					cin>>size_board>>a>>m;
					if(size_board!=m || a!='X' || size_board<6){
						cerr<<"ERROR PLEASE TRY AGAİN"<<endl;
					}

					else 
						break;
					cin.clear();
					cin.ignore(100,'\n');			
				}
				
				while(1){
					cout<<"PLEASE SELECT\n 1)PLAY WITH COMPUTER \n 2)PLAY WITH USER\n 3)QUIT"<<endl;
				
					cin>>user_who;
					if(user_who==3){
						exit(1);
					}
					if(user_who<1 || user_who>3){
						cerr<<"ERROR!! PLEASE TRY AGİN!!"<<endl;
					}
					else 
						break;
					cin.clear();
					cin.ignore(100,'\n');
				}
				creat_empty_array();
				if(user_who==1)
					marked++;
			
				cin.clear();
				cin.ignore(100,'\n');	
				print();
					while(flag==true){
						if(user_who==1){
							while(flag==true){
								cout<<"it's time for O (please enter upper case for ex:A8)\t"<<endl;
								getline(cin,str,'\n');
								if(str.length()>3 &&str!="RESET"){
									if(save_load(str)==0);
										continue;
									if(save_load(str)==2){
										print();
										continue;
									}
									if(save_load(str)==1){
										print();
										break;
									}
								}
								else if (str.length()>1 && str[0]>='A' && str[0]<=65+size_board){
									column=str[0];
									str.erase(str.begin());
									row=stoi(str);
									row-=1;
									turn=1;
									y_=column-65;
									x_=row;
									play(column,row);
									marked++;
									cout<<"MARKED="<<numberOfMoves()<<endl;
									if(isEnd()==true){
										flag=false;
										print();
									}
									print();
									break;
								}
								else if(str=="RESET")
									break;
								else
									cerr<<"ERROR!!"<<endl;
							}
							if(str=="RESET"){
								reset();
								print();
								continue;
							}
							if(flag==true){
								cout<<"it's time for X (please enter upper case for ex:A8)\t"<<endl;
								turn =0;
								play();
								marked++;
								
								cout<<"MARKED="<<numberOfMoves()<<endl;
								if(isEnd()==true){
									flag=false;
									print();
								}
								print();
							}

						}
						else{
							while(flag==true){
								cout<<"it's time for X (please enter upper case for ex:A8)\t"<<endl;
								getline(cin,str,'\n');
								if(str=="LASTMOVE"){
									try{
										if(marked==0){
											throw hata2();
										}
										cout<<"LAST MOVE="<<column<<row+1<<endl;
									}
									catch(hata2 x){
										cout<<x.error();
									}
									
								}
								if(str=="RESET")
									break;
								if(str.length()>3 && str!="LASTMOVE"){
									if(save_load(str)==0);
										continue;
									if(save_load(str)==2){
										print();
										continue;
									}
									if(save_load(str)==1){
										print();
										break;
									}
								}
								else if (str.length()>1 && str[0]>='A' && str[0]<=65+size_board){
									column=str[0];
									str.erase(str.begin());
									row=stoi(str);
									row-=1;
									turn=0;	
									play(column,row);
									marked++;
									cout<<"MARKED="<<numberOfMoves()<<endl;
									if(isEnd()==true){
										flag=false;
										print();
									}
									break;
								}
								else if(str!="RESET" && str!="LASTMOVE")
									cerr<<"ERORR!!"<<endl;
							}
							if(str=="RESET"){
								reset();
								print();
								continue;
							}
							while(flag==true){
								cout<<"it's time for O (please enter upper case for ex:A8)\t"<<endl;
								getline(cin,str,'\n');
								if(str=="LASTMOVE"){
									try{
										if(marked==0){
											throw hata2();
										}
										cout<<"LAST MOVE="<<column<<row+1<<endl;
									}
									catch(hata2 x){
										cout<<x.error();
									}
									
								}
								if(str.length()>3 && str!="RESET" && str!="LASTMOVE"){
									if(save_load(str)==0);
										continue;
									if(save_load(str)==2){
										print();
										continue;
									}
									if(save_load(str)==1){
										print();
										break;
									}
								}
								else if (str.length()>1 && str[0]>='A' && str[0]<=65+size_board){
									column=str[0];
									str.erase(str.begin());
									row=stoi(str);
									row-=1;
									turn=1;
									play(column,row);
									marked++;
									cout<<"MARKED="<<numberOfMoves()<<endl;
									if(isEnd()==true){
										flag=false;
										print();
									}
									break;
								}
								else if(str=="RESET"){
									reset();
									print();
									break;
								}
								else if(str!="LASTMOVE")
									cerr<<"ERROR!!";
							}
						}
					}
		}
	void HexVector::creat_empty_array(){
		int i,j;
		mt19937 generator;
		generator.seed(time(0));
		uniform_int_distribution<uint32_t> dice(0,size_board-1);
		random[0]=dice(generator);
		random[1]=dice(generator);
		if(random[1]==size_board-1)
			random[1]-=1;
		if(random[1]==0)
			random[1]+=1;
		
		back_move[0]=random[0];
		back_move[1]=random[1];
		
		next_move[0]=random[0];
		next_move[1]=random[1];


		hexCell.resize((size_board+1));	
		for(i=0;i<size_board+1;i++){
			hexCell[i].resize((size_board+1));
		}
			
		for(i=0;i<size_board+1;i++){
			for(j=0;j<size_board+1;j++){
				hexCell[i][j].set_type(empty);
				hexCell[i][j].set_position_column(i);
				hexCell[i][j].set_position_row(j);
			}
		}
		if(user_who==1){
			hexCell[random[0]][random[1]].set_type(user1);
		}
	}
	void HexVector::print()const{
		int i,j,k;
		char letters='a';
		cout<<" ";
		for(i=0;i<size_board;i++){
			cout<<(char)(letters+i)<<"  ";
		}
		cout<<endl;
		for(i=0;i<size_board;i++){
			cout<<i+1<<" ";
			for(k=0;k<i;k++){
				cout<<" ";
			}
			for(j=0;j<size_board;j++){
				cout<<hexCell[j][i].get_type()<<"  ";
			}
			cout<<"\n";
		}
	}
	void HexVector::play(char column,int row){
		if(turn==0){
			while(1){
				try{
				
					this->operator()(column-65,row);
					hexCell[column-65][row].set_type(user1);
					break;
				}
				catch(hata1 i){
					cout<<i.error();
					cin>>column>>row;
					row-=1;
				}
			}
		}
		else{
			while(1){
				
				try{			
					this->operator()(column-65,row);
					hexCell[column-65][row].set_type(user2);
					break;
				}
				catch(hata1 i){
					cout<<i.error();
					cin>>column>>row;
					row-=1;
				}
			}
		}
		print();
	}
	int HexVector::finish_control_x(){
		int i;
		int flag=0;	
		int counter=1;
		/*Determines the starting position of x*/
		for(i=0;i<size_board;i++){
			if(hexCell[0][i].get_type()=='x'){
				
				flag=recursion_x(0,i,counter);
			}
			if(flag==1){
				hexCell[0][i].set_type(win_user1);
				return 1;		
			}
		}
		return 0;
	}
	int HexVector::recursion_x(int column,int row,int counter){
		//cout<<hexCell[column][row].get_type()<<endl;
		if(hexCell[column+1][row].get_type()=='x'&& counter<(size_board*3)){
			// cout<<"girdi"<<counter;
			 if(recursion_x((column+1),row,(counter+1))==1){
			 	hexCell[column+1][row].set_type(win_user1);
			 	return 1;
			 }
		
		}
		if(row>0){
			if(hexCell[column+1][row-1].get_type()=='x'&& counter<(size_board*3)){
				 if(recursion_x((column+1),(row-1),(counter+1))==1){
				 	hexCell[column+1][row-1].set_type(win_user1);
				 	return 1;
				 }
			}
		}
		/*north*/
		if(hexCell[column][row+1].get_type()=='x' && counter<(size_board*3)){
			 
			 if(recursion_x(column,(row+1),(counter+1))==1){
			 	hexCell[column][row+1].set_type(win_user1);
			 	return 1;
			 }
		}
		/*south*/
		if(row>0){
			if(hexCell[column][row-1].get_type()=='x'&& counter<(size_board*3)){
				 if(recursion_x(column,row-1,(counter+1))==1){
				 	hexCell[column][row-1].set_type(win_user1);
				 	return 1;
				 }
			}
		}
			
		if(column==size_board-1){
			return 1;
		}
		else{
			return 0;
		}

	}
	int HexVector:: finish_control_o(){
		int i,counter=0;
		int flag=0;
		/*Determines the starting position of o*/
		for(i=0;i<size_board;i++){
			if(hexCell[i][0].get_type()=='o'){
				flag=recursion_o(i,0,counter);
			}
			if(flag==1){
				hexCell[i][0].set_type(win_user2);
				return 1;
			}
		}
		return 0;	

	}
	/*FİNİSH CONTROL*/
	int HexVector:: recursion_o(int column,int row,int counter){
		/*north*/
		if(hexCell[column][row+1].get_type()=='o' && counter<(size_board*3)){
			 
			 if(recursion_o(column,(row+1),(counter+1))==1){
			 	hexCell[column][row+1].set_type(win_user2);
			 	return 1;
			 }
		}
		/*west*/
		 
		if(hexCell[column+1][row].get_type()=='o' && counter<(size_board*3)){
			 if(recursion_o((column+1),row,(counter+1))==1){
			 	hexCell[column+1][row].set_type(win_user2);
			 	return 1;
			 }
		}
		/*east*/
		if(column>0){
			if(hexCell[column-1][row].get_type()=='o' && counter<(size_board*3)){
				 if(recursion_o((column-1),(row),(counter+1))==1){
				 	hexCell[column-1][row].set_type(win_user2);
				 	return 1;
				 }
			}
		}
		/*northeast*/
		if(column>0){
			if(hexCell[column-1][row+1].get_type()=='o' && counter<(size_board*3)){
				 if(recursion_o((column-1),(row+1),(counter+1))==1){
				 	hexCell[column-1][row+1].set_type(win_user2);
				 	return 1;
				 }
			}
		}
		
		if(row==size_board-1){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool HexVector:: isEnd(){
		if(turn==0){
			return finish_control_x();
		}
		else
			return finish_control_o();
	}
	void HexVector:: play(){

		int i,j;
		if(hexCell[next_move[0]+1][next_move[1]].get_type()=='.' && next_move[0]<size_board-1){
			hexCell[next_move[0]+1][next_move[1]].set_type(user1);
			next_move[0]+=1;
			return ;
		}
		
		else if(hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.' && next_move[0]<size_board-1 && next_move[1]>0){
			hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
			next_move[0]+=1;
			next_move[1]-=1;
			return ;
		}
		
		else if(hexCell[back_move[0]-1][back_move[1]].get_type()=='.'  && back_move[0]>0){
			hexCell[back_move[0]-1][back_move[1]].set_type(user1);
			back_move[0]-=1;
			return ;
		}
		
		else if(hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.' &&back_move[0]>0 && back_move[1]<size_board-1){
			hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
			back_move[0]-=1;
			back_move[1]+=1;
			return ;
		}
		
		else if(hexCell[next_move[0]][next_move[1]+1].get_type()=='.'  && next_move[1]<size_board-1 && next_move[0]<size_board-1){
			hexCell[next_move[0]][next_move[1]+1].set_type(user1);
			next_move[1]+=1;
			return ;
		}
		
		else if(hexCell[back_move[0]][back_move[1]-1].get_type()=='.'  && back_move[0]>0 && back_move[1]>0){
			hexCell[back_move[0]][back_move[1]-1].set_type(user1);
			back_move[1]-=1;
			return ;
		}
		else{
			while(1){
				mt19937 generator;
				generator.seed(time(0));
				uniform_int_distribution<uint32_t> dice(0,size_board-1);
				random[0]=dice(generator);
				random[1]=dice(generator);
				if(random[1]==size_board-1)
					random[1]-=1;
				if(random[1]==0)
					random[1]+=1;
		
				if(hexCell[random[0]][random[1]].get_type()=='.'){
					back_move[0]=random[0];
					back_move[1]=random[1];
						
					next_move[0]=random[0];
					next_move[1]=random[1];
					hexCell[random[0]][random[1]].set_type(user1);
					return ;
				}
					
				
				
			}
		}

	}

	/*The priorities that the computer has to do in the movements to the right are listed.*/
	int HexVector::save_load(const string &str){		
		/*SAVING PROCEDURES*/
		char laod_control;
		if(str.compare(0,4,"SAVE")==0 ||str.compare(0,4,"save")==0){
			if(str.compare(str.size()-4,4,".txt")==0 || str.compare(str.size()-4,4,".TXT")==0){
				cout<<"SAVING...."<<endl;
				writeToFile(str.substr(5));
				return 0;
			}
			else{
				cerr<<"ERROR!!you should enter a file.txt!!!!"<<endl;
			}
		}
					
		
		else if(str.compare(0,4,"LOAD")==0 ||str.compare(0,4,"load")==0){
			if(str.compare((str.size()-4),4,".txt")==0 ||str.compare((str.size()-4),4,".TXT")==0){
				cout<<"LOADİNG..."<<endl;
				cout<<str.substr(5)<<endl;
				laod_control=readFromFile(str.substr(5));
				if(laod_control=='!'){
					cerr<<"ERROR!!File open failed"<<endl;
				}
					
				else if(laod_control=='i'){
					cerr<<"ERROR!!this file is computer vs human file...please try again"<<endl;
				}
				else if(laod_control=='c'){
					cerr<<"ERROR!!this file is computer vs computer file...please try again"<<endl;
				}
							
				else if(laod_control=='x'){
					print();
					return 1;	
				}
				else if(laod_control=='o')
					print();
					return 2;
							
				}
				else{
					cerr<<"ERROR!!you should enter a file.txt!!"<<endl;
					return -1;
				}
			}
		else{
			cerr<<"ERROR!!you should enter a file.txt!!"<<endl;
			return -1;			
		}
		
	}
	void HexVector::writeToFile(const string &str){
		ofstream outstream;
		outstream.open(str);
		char ch;
		int i,j;
		if(user_who==2){
			outstream<<"!";
		}
		else{
			outstream<<"f";
		}
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				outstream<<hexCell[j][i].get_type();
			}
		}
		outstream.close();
	}
	char HexVector::readFromFile(const string &str){
		string copy;
		int i,j,z=0;
		
		int count1=0,count2=0;
		string number;
		ifstream instream;
		instream.open(str);
		
		if(instream.fail())
			return '!';
		
		instream>>copy;
		instream.close();
		
		/*human or computer control*/
		if(copy[0]=='f' && user_who==2)
			return 'c';
		else if(copy[0]=='!' && user_who==1)
			return 'i';

		
		i=copy.length();
		j=sqrt(i);
		for(i=0;i<(j*j);i++){
			if(copy[i]!='x'&& copy[i]!='o' && copy[i]!='.' && copy[i]!='f' && copy[i]!='!'){
				return '!';
			}
		}
		int x_=0,o_=0;
		setSize(j);
		/*x and o numbers to determine who's the turn*/ 
		for(i=0;i<copy.length();i++){
			if(copy[i]=='x')
				x_++;
			else if(copy[i]=='o')
				o_++;
		}
		marked=x_+o_;
		hexCell.resize((size_board+1));
		for(i=0;i<size_board+1;i++){
			hexCell[i].resize((size_board+1));
		}
		
		for(i=0;i<size_board+1;i++){
			for(j=0;j<size_board+1;j++){
				hexCell[i][j].set_type(empty);
				hexCell[i][j].set_position_column(i);
				hexCell[i][j].set_position_row(j);
			}
		}
		
		/*filling the board*/
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				
				switch(copy[j+z+1]){
					case '.':
						hexCell[j][i].set_type(empty);
						break;
					case 'x':
						hexCell[j][i].set_type(user1);
						break;
					case 'o':
						hexCell[j][i].set_type(user2);
						break;
				}
			}
			z+=size_board;
		}

		if(user_who==1){
			for(i=0;i<size_board;i++){
				for(j=0;j<size_board;j++){
					if(hexCell[i][j].get_type()=='x'){
						back_move[0]=i;
						back_move[1]=j;
						i=size_board;
						break;
					}
				}
			}
			for(i=0;i<size_board;i++){
				for(j=0;j<size_board;j++){
					if(hexCell[i][j].get_type()=='x'){
						next_move[0]=i;
						next_move[1]=j;
						
						break;
					}
				}
			}
		}

		if(x_==o_)
			return 'x';
		return 'o';
	}
	void HexVector::setSize(int a){
		size_board=a;
	}
	void HexVector::reset(){
		int i,j;
		if(user_who==1)
			marked=1;
		else
			marked=0;
		back_move[0]=random[0];
		back_move[1]=random[1];
		next_move[0]=random[0];
		next_move[1]=random[1];

		for(i=0;i<size_board+1;i++){
			for(j=0;j<size_board+1;j++){
				hexCell[i][j].set_type(empty);
				hexCell[i][j].set_position_column(i);
				hexCell[i][j].set_position_row(j);
			}
		}
		if(user_who==1){
			hexCell[random[0]][random[1]].set_type(user1);
		}
	}
	Cell HexVector:: operator()(int column,int row){

		if(hexCell[column][row].get_type()!='.')
			throw hata1();
		return hexCell[column][row];
	}
	const string HexVector::get_board()const{
		int i,j;
		string str;
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				str.push_back(hexCell[i][j].get_type());
			}
		}
		return str;
	}
}