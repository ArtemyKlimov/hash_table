#include <iostream>
#include "hashtable.hpp"

int main(){
	Hashtable hashy;
	hashy.insert("Schumacher", "Michael", 123321);
	hashy.insert("Bullock", "Michael", 123321);
	hashy.insert("Eidel", "Igor", 123321);
	std::cout<<"Hello, World"<<std::endl;
	hashy.insert("Klimov", "Michael", 123321);
	hashy.insert("Zorin", "Oleg", 123321);
	hashy.insert("Zimmerman","Hans", 123321);
	hashy.insert("Luter", "Lex", 320502);
	hashy.insert("Parker", "Piter", 333321);
	hashy.printTable();

	return 0;
}

