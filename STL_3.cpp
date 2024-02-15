#include<bits/stdc++.h> 

using namespace std;

// Maps
int main(){

	/////////////////////// Ordered Maps //////////////////
	// Normal Maps are based on Red Black Trees.

	map<int, string> m;  // Ordered Map

	m[1] = "Manan";      // O(log(n))  --- This also depends on key's datatype	
	m[2] = "Montu";
	m.insert({4, "Rastogi"});

	m[8];              // Avoid these as they insert blank string in O(log(n)).

	map<int, string> :: iterator it;

	for(it=m.begin(); it!=m.end(); it++){
		cout<<it->first<<" -- "<<(*it).second<<endl;
	}

	for (auto &pr: m){
		cout<<pr.first<<" ... "<<pr.second<<endl;
	}

	// Find in Map

	auto f = m.find(21);  // O(NlogN)
	if (f==m.end()){
		cout<<"Key not Found. \n";
	}else{
		cout<<f->first<<" ... "<<f->second<<endl;
	}

	// Remove form map
	if (f!=m.end()){
		m.erase(f);  //o(logn)
	}

	m.clear();  // clear entire map



	//////////////////////////////////// Unordered Maps ///////////////////////
	unordered_map<int, int> um;        // It uses hash instead of a tree

	um[1] = 1;         // O(1)  on avg
	um[3] = 3; 
	um[2] = 900;

	for (auto &pr: um){
		cout<<pr.first<<" ... "<<pr.second<<endl;
	}

	// Find and erase also O(1)
	// Can't use much complex in unordered map like a pair as their is no inbuilt func in cpp for pairs.



	//////////////////////////////////  MULTIMAPS /////////////////////////////
	//        Red Black Tree
	//        multiple same keys
	// multimap
}