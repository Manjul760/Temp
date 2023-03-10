#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=1000, a[1000], temp,count = 0; 
    for (int i = 0; i < n; i++){ a[i]=rand()%10000; }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
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
    for (int i = 0; i < n; i++) { cout << a[i] << " "; }
    count+= 10+8*n;
    cout << "\ntotal time complexity by using RAM model=:" << count << endl<<endl;
    cin>>n;
}