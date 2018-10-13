
/*
 Petar 'PetarV' Velickovic
 Algorithm: Cycle Detection
*/
#include <bits/stdc++.h>
#define MAX_N 5001

using namespace std;
typedef long long lld;

int node, edge;

struct Node
{
    vector<int> adj;
};
Node graf[MAX_N];
bool mark[MAX_N];

//Algoritam za trazenje ciklusa u neusmerenom grafu, koristeci DFS
//Slozenost: O(V + E)

inline bool DFS(int start)
{
    stack <int> dfs_stek;
    stack <int> previous;
    dfs_stek.push(start);
    previous.push(-1);

    while (!dfs_stek.empty())
    {
        int xt = dfs_stek.top();
        int pt = previous.top();
        dfs_stek.pop();
        previous.pop();

        mark[xt] = true;
        for (int i=0; i<graf[xt].adj.size(); i++)
        {
            if (!mark[graf[xt].adj[i]])
            {
                dfs_stek.push(graf[xt].adj[i]);
                previous.push(xt);
                mark[graf[xt].adj[i]] = true;
            }
            else if (graf[xt].adj[i] != pt) return true;
        }
    }
    return false;
}

inline bool hasCycle(int n)
{
    for (int i=0;i<n;i++)
    {
        if (!mark[i])
        {
            if (DFS(i)) return true;
        }
    }
    return false;
}

int main()
{
    int i, u, v, w;
    cout<<"Number of Node and Edge"<<endl;
    cin >> node >> edge;

    cout << "Enter "<<edge<<" edges: "<<endl;

    for(i = 0; i < edge; i++){
        cin>>u>>v;
        graf[u].adj.push_back(v);
        graf[v].adj.push_back(u);
    }

    cout << hasCycle(node)<<endl;

    return 0;
}
