#include <iostream>
#include <cmath>
using namespace std;
void calculator() 
{
    double num1, num2, result;
    char operand, choice='\0';
    bool error=0;
    do{
    error=0;
    cout << "Enter the first operand: \n";
    cin >> num1;
    cout << "Enter an operation(+, -, *, /): \n";
    cin >> operand;
    cout << "Enter the second operand: \n";
    cin >> num2;
    if(operand=='+')
    {
	result=num1+num2;
	break;
    }
    else if(operand=='-')
    {
	result=num1-num2;
	break;
    }
    else if(operand=='*')
    {
	result=num1*num2;
	break;
    } 
    else if(operand=='/')
    {
	if (num2 != 0) 
	{
	result = num1 / num2;
    break;
    }
    else 
	{
	cout << "Error. Invalid input." << endl;
	error=1;
	}
	break;
    }
    else 
    {
 	cout << "Error: Invalid operation." << endl;
	error=1;
	break;
    }
    } while (choice == 'y' || choice == 'Y');
    if(error==0)
     {
        cout << num1 << " " << operand << " " << num2 << " = " << result << endl;
     }
    
}
int main(){
calculator();
char choice;
while(1){
cout << "Perform another calculation? (Y/N): \n";
cin>> choice;
if(choice=='y' || choice=='Y')
calculator();
else
break;
}
}
