#include<bits/stdc++.h> 
using namespace std;



/*
#################################### 1. Pointers with Array

----------------------1a. array and addresses
*	int arr[10]; => memory of 10*4 is allocated for this array. [10-> sizeof array; 4-> sizeof int]
				 =>	arr will indicate 1st block of this array. 
				 => arr will be address of arr[0] 
				 => address of arr[3]? => arr + 3
				 => arr[i] = *(arr+i)
				 => i[arr] = *(i+arr)                    // Confusing
 					Why this works? - arr[i] is calculated as *(arr+i) internally. By this logic i[arr] will be *(i+ arr)
				 => &arr == arr == &arr[0]  in arrays
				 	&arr and arr both represent the address of the first element of the array.
				 	&arr[0] explicitly represents the address of the first element.


----------------------1b. Difference Pointers vs Array
*	int arr[10]; --> sizeof(arr) = 10*4 = 40 bytes.
	int *pa= &arr[0] --> sizeof(pa) = 8 bytes.	

*	arr == &arr != &pa   // &arr is address of 1st element in array, &pa is address of pointer to array.

*	Content of Symbol Table cannot be changed in case of array. array is continuous memory allocation so 	 it does not make sense to change addresses.
	Eg: arr = arr + 1   // Not Possible

	Addresses can be changed for pointers. They will simply point to another address.
	eg: pt= pt+1;       // Pointer Arithmatic





#################################### 2. Pointers with char Array

------------------------- 2a. int vs char array and pointers
*	int arr[2] = {1, 2};
	char carr[3] = "12";  // carr[2] == '/0'  Last char is null character.
	=> cout <<  is implemented differently for char and int
	

*	arr is address of 1st element. carr is the string(char array) formed by characters.

*	char *pc = &carr[0];
	cout<<pc;  // pc should be address of carr[0] but it will give the char at carr[0].
	cout<<*pc;  // again entire string.  

*/


int main(){

	//  -----------------     1a. array and addresses
	int arr[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

	cout<<*arr << " - " << arr[0]<<" - "<<arr<<" - "<<&arr[0]<<endl;
	cout<<*(arr+5) <<" - "<< arr[5]<<" - "<<arr+5<<" - "<<&arr[5]<<endl;

	cout<<*(arr+2) + 7<<endl;   // dereference array+2 address and then add 1;

	cout<<&arr << " == "<< arr<<endl;

	for(int i=0; i<10; i++){
		cout<<arr[i]<< " - "<< *(arr + i)<<endl;
	}

	cout<<"\n**********************\n";
	for(int i=0; i<10; i++){
		cout<<i[arr]<< " - "<< *(i + arr)<<endl;       // WOW!!!!!
	}
	cout<<"\n**********************\n";



// ----------------------1b. Difference Pointers vs Array
	cout<<sizeof(arr)<<endl;
	int *pa = &arr[0];
	int *pa2 = arr;

	cout<<sizeof(pa)<<" -- "<<sizeof(pa2)<<endl;

	cout<< &arr <<" == "<< arr << " != "<< &pa<< endl;





// ------------------------ 2a. int vs char array
	int iarr[5] = {1, 3, 5 ,7, 9};
	char carr[6] = "AeIoU";

	cout<<"Last Char = "<< carr[5]<<endl;

	cout<<"arr = "<< arr << " is Address. carr = "<< carr <<" is string.\n";

	cout<<"\n**********************\n";

	char *pc = &carr[0];
	cout<<*pc<<endl;         
	cout<<pc<<endl;





	return 0;

}