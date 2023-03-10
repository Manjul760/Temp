#include<bits/stdc++.h>
using namespace std;
void extendedeuclid(int ans[],int a,int b,int x2=0,int y2=1)
{
    if(b==0){ans[0]=a; ans[1]=x2;return;}
    extendedeuclid(ans,b,a%b,y2,x2-(a/b)*y2);
}
int mod(int a,int m){while(a<0){a+=m;}return a%m;}
int mod_with_power(int a,int e,int m)
{
    int b=1;
    for (int i = 0; i < e; i++){b=mod(a*b,m);}
    return b;
}
bool is_prime(int p)
{
    if(p==2){return true;}
    if(p==1||p==0||p%2==0){return false;}
    for(int i=3;i<int(sqrt(p));i+=2){if(p%i==0){return false;}}
    return true;
}
int main()
{
    int p=0,q=0,ans[2],ct;
    while(!is_prime(p)&&!is_prime(q))
    {
        cout<<"Enter two prime numbers: ";cin>>p>>q;
    } 
    for (int i = 2; i < p*q; i++)
    {
        extendedeuclid(ans,(p-1)*(q-1),i);
        if(ans[0]==1){ans[0]=i;ans[1]=mod(ans[1],(p-1)*(q-1));break;}
    }
    cout<<"private key= "<<ans[0]<<" public key= "<<ans[1]<<endl;
    string pt;
    cout<<"Enter pt: ";cin>>pt;
    cout<<"Plain\tEncript\tDecript\n";
    for (int i = 0; i < pt.length(); i++)
    {
        cout<<"("<<int(pt[i])<<")"<<pt[i]<<"\t";
        ct=mod_with_power(int(pt[i]),ans[1],p*q);
        cout<<ct<<"\t";
        cout<<mod_with_power(ct,ans[0],p*q)<<endl;
    }
    cin>>p;
}