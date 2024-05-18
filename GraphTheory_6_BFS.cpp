#include<bits/stdc++.h> 
using namespace std; 

/*
	BFS- Level order Traversal -- level by level

	We use queue to maintain parent child level order.

	->	BFS helps to find shortest distance in non weighted graph or equal wtd graph.
	->	Level in bfs will give shortest path from source to node.

	-> TC- v- nodes, e- edges.  O(V+2E)  V-> while loop maxm  2E-> For loop for each edge.
	==> TC- O(V+E)    // while and for loop will balance each other-- if while is running maxm times then all nodes will have minm edges, then for loop will run minm time. 

*/

const int N=1e5+10;
vector<int> tree[N];     // array of vector for tree/grapg
bool visited[N];
int level[N];

void BFS(int v){
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	level[v] = 0;

	while(!q.empty()){  // Max- O(V)
		int l = q.size();
		while(l--){ // This will make sure level is completely visited.
		int curr_v = q.front();
		q.pop();
		cout<<curr_v<<" >> ";
		for(int child: tree[curr_v]){  // O(2E)
			if(!visited[child]){
				visited[child] = 1;
				q.push(child);
				level[child] = level[curr_v] + 1;
			}
		}
		}
	} // O(V + E)
	cout<<endl;
}

int main(){
	int n, e; 
	cin>>n>>e; 

	for(int i=0; i<e; i++){ 
		int x, y;
		cin>>x>>y;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	BFS(1);

	for(int i=1;i<=n;i++){
		cout<<i<<" - "<<level[i]<<endl;
	}

	return 0;
}