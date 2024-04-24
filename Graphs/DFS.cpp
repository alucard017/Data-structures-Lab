#include <iostream>
#include <stack>
using namespace std;

const int maxNodes = 100;

void dfs(int start, int graph[][maxNodes], bool visited[], int nodes)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        cout << current << " ";

        for (int i = 0; i < nodes; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                s.push(i);
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
    dfs(startNode, graph, visited, n + 1);

    return 0;
}
