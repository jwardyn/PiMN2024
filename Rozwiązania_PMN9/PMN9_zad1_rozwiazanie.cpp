#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T rectangular_integration(T (*f)(T), T x, T h) {
    return f(x) * h;
}

template <typename T>
T trapezoid_integration(T (*f)(T), T x, T h) {
    return (f(x) + f(x + h)) * h / 2.0;
}

template <typename T>
T simpson_integration(T (*f)(T), T x, T h) {
    return (h / 6.0) * (f(x) + 4.0 * f(x + h / 2.0) + f(x + h));
}

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
    double a = 0.0; // Lower bound of integration
    double b = M_PI; // Upper bound of integration
    double h = 0.1; // Step size
    double exact_value = 2.0; // Exact value of integral of sin(x) from 0 to pi

    cout << "Exact value of integral of sin(x) from 0 to pi: " << exact_value << endl;
    cout << "x" << setw(15) << "f(x)" << setw(15) << "Rectangular" << setw(15) << "Trapezoid" << setw(15) << "Simpson" << endl;

    vector<pair<double, double>> values;
    for (double x = a; x < b; x += h) {
        double fx = sin_function(x);
        values.push_back(make_pair(x, fx));
    }

    for (const auto& pair : values) {
        cout << fixed << setprecision(6) << pair.first << setw(15) << pair.second;
        for (const string& method : {"Rectangular", "Trapezoid", "Simpson"}) {
            double result = 0.0;
            for (double x = a; x < pair.first; x += h) {
                result += integrate(sin_function, x, h, method);

            }
            cout << setw(15) << result;
        }
        cout << endl;
    }

    return 0;
}
