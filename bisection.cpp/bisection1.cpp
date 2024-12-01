

#include <bits/stdc++.h>
using namespace std;

double findError(double prevC, double actualC)
{
    return abs(actualC - prevC) / actualC;
}

double f(double x)
{
    return (x * x * x) - (x * x) + 2;
}

double bisection(double a, double b, double approximateError)
{

    double tempError = 1, c = b, prevC;
    double cnt=0;
    while (abs(tempError )> approximateError)
    {

        prevC = c;
        c = (a + b) / 2;
        if (f(c) == 0)
            break;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        tempError = findError(prevC, c);
        cnt++;
    }
    cout<<cnt<<" ";
    return c;
}

int main()
{
    double a, b, approximateError = 0.01;
    cin >> a >> b;
    cout << bisection(a, b, approximateError);
}