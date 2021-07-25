#include <iostream>
#include <cmath>
#include <chrono>

#include "integral2D.cpp"

// f(x) = sqrt(1-x²)
double f(double x){
    return (std::sqrt(1-(x*x)));
};

// f(x) = -x² + 1
double aprox_f(double x){
    return (-(x*x)+1);
};

double integrationLimits[2] {0, 1};
int numberOfIntervals = 100000;

using namespace std::chrono;

int main() {
    // EX 2.1 - 1
    auto start = high_resolution_clock::now();
    double area = Integral::rectangleSum(f, integrationLimits, numberOfIntervals);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.1-1 Resultado: " << area << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << "\n\n";

    // EX 2.1 - 2
    start = high_resolution_clock::now();
    area = Integral::rectangleMean(f, integrationLimits, numberOfIntervals);
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.1-2 Resultado: " << area << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << "\n\n";

    // EX 2.1 - 3
    start = high_resolution_clock::now();
    area = Integral::rectangleMean(aprox_f, integrationLimits, numberOfIntervals);
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.1-3 Resultado: " << area << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << std::endl;

};