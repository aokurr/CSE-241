#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

enum type{user1='x',user2='o',empty='.',win_user1='X',win_user2='O'};
class Hex{
	public:

		Hex();
		Hex(int size,int user);
		/*ALL GAME STEPS*/
		void play_game();
		bool get_finish();
		int get_all_marked()const;
		/*NEXTGAME BACKGAME CONTROL*/
		static string what_make;

	private:
		bool transition;
		static vector<int> marked;
		int static game_number;
		bool finish;
		class Cell;
		int constr;
		
		/*GAME FEATURE*/
		vector<vector<Cell>>hexCell;
		int game_name;
		int size_board;
		int user_who;
		
		/*single step for human*/
		void play(char column,int row);
		void print()const;
		
		int turn;
		void creat_empty_array();
		int x_;
		int y_;
	
	/*finsh control functions*/
	private:
		int  finish_control_x();
		int recursion_x(int column, int row,int counter);
		int finish_control_o();
		int recursion_o(int column,int row,int counter);
	
	/*save and load member func*/
	private:
		void save_file(const string &str);
		char load_file(const string &str);
		int save_load(const string &str);
	
	/*computer skills and their func*/
	private:
		/*single step for computer*/
		void play();
		
		void left_move();
		void bridge_rule_left();
		void right_move();
		void bridge_rule_right();
		int bridge_rule_control();
		void fill_bridge();
		int memory_bridge_rule[27][3];
		int next_move[2];
		int back_move[2];
		int random[2];
};
Hex::Hex(){
	marked.push_back(0);
	game_name=game_number;
	game_number++;
	transition=false;
	finish=false;
}
Hex::Hex(int size,int user):size_board(size),user_who(user){
	marked.push_back(0);
	game_name=game_number;
	game_number++;
	transition=true;
	finish=false;
	constr=1;
	play_game();
}
int Hex::game_number=0;
vector<int> Hex:: marked;
string Hex:: what_make="free";
class Hex::Cell{
	public:
	inline int get_position_row(){return row;} const
	
	inline void set_position_row(int a){a=row;}
	
	inline char get_position_column(){return column;} const
	
	inline void set_position_column(char b){column=b;}
	
	inline char get_type() const {return gamer;}
	
	inline void set_type(type a){gamer=a;}
	private:
		int row;
		char column;
		type gamer;

};

