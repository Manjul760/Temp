#include <bits/stdc++.h>
using namespace std;
#define SEED 35791246
int main()
{
    srand(SEED);

    int niter,count=0;
    double z,pi;
    cout<<"Enter the number of iterations used to estimate pi: ";  cin>>niter;
    for (int i = 0; i < niter; i++)
    {
        z = pow((double)rand() / RAND_MAX,2) + pow((double)rand() / RAND_MAX,2);
        if (z <= 1) { count++; }
    }
    pi = (double)count / niter * 4;
    cout<<"no of trials= "<<niter<<" , estimate of pi is "<<pi<<" \n"<<endl;
    main(); 
       
}