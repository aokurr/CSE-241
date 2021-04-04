#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "HexVector.h"
#include "HexAdapter.h"
#include "HexAdapter.cpp"
#include "HexArray1D.h"
#include "AbstractHex.h"
using namespace std;
using namespace ahmet_vector;
using namespace ahmet_adapter;
using namespace ahmet_array;
bool valid_sequence(AbstractHex *hw5[3]);
int main(){

	HexVector test_vector;
	test_vector.play_game();
	
	HexAdapter<deque> test_adapter;
	test_adapter.play_game();

	HexArray1D test_1d;
	test_1d.play_game();
	

	if(test_adapter==test_vector){
		cout<<"test_adapter==test_vector"<<endl;
		cout<<"BOTH BOARD ARE EQUAL"<<endl;
	}
	else{
		cout<<"test_adapter==test_vector"<<endl;
		cout<<"BOTH BOARD ARE NOT EQUAL"<<endl;
	}
	

	if(test_adapter==test_1d){
		cout<<"test_adapter==test_1d"<<endl;
		cout<<"BOTH BOARD ARE EQUAL"<<endl;
	}
	else{
		cout<<"test_adapter==test_1d"<<endl;
		cout<<"BOTH BOARD ARE NOT EQUAL"<<endl;
	}
	cout<<"\n\n\n!!!THİS SECTİON FOR GLOBAL FUNCTİON!!!!\n";
	AbstractHex *games[3];
	games[0]=new HexVector;
	games[1]=new HexAdapter<deque>;
	games[2]=new HexArray1D;
	if(valid_sequence(games)==true){
		cout<<"THİS BOARD IS VALID"<<endl;
	};
	
	return 0;
}
bool valid_sequence(AbstractHex *hw5[3]){
	string str;
	int size;
	int i;
	bool flag=true;
	/*HOCAM VALİD.TXT Yİ DEĞİŞTİRİP-BOZUP KONTROL EDEBİLİRSİNİZ*/
	/*readFromFile --->> pure virtual*/
	
	if(hw5[0]->readFromFile("VALİD.TXT")=='!'){
		cerr<<"INVALID BOARD FOR VECTOR"<<endl;
		flag=false;
	}
	if(hw5[0]->get_size()<6){
		cerr<<"THİS GAME NOT VALİD BECAUSE INVALID SİZE FOR VECTOR"<<endl;
		flag=false;
	}
	if(hw5[1]->readFromFile("VALİD.TXT")=='!'){
		cerr<<"INVALID BOARD FOR ADAPTER"<<endl;
		flag=false;
	}
	if(hw5[1]->get_size()<6){
		cerr<<"THİS GAME NOT VALİD BECAUSE INVALID SİZE FOR ADAPTER"<<endl;
		flag=false;
	}
	if(hw5[2]->readFromFile("VALİD.TXT")=='!'){
		cerr<<"INVALID BOARD FOR ARRAY"<<endl;
		flag=false;
	}
	if(hw5[2]->get_size()<6){
		cerr<<"THİS GAME NOT VALİD BECAUSE INVALID SİZE FOR ARRAY"<<endl;
		flag=false;
	}

	
	return flag;
}
