#include "integral3D.hpp"

double Integral::parallelepipeds(
    Expression f,
    double integrationLimitsX[], 
    double integrationLimitsY[],
    int &numberOfDivisions)
{
    double integral = 0;
    double dx = (integrationLimitsX[1] - integrationLimitsX[0]) / numberOfDivisions;
    double dy = (integrationLimitsY[1] - integrationLimitsY[0]) / numberOfDivisions;
    
    for (int i = 1; i <= numberOfDivisions; i++)
    {   
        for (int j = 1; j <= numberOfDivisions; j++)
            integral += (f(integrationLimitsX[0]+i*dx, integrationLimitsY[0]+j*dy)\
            +f(integrationLimitsX[0]+(i-1)*dx, integrationLimitsY[0]+(j-1)*dy))/2\
            * dx * dy;
    };
    return integral;
};