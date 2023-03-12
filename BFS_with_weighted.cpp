#include<bits/stdc++.h>
using namespace std;



const int mx=1e5;///DFS with weighted.

vector <int> graph[mx];
vector <int> cost[mx];
bool visit[mx];
int dis[mx];

void adjacency_list(int nodes)
{
    cout<<endl<< "Adjacency list."<<endl;
    for(int i=0; i<nodes; i++)
    {
        cout<<i<< " -> ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<< " ";
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<nodes; i++)
    {
        cout<<i<< " -> ";
        for(int j=0; j<cost[i].size(); j++)
            cout<<cost[i][j]<< " ";
        cout<<endl;
    }
    cout<<endl;
}

void BFS(int source)
{
    int c=0;
    queue <int> Q;
    visit[source]=1;
    dis[source]=0;
    Q.push(source);

    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();

        for(int i=0; i<graph[node].size(); i++)
        {
            int next=graph[node][i];
            if(visit[next]==0)
            {
                visit[next]=1;
                dis[next]=dis[node]+cost[node][i];
                Q.push(next);
            }
            c++;
        }
    }
    cout<<"Complexity -> "<<c<<endl;
}


int main()
{
    int nodes,edges,source;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }

    adjacency_list(nodes);
    BFS(source);

    cout<< "Input starting node : ";
    cin>>source;

    adjacency_list(nodes);
    BFS(source);

    cout<<"Start from -> "<<source<<endl<<endl;
    for(int i=1; i<=nodes; i++)
        cout<<"Distance of "<<i<< " is -> "<<dis[i]<<endl;

    return 0;
}

/*
7 7
1 3 22
1 2 33
1 7 80
2 4 20
3 6 55
4 5 77
6 5 71
1
*/
