#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "library_ahmet.h"

using namespace std;

/*The process of returning int(enum) to char*/
template<typename T1 ,typename T2>
T2 convert(T1 a,T2 b){
	b=a;
	return b;
}
void menu(){
	auto size=0;
	auto user_computer=0;
	int random[2];
	int flag=0;
	auto a='a';
	auto m=0;
	cout<<"WELCOME TO HEX GAME!!"<<endl;
	while(flag==0){
		cout<<"PLEASE ENTER THE SIZE"<<endl;
		cout<<"6X6\t7X7\t8X8\t9X9\t10X10\t11X11\t12X12"<<endl;
		
		while(1){
			cin>>size>>a>>m;

			if(size<6 || size>12 || size!=m){
				cerr<<"INCORRET ENTRY PLEASE TRY AGAIN!!"<<endl;
				continue;
			}
			else if(a=='x' || a=='X'){
				break;
			}
			else
				cerr<<"INCORRET ENTRY PLEASE TRY AGAIN!!"<<endl;
			
		}
		
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
				cerr<<"İNCORRET ENTRY"<<endl;
				break;
		}
	}
}
void print(cells board[12][12],int size){
	int i,j,k;
	char letters[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	char ch;
	cout<<" ";
	for(i=0;i<size;i++){
		cout<<letters[i]<<"  ";
	}
	cout<<endl;
	for(i=0;i<size;i++){
		cout<<i+1<<" ";
		for(k=0;k<i;k++){
			cout<<" ";
		}
		for(j=0;j<size;j++){
			cout<<convert(board[j][i],ch)<<"  ";
		}
		cout<<"\n";
	}
}
int finish_control_x(cells board[12][12],int size){
	int i;
	int flag=0;
	int control_start_end[2]={0,0};
	
	int counter=0;
	/*Determines the starting position of x*/
	for(i=0;i<size;i++){
		if(board[0][i]=='x'){
			flag=recursion_x(board,0,i,size,counter);
		}
		if(flag==1){
			board[0][i]=d;
			return 1;		
		}
	}
	return 0;
}

int recursion_x(cells board[12][12],int column,int row,int size,int counter){
	/*west*/
	if(board[column+1][row]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column+1),row,size,(counter+1))==1){
		 	board[column+1][row]=d;
		 	return 1;
		 }
	}
	/*northwest*/
	else if(board[column+1][row-1]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column+1),(row-1),size,(counter+1))==1){
		 	board[column+1][row-1]=d;
		 	return 1;
		 }
	}
	/*north*/
	else if(board[column][row+1]=='x' && counter<(size*3)){
		 
		 if(recursion_x(board,column,(row+1),size,(counter+1))==1){
		 	board[column][row+1]=d;
		 	return 1;
		 }
	}

	/*south*/
	else if(board[column][row-1]=='x'&& counter<(size*3)){
		 if(recursion_x(board,column,row-1,size,(counter+1))==1){
		 	board[column][row-1]=d;
		 	return 1;
		 }
	}
	/*east*/
	if(board[column-1][row]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column-1),row,size,(counter+1))==1){
		 	board[column-1][row]=d;
		 	return 1;
		 }
	}
	
	if(column==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
int finish_control_o(cells board[12][12],int size){
	int i,counter=0;
	int flag=0;
	int control_start_end[2]={0,0};
	/*Determines the starting position of o*/
	for(i=0;i<size;i++){
		if(board[i][0]=='o'){
			flag=recursion_o(board,i,0,size,counter);
		}
		if(flag==1){
			board[i][0]=e;
			return 1;
		}
	}
	return 0;	

}
int recursion_o(cells board[12][12],int column,int row,int size,int counter){
	/*north*/
	if(board[column][row+1]=='o' && counter<(size*3)){
		 
		 if(recursion_o(board,column,(row+1),size,(counter+1))==1){
		 	board[column][row+1]=e;
		 	return 1;
		 }
	}
	/*west*/
	else if(board[column+1][row]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column+1),row,size,(counter+1))==1){
		 	board[column+1][row]=e;
		 	return 1;
		 }
	}
	/*east*/
	else if(board[column-1][row]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column-1),(row),size,(counter+1))==1){
		 	board[column-1][row]=e;
		 	return 1;
		 }
	}
	/*northeast*/
	else if(board[column-1][row+1]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column-1),(row+1),size,(counter+1))==1){
		 	board[column-1][row+1]=e;
		 	return 1;
		 }
	}
	
	if(row==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
void play_user(int size){
	int i,j;
	cells board[12][12];	
	char column;
	int row;
	char laod_control;
	string str;
	string str2;

	for( i=0;i<size;i++){
		for(j=0;j<size;j++){
			board[i][j]=a;
		}
	}
	print(board,size);
	
	while(1){
		if(finish_control_o(board,size)==1)
			break;
		
		/*x user's actions*/
		while(1){
			cout<<"it's time for X (please enter upper case for ex:A8)"<<endl;
			
			cin>>str;
			if(str.size()==4){
				cin>>str2;
				
				/*SAVING PROCEDURES*/
				if(str.compare(0,4,"SAVE")==0 ||str.compare(0,4,"save")==0){
					if(str2.compare(str2.size()-4,4,".txt")==0 || str2.compare(str2.size()-4,4,".TXT")==0){
						cout<<"SAVING...."<<endl;
						save_file(board,size,str2);
						continue;
					}
					else{
						cerr<<"ERROR!!you should enter a file.txt!!!!"<<endl;
					}
				}
				
				/*LOADING PROCEDURES*/

				else if(str.compare(0,4,"LOAD")==0 ||str.compare(0,4,"load")==0)
					if(str2.compare((str2.size()-4),4,".txt")==0 ||str2.compare((str2.size()-4),4,".TXT")==0){
						cout<<"LOADİNG..."<<endl;
						
						laod_control=load_file(board,size,str2);
						
						if(laod_control=='!'){
							cerr<<"ERROR!!File open failed"<<endl;
							continue;
						}
						
						else if(laod_control=='e'){
							cerr<<"ERROR!!this file is computer vs human file...please try again"<<endl;
							continue;
						}
						
						else if(laod_control=='x'){
							print(board,size);
							continue;	
						}
						else
							break;
						
					}
					else{
						cerr<<"ERROR!!you should enter a file.txt!!"<<endl;
				}				
			}
			
			else if (str.length()>1 && str[0]>='A' && str[0]<='Z'){
				column=str[0];
				str.erase(str.begin());
				row=stoi(str);
			
			
				if(board[column-65][row-1]=='.'){
					board[column-65][row-1]=b;
					break;
				}
				else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
				}
	
			}
			
			else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}
		
		print(board,size);
		if(finish_control_x(board,size)==1)
			break;
		/*o user's actions*/
		

		while(1){
			cout<<"it's time for O (please enter upper case for ex:A8)"<<endl;
			cin>>str;
			
			if(str.size()==4){
				cin>>str2;
				
				/*SAVING PROCEDURE*/
				if(str.compare(0,4,"SAVE")==0 ||str.compare(0,4,"save")==0){
					if(str2.compare(str2.size()-4,4,".txt")==0 || str2.compare(str2.size()-4,4,".TXT")==0){
						cout<<"SAVING...."<<endl;
						save_file(board,size,str2);
						
						continue;
					}
					else{
						cerr<<"ERROR!!you should enter a file.txt "<<endl;
					}
				}
				
				/*LOADING PRECODURE*/
				else if(str.compare(0,4,"LOAD")==0 ||str.compare(0,4,"load")==0)
					if(str2.compare((str2.size()-4),4,".txt")==0 || str2.compare((str2.size()-4),4,".TXT")==0){
						
						cout<<"LOADİNG..."<<endl;
						laod_control=load_file(board,size,str2);
						
						if(laod_control=='!'){
							cerr<<"ERROR!!File open failed"<<endl;
							continue;
						}
						else if(laod_control=='e'){
							cerr<<"ERROR!!this file is computer vs human file...please try again"<<endl;
							continue;
						}
						else if(laod_control=='o'){
							print(board,size);
							continue;	
						}
						
						else
							break;
					}
					else{
						cerr<<"ERROR!!you should enter a file.txt ";
				}				
			}
			else if (str.length()>1 && str[0]>='A' && str[0]<='Z'){
				column=str[0];
				str.erase(str.begin());
				row=stoi(str);
			
			
				if(board[column-65][row-1]=='.'){
					board[column-65][row-1]=c;
					break;
				}
				else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
				}
	
			}
			
			else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}
			print(board,size);	
	}

		print(board,size);
}


