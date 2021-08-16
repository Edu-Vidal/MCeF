#include <iostream>
#include <cmath>
#include <chrono>

#include "integral.cpp"

// f(x) = -x² + 1
double f(double x){
    return (-(x*x)+1);
};

// f(x, y) = e^(0.1(x²+y²))
double exponential_f(double x, double y){
    return exp(0.1 * (x * x + y * y));
};

double f_limits[2] {0, 1};
int numberOfIntervals = 1000;

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    double volume = Integral::monteCarlo(
        f, 
        f_limits,
        f_limits,
        numberOfIntervals);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.3-1 Resultado: " << volume << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << "\n\n";
}