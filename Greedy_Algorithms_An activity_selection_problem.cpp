#include<bits/stdc++.h>
using namespace std;



void GREEDY_ACTIVITY_SELECTOR(int s[],int f[],int);


void Quicksort(int A[],int,int);//Using Quick sort.
int Partition(int A[],int,int);

int main()
{
    int n,c=1;
    cin>>n;
    int s[n],f[n];

    for(int i=1;i<=n;i++)
        cin>>s[i];

    for(int j=1;j<=n;j++)
        cin>>f[j];

        //Quicksort(f,c,n);

        GREEDY_ACTIVITY_SELECTOR(s,f,n);

    return 0;
}


void GREEDY_ACTIVITY_SELECTOR(int s[],int f[],int n)
{
    int a[n],k=1,l,x=2;

    a[1]=1;

    for(l=2;l<=n;l++)
    {
        if(s[l]>=f[k])
        {
            a[x]=l;
            k=l;
            x++;
        }
    }

    for(int p=1;p<x;p++)
        cout<<a[p]<< " ";
    cout<<endl;
}

void Quicksort(int A[],int p,int r)
{
    if(p<r)
    {
        int q;
        q=Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

int Partition(int A[],int p,int r)
{
    int pvort,i,tmp,tmp2;
    i=p-1,pvort=A[r];

    for(int j=p; j<=r-1; j++)
    {
        if(A[j]<=pvort)
        {
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp2=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp2;
    return i+1;
}





///i  1 2 3 4 5 6 7 8 9 10 11
/// -------------------------
///si 1 3 0 5 3 5 6 8 8 2 12
///fi 4 5 6 7 9 9 10 11 12 14 16





























/*

void GREEDY_ACTIVITY_SELECTOR(int s[],int f[],int);


int main()
{
    int n;
    cin>>n;
    int s[n],f[n];

    for(int i=1;i<=n;i++)
        cin>>s[i];

    for(int j=1;j<=n;j++)
        cin>>f[j];

        GREEDY_ACTIVITY_SELECTOR(s,f,n);

    return 0;
}


void GREEDY_ACTIVITY_SELECTOR(int s[],int f[],int n)
{
    int a[n],k=1,l,x=2;

    a[1]=1;

    for(l=2;l<=n;l++)
    {
        if(s[l]>=f[k])
        {
            a[x]=l;
            k=l;
            x++;
        }
    }

    for(int p=1;p<x;p++)
        cout<<a[p]<< " ";
    cout<<endl;
}


///i  1 2 3 4 5 6 7 8 9 10 11
/// -------------------------
///si 1 3 0 5 3 5 6 8 8 2 12
///fi 4 5 6 7 9 9 10 11 12 14 16


*/
