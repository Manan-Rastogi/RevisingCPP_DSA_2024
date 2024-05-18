#include<bits/stdc++.h> 
using namespace std;

// https://www.interviewbit.com/problems/delete-edge/ 

// Easy Soln but difficult to Think first. 

// Precompute subtree sums. 
// Delete a Node and compute sum of both subtrees.
// Store details for maxm product.





const int M = 1e9+7;

void dfs(int vertex, int par, vector<int> g[], vector<int> &subtree_sum, vector<int> &vals){
    subtree_sum[vertex] += vals[vertex-1];                  // vertex is 0 based indexed
    for(int child: g[vertex]){
        if(child != par){
            dfs(child, vertex, g, subtree_sum, vals);
            subtree_sum[vertex] += subtree_sum[child];
        }
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> subtree_sum(A.size() + 1, 0);
    vector<int> tree[A.size() + 1];
    for(auto edge: B) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    
    dfs(1, 0, tree, subtree_sum, A);
    
    long long ans = 0;
    // Removing edges 1 by 1. For a Node the edge above it will be removed. Except for 1.
    for(int i=2; i<=A.size(); i++){
        int sub1 = subtree_sum[i];
        int sub2 = subtree_sum[1] - sub1;
        
        ans = max(ans, (sub1*1LL*sub2)%M);
    }
    
    return ans;
}





int main(){
    

	return 0;
}