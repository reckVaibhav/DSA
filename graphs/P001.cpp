#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------------------------------
    // 1. Brute Force BFS Approach
    // -------------------------------
    vector<int> bfsBruteForce(int V, vector<vector<int>>& adj) {
        vector<int> result;
        vector<int> visited(V, 0);

        // Start BFS from each node, even if already visited
        for (int start = 0; start < V; start++) {
            if (!visited[start]) {
                queue<int> q;
                q.push(start);
                visited[start] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    result.push_back(node);

                    // Brute force scanning neighbors
                    for (int i = 0; i < adj[node].size(); i++) {
                        int neighbor = adj[node][i];
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return result;
    }

    // -------------------------------
    // 2. Optimal BFS Approach
    // -------------------------------
   class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n= adj.size();
        int vis[n]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>Bfs;
        while(!q.empty()){
           int node= q.front();
           q.pop();
           Bfs.push_back(node);
           for(auto it: adj[node]){
               if(!vis[it]){
                   vis[it]=1;
                   q.push(it);
               }
           }
        }
        return Bfs;
        
    }
};

// -------------------------------
// Driver code
// -------------------------------
int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example graph (undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    Solution obj;

    cout << "Brute Force BFS Traversal: ";
    vector<int> brute = obj.bfsBruteForce(V, adj);
    for (int node : brute) cout << node << " ";
    cout << "\n";

    cout << "Optimal BFS Traversal: ";
    vector<int> optimal = obj.bfsOptimal(V, adj);
    for (int node : optimal) cout << node << " ";
    cout << "\n";

    return 0;
}
