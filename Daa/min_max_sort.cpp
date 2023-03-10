#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){int temp=*a;*a=*b,*b=temp;}
bool sorted(int*a,int n){for (size_t i = 1; i < n; i++){if(a[i-1]>a[i]){return false;}}return true;}
int main()
{
    srand(time(0));
    int n;
    cout<<"Enter n: ";cin>>n;
    int a[n],maxidx,minidx;
    for (size_t i = 0; i < n; i++){a[i]=rand()%100;}

    for (size_t i = 0; i < n-i-1; i++)
    {
        maxidx=i;
        minidx=i;
        for (size_t j = i; j <= n-i-1; j++)
        {
            if(a[maxidx]<a[j]){maxidx=j;}
            else if(a[minidx]>=a[j]){minidx=j;}
        }
        swap(&a[maxidx],&a[n-i-1]);
        if(minidx==n-i-1)
        {
            if(maxidx!=i){swap(&a[maxidx],&a[i]);}
        }
        else{swap(&a[minidx],&a[i]);}

    }
    cout<<"sorted data: "<<sorted(a,n)<<endl;
    for (size_t i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
}