#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,knapsack_capacity,data[100][2],matrix[100][100];
    cout<<"Enter the number of data: "; cin>>n;
    cout<<"Enter the knapsack capacity: "; cin>>knapsack_capacity;
    bool takenweights[n];
    cout<<"Enter weights with their profit\n";
    cout<<"Weight(int) profit(int)\n";
    for (int i = 0; i < n; i++){cin>>data[i][0]>>data[i][1];}
    cout<<"Matrix generated = \n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= knapsack_capacity; w++)
        {
            if(i==0 || w==0){matrix[i][w]=0;}
            else
            {
                if(w-data[i-1][0]>=0 &&matrix[i-1][w]<matrix[i-1][w-data[i-1][0]]+data[i-1][1])
                {
                    matrix[i][w]=matrix[i-1][w-data[i-1][0]]+data[i-1][1];
                }
                else{ matrix[i][w]= matrix[i-1][w];}
            }
            cout<<matrix[i][w]<<" ";
        }
        cout<<endl;  
    }
    for (int row = n,column=knapsack_capacity; row>=1; row--)
    {
        if(matrix[row][column]==matrix[row-1][column]){ takenweights[row-1]=0;  }
        else{takenweights[row-1]=1;  column -= data[row-1][0]; }
    }
    cout<<"Weignts taken are \nweights(int)  profit(int)\n";
    for (int i = 0; i < n; i++)
    {
        if(takenweights[i]){cout<<data[i][0]<<"\t\t"<<data[i][1]<<"\n";}
    }
    cin>>n;
}