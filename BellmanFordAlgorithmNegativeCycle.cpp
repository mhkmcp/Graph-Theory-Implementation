/**
 Humayun Kabir
 CSE PUST, email: mhkmcp@yahoo.com
 Algorithm: Bellman-Ford Algorithm
 Complexity: O(V*E)
*/

#include <bits/stdc++.h>
#define MAX_N 5001
#define MAX_E 25000001
#define INF 987654321

using namespace std;
typedef long long lld;

int v, e;

int dist[MAX_N];
struct Edge
{
    int x, y, weight;
};
Edge E[MAX_N];



inline int BellmanFord(int source)
{
    for (int i=0; i<v; i++)
    {
        if (i == source) dist[i]=0;
        else dist[i] = INF;
    }
    bool done = false;
    for (int i = 0; !done && i<v; i++)
    {
        done = true;
        for (int j=0; j<e; j++)
        {
            int so = E[j].x;
            int de = E[j].y;
            if (dist[so] + E[j].weight < dist[de])
            {
                dist[de] = dist[so] + E[j].weight;
                done = false;
            }
        }
    }
    if (!done) return -1; //negative edge cycle detected
    return 0;
}

int main()
{

    int i, u, v, w;
    cout<<"Number of Node and Edge"<<endl;
    cin >> v >> e;

    cout << "Enter "<<e<<" edges: "<<endl;

    for(i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        E[i].x = u;
        E[i].y = v;
        E[i].weight = w;
    }

    cout << BellmanFord(0)<<endl; /// Negative Edge is detected but not the distance.
    printf("%d\n",dist[4]);
    return 0;
}

