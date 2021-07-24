#include "integral.hpp"

double Integral::compute(Expression f, double integrationLimits[], int numberOfDivisions)
{
  double integral = 0;
  double dx = (integrationLimits[1] - integrationLimits[0]) / numberOfDivisions;

  for (int i = 1; i <= numberOfDivisions; i++) {
    integral += f(integrationLimits[0] + i * dx)*dx;
  };
  return integral;
};

double Integral::computeMedia(Expression f, double integrationLimits[], int numberOfDivisions)
{
  double integral = 0;
  double dx = (integrationLimits[1] - integrationLimits[0]) / numberOfDivisions;

  for (int i = 1; i <= numberOfDivisions; i++) {
    integral += (f(integrationLimits[0] + i * dx)*dx + f(integrationLimits[0] + (i-1) * dx)*dx)/2;
  };
  return integral;
}