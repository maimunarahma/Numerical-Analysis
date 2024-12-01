#include<bits/stdc++.h>
using namespace std;

#define EPSILON 1e-6
#define MAX_ITER 100


double f(double x){
    return pow(x,10)-1;

}

double Error(double NewValue, double OldValue){
    return abs(NewValue-OldValue);

}

double differenciate(double x){
    return 10*pow(x,9);

}

double SecondDerivative(double x){
    return 90*pow(x,8);
}

void NewtonRaphson(double initialGuess){
    double x=initialGuess,oldGuess;
    
    double iter=0;

    while(fabs(f(x))>=EPSILON){
        double fx=f(x);
        double dfx=differenciate(x);
          if (dfx == 0)
        {
            cout << "Error: Derivative is zero, cannot proceed." << endl;
            return;
        }
        x=x-fx/dfx;
        iter++;

        double tempError=Error(x,oldGuess);
        cout<<tempError<<'\n';


    }
    
    cout << "Root found: x = " << x << endl;
    }