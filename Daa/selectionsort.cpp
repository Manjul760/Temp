#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[100], temp,idx_l,count = 0; 
    cout << "Enter number of elements: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i]; }

    for (int i = 0; i < n; i++)
    {
        idx_l=0;
        for(int idx=0;idx<n-i;idx++)
        {
            if(a[idx_l]<a[idx]){idx_l=idx; count+=2;}
        }
        temp=a[idx_l];
        a[idx_l]=a[n-i-1];
        a[n-i-1]=temp;

        count+=7+3*(n-i);
    }
    cout<<"Sorted data:\n";
    for (int i = 0; i < n; i++) { cout << a[i] << "\t"; }
    count+=13+8*n;
    cout << "\ntotal time complexity =:" << count << endl;
    cin>>n;
}