#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[100], temp,count = 0; 
    cout << "Enter number of elements to sort: ";  
    cin >> n; 
    cout << "Enter the numbers\n"; 
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count+=4;
            }
        }
        count+=3*(n-i);
    }
    
    cout<<"Sorted data:\n";
    for (int i = 0; i < n; i++) { cout << a[i] << "\t"; }
    count+= 13+ 8*n;
    cout << "\ntotal time complexity = " << count << endl<<endl;
    main();
}