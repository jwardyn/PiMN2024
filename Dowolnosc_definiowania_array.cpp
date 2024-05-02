#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void arrdymtest(T x1,T x2,int n) {
    T *arr=new T(n);
    T *arr2=new T[n];

    arr[0]=1;
    arr[1]=2;
    arr2[0]=3;
    arr2[1]=4;

    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr2[0]<<endl;
    cout<<arr2[1]<<endl;
}



double sin_function(double x) {
    return sin(x);
}

int main() {
double tt=5.0;
arrdymtest(tt,tt/2,2);



    return 0;
}
