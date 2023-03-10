#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vertices: "; cin>>n;
    int Edges[n][n];

    cout<<"Enter weights [-1 if no path]:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j){Edges[i][j]=0;}
            else
            {
                cout<<i<<"->"<<j<<": ";
                cin>>Edges[i][j];
                if(Edges[i][j]<0){Edges[i][j]=INT16_MAX;}
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int s = 0; s < n; s++)
        {
            if(!s==k)
            {
                for (int e = 0; e < n; e++)
                {
                    if(!e==k)
                    {
                        if(Edges[s][e]>=(Edges[s][k]+Edges[k][e]))
                        {
                            Edges[s][e]=Edges[s][k]+Edges[k][e];
                        }
                    }
                }
            }  
        }
    }

    cout<<"Final minimum weights are: \n";
    for (int s = 0; s < n; s++)
    {
        for (int e = 0; e < n; e++)
        {
            cout<<s<<"->"<<e<<":"<<Edges[s][e]<<endl;
        } 
    }
    cin>>n;
}