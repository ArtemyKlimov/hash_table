#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <string>


class Hashtable{
private:
	static const size_t table_size = 10;

struct unit{
	std::string family;
	std::string name;
	int number;
	unit* next;
};

	unit* cell[table_size];

public:
	Hashtable();
	Hashtable(size_t _table_size);
	~Hashtable(){}
	void insert(std::string family, std::string name = "none", int number = 000);
	int hash_function(std::string name);
	size_t getNumberofElements(int index);
	void printTable();	
};

#endif
