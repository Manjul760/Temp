#include<bits/stdc++.h>
using namespace std;
class vigenere
{
    private:
        char plain_text[100],cipher_text[100],key[100];

    public:
        void set_key(){cout<<"Enter key: ";cin>>key;}
        long int Mod(long int a,long int b){while(a<0){a=a+b;}return a%b;}
        void process(int ed=1)
        {
            char a,b;
            cout<<"Enter input text: ";cin>>plain_text;

            cout<<"Output text is: ";
            for(long int i=0;i<strlen(plain_text);i++)
            {
                a=toupper(plain_text[i])-65;
                b=toupper(key[Mod(i,strlen(key))])-65;
                cipher_text[i]=Mod(a+ed*b,26)+65;
                cout<<cipher_text[i];
            }
            cout<<endl;
        }
}vigenere;

int main()
{
    char choice;
    do
    {
        vigenere.set_key();
        vigenere.process(1);
        vigenere.process(-1);
        cout<<"Do you want to repeat the process[y/n]";cin>>choice;
        
    } 
    while (24+65 == choice || 24+97 == choice);
}






































