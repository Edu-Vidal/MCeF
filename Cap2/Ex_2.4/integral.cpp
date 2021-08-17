#include <random>
#include "integral.hpp"

float Integral::monteCarlo(
    Expression f,
    double integrationLimitsX[],
    double integrationLimitsY[],
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
    std::uniform_real_distribution<double> dist_x(
        integrationLimitsX[0], 
        integrationLimitsX[1]
        );
    std::uniform_real_distribution<double> dist_y(
        integrationLimitsY[0], 
        integrationLimitsY[1]
        );

    int n_c = 0;

    for (int i = 0; i <= numberOfDivisions; i++) {
        int r_x = dist_x(gen);
        double x = integrationLimitsX[0] + (integrationLimitsX[1] - integrationLimitsX[0]) * r_x;
        int r_y = dist_y(gen);
        double y = integrationLimitsY[0] + (integrationLimitsY[1] - integrationLimitsY[0]) * r_y;
        
        double z = f(integrationLimitsX[0], integrationLimitsY[0]) +
            (f(integrationLimitsX[0], integrationLimitsY[1]) - 
            f(integrationLimitsX[0], integrationLimitsY[0])) * r_x +
            (f(integrationLimitsX[1], integrationLimitsY[0]) - 
            f(integrationLimitsX[0], integrationLimitsY[0])) * r_y;

        if (f(x, y) <= z) {
            n_c += 1;
        };

        return n_c / numberOfDivisions;
    }
}
