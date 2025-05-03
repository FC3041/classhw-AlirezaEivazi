#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));
    int randomnumber = (rand() % 100) + 1;

    int number;
    cout<<"guess a number between 1 and 100:"<<endl;
    cin>>number;
    
    while (true)
    {
        
        if(number > randomnumber)
        {
            cout<<"your number is bigger than random number try again"<<endl;
        }

        else if(number < randomnumber)
        {
            cout<<"your number is smaller than random number try again"<<endl;
        }

        else if(number == randomnumber)
        {
            cout<<"you win !"<<"the correct number is :"<<randomnumber<<endl;
            break;
        } 
        cin>>number;
    };

    return 0;
};