#include <iostream>
#include "AbstractHex.h"
#include <vector>
namespace ahmet_abstract{
	int Cell::get_position_row()const {return row;}
		
	void Cell::set_position_row(int a){a=row;}
		
	char Cell:: get_position_column()const {return column;}
		
	void  Cell::set_position_column(char b){column=b;}
		
	char Cell::get_type() const {return gamer;}

	void Cell::set_type(type a){gamer=a;}

	AbstractHex::AbstractHex():size_board(0){
		marked=0;
	}
	AbstractHex::AbstractHex(int size_):size_board(size_){
		marked=0;
	}
	int AbstractHex:: numberOfMoves(){return marked;}

	bool AbstractHex::operator==(const AbstractHex &right){
		string str1,str2;
		str1=get_board();
		str2=right.get_board();
		if(size_board!=right.size_board){
			return false;
		}
		for(int i=0;i<size_board*size_board;i++){
			if(str1[i]!=str2[i]){
				return false;
			}
		}
		return true;

	}
}
