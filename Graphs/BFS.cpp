#include <iostream>
#include <queue>
using namespace std;

const int maxNodes = 100;

void bfs(int start, int graph[][maxNodes], bool visited[], int nodes)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < nodes; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n, m; 
    cin >> n >> m;

    int graph[maxNodes][maxNodes] = {0}; 

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    int startNode; 
    cin >> startNode;

    bool visited[maxNodes] = {false};
    bfs(startNode, graph, visited, n + 1);

    return 0;
}