int main(){
	int count=0;
	Hex Games[5]; 
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

	}
	

	return 0;
}
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
				marked[game_name]++;
			}
		}
		if(constr==1){
			creat_empty_array();
		}
		print();
		
		while(flag==true){
			
			if(user_who==1 && flag==true){
				while(flag==true){
					cout<<"it's time for O (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					if(game_name!=0){
						cout<<"BACKGAME MARKED CELL= "<<marked[game_name-1]<<"\tTHİS GAME MARKED CELL= "<<marked[game_name]<<"\tALL MARKED GAMES= "<<get_all_marked()<<endl;
					}
					getline(cin,str,'\n');
					if(str.length()>3){
						
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0 ){
							
							if(str.compare("NEXTGAME")==0 && game_name+1==game_number){
								cerr<<"you are already in the last game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							
							if(str.compare("BACKGAME")==0 && game_name==0){
								cerr<<"you are already in the first game!!PLEASE TRY AGAIN"<<endl;
								continue;
							}
							if(str.compare("EXIT")==0 ){
								exit(1);
							}

							
							what_make=str;
							flag=false;
							break;
						}
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
						marked[game_name]++;
						break;
					}
					else
						cerr<<"ERROR!!"<<endl;
				}
				if(finish_control_o()==1){
					print();
					cout<<"PARTY TİMEEEE !! USER2  WINS!!!!"<<endl;
					flag=false;
					finish=true;
					what_make="WAİT";
					break;
				}
					if(flag==true){
					cout<<"it's time for X (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					play();
					marked[game_name]++;
					if(finish_control_x()==1){
						print();
						cout<<"PARTY TİMEEEE !! COMPUTER  WINS!!!!"<<endl;
						flag=false;
						finish=true;
						what_make="WAİT";
						break;
					}
					else
						print();
				}

			}
			
			else{
				while(flag==true){
					cout<<"it's time for X (please enter upper case for ex:A8)\t"<<game_name+1<<"rd game"<<endl;
					getline(cin,str,'\n');
					if(str.length()>3){
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0 ){
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
							what_make=str;
							flag=false;
							break;
						}
						if(save_load(str)==0);
							continue;
						if(save_load(str)==2){
							print();
							break;
						}
						else if(save_load(str)==1){
							print();
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
						marked[game_name]++;
						break;
					}
					else
						cerr<<"ERORR!!"<<endl;
				}
				if(finish_control_x()==1){
					print();
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
						if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0 || str.compare("EXIT")==0){
							if(str.compare("NEXTGAME")==0){
								cerr<<"YOU CAN ONLY SWİTCH DURİNG X"<<endl;
								continue;
							}
							if(str.compare("BACKGAME")==0){
								cerr<<"YOU CAN ONLY SWİTCH DURİNG X"<<endl;
								continue;
							}
							if(str.compare("EXIT")==0){
								exit(1);
							}

						}
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
						marked[game_name]++;
						break;
					}
					else 
						cerr<<"ERROR!!";
				}
				if(finish_control_o()==1){
					print();
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
 		if(flag==true){print();}
 		while(1){
	 		getline(cin,str,'\n');
	 		if(str.compare("NEXTGAME")==0 || str.compare("BACKGAME")==0||str.compare("EXIT")==0 ){
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
/*PRİNT BOARD*/
void Hex::print()const{
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
/*FİRST STEP .CREATE EMPTY ARRAY*/
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
/*HUMAN STEP*/
void Hex::play(char column,int row){
	if(turn==0){
		while(1){
			if(hexCell[column-65][row].get_type()=='.'){
				hexCell[column-65][row].set_type(user1);
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
	print();
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
	if(user_who==1){
		for(i=0;memory_bridge_rule[i][0]!=-1;i++){
			for(j=0;j<3;j++){
				outstream<<memory_bridge_rule[i][j]<<",";
			}
		}
	}
	outstream.close();

}
/*LOAD THE GAME*/
char Hex::load_file(const string &str){
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

	i=0;
	while(1){
		if(copy[i]=='x'||copy[i]=='o'||copy[i]=='.' || copy[i]=='f')
			i++;
		else
			break;
	}
	size_board=sqrt(i);
	int x_=0,o_=0;
	
	/*x and o numbers to determine who's the turn*/ 
	for(i=0;i<copy.length();i++){
		if(copy[i]=='x')
			x_++;
		else if(copy[i]=='o')
			o_++;
	}
	marked[game_name]=x_+o_;

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

	cout<<size_board<<endl;
	if(user_who==1){
		for(i=((size_board*size_board)+1);i<copy.length();i++){
			if(copy[i]!=','){
				
				if(copy[i+1]!=','){
					number=copy.substr(i,2);
					memory_bridge_rule[count1][count2]=stoi(number);
					i++;
					count2++;
				}
				else{
					number=copy.substr (i,1);	
					cout<<stoi(number)<<endl;
					memory_bridge_rule[count1][count2]=stoi(number);
					count2++;
				}
				
				if(count2>2){
					count1++;
					count2=0;
				}
			}		
		}
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
		print();
		return;
		
	}
	if(back_move[0]==2 && hexCell[back_move[0]-1][back_move[1]].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]].set_type(user1);
		back_move[0]=1;
		print();
		return ;

	}
		
	else if(back_move[0]==2 && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'&& hexCell[back_move[0]-2][back_move[1]+1].get_type()=='.' && hexCell[back_move[0]-2][back_move[1]+2].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		back_move[0]=1;
		back_move[1]+=1;
		print();
		return ;


	}
		
	else if(back_move[0]==1 && hexCell[back_move[0]-1][back_move[1]].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]].set_type(user1);
		back_move[0]=0;
		print();
		return ;



	}
	else if(back_move[0]==1 && hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		back_move[0]=0;
		back_move[1]+=1;
		print();
		return ;

		}	
	else{
		bridge_rule_left();
		print();
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
		back_move[0]-=1;
	}
	else if(hexCell[back_move[0]-1][back_move[1]+1].get_type()=='.'){
		hexCell[back_move[0]-1][back_move[1]+1].set_type(user1);
		back_move[1]+=1;
		back_move[0]-=1;
	}
	else if(hexCell[back_move[0]][back_move[1]-1].get_type()=='.'){
		hexCell[back_move[0]][back_move[1]-1].set_type(user1);
		back_move[1]-=1;
	}
}
/*The priorities that the computer has to do in the movements to the right are listed.*/
void Hex::right_move(){
	
	if(bridge_rule_control()==1){
		print();
		return;
		
	}
	if(next_move[0]==size_board-3 && hexCell[next_move[0]+1][next_move[1]].get_type()=='.' &&hexCell[next_move[0]+2][next_move[1]].get_type()=='.' && hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.' ){
		hexCell[next_move[0]+1][next_move[1]].set_type(user1);
		next_move[0]=size_board-2;
		print();
		return;
	}
	else if(next_move[0]==size_board-3 && hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.' &&hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.' && hexCell[next_move[0]+2][next_move[1]-2].get_type()=='.' ){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		next_move[0]=size_board-2;
		next_move[1]-=1;
		print();
		return;
	}
	else if(next_move[0]==(size_board-2) && hexCell[next_move[0]+1][next_move[1]].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]].set_type(user1);
		next_move[0]=size_board-1;
		print();
		return;
	}
	else if(next_move[0]==size_board-2 && hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		next_move[0]=size_board-1;
		next_move[1]-=1;
		print();
		return ;
	}
	bridge_rule_right();
	print();
	
}
/*BRİDGE RULE ->>>  x .  there are 2 options
					 . x
						
Use bridges to make connections between your pieces and simultaneously to block your opponent.*/

void Hex:: bridge_rule_right(){
	int i=0;
	if(hexCell[next_move[0]+2][next_move[1]-1].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]].get_type()=='.'&& hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.' && next_move[1]!=1){
		hexCell[next_move[0]+2][next_move[1]-1].set_type(user1);
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
		next_move[0]+=1;
	}
	else if(hexCell[next_move[0]+1][next_move[1]-1].get_type()=='.'){
		hexCell[next_move[0]+1][next_move[1]-1].set_type(user1);
		next_move[0]+=1;
		next_move[1]-=1;
	}
	else if(hexCell[next_move[0]][next_move[1]+1].get_type()=='.'){
		hexCell[next_move[0]][next_move[1]+1].set_type(user1);
		next_move[1]+=1;
	}
}
int Hex:: bridge_rule_control(){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='o' && hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='o' &&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].set_type(user1);
				return 1;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='o'&& hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].set_type(user1);
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='o' && hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].set_type(user1);
				return 1;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='o'&&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				return 1;
			}
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='o'&&hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].set_type(user1);
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
				return ;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]].get_type()=='.'&& hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1].set_type(user1);
				return ;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(hexCell[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1].get_type()=='.'&&hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].get_type()=='.'){
				hexCell[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1].set_type(user1);
				return ;
			}
		}
	i++;

	}

}
/*bool compare_game(const string &str){
	int number;
	number=stoi(str.substr (7,str.length()-7));
	if()
	
}*/
 bool Hex:: get_finish(){return finish;}


int Hex::get_all_marked()const{
	int i;
	int x=0;
	for(i=0;i<5;i++){
		x=x+marked[i];
	}
	return x;
}
