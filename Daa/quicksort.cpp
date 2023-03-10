#include <bits/stdc++.h>
using namespace std;
bool sorted(int*a,int n){for (size_t i = 1; i < n; i++){if(a[i-1]>a[i]){return false;}}return true;}
void swap(int *a,int *b){int temp=*a;*a=*b,*b=temp;}
void quicksort(int*a,int f,int b)
{
    if(f>=b){return;}
    int p=f,last_idx=b;
    while(1)
    {
        while (a[f]<=a[p]&&f<b){f++; }
        while(a[b]>a[p]){b--;}
        if(f<b) { swap(&a[f],&a[b]); }
        else{swap(&a[p],&a[b]);break; }
    }
    quicksort(a,p,b-1);
    quicksort(a,b+1,last_idx);
}
int main()
{
    int n, a[100]; 
    cout << "Enter number of elements to sort: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { a[i]=rand()%500;cout<<a[i]<<" "; }cout<<endl;
    quicksort(&a[0],0,n-1);
    cout<<"sorted data: "<<sorted(a,n)<<endl;
    for (int i = 0; i < n; i++) { cout << a[i] << " "; }
    cin>>n;
}