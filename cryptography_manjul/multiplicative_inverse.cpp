#include<bits/stdc++.h>
using namespace std;
int mod(int a,int m){while(a<0){a+=m;}return a%m;}
void inv(int ans[],int a,int b,int x2=0,int y2=1)
{
    if(b==0){ans[0]=a; ans[1]=x2;;return; }
    inv(ans,b,a%b,y2,x2-(a/b)*y2);
}
int main()
{
    int a,b,ans[2];
    cout<<"Enter [n,m] to find multiplicative inverse:"<<endl;cin>>b>>a;
    inv(ans,a,b);
    if(ans[0]==1){cout<<b<<"*"<<mod(ans[1],a)<<" % "<<a<<" = "<<ans[0];}
    else{cout<<"Inverse doesnt exist";}
    cout<<endl<<endl;
    main();
}