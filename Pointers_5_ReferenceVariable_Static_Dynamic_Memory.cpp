#include<bits/stdc++.h> 
using namespace std;

// https://www.naukri.com/code360/guided-paths/basics-of-c/content/118785/offering/1381139?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
>>>>>>>>>>>>>>>>		Reference Variable:
	When a single memory location have multiple names. 
	int i =10;
	int &j = i;          -- Reference variable

	-	i and j points to same memory so manipulating 1 will change other as well.

	-	Used for Passed by Reference Concept to avoid creating copy and save time and memory.

	-	int& func(int a){
		int &ans = a;    -- Ans is local var will die outside this func, so this is a very bad practice. This mem might be inaccessible or something else might be here (some other program or block used this address after release.)
		return ans;
		} 	


>>>>>>>>>>>>>>>>>>>	Dynamic And Static Memory

	-	Avoid using run time array sizes determined at runtime like this:

		int n;
		cin >> n;
		int arr[n];         -- Bad Practice

		This is considered bad practice because:
		1. It declares the array size at runtime, which can cause problems if the stack doesn't have enough memory available to accommodate the size.
		2. It's better to know the array size at compile time for better memory management and efficiency.

		Instead, consider using a constant size determined at compile time, like this:

		const int MAX_SIZE = 1e5 + 1;
		int arr[MAX_SIZE];

		This approach has several benefits:
		1. The array size is known at compile time, so there's no risk of running out of stack memory at runtime.
		2. Using a constant size improves code readability and maintainability because it's clear how much memory the array will require.
		3. It ensures better performance because the compiler can optimize memory allocation and access.


	-	Another approach is to use heap memory instead of stack memory. Heap memory typically offers more space compared to stack memory. However, unlike stack memory where variables can be directly named, in heap memory, variables are referenced by their memory addresses. Therefore, we need to store these addresses in pointer or reference variables.

		To allocate memory for a single integer on the heap, we use:
		   
		   int* i = new int;

		Here, the integer (which takes up 4 bytes) is stored in the heap, while the pointer variable `i` (which takes up 8 bytes) is stored in stack memory. So, a total of 12 bytes is used.

		For creating an array with a size determined at runtime (`n`), we utilize dynamic memory allocation on the heap:

		   int n;
		   cin >> n;
		   int* arr = new int[n];

		In this scenario, the array of integers (with a size of `n`) is stored in heap memory, while the pointer variable `arr` is stored in stack memory.

	
	-	In programming, memory allocation can be broadly categorized into two types: stack memory and heap memory.

		1. Stack Memory:
		   - Stack memory is used for static allocation.
		   - It's called "stack" because memory is allocated and deallocated in a last-in, first-out (LIFO) manner, similar to a stack of plates.
		   - Variables declared on the stack have fixed sizes and lifetimes determined at compile time.
		   - Stack memory is limited and usually smaller than heap memory.
		   - Example: When you declare a variable inside a function, it's typically allocated on the stack.

		2. Heap Memory:
		   - Heap memory is used for dynamic allocation.
		   - It's called "heap" because memory is allocated and deallocated in a more flexible manner, like a heap of objects.
		   - Variables declared on the heap have dynamic sizes and lifetimes determined at runtime.
		   - Heap memory is larger than stack memory and can grow dynamically as needed.
		   - Example: When you use dynamic memory allocation functions like 'malloc' or 'new' in C++ to allocate memory, it's typically allocated on the heap.


	-	Static vs Dynamic- Apart from previously mentioned defn.
		1. size of memory allocated:
			Static -- int arr[10]; -- 40 bytes
			Dynamic-- int *arr = new int[10] -- 48 bytes

		2. infinite declaration  -- very dangerous... can crash systems
			Static: while(1){int i = 5}  // at any point only 1 int is using memory.
			Dynamic: while(1){
				int *p= new int;   -- stack memory will be cleared but heam memory will not and it will end up consuming all available memory crashing system.
			}

	- REMEMBER to clear Dynamic Memory:
		-- delete arr[];
		-- delete i;


>>>>>>>>>>>>>>>>>>>>> Dynamic Memory Allocation in 2d Arrays

*/

int main(){
	 int i=101;
	 int &j=i; 

	 cout<<i<<" == "<< j<< endl; 
	 i++;

	 cout<<i<<" == "<<j<<endl;


	 cout<<"\n\n*********************************\n\n";

	 int *v = new int;
	 cout<<sizeof(v)<<endl;

	 // Creating Dynamic Array
	 int *arr = new int[5];                    // Total Memory = 28

	 delete arr[];        // deleting heap/dynamic memory.
}