#include<bits/stdc++.h>
using namespace std;

const int mx=1e6;///BFS
vector <int> graph[mx];
bool visit[mx];
int dis[mx];

void adjacency_list(int nodes)
{
    cout<<endl<< "Adjacency list."<<endl;
    for(int i=1; i<nodes; i++)
    {
        cout<<i<< " -> ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<< " ";
        cout<<endl;
    }
    cout<<endl;
}

void BFS(int source)
{
    int c=0;//for counting complexity
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
                dis[next]=dis[node]+1;
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
    cout<< "Input number of node & edge : ";
    cin>>nodes>>edges;

    cout<< "Input nodes & edges."<<endl;
    for(int i=1; i<=edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

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
7 9
1 2
1 3
1 7
2 4
2 3
3 7
3 5
4 6
5 6
1
*/

/*
12 11
1 2
1 3
1 4
2 5
2 6
5 9
5 10
4 7
4 8
7 11
7 12
1
*/
