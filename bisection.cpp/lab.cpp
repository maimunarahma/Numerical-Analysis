#include <bits/stdc++.h>
#define EPSILON 1e-6
#define MAX_ITER 100
using namespace std;

double f(double x)
{
    return pow(x, 10) - 1;
}

double Error(double newValue, double oldValue)
{
    return abs(newValue - oldValue);
}

double df(double x)
{
    return 10 * pow(x, 9);
}

double doublePrime(double x){
    return 90 * pow(x,8);
}

// Newton-Raphson Method
void newtonRaphson(double initial_guess)
{
    double x = initial_guess, oldX;
    int iter = 0;

    cout << "Newton-Raphson Method:" << '\n';
    while (fabs(f(x)) >= EPSILON)
    {
        double fx = f(x);
        double dfx = df(x);

        if (dfx == 0)
        {
            cout << "Error: Derivative is zero, cannot proceed." << endl;
            return;
        }

        x = x - fx / dfx;
        iter++;
        double tempError = Error(x, oldX);
        cout << tempError << '\n';
    }

    cout << "Root found: x = " << x << endl;
}

// Modified Newton-Raphson Method
// void modifiedNewtonRaphson(double initial_guess)
// {
//     double x = initial_guess;
//     int iter = 0;

//     cout << "Modified Newton-Raphson Method:" << endl;
//     while (fabs(f(x)) > EPSILON)
//     {
//         double fx = f(x);
//         double dfx = df(x);

//         if (dfx == 0)
//         {
//             cout << "Error: Derivative is zero, cannot proceed." << endl;
//             return;
//         }

//         x = x - (fx / dfx) / (1 - fx * df(x) / (dfx * dfx));
//         iter++;
//         cout << "Iteration " << iter << ": x = " << x << ", f(x) = " << fx << endl;
//     }

//     if (fabs(f(x)) <= EPSILON)
//         cout << "Root found: x = " << x << endl;
//     else
//         cout << "Max iterations reached, no convergence." << endl;
// }

// Secant Method
void secantMethod(double x0, double x1) {
    int iter = 0;

    cout << "Secant Method:" << endl;
    while (true) {
        double fx0 = f(x0), fx1 = f(x1);

        if (fabs(fx1 - fx0) < EPSILON) {
            cout << "Error: Denominator close to zero, cannot proceed." << endl;
            return;
        }

        double x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);

        double error = fabs((x2 - x1) / x2) * 100;
        iter++;

        cout << "Iteration " << iter << ": x = " << x2 << ", Error = " << error << "%" << endl;

        if (fabs(f(x2)) < EPSILON) {
            cout << "Root found: x = " << x2 << endl;
            break;
        }

        x0 = x1;
        x1 = x2;

        if (iter >= MAX_ITER) {
            cout << "Max iterations reached, no convergence." << endl;
            break;
        }
    }
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    newtonRaphson(a);
    secantMethod(b, c);
    return 0;
}
