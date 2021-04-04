#include "AbstractHex.h"
#ifndef bb
#define bb
using namespace std;
using namespace ahmet_abstract;

namespace ahmet_array{
	class HexArray1D:public AbstractHex{
		public:
			HexArray1D();
			HexArray1D(int size_);
			/*BIG THEERE*/
			HexArray1D(const HexArray1D &copyc);
			~HexArray1D();
			HexArray1D &operator=(const HexArray1D &rightSide);
			
			void play(char column,int row)override;
			void play()override;
			void print()const override;
			bool isEnd() override;
			void writeToFile(const string &str)override;
			char readFromFile(const string &str)override;
			void setSize(int a)override;
			void reset()override;
			Cell operator()(int column,int row);
			const string get_board()const override;
			void play_game();
		private:
			Cell *hexCell;
			int turn;
			void creat_empty_array();
			int  finish_control_x();
			int recursion_x(int column, int row,int counter);
			int finish_control_o();
			int recursion_o(int column,int row,int counter);
		private:
			/*play computer rules "AI"*/
			int next_move[2];
			int back_move[2];
			int random[2];
			int x_;
			int y_;
			int save_load(const string &str);

	};
}
#endif