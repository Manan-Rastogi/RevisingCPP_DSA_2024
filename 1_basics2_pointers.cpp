#include<bits/stdc++.h>
using namespace std;


void increment_pointers(int *a){
	(*a)++;
}

void increment_reference(int &a){
	a++;
}


int main(){
	int x;
	x=4;

	int *p_x= &x;

	cout<<"Addr of x= "<<&x<<endl;
	cout<<"Val of p_x= "<<p_x<<endl;

	cout<<"Val of x= "<<x<<endl;
	cout<<"Val at p_x= "<<*p_x<<endl;

	*p_x= 5;
	cout<<"Changing  Value..."<<endl;
	cout<<"Val of x= "<<x<<endl;
	cout<<"Val at p_x= "<<*p_x<<endl;


	cout<<"p_x + 1 = "<<p_x + 1<<endl;                            // Add 4 bytes


	int **p_p_x= &p_x;

	cout<<"Addr of p_x= "<<&p_x<<endl;
	cout<<"Val of p_p_x= "<<p_p_x<<endl;
	cout<<"Val at p_p_x= "<<*p_p_x<<endl;

	cout<<"Val at *p_p_x= "<<**p_p_x<<endl;








	cout<<endl<<"*************************"<<endl;



	int a[10];
	a[0] = 1;
	a[1] = 2;

	cout<<"a = "<<a<<endl;
	cout<<"*a = "<<*a<<endl;
	cout<<"*(a+1) = "<<*(a+1)<<endl;



	// Difference Pointers and  References
	int s=1;
	cout<<s<<endl;
	increment_pointers(&s);
	cout<<s<<endl;
	increment_reference(s);
	cout<<s;
}

