#pragma once

typedef double(*Expression)(double, double);

class Integral {
  public:
    static double parallelepipeds(
      Expression f, 
      double integrationLimitsX[], 
      double integrationLimitsY[], 
      int &numberOfDivisions);
};