void play_computer(int size,int random[2]){
	int i,j;
	cells board[12][12];	
	int memory_bridge_rule[12][3];
	int row;
	char column;
	string str,str2;
	int laod_control;
	for(i=0;i<12;i++){
		memory_bridge_rule[i][0]=-1;
	}

	/*Keeps the computer's forward and backward movements in memory*/
	int back_move[2];
	int next_move[2];
	
	for( i=0;i<size;i++){
		for(j=0;j<size;j++){
			board[i][j]=a;
		}
	}
	board[random[0]][random[1]]=b;
	print(board,size);
	
	back_move[0]=random[0];
	back_move[1]=random[1];
	
	next_move[0]=random[0];
	next_move[1]=random[1];
	
	while(1){	
		i=0;
		
		/*user's actions*/
		while(1){
			
			cout<<"it's time for O (please enter upper case for ex:A8)"<<endl;
			cin>>str;
			
			if(str.size()==4){
				cin>>str2;
				
				/*SAVING PROCEDURE*/
				if(str.compare(0,4,"SAVE")==0 ||str.compare(0,4,"save")==0){
					if(str2.compare(str2.size()-4,4,".txt")==0||str2.compare(str2.size()-4,4,".TXT")==0){
						cout<<"SAVING...."<<endl;
						save_file(board,size,str2,memory_bridge_rule);
						
						continue;
					}
					else{
						cerr<<"ERROR!!you should enter a file.txt "<<endl;
					}
				}
				/*SAVING PROCEDURE*/
				else if(str.compare(0,4,"LOAD")==0 ||str.compare(0,4,"load")==0){
					if(str2.compare((str2.size()-4),4,".txt")==0||str2.compare((str2.size()-4),4,".TXT")==0){
						
						cout<<"LOADİNG..."<<endl;
						laod_control=load_file_(board,size,str2,memory_bridge_rule,next_move,back_move);
						cout<<"\n";
					
						if(laod_control==0){
							cerr<<"ERROR!!File open failed"<<endl;
							continue;

						}
						else if(laod_control==2){			
							cerr<<"ERROR!!this file is human vs human file please try again"<<endl;
							continue;

						}
						else if(laod_control==1){
							print(board,size);
							continue;	
						}	
					}
				}
				else{
					cerr<<"ERROR!!you should enter a file.txt "<<endl;
				}				
			}
			else if (str.length()>1 && str[0]>='A' && str[0]<='Z'){
				column=str[0];
				str.erase(str.begin());
				row=stoi(str);
			
			
				if(board[column-65][row-1]=='.'){
					board[column-65][row-1]=c;
					break;
				}
				else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
				}
	
			}
			
			else{
				cerr<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}	
		print(board,size);
		
		
		/*computer's actions*/
		if(back_move[0]==0 && next_move[0]==size-1){
			i=bridge_rule_control(memory_bridge_rule,board);
			if(i==0){
				fill_bridge(board,memory_bridge_rule);

			}
			if(finish_control_x(board,size)==1)
				break;
		
			print(board,size);

			continue;
		}
		if((column-65)>=random[0] && next_move[0]!=size-1)
			right_move(memory_bridge_rule,board,next_move,size);
		
		else{
			if(back_move[0]!=0)
				left_move(memory_bridge_rule,board,back_move,size);
			else
				right_move(memory_bridge_rule,board,next_move,size);
		}
		if(finish_control_x(board,size)==1)
			break;

	}
	print(board,size);

}

