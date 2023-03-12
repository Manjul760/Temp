#include <iostream>
using namespace std;
void swap(float *a,float*b){float temp = *a;*a=*b;*b=temp;}
float largest(float data[], int n,float large=0)
{
    for (int i = 0; i < n; i++)
    {
        if (large < data[i]){large = data[i]; }
    }
    return large;
}
float dplusminus(float num[], int n,bool plus)
{
    float data[n];
    for (int i = 0; i < n; i++)
    {
        if(plus){  data[i] = (i + 1) / ((float)n) - num[i]; }
        else{ data[i] = num[i] - i / ((float)n); }
    }
    return largest(data, n);
}

int main()
{
    int n;
    cout<<"Kolmogorov Test\nEnter number of elements to test: "; cin>>n;
    float num[n];
    cout<<"Enter numbers \n";
    for (int i = 0; i < n; i++) { cin>>num[i]; }
    
    for (int i = 0; i < n; i++) // sorting in ascending order
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[i] > num[j]){ swap(&num[i],&num[j]); }
        }
    }
    cout<<"Numbers in ascending order are: ";
    for (int i = 0; i < n; i++) { cout<<num[i]<<" "; }

    float arr[2]={dplusminus(num, n,1),dplusminus(num, n,0)},dvalue=largest(arr,2); 
    cout<<"\ndp = "<<arr[0]<<endl<<"dn = "<< arr[1]<<endl<<"Calculated D = "<<dvalue<<endl;
    
    if (0.565 > dvalue){cout<<"Dcalc < Dalpha(0.565), thus uniformly distributed.\n"; } // for alpha = 0.05
    else{cout<<"Dcalc > Dalpha(0.565), thus not uniformly distributed.\n"; }
    cout<<endl;
    main();
}




