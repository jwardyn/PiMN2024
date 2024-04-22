#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// sin(x)
template <typename T>
T sin_func(T x) {
    return sin(x)
}

// Tu macie wprowadzić inne funkcje z treści zadania



template <typename T>
T diff(T (*f)(T), T x, T h, string method) {

// W tym szablonie macie umieścić metody różniczkowania
// żeby można było wybrać za pomocą wprowadzanej string method


    //Jak chcemy coś podzielić/pomnożyć to należy użyć
    // T Nprzez2=  N/ static_cast<T>(2.0);
}


template <typename T>
T measure_error(T result, T reference) {
    return abs(result - reference);
}


int main(int argc, char* argv[]) {

    


    double x = 1.0;
    double h = 0.01;
    
    // Analytical derivatives for reference comparison
    double sin_exact = sin(x);


    // Differentiation using various methods and measuring error
    cout << "Pochodna sin(x) roznymi metodami:" << endl;
    
    cout << "Backward Difference for sin(x): " << diff(sin_func, x, h, "backward_difference")
         << ", Error: " << measure_error(diff(sin_func, x, h, "backward_difference"), sin_exact) << endl;
    
    cout << "Forward Difference for sin(x): " << diff(sin_func, x, h, "forward_difference")
         << ", Error: " << measure_error(diff(sin_func, x, h, "forward_difference"), sin_exact) << endl;
    
    cout << "Central Difference for sin(x): " << diff(sin_func, x, h, "central_difference")
         << ", Error: " << measure_error(diff(sin_func, x, h, "central_difference"), sin_exact) << endl;
    
    cout << "Richardson Extrapolation for sin(x): " << diff(sin_func, x, h, "richardson_extrapolation")
         << ", Error: " << measure_error(diff(sin_func, x, h, "richardson_extrapolation"), sin_exact) << endl;
    
    return 0;
}
 
