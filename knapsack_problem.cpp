#include<bits/stdc++.h>
using namespace std;

void knapSack(int TotalWeight, int ItemWeigth[], int ItemValue[], int n)
{
    int P[n + 1][TotalWeight + 1];

    for(int i = 0; i<=TotalWeight; i++)
        P[0][i] = 0;
    for (int i = 0; i<=n; i++)
        P[i][0] = 0;
    cout<<endl;

    for (int i = 1; i<=n; i++)
    {
        for (int CurrentWeight = 0 ; CurrentWeight<= TotalWeight ; CurrentWeight++)
            if (ItemWeigth[i] > CurrentWeight)
            {
                P[i][CurrentWeight] = P[i-1][CurrentWeight];
            }
            else
            {
                P[i][CurrentWeight] =max( ItemValue[i] + P[i-1][CurrentWeight-ItemWeigth[i] ], P[i-1][CurrentWeight] ) ;
            }

        for(int k=1; k<=TotalWeight; k++)
            cout<<P[i][k]<< " ";
        cout<<endl;
    }
    cout<<endl<< "Maximum profit : " <<P[n][TotalWeight]<<endl;
}

int main()
{
    cout << "Enter the number of items in a Knapsack : ";
    int n, TotalWeight;
    cin >> n;
    int ItemValue[n], ItemWeigth[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value and weight for item " << i << " : ";
        cin >> ItemWeigth[i];
        cout << "Enter value and price  for item " << i << " : ";
        cin >> ItemValue[i];
    }
    cout << "Enter the capacity of knapsack : ";
    cin >> TotalWeight;
    knapSack(TotalWeight, ItemWeigth, ItemValue, n);
    return 0;
}































































/*
void knapSack(int TW, int iw[], int v[], int n)
{
    int P[n + 1][TW + 1];

    for(int i = 0; i<=TW; i++)
        P[0][i] = 0;
    for (int i = 0; i<=n; i++)
        P[i][0] = 0;
    cout<<endl;

    for (int i = 1; i<=n; i++)
    {
        for (int w = 0 ; w<= TW ; w++)
            if (iw[i] > w)
            {
                P[i][w] = P[i-1][w];
            }
            else
            {
                P[i][w] =max( v[i] + P[i-1][w-iw[i] ], P[i-1][w] ) ;
            }

        for(int k=1; k<=TW; k++)
            cout<<P[i][k]<< " ";
        cout<<endl;
    }
    cout<<endl<< "Maximum profit : " <<P[n][TW]<<endl;
}

int main()
{
    cout << "Enter the number of items in a Knapsack : ";
    int n, TW;
    cin >> n;
    int v[n], iw[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value and weight for item " << i << " : ";
        cin >> iw[i];
        cout << "Enter value and price  for item " << i << " : ";
        cin >> v[i];
    }
    cout << "Enter the capacity of knapsack : ";
    cin >> TW;
    knapSack(TW, iw, v, n);
    return 0;
}
*/
