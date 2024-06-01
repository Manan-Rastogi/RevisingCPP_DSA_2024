#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/home/goals?selectedPhaseIndex=2

/*
	Constructor:
		-	a func to invoke the class
		-	same name as class
		-	No return type
		-	Types of Constructor:
			-	Default: Constructor called automatically during object creation by compiler. If we create a constructor of our own, then the constructor of compiler will not be called.
			
			-	Parameterized: constructor with parameters.
			**	this keyword: 'this' stores the address of current object. 'this' is a pointer.	
				-	If a parameterized constructor(PC) exist, and we didn't create a default constructor then compiler's constructor will not be called if we didn't call the PC.
			
			-	Copy Constructor: Object is Copied to another. It is also generated automatically.	We can also create a copy constructor which will override the default copy constructor. Unlike default constructor it will be called even if parameterized constructor is there.
				** copy cons is mmade using reference. If we use pass by value we will be stuck in an infinite loop of copy constructor as pass by value itself wants a copy of the constructor and will call this copy constructor again and again.	

		-	Shallow and Deep Copy:
			-	default CC is shallow copy(copy by reference).
			-	we can create a deep copy[copy by value] in our CC.

 		-	Copy Assignment Operator =
 			-	when 2 objs have been created and now we want to copy one of this obj into another we use assignment operator.
 			-	Hero h1(1); Hero h2(2); h1= h2 (CC is invoked)


 		- DESTRUCTOR
 			-	obj memory deallocation
 			-	when obj is about to be out of scope - destructor is invoked.
 			-	automatically created when class is created.
 			-	can also create a destructor manually.
 			-	same name as class with a ~
 			-	Destructure is called automatically for static allocation.
 			-	For Dynamic , destructure needs to be called manually. (delete h1)
		
*/


class Hero {
	char Rank;                      // size= 1 + 3(padding)

	public:
		char* name;
		int level;
		bool evolved;

	// Default
	Hero() {
		cout<<"Constructor Called!"<<endl;
	}

	// Parameterized
	Hero(bool evolved){
		this->evolved= evolved;   // this refers to current object.
	}

	// Copy -- need to use reference
	Hero(Hero& h){
		// deep copy Hero Name
		char* heroName = new char[strlen(h.name) + 1];
		strcpy(heroName, h.name);
		this->name = heroName;

		// these were non pointers so no worries
		this->level = h.level;
		this->evolved = h.evolved;
	}

	void print(){
		cout<<this->name<<" -- "<<this->level << " -- "<< this->evolved<<endl;
	}


	//////////////// DESTRUCTOR
	~Hero(){
		cout<<"Destructor called!"<<endl;
	}
};

int main(){
	// Static Hero
	Hero naruto(1);
	naruto.level = 80;
	char narutoName[7] = "Naruto";
	naruto.name = narutoName;
	naruto.print();

	// Dynamic Hero
	Hero* kurama = new Hero(0);
	(*kurama).level = 91;
	kurama->print();


	Hero kakashi(naruto);                // copy constructor is called
	kakashi.print();                   


	delete kurama;
	return 0;
}