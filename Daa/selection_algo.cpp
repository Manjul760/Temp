#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[100],b[100] ,temp,nth; 
    cout << "Enter number of elements: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i];b[i]=a[i]; }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    cout<<"Enter n of nth smallest number[1-n]: ";
    cin>>nth;

    cout<<"In data:\n";
    for (int i = 0; i < n; i++) { cout << a[i] << "\t"; }
    cout<<endl<<nth%n<<"th smallest number = "<<b[(nth-1)%n];
    cin>>n;
}
