#include <iostream>
#include "hashtable.hpp"

using namespace std;

Hashtable::Hashtable(){
	for(size_t i = 0; i <table_size; ++i){
		cell[i] = new unit();
		cell[i]->next = nullptr;
	}
}

int Hashtable::hash_function(string family){
	int index = 0;
	cout<<index%table_size;
	for(size_t i = 0; i <family.length();++i){
		index +=family[i];
	}
	return (index%table_size);

}

void Hashtable::insert(string _family, string _name, int _number){
	int index = hash_function(_family);

	if(cell[index]->family ==""){
		cell[index]->family = _family;
		cell[index]->name = _name;
		cell[index]->number = _number;
		cell[index]->next = new unit();
	}
	else{
	cout<<"THE ERROR IS HERE!!"<<endl;
		unit* Ptr = cell[index]->next;
		unit *n = new unit();
		n->family = _family;
		n->name = _name;
		n->number = _number;
		while(Ptr != nullptr){
			Ptr = Ptr->next;
		}
		Ptr = n;
	}
}


size_t Hashtable::getNumberofElements(int index){
	int count = 0;
	if (cell[index]->family == ""){
		return 0;
	}
	count++;
	unit* Ptr = cell[index]->next;
	while(Ptr != nullptr){
		Ptr = Ptr->next;
		count++;
	}
	return count;
}

void Hashtable::printTable(){
	int count = 0;
	for(size_t i = 0; i < table_size; ++i){
		count = getNumberofElements(i);
		if(count == 0) continue;
		unit* Ptr = cell[i];
		while(Ptr != nullptr){
			cout<<i<<":"<<endl;	
			cout<<"-------------------\n";
			cout<<"family: "<<Ptr->family<<endl;
			cout<<"name: "<<Ptr->name<<endl;
			cout<<"phone number: "<<Ptr->number<<endl;
			Ptr = Ptr->next; 	
		}
	}

}



