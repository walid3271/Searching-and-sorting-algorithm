#include<bits/stdc++.h>
using namespace std;

int bottom_up_cut_rod(int p[],int n)
{
    int r[n],q,i,j;
    r[0]=0;

    for(j=1; j<=n; j++)
    {
        q=-9999;
        for(i=1; i<=j; i++)
        {
            q=max(q, (p[i]+r[j-i]) );
            //cout<<q<<endl;
        }
        r[j]=q;
        //cout<<i<< " " ;
    }
    return r[n];

}


int main()
{

    int n;
    cin>>n;
    int p[n];
    for(int i=1; i<=n; i++)
        cin>>p[i];

        cout<< "Maximum profit -> " <<bottom_up_cut_rod(p,n);


    /*
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    int n= sizeof(p)/sizeof(p[0]);

    cout<<bottom_up_cut_rod(p,n-1);

    */
    return 0;
}
/*
1 5 8 9 10 17 17 20 24 30
*/