/*BRİDGE RULE ->>>  x .  there are 2 options
					 . x
						
Use bridges to make connections between your pieces and simultaneously to block your opponent.
*/

void bridge_rule_left(cells board[12][12],int size,int back_move[2],int memory_bridge_rule[12][3]){
	int i=0;
	if(board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]]=='.' && back_move[1]!=size-2){
		board[back_move[0]-2][back_move[1]+1]=b;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;

	}

	else if(board[back_move[0]-1][back_move[1]-1]=='.' && board[back_move[0]-1][back_move[1]]=='.' && board[back_move[0]][back_move[1]-1]=='.'){
		board[back_move[0]-1][back_move[1]-1]=b;


		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=2;
		back_move[0]-=1;
		back_move[1]-=1;
	}

	else if(board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-2][back_move[1]+1]=b;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;
		
	}
	else if(board[back_move[0]-1][back_move[1]+2]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+2]=b;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=3;
		back_move[0]-=1;
		back_move[1]+=2;
	}
	else if(board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-1][back_move[1]]=b;
		back_move[0]-=1;
	}
	else if(board[back_move[0]-1][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+1]=b;
		back_move[1]+=1;
		back_move[0]-=1;
	}
	else if(board[back_move[0]][back_move[1]-1]=='.'){
		board[back_move[0]][back_move[1]-1]=b;
		back_move[1]-=1;
	}
}

