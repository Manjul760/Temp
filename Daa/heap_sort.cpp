#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){int temp=*a;*a=*b,*b=temp;}
int main()
{
    int n,a[100],temp;
    cout<<"How many values in array? [n]: ";
    cin>>n;
    cout<<"Enter numbers: \n";
    for (int i = 0; i < n; i++){ cin>>a[i]; }
    for (int i = n; i >0; i--)
    {
        bool heapified=false;
        while(!heapified)
        {
            heapified=true;
            for(int j =0;j<i;j++)
            {
                if(2*j+1>=i){break;}
                else if(a[2*j+1]>a[j]){swap(&a[j],&a[2*j+1]);heapified=false;}
                
                if(2*j+2>=i){break;}
                else if(a[2*j+2]>a[j]){swap(&a[j],&a[2*j+2]);heapified=false;}
            }
        }
        swap(&a[i-1],&a[0]);
    }
    cout<<"Sorted elements are:\n";
    for (int i = 0; i < n; i++){  cout<<a[i]<<" "; }
    cin>>n;
}