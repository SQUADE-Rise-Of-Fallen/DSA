/*BFS of graph
Given a directed graph. The task is to do Breadth First Traversal of this  graph starting from 0.
Note:  One  can  move  from  node  u  to  node  v  only  if  there's  an  edge  from    u  to  v  and  find  the  BFS
traversal of the graph starting from the 0th  vertex, from left to right according to the graph. Also, you
should only take  nodes directly or indirectly connected from Node 0 in consideration.
Example 1:
Input:
Output: 0 1 2 3 4
Explanation:
0 is connected to 1 , 2 , 3.*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    vector<int> bfs(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> result;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return result;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    vector<int> bfsResult = g.bfs(0);

    cout << "BFS Traversal: ";
    for (int node : bfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}