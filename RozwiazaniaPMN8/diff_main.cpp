#include <iostream>
#include <cmath>
#include <string>

using namespace std;


template <typename T>
T sin_func(T x) {
    return sin(x);
}


template <typename T>
T cos_func(T x) {
    return cos(x);
}


template <typename T>
T exp_func(T x) {
    return exp(x);
}

template <typename T>
T log_func(T x) {
    return log(x);
}


template <typename T>
T x4_func(T x) {
    return x*x*x*x;
}


// Function to compute the differentiation using various methods
template <typename T>
T diff(T (*f)(T), T x, T h, string method) {
    if (method == "backward_difference") {
        return (f(x) - f(x - h)) / h;
    } else if (method == "forward_difference") {
        return (f(x + h) - f(x)) / h;
    } else if (method == "central_difference") {
        return (f(x + h) - f(x - h)) / (2 * h);
    } else if (method == "richardson_extrapolation") {
        T h2 = h / static_cast<T>(2.0);
        T df1 = diff(f, x, h, "central_difference");
        T df2 = diff(f, x, h2, "central_difference");
        return (static_cast<T>(4) * df2 - df1) / static_cast<T>(3.0);
    } else {
        cerr << "Error: Unknown differentiation method" << endl;
        return NAN; // Not-a-Number
    }
}

// Function to measure numerical error
template <typename T>
T measure_error(T result, T reference) {
    return abs(result - reference);
}


void differentiate_and_measure_error(double (*func)(double), double x, double h, double sin_exact) {
    cout << "Differentiation using various methods and measuring error:" << endl;
    cout << "Backward Difference for sin(x): " << diff(func, x, h, "backward_difference")
         << ", Error: " << measure_error(diff(func, x, h, "backward_difference"), sin_exact) << endl;
    cout << "Forward Difference for sin(x): " << diff(func, x, h, "forward_difference")
         << ", Error: " << measure_error(diff(func, x, h, "forward_difference"), sin_exact) << endl;
    cout << "Central Difference for sin(x): " << diff(func, x, h, "central_difference")
         << ", Error: " << measure_error(diff(func, x, h, "central_difference"), sin_exact) << endl;
    cout << "Richardson Extrapolation for sin(x): " << diff(func, x, h, "richardson_extrapolation")
         << ", Error: " << measure_error(diff(func, x, h, "richardson_extrapolation"), sin_exact) << endl;
         cout<<endl;
}



int main() {
    double x = 1.0;
    double h = 0.001;
    
    // Analytical derivatives for reference comparison

    double exp_exact = exp(x);
    double x4_exact = 4*x*x*x;
    double logfunc_exact = log(x+1);


cout<<endl;
    differentiate_and_measure_error(exp_func, x, h, exp_exact);
    differentiate_and_measure_error(x4_func, x, h, x4_exact);
    differentiate_and_measure_error(log_func, (x+1), h, logfunc_exact);

    












    return 0;
}
 
