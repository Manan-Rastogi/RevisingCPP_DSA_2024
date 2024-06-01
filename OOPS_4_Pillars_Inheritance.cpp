#include<bits/stdc++.h>
using namespace std;

/*
	Inheritance: https://www.naukri.com/code360/guided-paths/oops-in-c/content/274159/offering/3757646?goalRedirection=true
		-	Inherit properties of a parent class.
		-	syntax : class child : access_modifier parent {};
		-	Private mems of parent class can not be accessed
		-	public mode: private and protected mems in parent class remains private and protected in base class.
		-	protected mode: both turned into protected
		-	private mode: both turned into private.

	Types of Inheritance:
		-	Single:	class A -----> class B
		-	Multiple:	class A , Class C  ----------> Class B    ineriting multiple classes
		-	Multilevel: class A -----> class B -----> class C
		-	Hierarchical: Class A -----> class B, class C
		-	Hybrid:	combination of more than 1 type of inheritance


	Inheritance Ambiguity:
		-	during multiple inheritance, class A and class B can have same name od properties and functions causing ambiguity about which one is being called.
		-	we use scope resolution operator : obj.A::func();

*/

class character {
public:	
	const int uba;
	const int lba;
	int hp;
	int dmg;
	int shd;

	character(int hp = 1000, int dmg = 0, int shd= 0, int x=0 ,int y=0): uba(x), lba(y) {
		this->hp = hp;
		this->dmg = dmg;
		this->shd = shd;
	}

	int gethp(){
		return this->hp;
	}

	int updateHp(int dmg){
		int damage = dmg - (shd * dmg)/100;
		this->hp = this->hp - damage;
		return this->hp;
	}

	int attack(int atkType){
		switch(atkType){
			case 1: 
				cout<<"Normal Attack\n";
				return (rand() % (uba - lba + 1)) + lba; 
			case 2:
				cout<<"Spl Attack\n";  
				return (rand() % (uba - lba + 1)) + lba + 10;
			default:
				std::cout << "Invalid Attack Type\n";
				return 0;
		}
	}
};

class summons {
public:
	int hp;
	int dmg; 

	void getStats(){
		cout<<this->hp<< "  --  "<< this->dmg<< endl;
	}
};

///////////////////////////////// single Inheritance
class npc : public character {
public:
	string gender;

	void greet(){
		cout<<"Hello there!"<< endl;
	}

};


//////////////////////////////// multilevel inheritance
class npc_pet: public npc {
public:
	void greet(string msg){
		cout<<msg<<endl;
	}
};



//////////////////////////////// multiple inheritance
class shikigami: public character, protected summons {
public:
	void greet(string msg){
		cout<<msg<< endl;
	}
};


//////////////////////////////// heirarchical inheritance
class hero : public character {

};

class villian: public character {

};

/////////////////////////////////////////////////////////

/////////////////////// hybrid -> entirety of above is hybrid.

/*
character ----- npc ------ npc_pet      summons
	|    \                               /
	|     \                             /
	|      \_ _ _ _ _ _ _ _ _ shikigami
   / \      
 hero villian
*/


int main(){

	// Single Inheritance
	npc trader;
	trader.greet();

	cout<<"Trader's Hp - "<< trader.hp<<endl;  

	// Multilevel Inheritance
	npc_pet trader_boar;
	trader_boar.greet("roaaar");

	cout<<"Trader's Boar's Hp - "<< trader_boar.hp<<endl;

	// Multiple Inheritance
	shikigami mahoraga;
	mahoraga.greet("Grrrrrrrr!!!");
	cout<<"Mahoraga Hp - "<<mahoraga.character::hp<<endl;

	return 0;
}