/*BRİDGE RULE CONTORL ->>>  x o   if 1 option is occupied we must settle on another
					         . x

and the connection is provided-> x  o
							       x  x
*/
int bridge_rule_control(int memory_bridge_rule[12][3],cells board[12][12]){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='o' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=b;
				return 1;
			}
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='o' &&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=b;
				return 1;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='o'&& board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=b;
				return 1;
			}
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='o' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=b;
				return 1;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='o'&&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=b;
				return 1;
			}
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='o'&&board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=b;
				return 1;
			}
		}
	i++;

	}
	return 0;
}
/*The priorities that the computer has to do in the movements to the right are listed.*/
void left_move(int memory_bridge_rule[12][3],cells board[12][12],int back_move[2],int size){
	if(bridge_rule_control(memory_bridge_rule,board)==1){
		print(board,size);
		return;
		
	}
	if(back_move[0]==2 && board[back_move[0]-1][back_move[1]]=='.' && board[back_move[0]-2][back_move[1]]=='.' && board[back_move[0]-2][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]]=b;
		back_move[0]=1;
		print(board,size);
		return ;

	}
		
	else if(back_move[0]==2 && board[back_move[0]-1][back_move[1]+1]=='.'&& board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-2][back_move[1]+2]=='.'){
		board[back_move[0]-1][back_move[1]+1]=b;
		back_move[0]=1;
		back_move[1]+=1;
		print(board,size);
		return ;


	}
		
	else if(back_move[0]==1 && board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-1][back_move[1]]=b;
		back_move[0]=0;
		print(board,size);
		return ;



	}
	else if(back_move[0]==1 && board[back_move[0]-1][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+1]=b;
		back_move[0]=0;
		back_move[1]+=1;
		print(board,size);
		return ;

		}	
	else{
		bridge_rule_left(board,size,back_move,memory_bridge_rule);
		print(board,size);
		return ;
	}
}
/*The priorities that the computer has to do in the movements to the right are listed.*/
void right_move(int memory_bridge_rule[12][3],cells board[12][12],int next_move[2],int size){
	
	if(bridge_rule_control(memory_bridge_rule,board)==1){
		print(board,size);
		return;
		
	}
	
	if(next_move[0]==size-3 && board[next_move[0]+1][next_move[1]]=='.' &&board[next_move[0]+2][next_move[1]]=='.' && board[next_move[0]+2][next_move[1]-1]=='.' ){
		board[next_move[0]+1][next_move[1]]=b;
		next_move[0]=size-2;
		print(board,size);
		return;
	}
	else if(next_move[0]==size-3 && board[next_move[0]+1][next_move[1]-1]=='.' &&board[next_move[0]+2][next_move[1]-1]=='.' && board[next_move[0]+2][next_move[1]-2]=='.' ){
		board[next_move[0]+1][next_move[1]-1]=b;
		next_move[0]=size-2;
		next_move[1]-=1;
		print(board,size);
		return;
	}
	else if(next_move[0]==(size-2) && board[next_move[0]+1][next_move[1]]=='.'){
		board[next_move[0]+1][next_move[1]]=b;
		next_move[0]=size-1;
		print(board,size);
		return;
	}
	else if(next_move[0]==size-2 && board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+1][next_move[1]-1]=b;
		next_move[0]=size-1;
		next_move[1]-=1;
		print(board,size);
		return ;
	}
	bridge_rule_right(board,size,next_move,memory_bridge_rule);
	print(board,size);
	
}

/*BRİDGE RULE ->>>  x .  there are 2 options
					 . x
						
Use bridges to make connections between your pieces and simultaneously to block your opponent.*/

void bridge_rule_right(cells board[12][12],int size,int next_move[2],int memory_bridge_rule[12][3]){
	int i=0;
	if(board[next_move[0]+2][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.' && next_move[1]!=1){
		board[next_move[0]+2][next_move[1]-1]=b;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(board[next_move[0]+1][next_move[1]+1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]][next_move[1]+1]){
		board[next_move[0]+1][next_move[1]+1]=b;
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=1;
		next_move[1]+=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=2;
	}
	else if(board[next_move[0]+2][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+2][next_move[1]-1]=b;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(board[next_move[0]+1][next_move[1]-2]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]-1]){
		board[next_move[0]+1][next_move[1]-2]=b;
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		
		next_move[0]+=1;
		next_move[1]-=2;
		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=3;
	}
	else if(board[next_move[0]+1][next_move[1]]=='.'){
		board[next_move[0]+1][next_move[1]]=b;
		next_move[0]+=1;
	}
	else if(board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+1][next_move[1]-1]=b;
		next_move[0]+=1;
		next_move[1]-=1;
	}
	else if(board[next_move[0]][next_move[1]+1]=='.'){
		board[next_move[0]][next_move[1]+1]=b;
		next_move[1]+=1;
	}
}
/*FİLL RULE ->>>  x .     If only empty bridges are left they will be filled
					 . x

	x  x    and the connection is provided
	  .  x						
*/

