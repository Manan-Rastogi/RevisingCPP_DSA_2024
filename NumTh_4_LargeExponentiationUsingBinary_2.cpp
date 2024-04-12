#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

// Now b <= 1e18 Earlier Code will work


/* 
If b > 1e18, sat a^(b^c) this b^c will be vary large and we cannot apply %M on power like we did with a in prev code.

We will use concept of:
1. Co-Primes => a, b are co-primes if GCD(a, b) = 1. Eg: 15, 28
2. ETF : Euler Totient Function
	ETF(N) = Count of all co-primes b/w 1 and N(both included).
	ETF(5) = [1, 2, 3, 4] = 4

	φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk) where p1, p2, ..., pk are the distinct prime factors of n.
	For example, if n = 10, which factors into primes 2 and 5, then φ(10) = 10 * (1 - 1/2) * (1 - 1/5) = 4.

3. Euler's Theorem
	a^b =_ a^(b mod φ(n)) mod φ(n) [=_ -> Congurent to   =>  a = b mod(n) says if I divide a by n I will get b]

	=> (a^b) % M = [a ^ (b % φ(M))] % M
	In most cases M will be prime so φ(M) = M(1 - 1/M) = M-1

	=> (a ^ b) % M = [a ^ (b % (M-1))] % M  [M is prime]
*/
int binaryExponentiationIter(int a, long long b, int m){  // TC= log(N)
	int ans = 1;
	while(b){
		if(b&1){
			ans= (ans * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return ans;
}

int main(){
	// 50 ^ 64 ^ 32
	long long a=50, b=64, c=32;
	cout<<binaryExponentiationIter(a, binaryExponentiationIter(b, c, M-1), M)<<endl;
}