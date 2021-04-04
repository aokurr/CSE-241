#include <iostream>
#include "library_ahmet.h"
#include <random>

using namespace std;
void print(char board[12][12],int size){
	int i,j,k;
	char letters[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
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
			cout<<board[j][i]<<"  ";
		}
		cout<<"\n";
	}
}
void play_user(int size){
	int i,j;
	char board[12][12];	
	char column;
	int row;
	for( i=0;i<size;i++){
		for(j=0;j<size;j++){
			board[i][j]='.';
		}
	}
	print(board,size);
	
	while(1){
		if(finish_control_o(board,size)==1)
			break;
		/*x user's actions*/
		while(1){
			cout<<"it's time for X (please enter upper case for ex:A8)"<<endl;
			
			cin.clear();
		    cin.ignore(100,'\n');
			cin>>column>>row;
			
			if(board[column-65][row-1]=='.'){
				board[column-65][row-1]='x';
				break;
			}
			else{
				cout<<column<<row<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}
		print(board,size);
		if(finish_control_x(board,size)==1)
			break;
		/*o user's actions*/
		while(1){
			cout<<"it's time for O (please enter upper case for ex:A8)"<<endl;
			
			cin.clear();
			cin.ignore(100,'\n');
			cin>>column>>row;
			
			if(board[column-65][row-1]=='.'){
				board[column-65][row-1]='o';
				break;
			}
			
			else{
				cout<<column<<row<<"ERROR!!PLEASE TRY AGAIN"<<endl;
			}
		}
			print(board,size);	
	}

		print(board,size);
}

int finish_control_x(char board[12][12],int size){
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
			board[0][i]='X';
			return 1;		
		}
	}
	return 0;
}

int recursion_x(char board[12][12],int column,int row,int size,int counter){
	/*west*/
	if(board[column+1][row]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column+1),row,size,(counter+1))==1){
		 	board[column+1][row]='X';
		 	return 1;
		 }
	}
	/*northwest*/
	else if(board[column+1][row-1]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column+1),(row-1),size,(counter+1))==1){
		 	board[column+1][row-1]='X';
		 	return 1;
		 }
	}
	/*north*/
	else if(board[column][row+1]=='x' && counter<(size*3)){
		 
		 if(recursion_x(board,column,(row+1),size,(counter+1))==1){
		 	board[column][row+1]='X';
		 	return 1;
		 }
	}

	/*south*/
	else if(board[column][row-1]=='x'&& counter<(size*3)){
		 if(recursion_x(board,column,row-1,size,(counter+1))==1){
		 	board[column][row-1]='X';
		 	return 1;
		 }
	}
	/*east*/
	if(board[column-1][row]=='x'&& counter<(size*3)){
		 if(recursion_x(board,(column-1),row,size,(counter+1))==1){
		 	board[column-1][row]='x';
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
int finish_control_o(char board[12][12],int size){
	int i,counter=0;
	int flag=0;
	int control_start_end[2]={0,0};
	/*Determines the starting position of o*/
	for(i=0;i<size;i++){
		if(board[i][0]=='o'){
			flag=recursion_o(board,i,0,size,counter);
		}
		if(flag==1){
			board[i][0]='O';
			return 1;
		}
	}
	return 0;	

}
int recursion_o(char board[12][12],int column,int row,int size,int counter){
	/*north*/
	if(board[column][row+1]=='o' && counter<(size*3)){
		 
		 if(recursion_o(board,column,(row+1),size,(counter+1))==1){
		 	board[column][row+1]='O';
		 	return 1;
		 }
	}
	/*west*/
	else if(board[column+1][row]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column+1),row,size,(counter+1))==1){
		 	board[column+1][row]='O';
		 	return 1;
		 }
	}
	/*east*/
	else if(board[column-1][row]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column-1),(row),size,(counter+1))==1){
		 	board[column-1][row]='O';
		 	return 1;
		 }
	}
	/*northeast*/
	else if(board[column-1][row+1]=='o' && counter<(size*3)){
		 if(recursion_o(board,(column-1),(row+1),size,(counter+1))==1){
		 	board[column-1][row+1]='O';
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

void play_computer(int size,int random[2]){
	int i,j;
	char board[12][12];	
	int memory_bridge_rule[12][3];
	int row;
	char column;
	for(i=0;i<12;i++){
		memory_bridge_rule[i][0]=-1;
	}

	/*Keeps the computer's forward and backward movements in memory*/
	int back_move[2];
	int next_move[2];
	
	for( i=0;i<size;i++){
		for(j=0;j<size;j++){
			board[i][j]='.';
		}
	}
	board[random[0]][random[1]]='x';
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
			
			cin.clear();
			cin.ignore(100,'\n');
			cin>>column>>row;
			
			if(board[column-65][row-1]=='.'){
				board[column-65][row-1]='o';
				break;
			}
				
			else{
				cout<<column<<row<<"ERROR!!PLEASE TRY AGAIN"<<endl;
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

void bridge_rule_left(char board[12][12],int size,int back_move[2],int memory_bridge_rule[12][3]){
	int i=0;
	if(board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]]=='.' && back_move[1]!=size-2){
		board[back_move[0]-2][back_move[1]+1]='x';
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;

	}

	else if(board[back_move[0]-1][back_move[1]-1]=='.' && board[back_move[0]-1][back_move[1]]=='.' && board[back_move[0]][back_move[1]-1]=='.'){
		board[back_move[0]-1][back_move[1]-1]='x';


		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=2;
		back_move[0]-=1;
		back_move[1]-=1;
	}

	else if(board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-2][back_move[1]+1]='x';
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=1;
		back_move[0]-=2;
		back_move[1]+=1;
		
	}
	else if(board[back_move[0]-1][back_move[1]+2]=='.' && board[back_move[0]-1][back_move[1]+1]=='.' && board[back_move[0]][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+2]='x';
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		memory_bridge_rule[i][0]=back_move[0];
		memory_bridge_rule[i][1]=back_move[1];
		memory_bridge_rule[i][2]=3;
		back_move[0]-=1;
		back_move[1]+=2;
	}
	else if(board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-1][back_move[1]]='x';
		back_move[0]-=1;
	}
	else if(board[back_move[0]-1][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+1]='x';
		back_move[1]+=1;
		back_move[0]-=1;
	}
	else if(board[back_move[0]][back_move[1]-1]=='.'){
		board[back_move[0]][back_move[1]-1]='x';
		back_move[1]-=1;
	}
}

