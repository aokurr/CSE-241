#ifndef library_ahmet
#define library_ahmet
#include <vector>
using namespace std;
namespace ahmet_abstract{
	enum type{user1='x',user2='o',empty='.',win_user1='X',win_user2='O'};
	class Cell{
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

	class AbstractHex{
		public:
			AbstractHex();
			AbstractHex(int size_);

			virtual void print()const =0;
			virtual void play(char column,int row)=0;
			virtual void play()=0;
			virtual bool isEnd()=0;
			virtual void writeToFile(const string &str)=0;
			virtual char readFromFile(const string &str)=0;
			virtual void setSize(int a)=0;
			virtual void reset()=0;
			int numberOfMoves();
			virtual Cell operator()(int column,int row)=0;
			virtual const string get_board()const=0;
			bool operator==(const AbstractHex &right);
			int get_size(){return size_board;}
		protected:
			int size_board;
			int user_who;
			int marked;


	};
	//EXCEPTİONS*/
	class hata1:public exception{
		public:
			string error(){
			return "PLEASE TRY AGAIN THIS CELL NOT EMPTY\n";
		}
	};
	class hata2:public exception{
		public:
			string error(){
			return "THERE İS NO LAST MOVE\n";
		}
	};
}
#endif