#include<bits/stdc++.h> 
using namespace std;


void printBinary(int n){
    for(int i = 10; i >= 0; i--){
        cout << ((n >> i) & 1); 
    }
    cout << endl; 	
}

// a ^ a = 0
// 0 ^ q = q
// x ^ y ^ z   =   y ^ z ^ x   =   z ^ x ^ y 

int main(){
    // Swap 2 nos

    int a = 3, b=9;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout<<a<<" "<<b<<endl;


}