/*BRİDGE RULE CONTORL ->>>  x o   if 1 option is occupied we must settle on another
					         . x

and the connection is provided-> x  o
							       x  x
*/
int bridge_rule_control(int memory_bridge_rule[12][3],char board[12][12]){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='o' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]='x';
				return 1;
			}
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='o' &&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]='x';
				return 1;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='o'&& board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]='x';
				return 1;
			}
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='o' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]='x';
				return 1;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='o'&&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]='x';
				return 1;
			}
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='o'&&board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]='x';
				return 1;
			}
		}
	i++;

	}
	return 0;
}
/*The priorities that the computer has to do in the movements to the right are listed.*/
void left_move(int memory_bridge_rule[12][3],char board[12][12],int back_move[2],int size){
	if(bridge_rule_control(memory_bridge_rule,board)==1){
		print(board,size);
		return;
		
	}
	if(back_move[0]==2 && board[back_move[0]-1][back_move[1]]=='.' && board[back_move[0]-2][back_move[1]]=='.' && board[back_move[0]-2][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]]='x';
		back_move[0]=1;
		print(board,size);
		return ;

	}
		
	else if(back_move[0]==2 && board[back_move[0]-1][back_move[1]+1]=='.'&& board[back_move[0]-2][back_move[1]+1]=='.' && board[back_move[0]-2][back_move[1]+2]=='.'){
		board[back_move[0]-1][back_move[1]+1]='x';
		back_move[0]=1;
		back_move[1]+=1;
		print(board,size);
		return ;


	}
		
	else if(back_move[0]==1 && board[back_move[0]-1][back_move[1]]=='.'){
		board[back_move[0]-1][back_move[1]]='x';
		back_move[0]=0;
		print(board,size);
		return ;



	}
	else if(back_move[0]==1 && board[back_move[0]-1][back_move[1]+1]=='.'){
		board[back_move[0]-1][back_move[1]+1]='x';
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
void right_move(int memory_bridge_rule[12][3],char board[12][12],int next_move[2],int size){
	
	if(bridge_rule_control(memory_bridge_rule,board)==1){
		print(board,size);
		return;
		
	}
	
	if(next_move[0]==size-3 && board[next_move[0]+1][next_move[1]]=='.' &&board[next_move[0]+2][next_move[1]]=='.' && board[next_move[0]+2][next_move[1]-1]=='.' ){
		board[next_move[0]+1][next_move[1]]='x';
		next_move[0]=size-2;
		print(board,size);
		return;
	}
	else if(next_move[0]==size-3 && board[next_move[0]+1][next_move[1]-1]=='.' &&board[next_move[0]+2][next_move[1]-1]=='.' && board[next_move[0]+2][next_move[1]-2]=='.' ){
		board[next_move[0]+1][next_move[1]-1]='x';
		next_move[0]=size-2;
		next_move[1]-=1;
		print(board,size);
		return;
	}
	else if(next_move[0]==(size-2) && board[next_move[0]+1][next_move[1]]=='.'){
		board[next_move[0]+1][next_move[1]]='x';
		next_move[0]=size-1;
		print(board,size);
		return;
	}
	else if(next_move[0]==size-2 && board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+1][next_move[1]-1]='x';
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

void bridge_rule_right(char board[12][12],int size,int next_move[2],int memory_bridge_rule[12][3]){
	int i=0;
	if(board[next_move[0]+2][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.' && next_move[1]!=1){
		board[next_move[0]+2][next_move[1]-1]='x';
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(board[next_move[0]+1][next_move[1]+1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]][next_move[1]+1]){
		board[next_move[0]+1][next_move[1]+1]='x';
		
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=1;
		next_move[1]+=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=2;
	}
	else if(board[next_move[0]+2][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+2][next_move[1]-1]='x';
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		next_move[0]+=2;
		next_move[1]-=1;

		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=1;

	}
	else if(board[next_move[0]+1][next_move[1]-2]=='.'&& board[next_move[0]+1][next_move[1]-1]=='.'&& board[next_move[0]+1][next_move[1]-1]){
		board[next_move[0]+1][next_move[1]-2]='x';
		while(memory_bridge_rule[i][0]!=-1)
			i++;
		
		next_move[0]+=1;
		next_move[1]-=2;
		memory_bridge_rule[i][0]=next_move[0];
		memory_bridge_rule[i][1]=next_move[1];
		memory_bridge_rule[i][2]=3;
	}
	else if(board[next_move[0]+1][next_move[1]]=='.'){
		board[next_move[0]+1][next_move[1]]='x';
		next_move[0]+=1;
	}
	else if(board[next_move[0]+1][next_move[1]-1]=='.'){
		board[next_move[0]+1][next_move[1]-1]='x';
		next_move[0]+=1;
		next_move[1]-=1;
	}
	else if(board[next_move[0]][next_move[1]+1]=='.'){
		board[next_move[0]][next_move[1]+1]='x';
		next_move[1]+=1;
	}
}
/*FİLL RULE ->>>  x .     If only empty bridges are left they will be filled
					 . x

	x  x    and the connection is provided
	  .  x						
*/

void fill_bridge(char board[12][12],int memory_bridge_rule[12][3]){
	int i=0;
	while(memory_bridge_rule[i][0]!=-1){
		
		if(memory_bridge_rule[i][2]==1){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.' && board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]='x';
				return ;
			}
		}
		
		
		else if(memory_bridge_rule[i][2]==2){
			if(board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]]=='.'&& board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]=='.'){
				board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]-1]='x';
				return ;
			}
		}
		

		else if(memory_bridge_rule[i][2]==3){
			if(board[memory_bridge_rule[i][0]][memory_bridge_rule[i][1]+1]=='.'&&board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]=='.'){
				board[memory_bridge_rule[i][0]-1][memory_bridge_rule[i][1]+1]='x';
				return ;
			}
		}
	i++;

	}

}