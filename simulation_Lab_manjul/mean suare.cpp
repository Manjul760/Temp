#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    long int seed = 6897; //take any 4 digit Number without trailing 00 
    int i, n; 
    cout<<"How many number you want to generate : "; cin>>n; 
    cout<<"Random Numbers are : "; 
    for(i = 0; i < n; i++) 
    { 
        seed = ((seed * seed)/100 )%10000;   
        cout<<seed<<" "; 
    }  
    main();
} 