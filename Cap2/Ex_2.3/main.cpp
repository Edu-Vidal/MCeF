#include <iostream>
#include <cmath>
#include <chrono>

#include "integral3D.cpp"

// f(x, y) = e^(0.1(x²+y²))
double f(double x, double y){
    return exp(0.1 * (x * x + y * y));
};

// Em x [-5, 5], em y [-5, 5]
double integrationLimitsX[] {-1, 1};
double integrationLimitsY[] {-1, 1};
int numberOfIntervals = 1000;

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    double volume = Integral::somaParalelepipedosMedia(
        f, 
        integrationLimitsX, 
        integrationLimitsY, 
        numberOfIntervals);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.3-1 Resultado: " << volume << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << "\n\n";

};