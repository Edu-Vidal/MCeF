#include "integral.hpp"

double Integral::monteCarlo2D(
    Expression2D f,
    double integrationLimits[],
    int &numberOfDivisions) {

    // Gera número 32 bits, 
    // função custosa para muitas repetições, 
    // usado para gerar seed
    std::random_device rd;

    // Instância de gerador de números 64 bits, 
    // recebe seed como parâmetro - PseudoRandom
    std::mt19937_64 gen(rd());

    // Recebe número e distribui de acordo com limites passados, 
    // uniformemente - Retorna número real
    std::uniform_real_distribution<double> dist(
        integrationLimits[0], 
        integrationLimits[1]
        );

    double n_c = 0;

    for (int i = 0; i < numberOfDivisions; i++) {
        double x = dist(gen);
        double y = dist(gen);

        if (y <= f(x)) {
            n_c++;
        };
    }

    return n_c / numberOfDivisions;
}