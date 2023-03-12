#include<bits/stdc++.h>
using namespace std;

///from Class
int weight[20][20],visited[20],key[20],p[20],V,e;

void printGraph()
{
    cout<< "The Graph"<<endl;
    for(int a=1; a<=V; a++)
    {
        for(int b=1; b<=V; b++)
        {
            cout<<weight[a][b]<< " ";
        }
        cout<<endl;
    }
}

void prims()
{
    int u,totalVisited,mincost,v;
    for(v=1; v<=V; v++)
    {
        key[v]=99999;
        p[v]=visited[v]=0;
    }
    u=1;
    key[u]=0;
    totalVisited=1;
    visited[u]=1;
    while(totalVisited!=V)
    {
        for(v=1; v<=V; v++)
        {
            if(weight[u][v]!=0)
            {
                if(visited[v]==0 && weight[u][v]<key[v])
                {
                    p[v]=u;
                    key[v]=weight[u][v];
                }
            }
        }

        mincost=99999;
        for(v=1; v<=V; v++)
        {
            if(visited[v]==0)
            {
                if(key[v]<mincost)
                {
                    mincost=key[v];
                    u=v;
                }
            }
        }
        visited[u]=1;
        totalVisited++;
    }

    cout<<endl<< "The Tree"<<endl;
    for(v=1; v<=V; v++)
        cout<<v<< "--"<<p[v]<< " cost " <<key[v]<<endl;

    mincost=0;
    for(v=1; v<=V; v++)
        mincost+=key[v];
    cout<<endl<< "MST Cost -> "<<mincost<<endl;
}

int main()
{
    freopen("krusKal.txt","r",stdin);
    int i,j,a,b,w;
    cin>>V>>e;
    weight[V][V]= {0};

    for(int i=1; i<=e; i++)
    {
        cin>>a>>b>>w;
        weight[a][b]=weight[b][a]=w;
    }
    printGraph();
    prims();
    return 0;
}

/*
7 11
1 4 5
1 2 7
2 4 9
2 3 8
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/






































































































///from YouTube
/*
const int MX=100;
typedef pair<int,int> PII;
vector <PII> v[MX];

struct node///prim's;
{
    int u,cost;
};

bool operator < (node a,node b)
{
    return a.cost>b.cost;
}

priority_queue <node> pq;

int cost[MX];
bool taken[MX];
int vertex,edge;



int prim(int source)
{
    for(int i=0; i<vertex; i++)
    {
        cost[i]=INT_MAX;
        taken[i]=0;
    }

    cost[source]=0;
    node temp;
    temp.u=source;
    temp.cost=0;
    pq.push(temp);
    int ans=0;

    while(!pq.empty())
    {
        node current=pq.top();
        pq.pop();
        if(taken[current.u])
            continue;

        taken[current.u]=1;
        ans+=current.cost;

        for(int i=0; i<v[current.u].size(); i++)
        {
            if(taken[v[current.u][i].first])
                continue;

            if(v[current.u][i].second<cost[v[current.u][i].first])
            {
                node temp2;
                temp2.u=v[current.u][i].first;
                temp2.cost=v[current.u][i].second;
                pq.push(temp2);
                cost[v[current.u][i].first]=v[current.u][i].second;
            }
        }
    }
    return ans;
}

void printGraph()
{
    for(int i=0;i<vertex;i++)
    {
        cout<<i<< "--";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].first<< " - "<<v[i][j].second<< "  ";
        }
        cout<<endl;
    }
}






int main()
{
    freopen("krusKal.txt","r",stdin);

    cin>>vertex>>edge;
    for(int i=0; i<edge; i++)
    {
        int node;
        PII p;
        cin>>node>>p.first>>p.second;
        v[node].push_back(p);

        int node2=p.first;
        p.first=node;
        v[node2].push_back(p);
    }
    //printGraph();
    int source;
    cin>>source;
    cout<< "MST IS "<<prim(source)<<endl;
    return 0;
}
*/


/*
8 9
0 3 3
0 4 6
1 5 5
1 6 1
2 4 6
3 5 8
5 6 3
5 7 2
6 7 6
*/
