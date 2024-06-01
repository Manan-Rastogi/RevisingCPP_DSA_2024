#include<bits/stdc++.h>
using namespace std;

/*
	- const keyword:
	- Use of const in object creation and functions and with data members:
		- When used with a variable, it makes that variable's value unchangeable after initialization.
		- When used with a function, it means that the function does not modify any member variables of the object.
		- When used with an object, it means that the object itself cannot be modified.

- initialization list:
	- Initialization lists are used to initialize data members of a class.
	- They provide a way to initialize members before the constructor body executes.
	- This is particularly useful for initializing const members and reference members, which must be initialized at the time of their creation.

	- Example:
		```
		class MyClass {
		public:
		    const int value;
		    MyClass(int v) : value(v) {} // initialization list
		};
		```

- static keyword:
	- A variable made with the static keyword belongs to the class.
	- Any update made to it will change the value for the entire class, not just a specific object.
	- Static variables are shared among all instances of the class.

	- Example:
		```
		class MyClass {
		public:
		    static int count;
		    MyClass() {
		        count++;
		    }
		};
		int MyClass::count = 0; // definition of static variable
		```

	- Static functions:
		- No need to create an object to access these functions.
		- They do not have access to the `this` keyword because they do not belong to any instance.
		- Can only access static members (variables or other static functions) of the class.

		- Example:
			```
			class MyClass {
			public:
			    static int count;
			    MyClass() {
			        count++;
			    }
			    static int getCount() {
			        return count;
			    }
			};
			int MyClass::count = 0;

			int main() {
			    MyClass obj1;
			    MyClass obj2;
			    int c = MyClass::getCount(); // Accessing static function without creating an object
			    return 0;
			}
			```

*/


class Hero {
	                    

	public:
		
		static int timeToComplete;                  // a static variable

	//////////// Static function
	static int Penalty(){
		timeToComplete = 3;
		cout<<"Due to cheat code from a member, time is reduced to - "<< 3 << " hours"<< endl;
	}


	//////////////// DESTRUCTOR
	~Hero(){
		cout<<"Destructor called!"<<endl;
	}
};

///////// Initializing a static member ///////////
// datatype ClassName ScopeResolution = value
int Hero::timeToComplete= 5; 

int main(){
	cout << Hero::timeToComplete<<endl;        // accessing a static member

	Hero::Penalty();

	cout<<Hero::timeToComplete<<endl;

	return 0;
}