void fill_bridge(cells board[12][12],int memory_bridge_rule[12][3]){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=b;
				return ;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'&& board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=b;
				return ;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='.'&&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=b;
				return ;
			}
		}
	i++;

	}

}
int sqrt(int x=12){
	int a=0;
	while(1){
		if(a*a==x){
			return a;
		}
		a++;
	}
}
void save_file(cells board[12][12],const int &size,const string &str2){
	ofstream outstream;
	outstream.open(str2);
	char ch;
	int i,j;
	outstream<<"!";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			outstream<<convert(board[j][i],ch);
		}
	}
	outstream.close();

}
char load_file(cells board[12][12],int &size,const string &str2){
	string copy;
	int i,j,z=0;
	ifstream instream;
	instream.open(str2);
	
	if(instream.fail())
		return '!';
	
	instream>>copy;
	instream.close();
	
	/*human or computer control*/
	if(copy[0]=='f')
		return 'e';
	

	size=sqrt(copy.length()-1);
	int x_=0,o_=0;
	
	/*x and o numbers to determine who's the turn*/ 
	for(i=0;i<copy.length();i++){
		if(copy[i]=='x')
			x_++;
		else if(copy[i]=='o')
			o_++;
	}

	/*filling the board*/
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			
			switch(copy[j+z+1]){
				case '.':
					board[j][i]=a;
					break;
				case 'x':
					board[j][i]=b;
					break;
				case 'o':
					board[j][i]=c;
					break;
			}
		}
		z+=size;
	}

	if(x_==o_)
		return 'x';
	return 'o';
}
void save_file(cells board[12][12],const int &size,const string &str2,int memory_bridge_rule[12][3]){
	ofstream outstream;
	outstream.open(str2);
	char ch;
	int i,j;
	outstream<<"f";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			outstream<<convert(board[j][i],ch);
		}
	}
	for(i=0;memory_bridge_rule[i][0]!=-1;i++){
		for(j=0;j<3;j++){
			outstream<<memory_bridge_rule[i][j]<<",";
		}
	}
	outstream.close();

}
int load_file_(cells board[12][12],int &size,const string &str2,int memory_bridge_rule[12][3],int next_move[2],int back_move[2]){
	string copy;
	string number;
	int i=0,j,z=0;
	int x=0,y=0;
	
	
	ifstream instream;
	instream.open(str2);
	if(instream.fail())
		return 0;

	instream>>copy;

	instream.close();
	if(copy[0]=='!'){
		return 2;
	}
	for(i=0;i<12;i++){
		memory_bridge_rule[i][0]=-1;
	}
	i=0;
	while(1){
		if(copy[i]=='x'||copy[i]=='o'||copy[i]=='.' || copy[i]=='f')
			i++;
		else
			break;
	}

	i-=1;
	size=sqrt(i);
	int x_=0,o_=0;
	
	/*filling the board*/ 
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			
			switch(copy[j+z+1]){
				case '.':
					board[j][i]=a;
					break;
				case 'x':
					board[j][i]=b;
					break;
				case 'o':
					board[j][i]=c;
					break;
			}
		}
		z+=size;
	}

	/*rule map of the loaded table*/
	for(i=((size*size)+1);i<copy.length();i++){
		if(copy[i]!=','){
			
			if(copy[i+1]!=','){
				number=copy.substr (i,2);

				memory_bridge_rule[x][y]=stoi(number);
				i++;
				y++;
			}
			else{
				number=copy.substr (i,1);	
				memory_bridge_rule[x][y]=stoi(number);
				y++;
			}
			
			if(y==3){
				x++;
				y=0;
			}
		}		
	}
	
	/*Identification of the front and rear point*/
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(board[i][j]=='x'){
				back_move[0]=i;
				back_move[1]=j;
				i=size;
				break;
			}
		}
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(board[i][j]=='x'){
				next_move[0]=i;
				next_move[1]=j;
				
				break;
			}
		}
	}
	return 1;
	
}