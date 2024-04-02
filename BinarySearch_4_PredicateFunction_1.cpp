// https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;


const int N=1e6 + 10;        // globally declare array with greater than 1e5 elements to avoid segmentation fault.
long long trees[N];


int n;
long long int m;             // Required amount of wood.





/*
A predicate function that takes h height as input and checks if this height is sufficient to get the appropriate amount of wood.
It will return true if amount of wood received by cutting at height h >= M (required wood).
It will return false if M > amount of wood we gain by cutting at height h. 

So we cut at h=0 we will get T
h= 0 1 2 3 .... 100 .... 10000 ............
P= T T T T ....  T  ....   F   ............

At some point we will get F. The Last T will be aur answer.

We can not go to all h from 0 to 1e9 so we use binary search to find this optimal height.
*/
bool PredicateFunc_IsWoodSufficient(long long h){
	long long wood=0; 
	for(int i = 0; i < n; i++){
		if(trees[i] > h){
			wood += trees[i] - h;
		}
	}

	return wood >= m;
}



int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin>>trees[i];
	}

	long long lo=0, hi=1e9, mid;

	while(hi-lo > 1){                                    // TC- Log(hi)
		mid = lo + (hi - lo)/2;
		if(PredicateFunc_IsWoodSufficient(mid)){         // TC- O(n)
			lo = mid;
		}else{
			hi=mid-1;
		}
	}

	if (PredicateFunc_IsWoodSufficient(hi)){
		cout<<hi;                          // we need max ht so we are checking hi first
	}else {
		cout<<lo;
	}

	return 0;
}

// TC - O(nlog(hi))