#include<bits/stdc++.h>
using namespace std;


/*
	MMI
	(A/B) % M = (A*B^-1) % M = [(A % M) / ((B^-1) % M)] % M

	B^-1 % M is MMI of B.

	If A*B = 1 => B is Multiplicative Inverse of A.

	If (A*B) % M = 1 => B is Modular Multiplicative Inverse of A.
	*	1 <= B < M-1                         [B's range is less than M as it will be % M.]
	
	How to find B^-1 
	1 ==> Loop B from 1 to M-1. If (A*B)%M == 1 we have MMI of A.
	TC= O(M)
	
	2 ==> Property of MMI. MMI of A will exist iff A and M are coprime [GCD(A, M) = 1].
	To solve this we use Fermet Theorem.
	FT => A^(m-1) =_ 1 mod M     (=_ : congurency)
	   => If I divide A^(M-1) by M we get remainder as 1. [M is to be prime. A is not multiple of M]
	   => Multiply both sides by A^-1
	   => A^(M-2) =_ A^-1 mod M => If I divide A^(M-2) by M I get A^-1.
	   => A^(M-2) % M = A-1
	   => binaryExponentiation(A, M-2)   // A and M are Coprime. M is Prime.
	   // Log(N)


	   => If M is not prime but A and M are Coprimes we need to use EEA(Extended Euclidean Algorithm)
	   // Veru Difficult Question. Generally Not Asked. Revisit once you are expert in Normal Questions.
*/

const int M = 1e9+7;

int binaryExponentiation(int A, int B){
	int ans = 1;
	while(B){
		if(B & 1){
			ans = (ans * 1LL * A) % M;
		}
		A = (A * 1LL * A) % M;
		B >>= 1;
	}
	return ans;
}

int main(){	
	int a = 2;
	int b = binaryExponentiation(a, M-2);

	cout<<b<<endl;

	cout<<(a * b) % M<<endl;

	return -1;
}