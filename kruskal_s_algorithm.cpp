#include<bits/stdc++.h>
using namespace std;


struct edgeStructure
{
    int u,v,w;
};

bool operator < (edgeStructure lh,edgeStructure rh)//operator overloading.
{
    return lh.w<rh.w;
}

const int MX=100;
int parent[MX];
int rankParent[MX];

vector <edgeStructure> EdgeV;
vector <edgeStructure> tree;


void initializerSet(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        //rankParent[i]=0;
    }
}

int findParent(int x)//searching until finding the parent
{
    if(x != parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void unionSet(int x,int y)
{
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)
        return;

    if(rankParent[px]<rankParent[py])
        parent[px]=py;

    else if(rankParent[px]>rankParent[py])
        parent[py]=px;

    else
    {
        parent[py]=px;
        rankParent[px]++;
    }
}

void printSet(int n)
{
    for(int i=0 ; i<n; i++)
    {
        cout<< "Node is "<< i<< " Parent are "<<parent[i]<< " Rank is "<<rankParent[i]<<endl;
    }
    cout<<endl;
}

int kruskal(int n)
{
    initializerSet(n);

    sort(EdgeV.begin(),EdgeV.end());

    int sz=EdgeV.size();


    cout<< "After sorting the graph."<<endl;
    for(int i=0; i<sz; i++)///After sorting the graph
    {
        cout<<EdgeV[i].u<< " -- "<<EdgeV[i].v<< " cost "<<EdgeV[i].w<<endl;
    }


    int ans = 0;
    for(int i=0; i<sz; i++)
    {
        if(findParent(EdgeV[i].u)!=findParent(EdgeV[i].v))//Whether both are part of the same set
        {
            unionSet(parent[EdgeV[i].u],parent[EdgeV[i].v]);
            ans+=EdgeV[i].w;
            tree.push_back(EdgeV[i]);

        }
    }
    return ans;
}



int main()
{
    freopen("krusKal.txt","r",stdin);
    int vertex,edge;
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++)
    {
        edgeStructure e;
        cin>>e.u>>e.v>>e.w;
        EdgeV.push_back(e);
    }

    int Cost=kruskal(vertex);

    cout<<endl<< "Tree"<<endl;
    for(int i=0; i<tree.size(); i++)
        cout<<tree[i].u<< "--"<<tree[i].v<< " cost "<<tree[i].w<<endl;

    cout<<endl<< "MST Cost "<<Cost<<endl;

    return 0;
}



/*
6 9
1 2 6
1 3 3
2 3 2
2 4 5
3 5 4
3 4 3
4 5 2
4 6 3
5 6 5
*/
