#include<bits/stdc++.h>
using namespace std;



///using string
void LCS(string x,string y)
{
    int m,n;
    m=x.size();
    n=y.size();
    //cout<<x[1]<< " == "<<y[1]<<endl;
    int c[n][m],b[n][m];

    for(int i=-1; i<=n-1; i++)
        c[i][-1]=0;

    for(int j=-1; j<=m-1; j++)
        c[-1][j]=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<x[j]<< " == "<<y[i]<<endl;
            if(x[j]==y[i])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else if( c[i-1][j] > c[i][j-1] )
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
        }
    }



    for(int i=-1; i<n; i++)
    {
        for(int j=-1; j<m; j++)
        {
            cout<<c[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<< "longest common subsequence : " <<c[n-1][m-1]<<endl;
}

int main()
{
    string x,y;
    cin>>x>>y;
    LCS(x,y);
    return 0;
}

/*
AAGCAATG
AACGC

AGGTAB
GXTXAYB
*/




























///using character

/*

void LCS(char *x,char *y,int m,int n)
{
    //cout<<x[1]<< " == "<<y[1]<<endl;
    int c[n][m],b[n][m];

    for(int i=0; i<=n; i++)
        c[i][0]=0;

    for(int j=0; j<=m; j++)
        c[0][j]=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            //cout<<x[1]<< " == "<<y[1]<<endl;
            if(x[j]==y[i])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else if( c[i-1][j] > c[i][j-1] )
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
        }
    }



    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<c[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<< "longest common subsequence : " <<c[n][m]<<endl;
}

int main()
{
    int n,m;
    cin>>m>>n;
    char x[m],y[n];

    for(int i=1; i<=m; i++)
        cin>>x[m];

    for(int j=1; j<=n; j++)
        cin>>y[n];

    LCS(x,y,m,n);

    return 0;
}
*/

/*
7 6
A B C B D A B
B D C A B A

6 7
B D C A B A
A B C B D A B

8 5
AAGCAATG
AACGC
*/
