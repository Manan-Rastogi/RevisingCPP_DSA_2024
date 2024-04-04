#include<bits/stdc++.h> 
using namespace std;

// Function to print the binary representation of an integer
// Input: Integer n
// Output: Prints the binary representation of n to the console
void printBinary(int n){
    // Iterate over each bit from the most significant bit to the least significant bit
    for(int i = 10; i >= 0; i--){
        // Extract the value of the i-th bit using bitwise AND operation
        cout << ((n >> i) & 1); // Shift n by i positions to the right, then perform AND operation with 1
    }
    cout << endl; // Print a newline character to move to the next line
}

int main(){
    
    printBinary(13);

    // Check if the i-th bit of an integer is set
    int a = 13;
    int i = 0; // Index of the bit to check
    if ((a & (1 << i)) != 0){
        cout << "0th bit is Set bit" << endl;
    }else{
        cout << "0th bit is Unset bit" << endl;
    }

    // Set the i-th bit of an integer
    i = 1; // Index of the bit to set
    a |= 1 << i; // Perform bitwise OR operation to set the i-th bit

    
    printBinary(a);

    // Unset the i-th bit of an integer
    // Bitwise AND operation with the complement of the i-th bit mask is used to unset the bit
    a &= ~(1 << i);

   
    printBinary(a);

    // Toggle the i-th bit of an integer (change 1 to 0 and vice versa)
    a ^= 1 << i; // Perform bitwise XOR operation to toggle the i-th bit

    
    printBinary(a);

    // Toggle the i-th bit again to revert back to the original value
    a ^= 1 << i;

    
    printBinary(a);

    // Count the number of set bits (1s) in an integer
    int count = 0;
    for(int i = 31; i >= 0; i--){ // Iterate over each bit of a 32-bit integer
        if ((a & (1 << i)) != 0){ // Check if the i-th bit is set
            count++; // Increment the count if the bit is set
        }
    }

    // Output the total count of set bits
    cout << "No of set bits = " << count << endl;

    // Using __builtin_popcount() to count set bits (only for int)
    cout << __builtin_popcount(a) << endl; // Output the number of set bits in 'a'

    // Example usage of __builtin_popcountll() to count set bits in a long long integer
    cout << __builtin_popcountll((1LL << 21) - 1) << endl; // Output the number of set bits in a long long integer

    return 0;
}
