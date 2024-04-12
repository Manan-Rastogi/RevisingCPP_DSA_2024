#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int binaryExponentiationRecur(int a, int b){
	if(b==0){
		return 1; 
	}

	int res= binaryExponentiationRecur(a, b/2);
	if(b&1){// odd
		return ((a * (res * 1LL * res) % M) % M);   // Using 1LL to capture res*res fully.
	}else{
		return ((res * 1LL * res) % M);
	}
}

/*
Convert Power into Binary then break a^b1 + a^b2 + .... like converting b back to decimal.
2^13 -> 2^(1101)bin -> 2^(8 + 4 + 0 + 1)
*/
int binaryExponentiationIter(int a, int b){  // TC= log(N)
	int ans = 1;
	while(b){
		if(b&1){
			ans= (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;
	}

	return ans;
}

int main(){
	// Due to precision issue of double and pow(){as it returns double} func, we need binary exponentiation.

	int a=2, b=13;

	cout<<binaryExponentiationRecur(a, b)<<endl;
	cout<<binaryExponentiationIter(a, b)<<endl;

}	