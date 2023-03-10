#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){int temp = *a;*a=*b;*b=temp;}
void quicksort_vertices(int a[][100],int f,int b,int fp=0,int bp=1)
{
    if(f>=b){return;}
    while(fp<bp)
    {
        fp=b,bp=f;
        for (int i = f; i <= b; i++){if(a[2][f]<a[2][i]){fp=i;break;}}
        for (int i = b; i >= f; i--){if(a[2][f]>=a[2][i]){bp=i;break;}}
        if(fp<bp)
        {
            swap(&a[2][bp],&a[2][fp]);
            swap(&a[1][bp],&a[1][fp]);
            swap(&a[0][bp],&a[0][fp]);
        }
        
    }
    swap(&a[2][bp],&a[2][f]);
    swap(&a[1][bp],&a[1][f]);
    swap(&a[0][bp],&a[0][f]);
    quicksort_vertices(a,f,bp-1);
    quicksort_vertices(a,bp+1,b);  
}

bool loop_exists(int a[][100],int n,int edge_index)
{
    int queue[n+1],queue_index=0,k;
    queue[0]=a[0][edge_index];
    
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j==edge_index){}
            else if(a[2][j]>=0 && a[0][j]==queue[i])
            {
                for (k = 0; k < queue_index+1; k++){if(a[1][j]==queue[k]){break;}}
                if(k==queue_index+1)
                {
                    if(a[1][j]==a[1][edge_index]){return true;}
                    queue_index++;
                    queue[queue_index]=a[1][j];
                }
                
            }
            else if(a[2][j]>=0 && a[1][j]==queue[i])
            {
                for (k = 0; k < queue_index+1; k++){if(a[0][j]==queue[k]){break;}}
                if(k==queue_index+1)
                {
                    if(a[0][j]==a[1][edge_index]){return true;}
                    queue_index++;
                    queue[queue_index]=a[0][j];
                } 
            } 
        }
        if(queue_index==i){break;}
    }
    return false;

}

int main()
{
    int n,source,vertices[3][100];
    cout<<"Enter the number of edges in graph: ";
    cin>>n;

    cout<<"Enter the verex and weight as:\n";
    cout<<"v1(int)  v2(int)  weight(int)\n";
    for (int i = 0; i < n; i++)
    {
        cin>>vertices[0][i]>>vertices[1][i]>>vertices[2][i];
    }
    quicksort_vertices(vertices,0,n-1);
    for (int i = n-1; i >= 0; i--)
    {
        if(loop_exists(vertices,n,i)){vertices[2][i]=-1;}
    }
    cout<<"\noutput as:\n";
    cout<<"v1(int)  v2(int)  weight(int)\n";
    for (int i = 0; i < n; i++)
    {
        if(vertices[2][i]>=0){cout<<vertices[0][i]<<" \t  "<<vertices[1][i]<<" \t  "<<vertices[2][i]<<endl;}
    }
    cin>>n;
}