#include<bits/stdc++.h> 
using namespace std;


void update(int** p);

int main(){
	int i=5;
	int* p=&i; 

	int** pp = &p;                  // Double Pointer

	cout<<pp<<" - "<<*pp<<" - "<<&pp<<" - "<<**pp<<endl;



	// Double Pointers and Functions.
	cout<<"<<<<<<<<<< Before >>>>>>>>>>\n";

	cout<<"i = "<< i << endl;
	cout<<"p = "<< p << endl;
	cout<<"pp = "<< pp << endl;

	update(pp);

	cout<<"<<<<<<<<<< After >>>>>>>>>>\n";
	cout<<"i = "<< i << endl;
	cout<<"p = "<< p << endl;
	cout<<"pp = "<< pp << endl;



	return 0;
}

// Comment others when running one. 
void update(int** p){
	// p = p + 1;               // No Change - p is pass by value

	// *p = *p + 1;             // Yes  

	**p = **p + 1;				// Yes				
}
