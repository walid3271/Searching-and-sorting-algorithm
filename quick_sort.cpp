#include<bits/stdc++.h>
using namespace std;

void Quicksort(int A[],int,int);//Quick sort
int Partition(int A[],int,int);

int main()
{
    int r,p=1,A[5000];
    cin>>r;
    for(int i=1; i<=r; i++)
        cin>>A[i];

    Quicksort(A,p,r);

    cout<<endl;
    for(int i=1; i<=r; i++)
        cout<<A[i]<< " ";
    cout<<endl;
    return 0;
}

void Quicksort(int A[],int p,int r)
{
    if(p<r)
    {
        int q;
        q=Partition(A,p,r);//return value from Partition function
        Quicksort(A,p,q-1);//q-1 recall int r
        Quicksort(A,q+1,r);//q+1 recall int p
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
