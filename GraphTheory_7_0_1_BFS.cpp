#include<bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/01_bfs.html

/*
0-1 BFS (0-1 Breadth-First Search)

Definition:
0-1 BFS is a special case of the Shortest Path algorithm using the BFS technique. It is optimized for graphs where the weights of the edges are either 0 or 1.

Key Points:
1. Queue Structure:
   - In the queue used for 0-1 BFS, at any given time, there will be only two levels of nodes.
   - Let's denote these levels as x and x + 1.

2. Node Levels:
   - Nodes at level x are processed first, followed by nodes at level x + 1.
   - This helps in efficiently finding the shortest path in graphs with 0 and 1 weighted edges.

3. Edge Weights:
   - Any edge with a weight of 0 is considered at the current level (x).
   - Thus, nodes connected by edges with weight 0 are pushed to the front of the queue, ensuring they are processed at the current level (x).

4. Processing Nodes:
   - Nodes connected by edges with weight 1 are pushed to the end of the queue, meaning they will be processed at the next level (x + 1).
   - This ensures that nodes with edge weight 0 are always prioritized in processing.

5. Algorithm Continuation:
   - The BFS continues with this condition, processing nodes with edge weight 0 before nodes with edge weight 1.

Steps:
1. Initialize a deque (double-ended queue) to store nodes.
2. Insert the starting node into the deque.
3. While the deque is not empty:
   a. Pop the front node from the deque.
   b. For each adjacent node:
      i. If the edge weight is 0 and the node is not yet visited, push it to the front of the deque.
      ii. If the edge weight is 1 and the node is not yet visited, push it to the back of the deque.

Example:
Consider a graph with nodes and edges where weights are either 0 or 1. Using 0-1 BFS will help you find the shortest path from the source to the destination more efficiently than the traditional BFS, especially for large graphs with these specific edge weights.

Advantages:
- More efficient than Dijkstra’s algorithm for graphs with edge weights restricted to 0 and 1.
- Maintains the simplicity of BFS with the added benefit of handling weighted edges.

Use Cases:
- Network routing where hops (edges) can have a delay of 0 or 1 unit.
- Any scenario where you need the shortest path in a graph with binary edge weights.

*/



// https://www.codechef.com/KCR22018/problems-old/REVERSE 
int main(){


	return 0;
}