#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,arr[100],temp,count=0;
    cout<<"Enter the number of input: ";
    cin>>n;
    cout<<"Enter numbers:\n";
    for (i = 0; i < n; i++)
    {
        cin>>arr[i];
        count+=2;
        for (j = 0; j < i; j++)
        {
            count+=2;
            if(arr[i]<arr[j])
            {
                temp = arr[i];
                for (int k = i; k >= j; k--)
                {
                    arr[k]=arr[k-1];
                }
                count+=9+3*(i-j);
                arr[j]=temp;
                break;
            }
            count+=3;
        }
    }
    
    cout<<"Sorted data:\n";
    for (i = 0; i < n; i++) { cout << arr[i] << "\t"; }
    count+=11+7*n;
    cout << "\ntotal time complexity =:" << count << endl;
    cin>>n;
}