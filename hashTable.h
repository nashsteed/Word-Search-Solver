// Nash Steed _ ucq8hz _ Mar 14 2022 _ "wordPuzzle.cpp"
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <vector>
#include <list>
class hashTable{
	public:
		hashTable();
		int hash(string s);
		void insert(string s);
		bool count(string s);
		vector<list<string> > table;
};
#endif
