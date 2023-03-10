#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,source,min_index=0,min_value;
    cout<<"Enter the number of nodes in graph: "; cin>>n;
    int weight[n][n],distances[n],process_distance[n];
    cout<<"Enter the weights \n-1 if no weight: \nv1 to v2 weight\n";
    for (int i = 0; i < n; i++)
    {
        weight[i][i]=0;
        for (int j = 0; j < i; j++)
        {
            cout<<i<<" <-> "<<j<<": ",cin>>weight[i][j];
            if(weight[i][j]==-1){weight[i][j]=INT16_MAX;}
            weight[j][i]=weight[i][j];
        }
    }
    cout<<"Enter source: "; cin>>source;
    source=source%n;
    for (int i = 0; i < n; i++)
    {
        process_distance[i]=weight[source][i];
        distances[i]=-1;
    }
    for (int values = 0; values < n; values++)
    {
        min_value=INT16_MAX;
        for (int i = 0; i < n; i++)
        {
            if(process_distance[i]!=-1 && process_distance[i]<min_value)
            {
                min_index=i;
                min_value=process_distance[i];
            }
        }
        distances[min_index]=process_distance[min_index];
        process_distance[min_index]=-1;
        for (int i = 0; i < n; i++)
        {
            if((min_value+weight[min_index][i]) <process_distance[i] && process_distance[i]!=1)
            {
                process_distance[i]=min_value+weight[min_index][i];
            }
        }
    }
    cout<<"Min distances are: \n";
    for (int p = 0; p < n; p++){cout<<source<<"->"<<p<<"="<<distances[p]<<" \n";}
    cin>>n;
}