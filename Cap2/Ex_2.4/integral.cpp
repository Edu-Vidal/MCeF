#include <random>
#include "integral.hpp"

float Integral::monteCarlo(
    Expression f,
    double integrationLimitsX[],
    double integrationLimitsY[],
    int &numberOfDivisions) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis;

    int n_c = 0;

    for (int i = 0; i <= numberOfDivisions; i++) {
        int r_x = dis(gen);
        double x = integrationLimitsX[0] + (integrationLimitsX[1] - integrationLimitsX[0]) * r_x;
        int r_y = dis(gen);
        double y = f(integrationLimitsX[0]) + (f(integrationLimitsX[1]) - f(integrationLimitsX[0])) * r_y;
        if (x <= f(x) || y <= f(y)) {
            n_c += 1;
        }
        return n_c / numberOfDivisions;
    }
}