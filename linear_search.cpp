#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tv,av[100];

    cout<< "Enter your array values -> ";
    int c=1,k=0;

    for(int i=0; i<10; i++)
        cin>>av[i];

    cout<< "Enter your array values -> ";
    cin>>tv;

    for(int i=0; i<10; i++)
    {
        if(tv==av[i])
        {
            cout<< tv <<" is found "<<c<< " index of array."<<endl;
            k=1;
            break;
        }
        c++;
    }
    if(k==0)
        cout<< "Your target value does not exist in your array."<<endl;
    return 0;
}
