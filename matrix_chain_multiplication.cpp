#include<bits/stdc++.h>
using namespace std;


void MATRIX_CHAIN_ORDER(int p[],int n)
{
    int m[n][n]={0},s[n-1][n]={0},j,q;


    for (int i=1; i<=n; i++)
    {
        m[i][i]=0;
        s[i][i]=0;
    }


    for (int l=2; l<=n; l++)
    {
        for (int i=1; i<=(n-l+1); i++)
        {
            j=i+l-1;
            m[i][j]=9999999;
            for(int k=i; k<=j-1; k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<endl;
    for(int x=1; x<=( sizeof(m)/sizeof(m[0]) ); x++)
    {
        for(int y=1; y<=( sizeof(m)/sizeof(m[0]) ); y++)
            cout<<m[x][y]<< " ";
        cout<<endl;
    }

    cout<<endl;
    cout<<"Minimum number of multiplications is "<<m[1][( sizeof(m)/sizeof(m[0]) )]<<endl;
    cout<<endl;
    for(int x=1; x<=( sizeof(s)/sizeof(s[0]) ); x++)
    {
        for(int y=1; y<=( sizeof(s)/sizeof(s[0]) ); y++)
            cout<<s[x][y]<< " ";
        cout<<endl;
    }
}


int main()
{
    int t;
    cin>>t;
    int p[t];
    for(int i=0; i<=t; i++)
    {
        cin>>p[i];
    }
    MATRIX_CHAIN_ORDER(p,t);
    return 0;
}

/*
5
20 25 10 12 18 30
*/
