#include <bits/stdc++.h>
using namespace std;
int binary_search(int*a,int f,int b,int *key)
{
    while(f<b)
    {
        if(*key<a[(f+b)/2]){b=(f+b)/2-1;}
        else if(*key>a[(f+b)/2]){f=(f+b)/2+1;}
        else{return (f+b)/2;}
    }

    if (a[f]==*key){return f;}
    return -1;
}

int main()
{
    int n, a[100], key; 
    cout << "Enter number of elements: ";  
    cin >> n; 
    cout << "Enter numbers in ascending order\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    cout<<"Enter key value to search: ";
    cin>>key;
    cout<<"Index of key (-1 means not found)= "<<binary_search(&a[0],0,n-1,&key)<<endl<<endl;
    cin>>n;
}