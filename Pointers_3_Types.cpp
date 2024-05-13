#include<bits/stdc++.h> 
using namespace std;


// https://www.naukri.com/code360/guided-paths/pointers/content/235645/offering/3168908?leftPanelTabValue=PROBLEM&customSource=studio_nav
int main(){
	/*
	1. 								Null Pointer
	A NULL pointer is a pointer that is pointing to nothing. If we don’t have the address to be assigned to a pointer, we can use NULL.

	Advantages of Null pointer:
	-> We can initialize a pointer variable when that pointer variable is not assigned any actual memory address.
	-> We can pass a null pointer to a function argument when we are unwilling to pass any actual memory address.
	*/

	int *np = NULL;
	cout<<" NP = "<<np<<endl;		// No Address
	cout<<"&NP = "<<&np<<endl;      // address of np
	// cout<<"*NP = "<<*np<<endl;	    // Dereferencing null pointer is undefined behaviour. Uncomment to chk.


	




	/*
	2. 								Double Pointer
		Covered in next Part.
	*/

	







	/*
	3.								Void Pointer

	A void pointer is a generic pointer; it has no associated type with it. A void pointer can hold an address of any type and can be typecasted to any type


	REMEMBER:
	->	void pointers cannot be dereferenced. It can, however, be done using typecasting the void pointer.
	->	Pointer arithmetic is not possible on pointers of void due to lack of concrete value and size.

	*/

	void *ptr = NULL;

	int i = 10;

	ptr= &i;

	cout<<&i<<endl;
	cout<<ptr<<endl;





	/*
	4.								Wild Pointer

	A pointer behaves like a wild pointer when declared but not initialized. So, they point to any random memory location.
	*/

	int *wp; //wild pointer   -- BAD PRACTICE
	wp = &i;
		
	cout<<wp<<" - "<<*wp<<endl;






	/*
	5.							 	Dangling Pointer

	A dangling pointer is a pointer pointing to a memory location that has been freed (or deleted).

	A Pointer becomes a dangling pointer when:
	i> Function Call: return address of a static variable of func.
		int * fun() {
   				 int x = 10;
    			 return &x;
			}

	ii> Deallocation of memory: 
		 /		/dynamic memory allocation.
			    int * p = (int * ) malloc(sizeof(int));
			    
			    //after calling free() p becomes a dangling pointer
			    free(p);
			    
			    //now p no more a dangling pointer.
			    p = NULL;

	iii> Variable goes out of scope:
		  	int * ptr;
		    ..... //any code statements
		    {   int ch;
		        ptr = & ch;
		    }
		    ....
		    // Here ptr is dangling pointer
	*/

	return 0;
}