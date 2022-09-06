// Nash Steed _ ucq8hz _ Mar 14 2022 _ "hashTable.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <vector>
#include <list>

hashTable::hashTable(){
	for(int i=0;i<75013;i++){
		list<string> l;
		table.push_back(l);
	}
}

int hashTable::hash(string s){
	int t=0;
	for(int i=0;i<s.length();i++){
		t+=(int)s.at(i);
	}
	return t%75000;
}
void hashTable::insert(string s){
	int h=hash(s);
	table[h].push_front(s);
}

bool hashTable::count(string s){
	int h=hash(s);
	int t=0;
	for(int i=0;i<table[h].size();i++){
		string check = table[h].front();
		table[h].pop_front();
		table[h].push_back(check);
		if(check==s){
			t=1;
		}
	}
	if(t==1){return true;}
	else{return false;}
}