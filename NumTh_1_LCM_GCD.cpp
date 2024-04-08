#include<bits/stdc++.h>
using namespace std;

/*
	GCD:
		use eucleadian gcd method. 
*/

// even if x is greater than y we will still get desired results.
int gcd(int x, int y){
	int r = y % x;
	if (r == 0){
		return x;
	}
	return gcd(r, x);
}
// TC: log(N)

int main(){
	int a = 9999;
	int b = 333;
	int hcf= gcd(a, b);
	cout<<hcf<<endl;

	int lcm= a*b/hcf;
	cout<<lcm<<endl;

	cout<<__gcd(a, b)<<endl;  // log(N)

	// GCD of 3 
	cout<<gcd(gcd(a,b), a+b);

	// Minimun fraction of a/b. we divide both num and deno by gcd(a,b).

	return 0;
}