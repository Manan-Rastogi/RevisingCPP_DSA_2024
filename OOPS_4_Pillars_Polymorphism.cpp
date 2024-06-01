#include<bits/stdc++.h>
using namespace std;

/*
	Polymorphism:
		-	poly = many
		-	morph = forms

	-> Compile Time Polymorphism:
		-	Function Overloading:
			-	use same name for more than 1 functions
			-	change return type or change no of params or change type of params

		-	Operator Overloading:
			-	assign an operator a new function to do
			-	eg: change defn of '+' operator to something else like adding 2 props of obj.

	-> Run Time Polymorphism:
		-	Method Overriding:
			-	override a parent's method.
			-	Rules:
				-	name of method should be same.
				-	parameters must be same
				-	Inheritance should be there.
				

*/

class A {
	public:
	int a;
	int b;

	// + operator is overloaded for class A's object	
	void operator+ (A &obj){
		int v1 = this->a;
		int v2 = obj.a;

		cout<<"output= "<< v1 - v2 << endl;
	}
};



int main(){	
	A a;
	a.a = 10;
	A b;
	b.a = 2;

	a + b;           //  this is subtracting -- : )

	return 0;
}