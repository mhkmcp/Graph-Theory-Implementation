/**
 Humayun Kabir
 CSE PUST, email: mhkmcp@yahoo.com
 Algorithm: Breadth First Search
 Complexity: O(V+E)
*/

#include <bits/stdc++.h>
#define MAX_N 5001

using namespace std;
typedef long long lld;

struct Node
{
    vector <int> adj;
};
Node graf[MAX_N];
bool mark[MAX_N];

inline void BFS(int start)
{
    queue <int> bfs_queue;
    bfs_queue.push(start);
    while (!bfs_queue.empty())
    {
        int xt = bfs_queue.front();
        bfs_queue.pop();
        mark[xt] = true;
        ///printf("Traversing Node ID %d\n", xt);
        for (int i=0; i<graf[xt].adj.size(); i++)
        {
            if (!mark[graf[xt].adj[i]])
            {
                bfs_queue.push(graf[xt].adj[i]);
                mark[graf[xt].adj[i]] = true;
            }
        }
    }
}

int main()
{
    int V, E, i, u, v, s;
    cout<<"Number of Node and Edge"<<endl;
    cin >> V >> E;
    vector <int> adj[V];

    cout << "Enter "<<E<<" edges: "<<endl;

    for(i = 0; i < E; i++){
        cin>>u>>v;
        graf[u].adj.push_back(v);
    }
    cout << "Enter source Node"<<endl;
    cin >> s;

    BFS(s);

    return 0;
}
