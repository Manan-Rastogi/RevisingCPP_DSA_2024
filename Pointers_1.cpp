#include<bits/stdc++.h> 
using namespace std;

void func(int a);
void func2(int* a);  
void func3(int& a);
// https://www.youtube.com/watch?v=YHwEIfrXZgE



/*
Why we need Pointers?

int x = 5; How does this works in memory?

In memory there will be a block with a hexadecimal address which is allocated to x. 
There is a Symbol table maintained by compiler which maintains  
x -> SymbolTable[address(x)] -> value(x)

cout<<x: will use above mapping to find out what's stored in x.





---------------- 2 --------------------

when an operation is done like x = x + 1;
-> x = SymbolTable(address[x])->Value(x) + 1           // x will be picked from symbolTable and then its value will be updated and stored.
-> SymbolTable(address(x)) = Updated(x)

==========> So we need a Pointer to save this address.

int* ptr = &x;     ptr is a pointer to int. It will store address of int variables.
                   ptr will have a different address than x.
                   &ptr will give address of ptr.

cout<<*ptr;        using * before a pointer will give value at the address stored by ptr.
                   * is the dereference operator here.
                  
==> *ptr and num are pointing to same mem locn.




------------------  3 ------------------
main(){
    int a;
    func(a)
}

func(a){
    a=a+1
}

changing value of a in func will not change value of a in main since they don't share same memory.
(CALL BY VALUE)

main(){
    int*p_a = &a;
    func(p_a);
}

func(int* a){
    a++;
}

Now the value of a will be changed as a pointer to a is passed which works on address of a rather than value
(CALL BY REFERENCE)





------------------ 4. Size of Pointer ------------------
Size of int is 4 bytes [generally]
Any type of Data, pointer will store the address only. so it's size is always 8 bytes.





----------------- 5. Coping a Pointer ------------------
int *p= &num;
int *q = p;       // p is the address so we can directly assign it to another pointer of same type





---------------- 6. Pointer Arithmatic -----------------
int *t = &i;
*t = *t + 1;      // increase the value i
t = t + 1;        // increase the address in t by 1. i.e inc t by sizeof(i). Here- t=t+4;





***************************************  BAD Practices:
-	int *ptr;        a pointer is declared. It can point anywhere and we can manipulate this memory.
                   	 ptr has a garbage value as an random address. This is quite dangerous as this address might not be even of our program and we van manipulate it. 

-	int *ptr=0;    	 There is No memory as 0 So this will give Segmentation Fault.

-	int *ptr=0;
	ptr = &w;        This is same as int* ptr= &w. Try to do in 1 line only.  [Concept for MCQs]



*/


int main(){
	// 1.                                    Why we need Pointers?
	int x = 5;
	cout<<x<<endl;

	x = x + 1;
	cout<<x<<endl;

	// address of operator - &
	cout<<&x<<endl;                                 // Hexadecimal Address

	// Pointer - *
	int* p_x = &x;
	cout<<p_x<<endl;                                // value at p_x is the &x(address)
	cout<<*p_x<<endl;                               // value at *p_x-> *(address) -> value at address

	cout<<&p_x<<endl;                               // address of ptr


	// -------------------- 2 ---------------------
	cout<<++x<<endl;                                // this will also inc *p_x as they refer to same memory
	cout<<*p_x<<endl;

	//Simmilarly increasing *p_x will inc x
	cout<<--(*p_x)<<endl;
	cout<<x<<endl;


	// -------------- 3 -------------

	int a = 100;
	int *ptr = &a;

	cout<<*ptr<<endl;

	func(a);
	cout<<a<<endl;

	func2(ptr);
	cout<<a<<endl;

	func3(a);
	cout<<a<<endl;

// ------------------ 4 Size of Pointer ------------------
	cout<<sizeof(a)<<endl;
	cout<<sizeof(ptr)<<endl;



// ----------------- 5. Coping a Pointer ------------------
	double v = 1.23;
	double* p_v= &v;

	cout<<p_v<<endl;

	double* c_p_v= p_v;
	cout<<c_p_v<<endl;



// ---------------- 6. Pointer Arithmatic -----------------
	int c = 1;
	int* pc= &c; 

	c++;
	cout<<*pc<<endl;

	cout<<pc<<endl;

	pc += 1;

	cout<<*pc<<endl;         // some unassigned address
	cout<<pc<<endl;

	
}


void func(int a){   // a copy is passes
	a++;
}

void func2(int* a){  // pointer    -- original concept of C
	(*a)++;
}

void func3(int& a){ // reference   -- easy concept of C++  -- reference is an alias or an alternative name for an existing variable
	a--;
}

// pointers allow you to indirectly access and modify values by manipulating memory addresses, while references provide a more direct way to work with variables, allowing modifications to affect the original data directly