
#ifndef library_ahmet
#define library_ahmet
using namespace std;
/*for cells*/
enum cells{a='.',b='x',c='o',d='X',e='O'};

/*for menu*/
void menu();

/*prints the table*/
void print(cells board[12][12],int size);

/*human to human game*/
void play_user(int size);

/*checks the end for x*/
int finish_control_x(cells board[12][12],int size);

/*Necessary application to control the completion*/
int recursion_x(cells board[12][12],int column,int row,int size,int counter);

/*checks the end for o*/
int finish_control_o(cells board[12][12],int size);

/*Necessary application to control the completion*/
int recursion_o(cells board[12][12],int column,int row,int size,int counter);

/*human versus computer*/
void play_computer(int size,int random[2]);

/*All the moves to the left side by the computer are here*/
void left_move(int memory_bridge_rule[12][3],cells board[12][12],int back_move[2],int size);

/*bridge strategy to the left*/
void bridge_rule_left(cells board[12][12],int size,int back_move[2],int memory_bridge_rule[12][3]);

/*If one leg of the bridge is occupied, the computer will fill the other*/
int bridge_rule_control(int memory_bridge_rule[12][3],cells board[12][12]);

/*All the moves to the right side by the computer are here*/
void right_move(int memory_bridge_rule[12][3],cells board[12][12],int next_move[2],int size);

/*bridge strategy to the right*/
void bridge_rule_right(cells board[12][12],int size,int next_move[2],int memory_bridge_rule[12][3]);

/*fills empty bridge legs*/
void fill_bridge(cells board[12][12],int memory_bridge_rule[12][3]);

/*SAVE AND LOAD FOR HUMAN VS HUMAN*/
void save_file(cells board[12][12],const int &size,const string &str2);

char load_file(cells board[12][12],int &size,const string &str2);

/*SAVE AND LOAD FOR HUMAN VS COMPUTER*/
void save_file(cells board[12][12],const int &size,const string &str2,int memory_bridge_rule[12][3]);

int load_file_(cells board[12][12],int &size,const string &str2,int memory_bridge_rule[12][3],int next_move[2],int back_move[2]);

/*find the size of the board*/
int sqrt(int x);

#endif