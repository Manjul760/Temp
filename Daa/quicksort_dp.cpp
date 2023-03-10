#include<bits/stdc++.h>
using namespace std;
bool sorted(int*a,int n){for (size_t i = 1; i < n; i++){if(a[i-1]>a[i]){return false;}}return true;}
void swap(int*a,int*b){int temp=*a;*a=*b;*b=temp;}
void quicksort(int a[],int n)
{
    if(n<2){return;}
    int indexes[int(ceil(double(n/2)))][2],count=0,i=0,f,b,i_mod_n;
    indexes[0][0]=0;
    indexes[0][1]=n-1;
    n = int(ceil(double(n/2)));
    for(int i=0;i<=count;i++)
    {
        i_mod_n = i%n;
        f=indexes[i_mod_n][0];
        b=indexes[i_mod_n][1];     
        while(1)
        {
            while(a[indexes[i_mod_n][0]]<=a[f] && indexes[i_mod_n][0]<b){indexes[i_mod_n][0]++;}
            while(a[indexes[i_mod_n][1]]>a[f] && indexes[i_mod_n][1]>f){indexes[i_mod_n][1]--;}

            if(indexes[i_mod_n][0]<indexes[i_mod_n][1]){swap(&a[indexes[i_mod_n][0]],&a[indexes[i_mod_n][1]]);}
            else{ swap(&a[f],&a[indexes[i_mod_n][1]]);break;}
        }
        if(f<indexes[i_mod_n][1]-1){count++;indexes[count%n][0]=f;indexes[count%n][1]=indexes[i_mod_n][1]-1;}
        if(b>indexes[i_mod_n][1]+1){count++;indexes[count%n][1]=b;indexes[count%n][0]=indexes[i_mod_n][1]+1;}
    }
    cout<<"Total partitions evaluated = "<<count<<endl;
}

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter number to enter: ";cin>>n;
    int a[n];

    for (size_t i = 0; i < n; i++) { a[i]=rand()%300; }
    cout<<"Elements unsorted are: "<<endl;
    for (size_t i = 0; i < n; i++) { cout<<a[i]<<" "; }cout<<endl;

    quicksort(a,n);

    cout<<"Elements sorted are: "<<sorted(&a[0],n)<<endl;
    for (size_t i = 0; i < n; i++) { cout<<a[i]<<" "; }cout<<endl;     
}