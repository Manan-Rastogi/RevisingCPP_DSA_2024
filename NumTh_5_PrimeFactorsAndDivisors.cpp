#include<bits/stdc++.h>
using namespace std;

/////////////////////// Count & Sum of Divisors //////////////////////
// O(N)
void divisors_brute(int n){
	int ct = 0, sum = 0;
	for(int i = 1; i<=n; i++){
		if(n%i == 0){
			ct++;
			sum += i;
			cout<<i<<endl;
		}
	}
	cout<<"No of divisors = "<<ct<<endl;
	cout<<"Sum of divisors = "<<sum<<endl;

}

// O(sqrt(n))
void divisors_root_n(int n){
	int ct=0;
	int sum=0;

	for(int i=1; i*i<=n; i++){
		if(n % i == 0){
			int x = n/i; 
			cout<<i<<endl;
			if (x != i){
				cout<<x<<endl;
				ct++;
				sum += x;
			}
			ct++;
			sum = sum + i;
		}
	}
	cout<<"No of divisors = "<<ct<<endl;
	cout<<"Sum of divisors = "<<sum<<endl;
}


/*
divisors_root_n is faster but not fast enough to find count or sum for 1e6 inputs. 
Total cals will reach 1e9 and will end up giving TLE. 

Using Prime Factorization
n = p1^n1 * p2^n2 * ...... * pK^nk

Eg: 36 = 2^2 * 3^2
All the factors of 36 will be combination of subsets of [2, 2, 3, 3] like 2, 2*2, 2*2*3, 2*3 etc.

So Choices for p1 = n1+1, p2 = n2 + 1 .......

For 36, count of factors = (p1+1) * (p2+1) = 3*3 = 9


Sum = (1 + p1^1 + p1^2 + ..... + p1^n1) * (1 + p2^1 + p2^2 + ... p2^n2) * .......
	= [(p1^(n1+1) - 1) / (p1-1)] * [(p2^(n2+1) - 1) / (p2-1)] * .....       [G.P]
For 36, (1 + 2 + 4)*(1 + 3 + 9)  [Expand it to see all divisors]
	= 7 * 13 = 91


So To optimize this soln we need to optimizee the method to find Prime Factors.
*/


/////////////////////// Prime Check //////////////////////
// O(N)
bool isPrimeBrute(int n){
	if (n<=1) return 0;
	if (n == 2) return 1;
	for(int i = 2; i<n; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

// O(sqrt(n))
bool isPrimeRoot(int n){
	if (n<=1) return 0;
	if (n == 2) return 1;
	for(int i = 2; i*i<=n; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}


/////////////////////// Prime Factorization //////////////////////
/*
NOTE: Any number's smallest divisor is always a prime number. [excluding 1]

36 ---> 18 ---> 9 ---> 3 ---> 1
    2       2      3      3

To find Prime Factorization we find smallest factor (prime) of the no and keep 
on dividing till its properly divible. Then we choose next smallest divisor and start dividing.
This keeps on going till we are left with 1.

*/

// O(N)
vector<int> PrimeFactorsBrute(int n){
	vector<int> prime_factors;
	for(int i = 2; i<=n; i++){
		while(n % i == 0){
			n = n/i;
			prime_factors.push_back(i);
		}
	}
	return prime_factors;
}

// O(sqrt(N))
vector<int> PrimeFactorsRoot(int n){
	vector<int> prime_factors;
	for(int i = 2; i*i<=n; i++){
		while(n % i == 0){
			n = n/i;
			prime_factors.push_back(i);
		}
	}
	return prime_factors;
}


int main(){
	// divisors_brute(20);
	// divisors_root_n(36);
	// cout<<isPrimeBrute(1e9+7)<<endl;
	// cout<<isPrimeRoot(121)<<endl;

	vector<int> pf;
	pf = PrimeFactorsBrute(121*7);

	for(int i:pf){
		cout<<i<<endl;
	}

	return 0;
}