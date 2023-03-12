#include<bits/stdc++.h>
using namespace std;
void binary(int a[],int n,int target)///binary search.
{
    int Bigen,End,Midle;
    Bigen=0,End=n;
    while(Bigen<=End)
    {
        Midle=(Bigen+End)/2;
        if(a[Midle]==target)
        {
            cout<< "Index -> "<<Midle+1<<endl;
            break;
        }
        if(a[Midle]<target)
        {
            Bigen=Midle+1;
        }
        else
        {
            End=Midle-1;
        }
    }
}
int main()
{
    int n,target;
    cout<< "Number of input -> ";
    cin>>n;
    cout<< "Array values -> ";
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<< "Target value -> ";
    cin>>target;
    binary(a,n,target);
    return 0;
}
