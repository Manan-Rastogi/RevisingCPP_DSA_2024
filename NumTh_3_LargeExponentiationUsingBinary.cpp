#include<bits/stdc++.h>
using namespace std;

const long long int M=1e18;
long long binaryMultiplication(long long a, long long b);

// a, b <= 1e9;

// How to deal if a <= 1e18 || a<=2^1024 (very very large no);

long long binaryExponentiationIter(long long a, long long b){        // TC= log^2(N)
	a %= M;         // (a^b) % M = ((a % M)^b) % M 
	long long ans = 1;
	while(b>0){
		if(b&1){
			ans= binaryMultiplication(ans, a) % M;
		}
		a = binaryMultiplication(a, a) % M;
		b >>= 1;
	}

	return ans;
}

/* 
Now if M is also very large like 1e18 then we can not calculate (a*1LL*a) % M [1e18 * 1e18] as it will overflow as it
can not be stored in long long. So we use concept of binary multiplication.
*/






/*
a*a = a+a+a+.....+a   a times
So we can do something like 
(((((a + a) % M) + a) % M) % M)..... a times. 
[as long long range is somewhere around 2e18, So we can add a 2 times.]

But this multiplication will take O(N) which will give TLE for N=1e18.

So we will use binary multiplication.

a*b => 3*13 => 3*(1101) => 3*(8 + 4 + 0 + 1) => (Same as binaryExp) => 39
*/
long long binaryMultiplication(long long a, long long b){
	long long ans = 0;
	while(b>0){
		if(b&1){
			ans= (ans + a) % M;
		}
		a = (a + a) % M;
		b >>= 1;
	}

	return ans;
}	

int main(){
	long long a=15, b=13;

	cout<<binaryMultiplication(1200000000, 12000000)<<endl;

	cout<<binaryExponentiationIter(a, b)<<endl;

}