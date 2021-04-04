#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "library_ahmet.h"

using namespace std;
int Hex::game_number=0;
string Hex::what_make="free";
Hex::Hex():size_board(0),marked(0),game_name(game_number),transition(false),finish(false){
	//marked.push_back(0);
	game_number++;
	memory_bridge_rule=new int*[27];
	if(memory_bridge_rule==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	for(int i=0;i<27;i++){
		memory_bridge_rule[i]=new int[3];
	}
	
	next_move=new int[2];
	back_move=new int[2];
	random=new int[2];
	if(back_move==nullptr||next_move==nullptr||random==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}

}
Hex::Hex(int size,int user):size_board(size),user_who(user),marked(0),transition(true),finish(false),constr(1),game_name(game_number){
	game_number++;
	memory_bridge_rule=new int*[27];
	if(memory_bridge_rule==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	for(int i=0;i<27;i++){
		memory_bridge_rule[i]=new int[3];
	}
	next_move=new int[2];
	back_move=new int[2];
	random=new int[2];
	if(back_move==nullptr||next_move==nullptr||random==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	play_game();
}

int Hex::Cell::get_position_row()const {return row;}
	
void Hex::Cell::set_position_row(int a){a=row;}
	
char Hex::Cell:: get_position_column()const {return column;}
	
void  Hex::Cell::set_position_column(char b){column=b;}
	
char Hex::Cell::get_type() const {return gamer;}

void Hex::Cell::set_type(type a){gamer=a;}

int Hex:: get_trun(){return turn;}

void Hex::play_game(){
	int m;
	char a;
	int row;
	char column;
	int i,j;
	bool flag=true;
	string str;
	cout<<"WELCOME TO HEX GAME!!"<<endl;
	while(flag==true && finish==false){
		if(transition==false){
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
			
		
			cin.clear();
			cin.ignore(100,'\n');
			if(user_who==1){
				marked++;
			}
		}
		if(constr==1){
			creat_empty_array();
		}
		cout<<*this;
		
		while(flag==true){
			
			if(user_who==1 && flag==true){
				while(flag==true){
					cout<<"it's time for O (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					cout<<"THİS GAME MARKED CELL= "<<marked<<endl;
					
					getline(cin,str,'\n');
					if(str.length()>3){
						
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0 || str=="UNDO" ||str=="COMPARE"){
							
							if(str.compare("NEXTGAME")==0 && game_name+1==game_number){
								cerr<<"you are already in the last game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							
							if(str.compare("BACKGAME")==0 && game_name==0){
								cerr<<"you are already in the first game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							if(str=="UNDO"){
								if(marked>1){
									--(*this);
									marked-=2;
									cout<<*this;								
								}
								else{
									cout<<*this;
									cerr<<"YOU ARE ALREADY AT THE STARTING POINT"<<endl;
								}
								
								
								continue;
							}
							if(str=="COMPARE"){
								if(game_name==0){
									cerr<<"you are already in the first game!!PLEASE,PLAY MORE THAN 1 GAME"<<endl;
									continue;
								}
							}

							
							what_make=str;
							flag=false;
							break;
						}
						if(save_load(str)==0);
							continue;
						if(save_load(str)==2){
							cout<<*this;
							
							continue;
						}
						if(save_load(str)==1){
							cout<<*this;						
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
						break;
					}
					else
						cerr<<"ERROR!!"<<endl;
				}
				if(finish_control_o()==1){
					cout<<*this;
					
					cout<<"PARTY TİMEEEE !! USER2  WINS!!!!"<<endl;
					flag=false;
					finish=true;
					what_make="WAİT";
					break;
				}
				if(flag==true){
					cout<<"it's time for X (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					play();
					marked++;
					if(finish_control_x()==1){
						cout<<*this;
						
						cout<<"PARTY TİMEEEE !! COMPUTER  WINS!!!!"<<endl;
						flag=false;
						finish=true;
						what_make="WAİT";
						break;
					}
				}

			}
			
			else{
				while(flag==true){
					cout<<"it's time for X (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					getline(cin,str,'\n');
					if(str.length()>3){
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0 ||str=="UNDO"||str=="COMPARE"){
							if(str.compare("NEXTGAME")==0 && game_name+1==game_number){
								cerr<<"you are already in the last game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							if(str.compare("BACKGAME")==0 && game_name==0){
								cerr<<"you are already in the first game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							if(str.compare("EXIT")==0){
								exit(0);
							}
							if(str=="UNDO"){
								if(marked>0){
									--(*this);
									cout<<*this;
								}
								else{
									cout<<*this;
									cerr<<"YOU ARE ALREADY AT THE STARTING POINT"<<endl;
									continue;
								}
								
								break;
							}
							if(str=="COMPARE"){
								if(game_name==0){
									cerr<<"you are already in the first game!!PLEASE,PLAY MORE THAN 1 GAME"<<endl;
									continue;
								}
							}
							what_make=str;
							flag=false;
							break;
						}
						if(save_load(str)==0);
							continue;
						if(save_load(str)==2){
							
							cout<<*this;
							break;
						}
						else if(save_load(str)==1){
							
							cout<<*this;
							continue;
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
						cout<<"THİS GAME MARKED CELL= "<<marked<<endl;
						break;
					}
					else
						cerr<<"ERORR!!"<<endl;
				}

				if(finish_control_x()==1){
					cout<<*this;
					
					cout<<"PARTY TİMEEEE !! USER1  WINS!!!!"<<endl;
					flag=false;
					finish=true;
					what_make="WAİT";
					break;
				}

				
				while(flag==true){
					cout<<"it's time for O (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					getline(cin,str,'\n');
					if(str.length()>3){
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0 ||str=="UNDO"|| str=="COMPARE"){
							if(str.compare("NEXTGAME")==0){
								cerr<<"YOU CAN ONLY SWİTCH DURİNG X"<<endl;
								continue;
							}
							if(str.compare("BACKGAME")==0){
								cerr<<"YOU CAN ONLY SWİTCH DURİNG X"<<endl;
								continue;
							}
							if(str.compare("EXIT")==0){
								exit(0);
								
							}
							if(str=="UNDO"){
								if(marked>0){
									--(*this);
									cout<<*this;
								}
								else{
									cout<<*this;
									cerr<<"YOU ARE ALREADY AT THE STARTING POINT"<<endl;
									continue;
								}
								break;
							}
							if(str=="COMPARE"){
								cerr<<"YOU CAN ONLY COMPARE DURİNG X"<<endl;
								continue;
							}

						}
						if(save_load(str)==0);
							continue;
						if(save_load(str)==2){
							cout<<*this;
							
							continue;
						}
						if(save_load(str)==1){
							cout<<*this;
							
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
						cout<<"THİS GAME MARKED CELL= "<<marked<<endl;
						break;
					}
					else 
						cerr<<"ERROR!!";
				}

				if(finish_control_o()==1){
					cout<<*this;
					
					cout<<"PARTY TİMEEEE !! USER2  WINS!!!!"<<endl;
					flag=false;
					finish=true;
					what_make="WAİT";
					break;
				}
			}
			
		}
		
 	}
 	
	 if(finish==true){
 		cerr<<"THİS GAME ALREADY FİNİSHED -->BACKGAME , NEXTGAME OR EXIT ?"<<endl;
 		if(flag==true){cout<<*this;}
 		while(1){
	 		getline(cin,str,'\n');
	 		if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0||str.compare("EXIT")==0||str=="COMPARE"){
				if(str.compare("NEXTGAME")==0 && game_name+1==game_number){
					cerr<<"you are already in the last game!!PLEASE TRY AGAIN"<<endl;
					continue;
				}
				if(str.compare("BACKGAME")==0 && game_name==0){
					cerr<<"you are already in the first game!!PLEASE TRY AGAIN"<<endl;
					continue;
				}
				if(str.compare("EXIT")==0){
					exit(1);
				}
				if(str=="COMPARE" && game_name==0){
					cerr<<"you are already in the first game!!PLEASE,PLAY MORE THAN 1 GAME"<<endl;
					continue;
				}

				what_make=str;
				flag=false;
				break;
			}
			else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}
 	}
}
void Hex::creat_empty_array(){
	int i,j;
	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<uint32_t> dice(0,size_board-1);
	random[0]=dice(generator);
	random[1]=dice(generator);
	transition=true;	
	if(random[1]==size_board-1)
		random[1]-=1;
	if(random[1]==0)
		random[1]+=1;
	
	back_move[0]=random[0];
	back_move[1]=random[1];
	
	next_move[0]=random[0];
	next_move[1]=random[1];
	
	for(i=0;i<27;i++){
		for(j=0;j<3;j++){
			memory_bridge_rule[i][j]=-1;
		}
	}
		
		

	hexCell=new Cell*[size_board+1];
	undo=new int*[size_board+1];
	for(i=0;i<size_board+1;i++){
		hexCell[i]=new Cell[size_board+1];
		undo[i]=new int[size_board+1];
	}
	if(hexCell==nullptr||undo==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	for(i=0;i<size_board+1;i++){
		for(j=0;j<size_board+1;j++){
			undo[i][j]=0;
			hexCell[i][j].set_type(empty);
			hexCell[i][j].set_position_column(i);
			hexCell[i][j].set_position_row(j);
		}
	}
	if(user_who==1){
		hexCell[random[0]][random[1]].set_type(user1);
		undo[random[0]][random[1]]=1;
	}
}
/*HUMAN STEP*/
void Hex::play(char column,int row){
	if(turn==0){
		while(1){
			if(hexCell[column-65][row].get_type()=='.'){
				hexCell[column-65][row].set_type(user1);
				undo[column-65][row]=marked+1;
				break;
			}

			else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
				cin>>column>>row;
				row-=1;
			}
		}
	}
	else{
		while(1){
			if(hexCell[column-65][row].get_type()=='.'){
				undo[column-65][row]=marked+1;
				hexCell[column-65][row].set_type(user2);
				break;
			}
			
			else{
				cerr<<"ERROR!TRY AGAİN"<<endl;
				cin>>column>>row;
				row-=1;
				cout<<column<<row;
			}
		}
	}
	cout<<*this;

}
/*FİNİSH CONTROL*/
int Hex::finish_control_x(){
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
/*FİSNİSH CONTROL*/
int Hex::recursion_x(int column,int row,int counter){
	if(hexCell[column+1][row].get_type()=='x'&& counter<(size_board*3)){
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
int Hex:: finish_control_o(){
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
int Hex:: recursion_o(int column,int row,int counter){
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
/*SAVE THE GAME*/
void Hex::save_file(const string &str){
	ofstream outstream;
	outstream.open(str);
	outstream<<*this;
	outstream.close();

}
/*LOAD THE GAME*/
char Hex::load_file(const string &str){
	char ch;
	int x_=0,o_=0;
	int i,j;
	ifstream instream;
	instream.open(str);
	
	if(instream.fail())
		return '!';
	
	instream>>ch;
	instream.close();
	
	/*human or computer control*/
	if(ch=='f' && user_who==2)
		return 'c';
	else if(ch=='!' && user_who==1)
		return 'i';

	instream.open(str);
	instream>>(*this);
	instream.close();
	for(i=0;i<size_board;i++){
		for(j=0;j<size_board;j++){
			if(hexCell[i][j].get_type()=='x')
				x_++;
			else if(hexCell[i][j].get_type()=='o')
				o_++;
		}
	}

	if(x_==o_)
		return 'x';
	return 'o';
}

/*SAVE OR LOAD WICH ONE ? CONTROL */
int Hex::save_load(const string &str){		
	/*SAVING PROCEDURES*/
	char laod_control;
	if(str.compare(0,4,"SAVE")==0 ||str.compare(0,4,"save")==0){
		if(str.compare(str.size()-4,4,".txt")==0 || str.compare(str.size()-4,4,".TXT")==0){
			cout<<"SAVING...."<<endl;
			save_file(str.substr(5));
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
			laod_control=load_file(str.substr(5));
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
				cout<<*this;
				return 1;	
			}
			else if(laod_control=='o')
				cout<<*this;
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
/*COMPUTER STEP*/
void Hex:: play(){

	int i;
		
	/*computer's actions*/
	if(back_move[0]==0 && next_move[0]==size_board-1){
		i=bridge_rule_control();
		if(i==0){
			fill_bridge();

		}
	}
	else if(y_>=random[0] && next_move[0]!=size_board-1)
		right_move();
		
	else{
		if(back_move[0]!=0)
			left_move();
		else
			right_move();
	}

}

/*The priorities that the computer has to do in the movements to the right are listed.*/
void Hex::left_move(){
	if(bridge_rule_control()==1){
		cout<<*this;
		return;
		
	}
	if(back_move[0]==2 && hexCell[back_move[0]-1][back_move[1]].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]].set_type(user1);
		undo[back_move[0]-1][back_move[1]]=marked+1;
		back_move[0]=1;
		cout<<*this;
		return ;

	}
		
	else if(back_move[0]==2 && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'&& hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]+2].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		undo[back_move[0]-1][back_move[1]+1]=marked+1;
		back_move[0]=1;
		back_move[1]+=1;
		cout<<*this;
		return ;


	}
		
	else if(back_move[0]==1 && hexCell[back_move[0]-1][back_move[1]].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]].set_type(user1);
		undo[back_move[0]-1][back_move[1]]=marked+1;
		back_move[0]=0;
		cout<<*this;
		return ;



	}
	else if(back_move[0]==1 && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		undo[back_move[0]-1][back_move[1]+1]=marked+1;
		back_move[0]=0;
		back_move[1]+=1;
		cout<<*this;
		return ;

		}	
	else{
		bridge_rule_left();
		cout<<*this;
		return ;
	}
}

/*BRİDGE RULE ->>>  x .  there are 2 options
					 . x
						
Use bridges to make connections between your pieces and simultaneously to block your opponent.
*/

void Hex::bridge_rule_left(){
	int i=0;
	if(hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]].get_type()=='.' && back_move[1]!=size_board-2){
		hexCell[back_move[0]-2][back_move[1]+1].set_type(user1);
		undo[back_move[0]-2][back_move[1]+1]=marked+1;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;

	}

	else if(hexCell[back_move[0]-1][back_move[1]-1].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]].get_type()=='.' && hexCell[back_move[0]][back_move[1]-1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]-1].set_type(user1);
		undo[back_move[0]-1][back_move[1]-1]=marked+1;

		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=2;
		back_move[0]-=1;
		back_move[1]-=1;
	}

	else if(hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]].get_type()=='.'){
		hexCell[back_move[0]-2][back_move[1]+1].set_type(user1);
		undo[back_move[0]-2][back_move[1]+1]=marked+1;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;
		
	}
	else if(hexCell[back_move[0]-1][back_move[1]+2].get_type()=='.' && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+2].set_type(user1);
		undo[back_move[0]-1][back_move[1]+2]=marked+1;

		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=3;
		back_move[0]-=1;
		back_move[1]+=2;
	}
	else if(hexCell[back_move[0]-1][back_move[1]].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]].set_type(user1);
		undo[back_move[0]-1][back_move[1]]=marked+1;
		back_move[0]-=1;
	}
	else if(hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		undo[back_move[0]-1][back_move[1]+1]=marked+1;
		back_move[1]+=1;
		back_move[0]-=1;
	}
	else if(hexCell[back_move[0]][back_move[1]-1].get_type()=='.'){
		hexCell[back_move[0]][back_move[1]-1].set_type(user1);
		undo[back_move[0]][back_move[1]-1]=marked+1;
		back_move[1]-=1;
	}
}
/*The priorities that the computer has to do in the movements to the right are listed.*/
void Hex::right_move(){
	
	if(bridge_rule_control()==1){
		cout<<*this;
		return;
		
	}
	if(next_move[0]==size_board-3 && hexCell[next_move[0]+1][next_move[1]].get_type()=='.' &&hexCell[next_move[0]+2][next_move[1]].get_type()=='.' && hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.' ){
		hexCell[next_move[0]+1][next_move[1]].set_type(user1);
		undo[next_move[0]+1][next_move[1]]=marked+1;
		next_move[0]=size_board-2;
		cout<<*this;
		return;
	}
	else if(next_move[0]==size_board-3 && hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.' &&hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.' && hexCell[next_move[0]+2][next_move[1]-2].get_type()=='.' ){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		undo[next_move[0]+1][next_move[1]-1]=marked+1;
		next_move[0]=size_board-2;
		next_move[1]-=1;
		cout<<*this;
		return;
	}
	else if(next_move[0]==(size_board-2) && hexCell[next_move[0]+1][next_move[1]].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]].set_type(user1);
		undo[next_move[0]+1][next_move[1]]=marked+1;
		next_move[0]=size_board-1;
		cout<<*this;
		return;
	}
	else if(next_move[0]==size_board-2 && hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		undo[next_move[0]+1][next_move[1]-1]=marked+1;
		next_move[0]=size_board-1;
		next_move[1]-=1;
		cout<<*this;
		return ;
	}
	bridge_rule_right();
	cout<<*this;
	
}
/*BRİDGE RULE ->>>  x .  there are 2 options
					 . x
						
Use bridges to make connections between your pieces and simultaneously to block your opponent.*/

