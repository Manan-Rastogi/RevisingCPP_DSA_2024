// https://visualgo.net/en/dfsbfs

#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+10;

vector<int> graph[N];
bool visited[N];

/*
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
*/

// we need to apply dfs for every child of current node that has not been visited.
// TC - O(N+E)   Recursion called E Times.
void dfs(int start_vertex){
	// 1. take action on vertex after entering the vertex.
	visited[start_vertex] = true;

	for(int child: graph[start_vertex]){
		cout<<"Par= "<<start_vertex<<" | Child= "<<child<<endl;
		if (visited[child]) {
			continue;
		}

		// 2. take action on child before entering child node
		

		dfs(child);
		

		// 3. take action on child after exiting child node.
	}
	
	// 4. take action on vertex before exiting the vertex..
}
// Most of the DFS questions can be solved by understanding and changing code in these 4 sections.


int main(){
	int n, e;
	cin>>n>>e; 

	for(int i=0;i<e;i++){
		int v1, v2;
		cin>>v1>>v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);

		
	}

	dfs(1);

	return 0;
}