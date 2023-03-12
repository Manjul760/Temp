#include <bits/stdc++.h>
using namespace std; 
int main()
{ 
    int n,a,c,m,seed; 
    cout<<"Enter the number of random numbers to generate:"; cin>>n; 
    cout<<"Enter the value of (a*X0+c)%m \nseed X0: "; cin>>seed; 
    cout<<"a: "; cin>>a; 
    cout<<"c: "; cin>>c; 
    cout<<"m: "; cin>>m; 
 
    if(a==1){ cout<<"Additive LCG :";  } 
    else if(c==0) { cout<<"Multiplicative LCG:"; } 
    else{ cout<<"Mixed LCG:";} 

    cout<<"\nThus the obtained random numbers are:";
    for(int i=0;i<n;i++)
    {
        cout<<"\nr = "<<(float)seed/m<<"  x = "<<seed ;
        seed = (a*seed+c)% m;
    }
    cout<<endl<<endl;
    main();
} 