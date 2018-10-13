/**
 Humayun Kabir
 CSE PUST, email: mhkmcp@yahoo.com
 Algorithm: Krushkal Algorithm for Minimam Spanning Tree
 Complexity: O(E log V)
*/

#include <bits/stdc++.h>
#define MAX_N 100001
using namespace std;
typedef long long lld;

int node, edge;
int numComponents, ret;

struct Edge
{
    int u, v, w;
    bool operator <(const Edge &e) const
    {
        return (w < e.w);
    }
};
Edge E[MAX_N];

struct Node
{
    int parent;
    int rank;
};
Node DSU[MAX_N];

inline void MakeSet(int x)
{
    DSU[x].parent = x;
    DSU[x].rank = 0;
}

inline int Find(int x)
{
    if (DSU[x].parent == x) return x;
    DSU[x].parent = Find(DSU[x].parent);
    return DSU[x].parent;
}

inline void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;

    ///Path Compression
    if (DSU[xRoot].rank < DSU[yRoot].rank)
    {
        DSU[xRoot].parent = yRoot;
    }
    else if (DSU[xRoot].rank > DSU[yRoot].rank)
    {
        DSU[yRoot].parent = xRoot;
    }
    else
    {
        DSU[yRoot].parent = xRoot;
        DSU[xRoot].rank++;
    }
}

inline int Kruskal()
{
    int ret = 0, numComponents = n;
    for (int i=0; i < n; i++)
        MakeSet(i);

    sort(E, E+edge);

    for (int i=0; i < m && numComponents > 1;i++)
    {
        if (Find(E[i].u) != Find(E[i].v))
        {
            Union(E[i].u, E[i].v);
            ret += E[i].w;
            numComponents--;
        }
    }
    if (numComponents > 1) return -1;
    return ret;
}

int main()
{
    int i, u, v, w;
    cout<<"Number of Node and Edge"<<endl;
    cin >> node >> edge;

    cout << "Enter "<<edge<<" edges: "<<endl;

    for(i = 0; i < edge; i++){
        cin>>u>>v>>w;
        E[i].u = u;
        E[i].v = v;
        E[i].w = w;
    }

    printf("%d\n",Kruskal());

    return 0;
}
