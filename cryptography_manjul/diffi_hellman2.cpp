#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int*b){int temp=*a;*a=*b;*b=temp;}
int mod(int a,int m){while(a<0){a+=m;}return a%m;}
int power_mod(int a,int e,int m)
{
    int b=1;
    for (int i = 0; i < e; i++){b=mod(a*b,m);}
    return b;
}
bool is_primitive_prime(int a,int b)
{
    int arr[b-1],v;
    for(int i=1;i<b;i++)
    {
        v=power_mod(a,i,b);
        if(v==0){return false;}
        for (int j = 0; j < i; j++){if(v==arr[j]){return false;}}
        arr[i-1]=v;
    }
    return true;
}
int main()
{
    int a,p,k1,k2,y1,y2;
    do 
    {
        cout<<"Enter primitive prime numbers: ";cin>>a>>p;
        if(a>p){swap(&a,&p);}
    } 
    while(!is_primitive_prime(a,p));
    cout<<"Enter 2 keys: ";cin>>k1>>k2;
    y1=power_mod(a,k1,p);
    y2=power_mod(a,k2,p);
    cout<<"Y1="<<y1<<" Y2="<<y2<<endl;
    cout<<"Verification after exchange="<<endl;
    cout<<"user 1:"<<power_mod(y2,k1,p)<<endl;
    cout<<"user 2:"<<power_mod(y1,k2,p)<<endl;
    cin>>a;
}