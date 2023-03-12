#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int iterations,currentPosition = 25;
    cout << "How many iterations would you like(<0 = quit): "; cin >> iterations;
    for (int i = 0; i < iterations; i++)
    {
        if(i==10){--currentPosition;}
        if(i==100){currentPosition--;}
        cout << "Iteration: " << i << ':' << setw(currentPosition) << '*' << endl;
        
        if (rand() % 2 == 0){ ++currentPosition; }
        else{ --currentPosition; }
    }
    cout<<endl;
    main();
}
