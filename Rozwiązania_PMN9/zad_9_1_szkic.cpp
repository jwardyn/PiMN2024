#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;



template <typename T>
T integrate(T (*f)(T), T x, T h, string method) {
    if (method == "Rectangular") {
        return rectangular_integration(f, x, h);
    } else if (method == "Trapezoid") {
        return trapezoid_integration(f, x, h);
    } else if (method == "Simpson") {
        return simpson_integration(f, x, h);
    } else {
        cerr << "Invalid method!" << endl;
        return 0;
    }
}

double sin_function(double x) {
    return sin(x);
}

int main() {
    double a = 0.0; 
    double b = M_PI;
    double h = 0.1; 
    double exact_value = 2.0;


    return 0;
}
