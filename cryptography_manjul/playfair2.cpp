#include<bits/stdc++.h>
using namespace std;
int mod(int a,int b){while(a<0){a=a+b;}return a%b;}
char f(int a)
{
    if(a>64 && a<91){return a;}
    else if(a>96 && a<123){a= a - 97;}
    else{a= mod(a,25);}

    if(a==8){return 9;}return a+65;
}
int idx(string a,char b)
{
    for(int i = 0; i < a.length(); i++){if(f(a[i])==f(b)){return i;}}
    return -1;
}
string digram(string pt)
{
    string pt2="";
    for (int i = 0; i < pt.length(); i+=2)
    {
        if(pt[i]==pt[i+1])
        {
            pt2+=f(pt[i]); pt2+=f(pt[i]+1);
            pt2+=f(pt[i+1]); pt2+=f(pt[i+1]+1);
        }
        else{pt2+=f(pt[i]);pt2+=f(pt[i+1]);}
    }
    return pt2;
}
string process(string pt,string matrix,int ed)
{
    string ct="";
    for (int i = 0,a,b; i < pt.length(); i+=2)
    {
        a=idx(matrix,pt[i]); b=idx(matrix,pt[i+1]);

        if(a/5==b/5)
        {
            ct+=matrix[(a/5)*5+mod(a+ed,5)];
            ct+=matrix[(b/5)*5+mod(b+ed,5)];
        }
        else if(mod(a,5)==mod(b,5))
        {
            ct+=matrix[mod((a/5)+ed,5)*5+mod(a,5)];
            ct+=matrix[mod((b/5)+ed,5)*5 +mod(b,5)];
        }
        else
        {
            ct+=matrix[(a/5)*5+mod(b,5)];
            ct+=matrix[(b/5)*5+mod(a,5)];
        }
    }
    return ct;
}
int main()
{
    string key,pt,ct,matrix;
    int a,b;
    cout<<"Enter key: ";cin>>key;
    for (int i = 0; i < key.length(); i++){if(idx(matrix,key[i])==-1){matrix+=f(key[i]);}}
    for (int i = 0; i < 25; i++){if(idx(matrix,i+65)==-1){matrix+=char(65+i);}}
    cout<<"Enter pt: ";cin>>pt;
    pt=digram(pt);
    ct=process(pt,matrix,1);
    cout<<"Cipher text= "<<ct<<endl;
    pt=process(ct,matrix,-1);
    cout<<"Plain text= "<<pt;
    cin>>pt;
    main();
}

