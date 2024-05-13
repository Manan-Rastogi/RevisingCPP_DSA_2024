#include<bits/stdc++.h> 
using namespace std;

/*
	DFS- Top Down Traversal.

	Height of a Node: Distance from given Node till we reach to the bottom of the subtree(leaf node). There will be a lot of Leaf Nodes, but we will consider the one with highest distance as height.
	Depth of a Node: Distance from root node to the given node.

	*	Depth of Root Node and Height of Leaf Node is 0.
	*	Depth(n) = Depth(n-1) + 1                      // Depth of nth node is 1 more than the depth of its parent.
	*	We will use depth of Root Node to get depth of each node. (Before Recursive Call)
	*	We will use height of Leaf Node to calculate height of Each Node. (After/Returning Recursive Call)

	* We can use same dfs as graph for trees as well. But we didn't need that.
	* Why?? - Visited was used to mark nodes that have called the current node OR to check if there is a loop. [uppar uppar se]
	* We don't need visited as trees have noo loops and we can maintain a parent to avoid calling node that called us.
*/

const int N=1e5+10;
vector<int> tree[N];
vector<int> depth(N);
vector<int> height(N);

// DFS over Tree
void dfs(int vertex, int par, vector<int>* path){
	path->push_back(vertex);               // Vector passed with pointers. pointers will use -> to call functions.
	for(int child: tree[vertex]){
		if(child == par) continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, vertex, path);
		height[vertex] = max(height[vertex], height[child] + 1); 
	}

}

/*
Subtree Queries:
 Eg: Count Even nos in Subtree
 Eg: Subtree Sum

Generally subtree queries are solved coming up the tree like heights

When q(1e5) queries are given. TC- q(N+ (N-1)) will be vwry high.
To tackle this we use PreComputation Techniques.

*	Sum of subtrees from egdes will bw their values only.


*/
int subtree_sum[N];

void SubtreeDfs(int vertex, int par){
	subtree_sum[vertex] = vertex;        // if val arr is we use- val[vertex]
	for(int child: tree[vertex]){
		if (child == par) continue;
		SubtreeDfs(child, vertex);

		// after dfs is completed
		subtree_sum[vertex] += subtree_sum[child];

	}
}



/*
	Diameter of a Tree:
	-	Maxm possible path b/w any 2 vertices.
	-	No of edges b/w any 2 vertices. find maxm no of edges.
	-	BruteForce: Find all Maxm distances from each vertex. Take Maxm Depth. O(n*2)
	-	Optimized:	O(n)
		i.	Take a root Node and Find node(Fn) farthest from it.
		ii. From this node(Fn: one end of Diameter) find furthest node and its length. This will be the diameter.
*/
vector<int> diameters(N);
void diameter_dfs(int vertex, int par){
	for(int child: tree[vertex]){
		diameters[child] = diameters[vertex] + 1;
		if(child != par){
			diameter_dfs(child, vertex);
		}
	}
}
 


/*
LCA -	Least Common Ancestor
	- 	Calculated b/w 2 nodes
	- 	1st Common Parent of 2 nodes is LCA.
	- 	There are a lot of ways to do so. Below is one O(N) approach. Solving <O(N) is possible but quite difficult so we will go through it when we are good with graphs and trees.
	- 	STEPS:
		--	Find Path from root node to both nodes.
		--	Store paths and iterate over them both, Last Same Node will ne the answer.
		--	How to find path?
			---	do a dfs and store parents of a node.
			---	use these parents to form path.
*/
int parents[N];

void dfs_store_par(int vertex, int par=-1){
	parents[vertex] = par;
	for(int child: tree[vertex]){
		if(child == par) continue;
		dfs_store_par(child, vertex);
	}
}

// We have parents of a vertex. We need path from root to this vertex.
vector<int> path_node(int v){
	vector<int> pth;
	while(v != -1){
		pth.push_back(v);
		v = parents[v]; 
	}

	reverse(pth.begin(), pth.end());
	return pth;
}



int main(){
	int n;
	cin>>n;
	// Tree with n nodes will have n-1 edges
	vector<int> dfs_path;
	for(int i=0;i<n-1;i++){
		int v1, v2;
		cin>>v1>>v2;

		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}

	dfs(1, 0, &dfs_path);

	for(int i : dfs_path){
		cout<<i<<" | h - "<<height[i]<<" | d - " << depth[i]<<endl;
	}


	SubtreeDfs(1, 0);
	// we use q queries loop --------- 
	cout<<"Tree Sum = " << subtree_sum[1]<<endl;


	// Diameter of a Tree
	int max_depth=0;
	int max_depth_node=0;

	diameter_dfs(1, 0);

	for(int i=1;i<=n;i++){
		if(max_depth < depth[i]){
			max_depth = depth[i];
			max_depth_node = i;
		}
		depth[i] = 0;   // reset for 2nd iteration
	}

	diameter_dfs(max_depth_node, 0);

	for(int i=1;i<=n;i++){
		if(max_depth < depth[i]){
			max_depth = depth[i];
		}
	}

	cout<<"Max Depth [Diameter] = "<< max_depth << endl;


	/////////  LCA   ////////////
	int x, y;
	cin>>x>>y;

	// store parents
	dfs_store_par(1);

	// get paths of x and y
	vector<int> path_x= path_node(x);
	vector<int> path_y= path_node(y);

	int lca = -1;

	for(int i=0; i<path_x.size(); i++){
		if(path_x[i] == path_y[i]){
			lca=path_x[i];
		}else{
			break;
		}
	}

	cout<<"LCA = "<<lca<<endl;

	return 0;
}