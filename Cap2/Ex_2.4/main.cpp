#include <iostream>
#include <cmath>
#include <chrono>

#include "integral.cpp"

// Declaração de funções -------
// f(x) = sqrt(1-x²)
double f(double x){
    return (std::sqrt(1-(x*x)));
};

// f(x, y) = e^(0.1(x²+y²))
double exponential_f(double x, double y){
    return exp(0.1 * (x * x + y * y));
};
//------------------------------

// Declaração dos limites de integração
double f_limits[2] {0, 1};

int numberOfDivisions = 1000000;

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    double volume = Integral::monteCarlo2D(
        f, 
        f_limits,
        numberOfDivisions);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "2.4-1 Resultado: " << volume << std::endl;
    std::cout << "Tempo gasto: " << duration.count() << " microsegundos" << "\n\n";
}