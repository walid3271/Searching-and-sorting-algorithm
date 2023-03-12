#include<bits/stdc++.h>
using namespace std;



const int mx=1e5;///DFS
int c=1;
vector <int> graph[mx];
bool vis[mx];
int seq[mx];

void adjacency_list(int nodes)
{
    cout<<endl<< "Adjacency list."<<endl;
    for(int i=1; i<=nodes; i++)
    {
        cout<<i<< " -> ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<< " ";
        cout<<endl;
    }
}

void dfs(int source)
{
    vis[source]=1;
    for(int i=0; i<graph[source].size(); i++)
    {
        int next=graph[source][i];
        if(vis[next]==0)
        {
            seq[c]=next;
            c++;
            dfs(next);
        }
    }
}





int main()
{
    int nodes,edges,source,i;
    cout<< "Input number of node & edge : ";
    cin>>nodes>>edges;
    for(i=1; i<=edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<< "Input starting node : ";
    cin>>source;

    adjacency_list(nodes);
    dfs(source);


    /*
    for(int i=1; i<=nodes; i++)
    {
        if(vis[i]==1)
            cout<<"Nodes "<<i<< " is visited."<<endl;
        else
            cout<<"Nodes "<<i<< " is not visited."<<endl;
    }
    */

    cout<<endl<<"Nodes visited sequence "<<source<< " -> ";
    for(i=1; i<c-1; i++)
        cout<<seq[i]<< " -> ";
    cout<<seq[i]<<endl;
    return 0;
}

/*
6 5
1 6
1 2
1 3
2 5
3 4
1
*/
