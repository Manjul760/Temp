#include<bits/stdc++.h>
using namespace std;
void X_euclid(int ans[],int a,int b,int x1=1,int y1=0,int x2=0,int y2=1)
{
    if(b==0){ans[0]=a; ans[1]=x1; ans[2]=x2;return; }
    X_euclid(ans,b,a%b,y1,x1-(a/b)*y1,y2,x2-(a/b)*y2);
}
int f(int a,int v=0){if(a>=65 && a<=90){a= a - 65;}else if(a>=97 && a<=122){a= a - 97;}else{a= - 1;}return a+v;}
int mod(int a,int m=25){while(a<0){a+=m;}return a%m;}
int main()
{
    string key,pt,ct;
    cout<<"Enter key(4chars): ";cin>>key;
    cout<<"Enter pt:(2chars): ";cin>>pt;
    
    int d=mod(f(key[0])*f(key[3])-f(key[1])*f(key[2])),ans[3];
    X_euclid(ans,25,d);
    if(ans[0]!=1){cout<<"!!!Error occurs during decription!!!!!"<<endl;}

    //encription
    ct+= char(65+mod(f(pt[0])*f(key[0])+f(pt[1])*f(key[2])));
    ct+= char(65+mod(f(pt[0])*f(key[1])+f(pt[1])*f(key[3])));
    cout<<"Encripted text: "<<ct<<endl;

    //decription
    pt="";
    pt+= char(65+mod(ans[2]*(f(ct[0])*f(key[3])+f(ct[1])*-f(key[2]))));
    pt+= char(65+mod(ans[2]*(f(ct[0])*-f(key[1])+f(ct[1])*f(key[0]))));
    cout<<"Encripted text: "<<pt<<endl;
    cin>>pt;
    
}