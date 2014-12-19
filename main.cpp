#include<iostream>
#include<math.h>

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
    
    
    cout << "The answer to all your worries is " << answer << endl;
    
    return answer;
}
