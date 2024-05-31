#include<bits/stdc++.h>
using namespace std;

/*
	OOPS -> Object-Oriented Programming System

	Object:
		- An entity. It has behavior and properties.

	Class:
		- Blueprint of an object. It's a user-defined datatype.
		- A class has a size equivalent to the size of its properties (datatypes/variables in the class).
		- An empty class has a size of 1 byte by default. This memory is allocated to keep track of the object.
		- A class can also be placed in a different file and included using `#include "filename.cpp"`.

	* An object is an instance of a class.

	Access Modifiers:
		- Public: Accessible anywhere.
		- Private: Accessible only inside the class.
		- Protected: Accessible within the class and its child classes but not outside (e.g., not in `main`).

		* By default, the private access modifier is used.

	Getters and Setters:
		- Simple functions to get and set values of a variable/property of a class.
		- Generally used with private properties.

	Padding:
		- Padding refers to the extra bytes added between data members to align them in memory.
		- Example:
			class Example {
				char a;    // 1 byte
				int b;     // 4 bytes
			};
			// Here, the char variable 'a' will have padding bytes added to align the int variable 'b' at a memory address divisible by 4.
			// Total size may be 8 bytes (1 byte for char + 3 bytes padding + 4 bytes for int).

	Greedy Alignment:
		- Greedy alignment ensures data members are aligned in memory to improve access speed and efficiency.
		- Example:
			class Example {
				char a;    // 1 byte
				char b;    // 1 byte
				int c;     // 4 bytes
			};
			// Here, no extra padding is needed between 'a' and 'b', but padding bytes will be added to align 'c'.
			// Total size may be 8 bytes (2 bytes for chars + 2 bytes padding + 4 bytes for int).

	Static Allocation:
		- Example: Hero h1;

	Dynamic Allocation:
		- Example: Hero* h1 = new Hero;
		- To free the allocated memory: delete h1;

		* When using pointers, the dot (.) operator changes to the arrow (->) operator, or you can use the dereferencing operator.
			- Example: h1->name  OR  (*h1).name
*/


// A class named hero
class Hero { 
	////////////// Properties of hero
	int level;

	public:
		string name; 
		int health;

	///////////////// Behaviour of a hero


	// Getter and setter 
	int getLevel(){
		return level;
	}

	int setLevel(int x){
		level = x;
	}

	//////////////////////
};

int main(){
	Hero goku; // goku is an objedt of hero

	cout<<sizeof(goku)<<endl;

	// Accessing Properties
	goku.name = "SonGoku";
	goku.health = 100;

	cout<<goku.name<<endl;


	// Set and get private properties using getter and settter.
	goku.setLevel(100);

	cout<<goku.getLevel()<<endl;
}