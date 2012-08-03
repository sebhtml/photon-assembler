
#include <iostream>
#include "plugins/TwinProcessor/Reader.h"
using namespace std;

void Reader::open(string*file){

	cout<<"Opening "<<file<<endl;
	m_hasNext=false;
}

bool Reader::hasNext(){
	return m_hasNext;
}

void Reader::getNext(Sequence*sequence){

}

void Reader::close(){

}

