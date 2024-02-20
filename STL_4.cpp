#include<bits/stdc++.h> 

using namespace std;

void print(set<string> s) {
	for (string str : s){
		cout<<str<<endl;
	}
}

void printm(multiset<string> s) {
	for (string str : s){
		cout<<str<<endl;
	}
}

int main(){
	/////////////////////////////////// ORDERED SETS //////////////////////////////////////
	// has mostly similar functions to maps
	set<string> s;   // Store unique elements in order.

	s.insert("abc");  // Red Black Tree - O(logn)
	s.insert("def");
	s.insert("bcc");

	print(s);

	auto it= s.find("abc");
	if (it!=s.end()){
		cout<<(*it)<<endl;
	}


	////////////////////////////////// UNORDERED SETS /////////////////////////////////////
	// Can not use comples datatypes here.
	unordered_set<string> us;
	us.insert("shdoi");  // Hash Tables ~ O(1)
	us.insert("jdfjfs");
	us.insert("kfjgi");
	us.insert("igjeti");
	us.insert("jgfufg");

	auto itr = us.find("kfjgi");  // O(1)
	if (itr != us.end()){
		cout<<(*itr)<<endl;
	}

	///////////////////////////////// MULTISETS //////////////////////////////////////////
	// Can use multiset inplace of priority queues.
	multiset<string> ms;       // Red Black Trees - O(logN)
	ms.insert("jdfjfs");
	ms.insert("kfjgi");
	ms.insert("igjeti");
	ms.insert("jgfufg");
	ms.insert("jdfjfs");
	ms.insert("kfjgi");
	ms.insert("igjeti");
	ms.insert("jgfufg");

	printm(ms);

	// erase("abc") will delete all values abc (O(N)) from multiset 
	// but erase(it) (O(logn)) will only delete the one it is pointing to.


}