#include<bits/stdc++.h> 
using namespace std;

/*
    Binary Numbers: Numbers represented in the binary system using only 0s and 1s.

    Power of 2: The expression 1 << n is equivalent to pow(2, n), representing 2 raised to the power of n.

    Maximum n-bit Number: The maximum value that can be represented using n bits is given by pow(2, n) - 1.
    For example, the maximum 32-bit integer is pow(2, 32) - 1. However, note that pow(2, 32) requires 33 bits and cannot be represented as an int.

    Signed Integers: In signed integers, 1 bit is reserved for the sign (+ or -). 
    If the Most Significant Bit (MSB) is 1, the number is negative.
*/


int main(){
	cout<<INT_MAX<<endl;

	int a= (1LL << 32) - 1;

	cout<<a<<endl;     // -1 ???
	// because of overflow a can not store pow(2, 32) - 1.

	a = (1LL << 31) - 1;
	cout<<a<<endl;    // INT_MAX
	// Why is a storing 31 bits and not 32 bits?
	// because it is unsigned integer.

	unsigned int b = (1LL << 32) - 1;
	cout<<b<<endl;   



	return 0;
}