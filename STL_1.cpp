#include<bits/stdc++.h> 

using namespace std;

// pairs and vectors
int main(){

	/////////////              PAIRS               /////////////////////
	pair<int, string> p; 

	// Inserting in a pair
	p= make_pair(2, "abc");
	cout<<p.first<<" "<<p.second<<endl;

	p = {3, "hell"};
	cout<<p.first<<" "<<p.second<<endl;

	// Coping pair
	pair<int, string> p1 = p;                 // Shallow copy- only values
	pair<int, string> &p2 = p;                // Deep Copy- reference copy 

	// Array of pair
	pair<int, int> p_arr[2];
	p_arr[0] = {121, 212};
	p_arr[1] = {233, 432};


	/////////////              VECTORS               /////////////////////
	vector<int> v;
	
	// Inserting
	v.push_back(1);
	v.push_back(2);        // insert at last   O(1)
	v.pop_back();          // delete last	   O(1)

	cout<<v[0]<<" "<<v[1]<<endl;

	// Size
	cout<<v.size()<<endl;


	// Prefilled Vector
	vector<int> v0(10);             // Filled with 0
	vector<int> v4(10, 4);          // Filled with 4


	// Coping array was by reference, but vectors can be directly copied.

	vector<int> v_copy = v;           // O(n) TC

	
	/////////////              VECTORS NESTING         /////////////////////          
	vector<pair<int, int>> vii = {{1, 3}, {2, 4}, {6, 7}};

	cout<<vii[2].first<<" -- "<<vii[2].second;

	vii.push_back({4, 6});


	/////////////              VECTORS of Array         /////////////////////          
	vector<int> va[10];   // an array of 10 vectors.
	// It has fixed rows-10 but cols are dynamic. 


	/////////////              VECTORS of VECTORS         /////////////////////
	vector<vector<int>> vv;
	// Both rows and columns are dynamic.

	return 0;
}