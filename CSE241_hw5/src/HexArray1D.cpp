#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "HexArray1D.h"
using namespace std;

namespace ahmet_array{
	HexArray1D::HexArray1D(){
	}

	HexArray1D::HexArray1D(int size_){

	}
	void HexArray1D::play_game(){
		int m;
		char a;
		int i,j;
		bool flag=true;
		int row;
		char column;
		string str;
		cout<<"GAME=1DARRAY!!"<<endl;
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
								if(isEnd()==true){
									flag=false;
									print();
								}
								cout<<"MARKED="<<numberOfMoves()<<endl;
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
									if(isEnd()==true){
										flag=false;
										print();
									}
									cout<<"MARKED="<<numberOfMoves()<<endl;
									break;
								}
								else if(str!="RESET" && str!="LASTMOVE")
									cerr<<"ERORR!!"<<endl;
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
									if(isEnd()==true){
										flag=false;
										print();
									}
									
									marked++;
									cout<<"MARKED="<<numberOfMoves()<<endl;
								
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
	void HexArray1D::creat_empty_array(){
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
		
		i=size_board*size_board;
		hexCell=(Cell*)malloc(sizeof(Cell)*i);
			
		for(i=0;i<((size_board)*(size_board));i++){

				hexCell[i].set_type(empty);
				hexCell[i].set_position_column(i);
				hexCell[i].set_position_row(j);
			
		}
		if(user_who==1){
			hexCell[((random[0]*size_board)+random[1])].set_type(user1);
		}
	}
	void HexArray1D::print()const{
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
				cout<<hexCell[(size_board*i)+j].get_type()<<"  ";
			}
			cout<<"\n";
		}
	}

	void HexArray1D::play(char column,int row){
		int index;
		if(turn==0){
			
			while(1){
				
				try{
					this->operator()(column-65,row);
					index=((column-65)+(size_board*row));
					hexCell[index].set_type(user1);
					break;
				}
				catch(hata1 i){
					cout<<i.error();
					cin>>column>>row;
					row-=1;
				}
				/*index=((column-65)+(size_board*row));
				if(hexCell[index].get_type()=='.' && (column-65)<size_board && row<size_board){
					hexCell[index].set_type(user1);
					break;
				}

				else{
					cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
					cin>>column>>row;
					row-=1;
				}*/
			}
		}
		else{
			while(1){
				
				try{
				
					this->operator()(column-65,row);
					index=((column-65)+(size_board*row));
					hexCell[index].set_type(user2);
					break;
				}
				catch(hata1 i){
					cout<<i.error();
					cin>>column>>row;
					row-=1;
				}
				/*index=((column-65)+(size_board*row));	
				if(hexCell[index].get_type()=='.'&& (column-65)<size_board && row<size_board){
					hexCell[index].set_type(user2);
					break;
				}
				
				else{
					cerr<<"ERROR!TRY AGAİN"<<endl;
					cin>>column>>row;
					row-=1;
					cout<<column<<row;
				}*/
			}
		}
		print();
	}
	int HexArray1D::finish_control_x(){
		int i;
		int flag=0;	
		int counter=1;
		/*Determines the starting position of x*/
		for(i=0;i<(size_board*size_board);i+=size_board){
			if(hexCell[i].get_type()=='x'){
				
				flag=recursion_x(0,(i/size_board),counter);
			}
			if(flag==1){
				hexCell[i].set_type(win_user1);
				return 1;		
			}
		}
		return 0;
	}
	int HexArray1D::recursion_x(int column,int row,int counter){
		//cout<<hexCell[column][row].get_type()<<endl;
		int index=(row*size_board)+column;
		
		if(hexCell[index+1].get_type()=='x'&& counter<(size_board*3)){
			
			 if(recursion_x((column+1),row,(counter+1))==1){
			 	hexCell[index+1].set_type(win_user1);
			 	return 1;
			 }
		
		}
		if(row>0){
			if(hexCell[index+1-size_board].get_type()=='x'&& counter<(size_board*3)){
				 if(recursion_x((column+1),(row-1),(counter+1))==1){
				 	hexCell[index+1-size_board].set_type(win_user1);
				 	return 1;
				 }
			}
		}
		/*north*/
		if(hexCell[index+size_board].get_type()=='x' && counter<(size_board*3)){
			 
			 if(recursion_x(column,(row+1),(counter+1))==1){
			 	hexCell[index+size_board].set_type(win_user1);
			 	return 1;
			 }
		}
		/*south*/
		if(row>0){
			if(hexCell[index-size_board].get_type()=='x'&& counter<(size_board*3)){
				 if(recursion_x(column,row-1,(counter+1))==1){
				 	hexCell[index-size_board].set_type(win_user1);
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
	int HexArray1D:: finish_control_o(){
		int i,counter=0;
		int flag=0;
		/*Determines the starting position of o*/
		for(i=0;i<size_board;i++){
			if(hexCell[i].get_type()=='o'){
				flag=recursion_o(i,0,counter);
			}
			if(flag==1){
				hexCell[i].set_type(win_user2);
				return 1;
			}
		}
		return 0;	

	}
	int HexArray1D:: recursion_o(int column,int row,int counter){
		int index=(row*size_board)+column;
		/*north*/
		if(hexCell[index+size_board].get_type()=='o' && counter<(size_board*3)){
			 
			 if(recursion_o(column,(row+1),(counter+1))==1){
			 	hexCell[index+size_board].set_type(win_user2);
			 	return 1;
			 }
		}
		/*west*/
		 
		if(hexCell[index+1].get_type()=='o' && counter<(size_board*3)){
			 if(recursion_o((column+1),row,(counter+1))==1){
			 	hexCell[index+1].set_type(win_user2);
			 	return 1;
			 }
		}
		/*east*/
		if(column>0){
			if(hexCell[index-1].get_type()=='o' && counter<(size_board*3)){
				 if(recursion_o((column-1),(row),(counter+1))==1){
				 	hexCell[index-1].set_type(win_user2);
				 	return 1;
				 }
			}
		}
		/*northeast*/
		if(column>0){
			if(hexCell[index-1+size_board].get_type()=='o' && counter<(size_board*3)){
				 if(recursion_o((column-1),(row+1),(counter+1))==1){
				 	hexCell[index-1+size_board].set_type(win_user2);
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
	void HexArray1D:: play(){

		int i;
		int index1,index2;
		index1=next_move[1]+(next_move[0]*size_board);
		index2=back_move[1]+(back_move[0]*size_board);

		if(hexCell[index1+1].get_type()=='.' && next_move[1]<size_board-1){
			hexCell[index1+1].set_type(user1);
			next_move[1]+=1;
			return ;
		}
		
		else if(hexCell[index1+1-size_board].get_type()=='.' && next_move[1]<size_board-1 && next_move[0]>0){
			hexCell[index1+1-size_board].set_type(user1);
			next_move[1]+=1;
			next_move[0]-=1;
			return ;
		}
		
		else if(hexCell[index2-1].get_type()=='.'  && back_move[1]>0){
			hexCell[index2-1].set_type(user1);
			back_move[1]-=1;
			return ;
		}
		
		else if(hexCell[index2-1+size_board].get_type()=='.' &&back_move[1]>0 && back_move[0]<size_board-1){
			hexCell[index2-1+size_board].set_type(user1);
			back_move[1]-=1;
			back_move[0]+=1;
			return ;
		}
		
		else if(hexCell[index1+size_board].get_type()=='.'  && next_move[0]<size_board-1 && next_move[1]<size_board-1){
			hexCell[index1+size_board].set_type(user1);
			next_move[0]+=1;
			return ;
		}
		
		else if(hexCell[index2-size_board].get_type()=='.'  && back_move[0]>0){
			hexCell[index2-size_board].set_type(user1);
			back_move[0]-=1;
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
				index1=random[1]+(random[0]*size_board);
				if(hexCell[index1].get_type()=='.'){
					back_move[0]=random[0];
					back_move[1]=random[1];
				
					next_move[0]=random[0];
					next_move[1]=random[1];
					hexCell[index1].set_type(user1);
					return ;
				}
			}
		}

		/*computer's actions*/
		

	}
	bool HexArray1D:: isEnd(){
		if(turn==0){
			return finish_control_x();
		}
		else
			return finish_control_o();
	}
	int HexArray1D::save_load(const string &str){		
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
	void HexArray1D::writeToFile(const string &str){
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
		for(i=0;i<(size_board*size_board);i++){
			
				outstream<<hexCell[i].get_type();
			
		}
		outstream.close();
	}
	char HexArray1D::readFromFile(const string &str){
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
		setSize(j);
		int x_=0,o_=0;
		
		/*x and o numbers to determine who's the turn*/ 
		for(i=0;i<copy.length();i++){
			if(copy[i]=='x')
				x_++;
			else if(copy[i]=='o')
				o_++;
		}
		marked=x_+o_;
		hexCell=(Cell*)malloc(sizeof(Cell)*(size_board*size_board));
		
		for(i=0;i<(size_board*size_board);i++){
			
			hexCell[i].set_type(empty);
			hexCell[i].set_position_column(i);
			hexCell[i].set_position_row(j);
			
		}
		
		/*filling the board*/
		for(i=0;i<(size_board*size_board);i++){
			switch(copy[i]){
				case '.':
					hexCell[i].set_type(empty);
					break;
				case 'x':
					hexCell[i].set_type(user1);
					break;
				case 'o':
					hexCell[i].set_type(user2);
					break;
			}

		}

		int option=size_board;
		if(user_who==1){
			for(i=0;i<(size_board*size_board);i++){
				
				if(hexCell[i].get_type()=='x'){
					if(i%size_board<=option){
						back_move[0]=i/size_board;
						back_move[1]=i%size_board;
						option=i%size_board;
					}
				}
			}
			option=0;
			for(i=0;i<(size_board*size_board);i++){
				if(hexCell[i].get_type()=='x'){
					if(i%size_board>=option){
						next_move[0]=i/size_board;
						next_move[1]=i%size_board;
					}
				}
			}
		}
		if(x_==o_)
			return 'x';
		return 'o';
	}
	void HexArray1D::setSize(int a){
		size_board=a;
	}
	void HexArray1D::reset(){
		int i,j;
		if(user_who==1)
			marked=1;
		else
			marked=0;
		back_move[0]=random[0];
		back_move[1]=random[1];
		next_move[0]=random[0];
		next_move[1]=random[1];
		
		for(i=0;i<(size_board*size_board);i++){
			
			hexCell[i].set_type(empty);
			hexCell[i].set_position_column(i);
			hexCell[i].set_position_row(j);
			
		}
		if(user_who==1){
			hexCell[(random[0]*size_board)+random[1]].set_type(user1);
		}
	}
	Cell HexArray1D:: operator()(int column,int row){
		int index1=(row*size_board)+column;
		if(hexCell[index1].get_type()!='.')
			throw hata1();
		return hexCell[index1];
	}
	const string HexArray1D::get_board()const{
		int i,j;
		string str;
		for(i=0;i<(size_board*size_board);i++){
			
			str.push_back(hexCell[i].get_type());
			
		}
		return str;
	}
	HexArray1D::HexArray1D(const HexArray1D &copyc){
		size_board=copyc.size_board;
		hexCell=(Cell*)malloc(sizeof(Cell)*size_board*size_board);
		for(int i=0;i<size_board*size_board;i++){
			hexCell[i]=copyc.hexCell[i];
		}

		back_move[0]=copyc.back_move[0];
		back_move[1]=copyc.back_move[1];
		next_move[0]=copyc.next_move[0];
		next_move[1]=copyc.next_move[1];
	}
	HexArray1D &HexArray1D::operator=(const HexArray1D &rightSide){
		if(size_board!=rightSide.size_board){
			size_board=rightSide.size_board;
			hexCell=(Cell*)malloc(sizeof(Cell)*size_board*size_board);

		}
		for(int i=0;i<size_board*size_board;i++){
			hexCell[i]=rightSide.hexCell[i];
		}

		back_move[0]=rightSide.back_move[0];
		back_move[1]=rightSide.back_move[1];
		next_move[0]=rightSide.next_move[0];
		next_move[1]=rightSide.next_move[1];
		return *this;

	}
	HexArray1D::~HexArray1D(){
		free(hexCell);
	}
}