#include<bits/stdc++.h>
using namespace std;
insertion(int a[],int n)///Insertion Sort.
{
    int i,j,temp;
    for(i=1; i<n; i++)//start loop from second index.
    {
        temp=a[i];//initialize second index value.
        for(j=i-1; j>=0 && a[j]>temp ; j--)
        {
            a[j+1]=a[j];//put first index value to second index.
        }
        //cout<<j<<endl;
        a[j+1]=temp;
    }
}
int main()
{
    int n;
    cout<< "Number of input -> ";
    cin>>n;
    cout<< "Array values -> ";
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    insertion(a,n);
    for(int i=0; i<n; i++)
        cout<< a[i]<< " ";
    cout<<endl;
    return 0;
}
