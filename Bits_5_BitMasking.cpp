#include<bits/stdc++.h> 
using namespace std;

// https://codeforces.com/blog/entry/73558

void printBinary(int n){
    for(int i = 10; i >= 0; i--){
        cout << ((n >> i) & 1); 
    }
    cout << endl; 	
}


//////////////// Subsets using bitmasking
/*
    an array of size n will have 2^n subsets.
    Write binary till n. where we have 1 we include that index in array [0 - (2^n) - 1]
*/
//https://leetcode.com/problems/subsets/submissions/1224910225/
int main(){

}