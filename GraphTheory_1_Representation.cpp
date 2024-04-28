#include<bits/stdc++.h>
using namespace std;

const int N= 1e3;

int graph1[N+1][N+1];

vector<int> graph2[N];  // array of vectors

int main(){
	/* 
							Adjacency Matrix

		Given 6 nodes[1-6], 9 edges :
			[1 3]
			[3 2] 
			[3 4] 
			[4 6] 
			[3 6] 
			[1 5] 
			[2 6] 
			[3 5] 
			[5 6] 

		Put in Input
		6 9
		1 3
		3 2 
		3 4 
		4 6 
		3 6 
		1 5 
		2 6 
		3 5 
		5 6 

		Adv:
		- Easy to tell i, j are connected or their weights. [O(N)]. In List method we need to iterate over ith row.
		
		Issues:
		Space Complexity: O(N^2)
		If N > 1e6, we can't use this method to store graphs.
		[Maxm memory allocation for continuous allocation is 1e7-1e8.]

	*/

	int n, e;
	cin>>n>>e;
	
	

	for(int i=0;i<e;i++){
		int v1, v2;
		cin>>v1>>v2;

		// Adjacency LMatrix
		graph1[v1][v2] = 1;
		graph1[v2][v1] = 1;

		// Adjacency List
		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
	}

	// For weighted graph - use wts in 1st method, in 2nd method use pair<int, int>.


	return 0;
}