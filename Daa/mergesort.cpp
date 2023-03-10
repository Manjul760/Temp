#include <bits/stdc++.h>
using namespace std;
void merge_sort(int*a,int f,int b)
{
    if(f>=b){return;}
    merge_sort(a,f,(f+b)/2);    merge_sort(a,(f+b)/2+1,b);
    
    int a2[b-f+1],idx=0,div1=f,div2=(f+b)/2+1;
    while(idx<(b-f+1))
    {
        if(a[div1]<a[div2]){ a2[idx]=a[div1]; div1++;idx++; }
        else{ a2[idx]=a[div2]; div2++;idx++; }

        if(div1>(f+b)/2)
        {
            for (int i = idx; i < b-f+1; i++){ a2[i]=a[div2]; div2++; }
            break;
        }
        else if(div2>b)
        {
            for (int i = idx; i < b-f+1; i++) { a2[i]=a[div1]; div1++;  }
            break;
        }
    }

    for (int i=0,j=f; j <= b; j++,i++){ a[j]=a2[i];  }
}
int main()
{
    int n, a[100]; 
    cout << "Enter number of elements to sort: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    merge_sort(&a[0],0,n-1);
    cout<<"Sorted data:\n";
    for (int i = 0; i < n; i++) { cout << a[i] << " "; }
    cin>>n;
}