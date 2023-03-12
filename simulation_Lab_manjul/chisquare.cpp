#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,e=0;
    cout<<"Total number of observed frequency[n]: "; cin>>n;
    int o[n];
    cout<<"Enter observed frequency for "<<n<<" intervals: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>o[i];
        e += o[i];
    }
    e /= n;

    float chi_tab = 16.919, chi_calc = 0;
    cout<<"Estimated frequency="<<e<<"\n";
    for (int i = 0; i < n; i++){ chi_calc += pow( o[i] - e ,2) / e; }

    cout<<"chi_calc =("<<chi_calc<<")";
    if (chi_calc <= chi_tab)
    {
        cout<<" <= chi_tab("<<chi_tab<<") Null hypothesis accepted. The value is uniformly distributed.\n";  
    }
    else 
    {
        cout<<" > chi_tab("<<chi_tab<<") Alt hypothesis accepted. The value is not uniformly distributed.\n"; 
    }
    cout<<endl;
    main();
}