void Hex:: bridge_rule_right(){
	int i=0;
	if(hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.' && next_move[1]!=1){
		hexCell[next_move[0]+2][next_move[1]-1].set_type(user1);
		undo[next_move[0]+2][next_move[1]-1]=marked+1;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(hexCell[next_move[0]+1][next_move[1]+1].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]].get_type()=='.'&& hexCell[next_move[0]][next_move[1]+1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]+1].set_type(user1);
		undo[next_move[0]+1][next_move[1]+1]=marked+1;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=1;
		next_move[1]+=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=2;
	}
	else if(hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+2][next_move[1]-1].set_type(user1);
		undo[next_move[0]+2][next_move[1]-1]=marked+1;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(hexCell[next_move[0]+1][next_move[1]-2].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'&& hexCell[next_move[0]][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]-2].set_type(user1);
		undo[next_move[0]+1][next_move[1]-2]=marked+1;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		
		next_move[0]+=1;
		next_move[1]-=2;
		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=3;
	}
	else if(hexCell[next_move[0]+1][next_move[1]].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]].set_type(user1);
		undo[next_move[0]+1][next_move[1]]=marked+1;
		next_move[0]+=1;
	}
	else if(hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		undo[next_move[0]+1][next_move[1]-1]=marked+1;
		next_move[0]+=1;
		next_move[1]-=1;
	}
	else if(hexCell[next_move[0]][next_move[1]+1].get_type()=='.'){
		hexCell[next_move[0]][next_move[1]+1].set_type(user1);
		undo[next_move[0]][next_move[1]+1]=marked+1;
		next_move[1]+=1;
	}
}
int Hex:: bridge_rule_control(){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='o' && hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=marked+1;
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='o' &&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=marked+1;
				return 1;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='o'&& hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].set_type(user1);
				undo[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=marked+1;
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='o' && hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=marked+1;
				return 1;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='o'&&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=marked+1;
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='o'&&hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].set_type(user1);
				undo[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=marked+1;
				return 1;
			}
		}
	i++;

	}
	return 0;
}
void Hex:: fill_bridge(){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.' && hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=marked+1;
				return ;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'&& hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].set_type(user1);
				undo[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=marked+1;
				return ;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='.'&&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				undo[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=marked+1;
				return ;
			}
		}
	i++;

	}

}

