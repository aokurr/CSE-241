
#ifndef library_ahmet
#define library_ahmet
using namespace std;
enum type{user1='x',user2='o',empty='.',win_user1='X',win_user2='O'};
class Hex{
	public:

		Hex();
		explicit Hex(int size,int user);
		/*BIG THREE*/
		Hex(const Hex &copyc);
		~Hex();
		Hex &operator=(const Hex &rightSide);
		/*ALL GAME STEPS*/
		void play_game();
		bool get_finish();
		int get_trun();
		/*NEXTGAME BACKGAME CONTROL*/
		static string what_make;
		class Cell ;
		
		/*Operator overload was done with (*this) pointer inside member functions*/
		Hex operator--();//prefix version
		Hex operator--(int);//postfix*/
		bool operator ==(const Hex &other)const;
		friend ofstream& operator <<(ofstream & output,const Hex &other);
		friend ostream&operator<<(ostream & ,const Hex &other);
		friend ifstream&operator>>(ifstream & ,Hex &other);
	private:
		bool transition;
		int marked;
		int static game_number;
		bool finish;
		Cell **hexCell;
		int constr;
		
		/*GAME FEATURE*/
		int game_name;
		int size_board;
		int user_who;
		
		/*single step for human*/
		void play(char column,int row);
		int **undo;
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
		int **memory_bridge_rule;
		int *next_move;
		int *back_move;
		int *random;
};
class Hex::Cell{
	public:
	/*BIG THEERE NOT NEEDED*/
	int get_position_row()const;
	
	void set_position_row(int a);
	
	char get_position_column()const;
	
	void set_position_column(char b);
	
	char get_type() const;
	void set_type(type a);
	private:
		int row;
		char column;
		type gamer;

};

#endif