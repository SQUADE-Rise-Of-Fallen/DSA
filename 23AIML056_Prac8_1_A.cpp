/*DFS of Graph
You are given a connected undirected graph. Perform a Depth First  Traversal of the graph.
Note:  Use  a  recursive  approach  to  find  the  DFS  traversal  of  the  graph    starting  from  the  0th
vertex from left to right according to the graph.
Example 1:
Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
Output: 0 2 4 3 1
Explanation:
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V, vector<int>()) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        stack<int> stack;
        stack.push(start);
        visited[start] = true;
        while (!stack.empty())
        {
            int current = stack.top();
            stack.pop();
            cout << current << " ";
            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(2, 4);

    cout << "DFS traversal starting from vertex 0: " << endl;
    g.DFS(0);

    return 0;
}