bool Hex:: get_finish(){return finish;}

Hex Hex :: operator--(){
	int max;
	int x=0,y=0;
	int i,j,k=0;
	bool flag=false;
	if(user_who==2){
		max=undo[0][0];
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max<undo[i][j]){
					max=undo[i][j];
					x=i;
					y=j;
				}
			}
		}
		
		undo[x][y]=0;
		hexCell[x][y].set_type(empty);
		marked--;
	
	}
	
	if(user_who==1){
		max=undo[0][0];
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max<undo[i][j]){
					max=undo[i][j];
					x=i;
					y=j;
				}
			}
		}		
		undo[x][y]=0;
		hexCell[x][y].set_type(empty);

		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max-1==undo[i][j]){
					hexCell[i][j].set_type(empty);
					undo[i][j]=0;
				}
				if(undo[i][j]==(max-2)){
					while(memory_bridge_rule[k][0]!=-1){
						k++;
					}
						
					if(memory_bridge_rule[k-1][0]==i && memory_bridge_rule[k-1][1]==j){
						memory_bridge_rule[k-1][0]=-1;						
					}
					else if(x>=random[0]){
						if(memory_bridge_rule[k-1][0]==x && memory_bridge_rule[k-1][1]==y){
							memory_bridge_rule[k-1][0]=-1;
						}
					}
					
				}
				if(hexCell[i][j].get_type()=='x'){
					next_move[0]=i;
					next_move[1]=j;
					if(flag==false){
						back_move[0]=i;
						back_move[1]=j;
						flag=true;
					}
				}
			}
		}
	}
	return *this;
}
Hex Hex :: operator--(int ignoreMe){
	int max;
	int x=0,y=0;
	int i,j,k=0;
	bool flag=false;
	Hex tmp=*this;
	if(user_who==2){
		max=undo[0][0];
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max<undo[i][j]){
					max=undo[i][j];
					x=i;
					y=j;
				}
			}
		}
		
		undo[x][y]=0;
		hexCell[x][y].set_type(empty);
		marked--;
	
	}
	if(user_who==1){
		max=undo[0][0];
		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max<undo[i][j]){
					max=undo[i][j];
					x=i;
					y=j;
				}
			}
		}		
		undo[x][y]=0;
		hexCell[x][y].set_type(empty);

		for(i=0;i<size_board;i++){
			for(j=0;j<size_board;j++){
				if(max-1==undo[i][j]){
					hexCell[i][j].set_type(empty);
					undo[i][j]=0;
				}
				if(undo[i][j]==(max-2)){
					while(memory_bridge_rule[k][0]!=-1){
						k++;
					}
						
					if(memory_bridge_rule[k-1][0]==i && memory_bridge_rule[k-1][1]==j){
						memory_bridge_rule[k-1][0]=-1;						
					}
					else if(x>=random[0]){
						if(memory_bridge_rule[k-1][0]==x && memory_bridge_rule[k-1][1]==y){
							memory_bridge_rule[k-1][0]=-1;
						}
					}
					
				}
				if(hexCell[i][j].get_type()=='x'){
					next_move[0]=i;
					next_move[1]=j;
					if(flag==false){
						back_move[0]=i;
						back_move[1]=j;
						flag=true;
					}
				}
			}
		}
	}

	return tmp;
}


