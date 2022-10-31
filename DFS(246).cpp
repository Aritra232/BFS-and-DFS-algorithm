#include<iostream>
#include<vector>

using namespace std;

int color[50],pre[100],d[100],f[100], white=0, gray=1, black=2,time ;

vector<int>graph[50];

void DFS_Visit(int p);

void DFS(int u, int source)
{
    for(int i=0; i<u; i++)
    {
        color[i] = white;
        pre[i] = -1;
        f[i] = 87544;
        d[i] = 42121;
    }
    time =0;
    for(int i=0; i<u; i++)
    {
        if(color[i]==white)
        {
            DFS_Visit(i);
        }
    }
}

void DFS_Visit(int u)
{

    color[u] = gray;
    time = time + 1;
    d[u] = time;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
       /* if(color[v]==white)
        {
            pre[v]=u;
            DFS_Visit(v)
        }*/
        if(color[v] == 0)
        {
            pre[v] = u;
            cout << u << "->" << v << "tree edge" << endl;
            DFS_Visit(v);
        }
        else if(color[v] == 1)
        {
            cout << u << "->" << v << "back edge" << endl;
            cout << "Cycle found" << endl;
        }
        else
        {
            if(d[u] < d[v])
            {
                cout << u << "->" << v << "forward edge" << endl;
            }
            else
            {
                cout << u << "->" << v << "cross edge" << endl;
            }
        }
    }
    color[u] = black;
    time=time+1;
    f[u] = time;
}


int main()
{
    int nodes, n, edge, i, j, u,v, source ;
    cout<< "Enter Nodes:";
    cin>> nodes;
    cout<< endl;
    cout<< "Enter Edge";
    cin>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>> u >> v;
        graph[u].push_back(v);
    }

    cout << "Enter Source Node :";
    cin>> source;
    DFS(edge,source);

}
