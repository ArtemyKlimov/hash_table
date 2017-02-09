#include <iostream>
#include "hashtable.hpp"

using namespace std;

Hashtable::Hashtable(){
	for(size_t i = 0; i <table_size; ++i){
		cell[i] = nullptr;
	}
}

int Hashtable::hash_function(string family){
	int index = 0;
	for(size_t i = 0; i <family.length();++i){
		index +=family[i];
	}
	return (index%table_size);
}

void Hashtable::insert(string _family, string _name, int _number){
	int index = hash_function(_family);
	if(cell[index] == nullptr){
		cell[index] = new unit();
		cell[index]->family = _family;
		cell[index]->name = _name;
		cell[index]->number = _number;
		cell[index]->next = nullptr;
		return;
	}	
	unit* Ptr = cell[index];
	while(Ptr->next !=nullptr){
		Ptr = Ptr->next;
	}
	unit *n = new unit();
	n->family = _family;
	n->name = _name;
	n->number = _number;
	Ptr->next = n;
}


size_t Hashtable::getNumberofElements(int index){
	int count = 0;
	if (cell[index] == nullptr){
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

void Hashtable::PrintList(unit* _cell){
	if(_cell !=nullptr){
		if(_cell->next != nullptr){
			PrintList(_cell->next);
		}
		cout<<"family: "<<_cell->family<<endl;
		cout<<"name: "<<_cell->name<<endl;
		cout<<"phone number: "<<_cell->number<<endl;
		cout<<endl;
	}
}


void Hashtable::printTable(){
	int count = 0;
	for(size_t i = 0; i < table_size; ++i){
		count = getNumberofElements(i);
		if(count == 0) continue;
		cout<<i<<":"<<endl;	
		cout<<"-------------------\n";
		PrintList(cell[i]);
	}

}

void Hashtable::removeList(unit* cell){
	if(cell != nullptr){
		if(cell->next !=nullptr){
			removeList(cell->next);
		}
		delete cell;
	}
}

Hashtable::~Hashtable(){
	for(size_t i = 0; i < table_size; ++i){
		if(cell[i] != nullptr){
			if(cell[i]->next != nullptr){
				removeList(cell[i]->next);
			}
	 		delete cell[i];
		}
	}
}
