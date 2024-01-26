// https://www.hackerrank.com/challenges/crush/problem

/*
Starting with a 1-indexed array of zeros and a list of operations, 
for each operation add a value to each the array element between two given indices, 
inclusive. Once all operations have been performed, return the maximum value in the array.

Example


Queries are interpreted as follows:
 a b k
 1 5 3
 4 8 7
 6 9 1


 Add the values of  between the indices  and  inclusive:

 	1  2 3  4  5 6 7 8 9 10
	[0,0,0, 0, 0,0,0,0,0, 0]
	[3,3,3, 3, 3,0,0,0,0, 0]
	[3,3,3,10,10,7,7,7,0, 0]
	[3,3,3,10,10,8,8,8,1, 0]


The largest value is  after all operations are performed.

Function Description

Complete the function arrayManipulation in the editor below.

arrayManipulation has the following parameters:

int n - the number of elements in the array
int queries[q][3] - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
Returns

int - the maximum value in the resultant array
Input Format

The first line contains two space-separated integers  and , the size of the array and the number of operations.
Each of the next  lines contains three space-separated integers ,  and , the left index, right index and summand.

Constraints

• (3 ≤ n ≤ 10^7)
• (1 ≤ m ≤ 2 * 10^5)
• (1 ≤ a ≤ b ≤ n)
• (0 ≤ k ≤ 10^9)
*/





/*
	######### TRICK #########
	1.	Add k to a and -k to b+1 index.
	2.	Take Prefix sum where you add ith index to i-1 index. It will add k from a to b and will cancel out k from b+1.

	ind = 1  2  3  4  5  6  7  8  9  10  11
	arr = 0  0  0  0  0  0  0  0  0   0   0   

	arr = 0  4 	0  0  0  0 -4  0  0   0   0         a=2, b=6, k=4
	arr = 1  4  0  0  0 -1 -4  0  0   0   0		 	a=1, b=5, k=1

	pfS = 1  5  5  5  5  4  0  0  0   0   0 ---> final Array

*/


#include<bits/stdc++.h>
using namespace std;

const int N= 1e7+10;         // 1e7 array in cpp can not be used locally. So creating a global array. It has to be const.
long long int arr[N]; 		 // a global array by default is filled by 0s.

int main(){
	int n, m;
	cin>>n>>m;
	while(m--){
		int a, b, k;
		cin>>a>>b>>k;

		arr[a] += k;
		arr[b+1] -= k;
	}

	// Compute Prefix
	long long max=-1;
	for(int i=1;i<=n;i++){
		arr[i] = arr[i] + arr[i-1];
		if (arr[i] >= max){
			max=arr[i];
		}
	}

	cout<<max<<endl;
}