#include <iostream>
#include <cmath>

using namespace std;


template <typename F>
double rootNewton(F f, double a, double b, double eps) {

}

template <typename F>
double rootBisection(F f, double a, double b, double eps) {

}

template <typename F>
double rootFalsi(F f, double a, double b, double eps) {


}

// zastąp tą funkcję tymi z polecenia
double func(double x) {
    return x * x - 3;
}


int main(int argc, char* argv[]) {
    double a=atof(argv[1]);
    double b=atof(argv[2]);
    double eps=atof(argv[3]); //1e-6


    double root_newton = rootNewton(func, a, b, eps);
    double root_bisection = rootBisection(func, a, b, eps);
    double root_falsi = rootFalsi(func, a, b, eps);


    cout << "Root using Newton's method: " << root_newton << endl;
    cout << "Root using Bisection method: " << root_bisection << endl;
    cout << "Root using Method of False Position: " << root_falsi << endl;

    return 0;
}
