#include <bits/stdc++.h>
using namespace std;
bool nqueen(int qp[],int n,int row=0)
{
    if(row>=n){return true;}
    for (size_t i = 0; i < n; i++)
    {
        qp[row]=i;
        if(row==0){if(nqueen(qp,n,row+1)){return true;}}
        else
        {
            bool call=true;
            for (size_t j = 0; j < row; j++)
            {
                if(qp[row]==qp[j] || abs(row-j)==abs(qp[row]-qp[j])){call=false;}
            }  
            if(call){if(nqueen(qp,n,row+1)){return true;}}
        }
    }
    return false;

}
int main()
{
    int n;

    cout<<"Enter the number of queens: ";  cin>>n;
    
    int qp[n];

    if(nqueen(qp,n)==false){cout<<"No solution";}
    else
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if(qp[i]==j){cout<<" 1 ";}
                else{cout<<" 0 ";}
            } 
            cout<<endl; 
        }
    }
    cout<<endl<<endl;
    main();
}

