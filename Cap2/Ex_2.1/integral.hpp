#pragma once

typedef double(*Expression)(double);

class Integral {
  public:
    static double compute(Expression f, double integrationLimits[], int numberOfDivisions);

    static double computeMedia(Expression f, double integrationLimits[], int numberOfDivisions);
};
