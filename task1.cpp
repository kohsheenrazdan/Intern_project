#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int n, guess;
    int count = 0;
    srand(time(0));
    n = rand() % 50 + 1;
    cout<< "Number Guessing Game";
    do{
        cout<< "Enter a number between 1 to 50"<<endl;
        cin>> guess;
        count++;

        if(guess < n)
            cout<< "Guess is lower than the number";

        else if(guess > n)
            cout<< "Guess is higher than the number";
        
        else
            cout<< "Your guess is correct";
    }
    while(guess != n);
    return 0;
}