#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <string>


class Hashtable{
private:
struct unit{
	std::string family;
	std::string name;
	int number;
	unit* next;

};
	
	static const size_t table_size = 10;
	void removeList(unit* cell);
	void PrintList(unit* cell);
	unit* cell[table_size];
public:
	Hashtable();
	Hashtable(size_t _table_size);
	~Hashtable();
	void insert(std::string family, std::string name, int number);
	int hash_function(std::string name);
	size_t getNumberofElements(int index);
	void printTable();	
};

#endif