Hex::Hex(const Hex &copyc):
size_board(copyc.size_board),transition(copyc.transition),game_name(game_number),finish(copyc.finish),constr(copyc.constr),user_who(copyc.user_who),
turn(copyc.turn),x_(copyc.x_),y_(copyc.y_),marked(copyc.marked)
{
	int i,j;
	marked=copyc.marked;
	game_number++;
	
	hexCell=new Cell*[size_board+1];
	undo=new int*[size_board+1];
	
	for(i=0;i<size_board+1;i++){
		hexCell[i]=new Cell[size_board+1];
		undo[i]=new int[size_board+1];
	}
	if(hexCell==nullptr||undo==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	for(i=0;i<size_board+1;i++){
		for(j=0;j<size_board+1;j++){
			hexCell[i][j]=copyc.hexCell[i][j];
			undo[i][j]=copyc.undo[i][j];
		}
	}
	memory_bridge_rule=new int*[27];
	for(i=0;i<27;i++){
		memory_bridge_rule[i]=new int[3];
	}
	next_move=new int[2];
	back_move=new int[2];
	random=new int[2];
	if(next_move==nullptr||back_move==nullptr||random==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	
	for(i=0;i<2;i++){
		next_move[i]=copyc.next_move[i];
		back_move[i]=copyc.back_move[i];
		random[i]=copyc.random[i];
	}
	
	for(i=0;i<27;i++){
		for(j=0;j<3;j++){
			memory_bridge_rule[i][j]=copyc.memory_bridge_rule[i][j];
		}
	}

}
Hex &Hex:: operator=(const Hex &rightSide){
	int i,j;
	cout<<"girdi1";
	if(size_board!=rightSide.size_board){
		if(size_board!=0){
			cout<<"girdi2";
			for(i=0;i<size_board;i++){
				delete []hexCell[i];
				delete []undo[i];
			}
			delete []hexCell;
			delete []undo;
			cout<<"girdi2";
		}
		
		size_board=rightSide.size_board;
		hexCell=new Cell*[size_board+1];
		undo=new int*[size_board+1];
		if(hexCell==nullptr||undo==nullptr){
			cerr<<"MEMORY NOT ALLOCATED";
			exit(1);
		}
		for(i=0;i<size_board+1;i++){
			
			hexCell[i]=new Cell[size_board+1];
			undo[i]=new int[size_board+1];
		}
	}
	marked=rightSide.marked;
	transition=rightSide.transition;
	finish=rightSide.finish;
	constr=rightSide.constr;
	user_who=rightSide.user_who;
	turn=rightSide.turn;
	x_=rightSide.x_;
	y_=rightSide.y_;
	
	for(i=0;i<size_board;i++){
		for(j=0;j<size_board;j++){
			hexCell[i][j]=rightSide.hexCell[i][j];
			undo[i][j]=rightSide.undo[i][j];
		}
	}
	
	for(i=0;i<2;i++){
		next_move[i]=rightSide.next_move[i];
		back_move[i]=rightSide.back_move[i];
		random[i]=rightSide.random[i];
	}
	
	for(i=0;i<27;i++){
		for(j=0;j<3;j++){
			memory_bridge_rule[i][j]=rightSide.memory_bridge_rule[i][j];
		}
	}
	return *this;

}

ofstream& operator <<(ofstream & output,const Hex &other){
	char ch;
	int i,j;
		if(other.user_who==2){
			output<<"!";
		}
		else{
			output<<"f";
		}

	for(i=0;i<other.size_board;i++){
		for(j=0;j<other.size_board;j++){
			output<<other.hexCell[j][i].get_type();
		}
	}
	if(other.user_who==1){
		for(i=0;other.memory_bridge_rule[i][0]!=-1;i++){
			for(j=0;j<3;j++){
				output<<other.memory_bridge_rule[i][j]<<",";
			}
		}
	}
	output<<"\n";
	for(i=0;i<other.size_board+1;i++){
		for(j=0;j<other.size_board+1;j++){
			output<<other.undo[j][i]<<",";
		}
	}
	return output;
}
ostream &operator<<(ostream &output,const Hex &other){
	int i,j,k;
	char letters='a';
	output<<" ";
	for(i=0;i<other.size_board;i++){
		output<<(char)(letters+i)<<"  ";
	}
	output<<endl;
	for(i=0;i<other.size_board;i++){
		output<<i+1<<" ";
		for(k=0;k<i;k++){
			output<<" ";
		}
		for(j=0;j<other.size_board;j++){
			output<<other.hexCell[j][i].get_type()<<"  ";
		}
		output<<"\n";
	}
	return output;
}
ifstream &operator>>(ifstream &input,Hex &other){
	string copy;
	string undoo;
	int i,j=0,z=0;
	int count1=0,count2=0;
	string number;
	input>>copy;
	i=0;
	while(1){
		if(copy[i]=='x'||copy[i]=='o'||copy[i]=='.' || copy[i]=='f')
			i++;
		else
			break;
	}
	for(j=0;j<(other.size_board+1);j++){
		delete[]other.hexCell[j];
		delete[]other.undo[j];
	}
		delete[]other.hexCell;
		delete[]other.undo;
	other.size_board=sqrt(i);
	int x_=0,o_=0;
	
	/*x and o numbers to determine who's the turn*/ 
	for(i=0;i<copy.length();i++){
		if(copy[i]=='x')
			x_++;
		else if(copy[i]=='o')
			o_++;
	}
	other.marked=x_+o_;
	other.hexCell=new Hex::Cell*[other.size_board+1];
	other.undo=new int*[other.size_board+1];
	if(other.hexCell==nullptr||other.undo==nullptr){
		cerr<<"MEMORY NOT ALLOCATED";
		exit(1);
	}
	for(i=0;i<other.size_board+1;i++){
		other.hexCell[i]=new Hex::Cell[other.size_board+1];
		other.undo[i]=new int[other.size_board+1];
	}
	
	for(i=0;i<(other.size_board+1);i++){
		for(j=0;j<(other.size_board+1);j++){
			other.hexCell[i][j].set_type(empty);
			other.hexCell[i][j].set_position_column(i);
			other.hexCell[i][j].set_position_row(j);
		}
	}
	
	/*filling the board*/
	z=0;
	for(i=0;i<other.size_board;i++){
		for(j=0;j<other.size_board;j++){
			
			switch(copy[j+z+1]){
				case '.':
					other.hexCell[j][i].set_type(empty);
					break;
				case 'x':
					other.hexCell[j][i].set_type(user1);
					break;
				case 'o':
					other.hexCell[j][i].set_type(user2);
					break;
			}
		}
		z+=other.size_board;
	}
	input>>undoo;
	for(i=0;i<undoo.length();i++){
			if(undoo[i]!=','){
				
				if(undoo[i+1]!=','){
					number=undoo.substr(i,2);
					other.undo[count2][count1]=stoi(number);
					i++;
					count2++;
				}
				else{
					number=undoo.substr (i,1);	
					other.undo[count2][count1]=stoi(number);
					count2++;
				}
				
				if(count2>other.size_board){
					count1++;
					count2=0;
				}
		}
	}
	count1=0;
	count2=0;
	if(other.user_who==1){
		for(i=((other.size_board*other.size_board)+1);i<copy.length();i++){
			if(copy[i]!=','){
				
				if(copy[i+1]!=','){
					number=copy.substr(i,2);
					other.memory_bridge_rule[count1][count2]=stoi(number);
					i++;
					count2++;
				}
				else{
					number=copy.substr (i,1);	
					other.memory_bridge_rule[count1][count2]=stoi(number);
					count2++;
				}
				
				if(count2>2){
					count1++;
					count2=0;
				}
			}		
		}
		for(i=0;i<other.size_board;i++){
			for(j=0;j<other.size_board;j++){
				if(other.hexCell[i][j].get_type()=='x'){
					other.back_move[0]=i;
					other.back_move[1]=j;
					i=other.size_board;
					break;
				}
			}
		}
		for(i=0;i<other.size_board;i++){
			for(j=0;j<other.size_board;j++){
				if(other.hexCell[i][j].get_type()=='x'){
					other.next_move[0]=i;
					other.next_move[1]=j;
					
					break;
				}
			}
		}
	}
	return input;
}
bool Hex:: operator ==(const Hex &other)const{
	return (marked>other.marked);
}
Hex::~Hex(){
	
	game_number--;
	
	for(int i=0;i<size_board+1;i++){
		delete[]hexCell[i];
		delete[]undo[i];
	}
	delete []hexCell;
	delete []undo;
	for(int i=0;i<27;i++){
		delete[]memory_bridge_rule[i];
	}
	delete[]memory_bridge_rule;

	delete[] next_move;
	delete[] back_move;
	delete[] random;
}