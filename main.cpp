#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
double Calculator(long double answer);
int main()
{
    cout << "WELCOME TO THE INDUSTRIAL CALCULATOR!\n";
    cout << "Available functions to use:\n";
    cout << "(+) Addition\n";
    cout << "(-) Subtraction\n";
    cout << "(x) Multiplication\n";
    cout << "(/) Division\n";
    cout << "(^) Power\n";
    cout << "(r) Root\n";
    cout << "(s) Sine\n";
    cout << "(c) Cosine\n";
    cout << "(t) Tangent\n";
    cout << "(e) Natural Log\n";
    cout << "(l) Common Log\n";
    cout << "(h) Hypotenuse\n";
	cout << "(p) Prime\n";
    cout << "Please enter a number: ";
    long double num1;
    int exitLoop = 0; //exit loop when 1 (on) and loop when 0 (off)
    cin >> num1;
    do
    {
        num1 = Calculator(num1);
        cout << "Do you want to use the answer in another equation? Type 1 to stop, and 0 to continue: ";
        cin >> exitLoop;
    } while (exitLoop == 0);
    return 0;
}

double Calculator (long double num1)
{
    char func;
    long double num2;
    long double answer = 0;
    cout << "Please enter a function: ";
    cin >> func;
    
    if(func == 's')
    {
        answer = sin(num1);
    }
    else if(func == 'c')
    {
        answer = cos(num1);
    }
    else if(func == 't')
    {
        answer = tan(num1);
    }
    else if(func == 'e')
    {
        answer = log(num1);
    }
    else if(func == 'l')
    {
        answer = log10(num1);
    }
	else if(func = 'p')
	{
		cout << "Converting from decimal values to integer if there is a decimal point...\n";
		int num1Converted = num1;
		vector <int> divisors;
		divisors.push_back(1);
		divisors.push_back(num1Converted);
		const int squareRoot = sqrt(num1);
		bool prime = true;
		for(unsigned int i = 2; i <= squareRoot; i++)
		{
			if(num1Converted % i == 0)
			{
				prime = false;
				divisors.push_back(i);
				if(i != num1Converted/i)
					divisors.push_back(num1Converted/i);
			}
		}
		if(prime == false)
		{
			cout << "The number is not prime.\n";
			cout << "Divisors: ";
			for(unsigned int i = 0; i < divisors.size(); i++)
				cout << divisors[i] << " ";
			cout << endl;
		}
		else
			cout << "The number is prime.\n";
		
	}
    else
    {
        cout << "Please enter another number: ";
        cin >> num2;
        switch (func)
        {
            case '+':
            {
                answer = num1 + num2; break;
            }
            case '-':
            {
                answer = num1-num2; break;
            }
            case 'x':
            {
                answer = num1*num2; break;
            }
            case '/':
            {
                answer = num1/num2; break;
            }
            case '^':
            {
                answer = pow(num1, num2); break;
            }
            case 'r':
            {
                answer = pow(num1, 1/num2); break;
            }
            case 'h':
            {
                answer = hypot(num1, num2);
            }
        }
        
    }
    
    if(func != 'p')
		cout << "The answer to all your worries is " << answer << endl;
	else
		answer = num1;
    return answer;
}
