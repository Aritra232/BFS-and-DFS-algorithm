#include<bits/stdc++.h>
using namespace std;

#define max 100

vector<int>g[max];
int white=0, gray=1, black=2;
bool vis[max];
int dis[max];
int prv[max];
int colour[max];

void bfs(int source)
{
    queue<int> Q;
    vis[source] = 1;
    dis[source] = 0;
    prv[source] = -1;
    colour[source] = gray;
    Q.push(source);

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for(int i=0; i<g[node].size(); i++)
        {
            int next = g[node][i];
            if(vis[next] == 0)
            {
                vis[next]=1;
                dis[next] = dis[node] + 1;
                prv[next] = node;
                colour[next] = gray;
                Q.push(next);
            }
        }
        colour[node] = black;
    }
}

void path()
{
    int src, dst;

    cin>> src >> dst;
    while(true)
    {
        cout<< dst << " ";
        dst = prv[dst];
        if(dst == src)
        {
            cout<< src<< endl;
            break;
        }
    }
}

void connected()
{
    for(int i=0; i<4; i++)
    {
        if(colour[i] == black)
        {
            cout<< "Disconnected"<< endl;
            break;
        }
        else
        {
            cout<< "connected"<< endl;
            //break;
        }
    }
}

int main()
{
    int node, edges,u,v;
    cout<< "Enter nodes: ";
    cin>> node;
    cout<< "Enter edges: ";
    cin>> edges;

    for(int i=0; i<edges; i++)
    {
        cin>> u >> v;
        g[u].push_back(v);
        colour[u]=white;
        g[v].push_back(u);
        colour[v]=white;
    }

    int source;
    cin>> source;

    bfs(source);

    cout<< "From node " << source  << endl;
    for(int i=1; i<=node; i++)
    {
        cout<< "Distance of " << i << " is : " << dis[i] << endl;
        cout<< "Color of " << i << "is : " << colour[i] << endl;
    }

    //cout<< "Find Path :";
    // path();

    cout<< " Connected Or disconnected :";
    connected();

}

