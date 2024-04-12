#include<bits/stdc++.h>
using namespace std;

/*
Sieve Algorithm

Given a range of nos say 1 to 100, We need to find all primes.

1.	In the array mark all as Primes P.
2.	Mark 1 as Not Prime N.
3.	Iterate through the array. Stop on 1st P marked element. This will be prime. 
4.	For this prime no mark all its multiples as N (non primes).
5.	Continue Iteration till next P marked is found. Mark all its multiple as N.
6.	At the end of iteration we have all primes of that continuous range.
*/

// Use sieve when Q queries around 1e7 and N also 1e7; 

const int N = 1e7+10;
vector<bool> isPrime(N, 1);

// O(nlog(log(n)))
void sieve(){
	isPrime[0] = isPrime[1] = 0;
	for(int i=2;i<N;i++){
		if (isPrime[i]) {
			for(int j= 2*i; j<N; j=j+i){    // This will run like n/2 +n/3 + n/4 + ... times but for only primes. So it gives a complexity of log(log(N))
				isPrime[j] = 0;
			}
		}
	}
}

///////////////// Variations in Sieve //////////////////////

// Highest and Lowest Prime
vector<int> lp(N, 0), hp(N, 0);

void sieve_hp_lp(){
	isPrime[0] = isPrime[1] = 0;
	for(int i=2;i<N;i++){
		if (isPrime[i]) {
			lp[i] = hp[i] = i; // Marking for Primes.
			for(int j= 2*i; j<N; j=j+i){    
				isPrime[j] = 0;
				hp[j] = i;          // last marking
				if (lp[j] == 0){
					lp[j] = i;      // Only fill lp if its empty.
				}
			}
		}
	}
}


/////////////////// Storing Divisors /////////////////////

const int M = 1e5+10;
vector<int> divisors[M];

void storing_divisors(){ // nlog(n)
	for(int i=2;i<M;i++){
		for(int j=i;j<M;j+=i){
			divisors[j].push_back(i);
		}
	}
}

int main(){

	sieve_hp_lp();

	for(int i=1;i<100;i++){
		cout<<i<<" "<<isPrime[i]<<" "<<lp[i]<<" "<<hp[i]<<endl;
	}


	cout<<"\n\n ******************************************* \n\n";
	///////////////// Using lp or hp to find Prime Factors
	int num = 36;

	vector<int> prime_factors;

	while(num>1){ // O(log(N))
		int pf = hp[num];
		while(num % pf == 0){
			num /= pf;
			prime_factors.push_back(pf);
		}
	}

	for(int i:prime_factors){
		cout<<i<<" ";
	}
	cout<<"\n\n *********************************************** \n\n";

	storing_divisors();
	for(int i=2;i<10;i++){
		cout<<i<<" - ";
		for(auto div: divisors[i]){
			cout<<div<<" ";
		}
		cout<<endl;
	}
	return 0;
}