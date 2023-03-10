#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){int temp=*a;*a=*b,*b=temp;}
void randomized_quicksort(int*a,int f,int b)
{
    if(f>=b){return;}
    int r=f+rand()%(b-f+1),fp=0,bp=1;
    swap(&a[r],&a[f]);
    while(fp<bp)
    {
        fp=b,bp=f;
        for (int i = f; i <= b; i++){ if(a[f]<a[i]) { fp=i; break; }}
        for (int i = b; i >= f; i--){ if(a[f]>=a[i]) { bp=i; break; } }

        if(fp<bp) { swap(&a[fp],&a[bp]); }
        else{swap(&a[f],&a[bp]); }
        
    }
    randomized_quicksort(a,f,bp-1);
    randomized_quicksort(a,bp+1,b);
}
int main()
{
    int n, a[100]; 
    cout << "Enter number of elements to sort: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    randomized_quicksort(&a[0],0,n-1);
    cout<<"Sorted data:\n";
    for (int i = 0; i < n; i++) { cout << a[i] << " "; }
    cin>>n;
}