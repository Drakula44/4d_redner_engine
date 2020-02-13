#include "../headers/vector.h"

Vector::Vector()
{
  this->n = 0;
  this->m = 0;
}
Vector::Vector(int n,bool orientation=true)
{
  this->orientation = orientation;
  this->n=n;
  this->m=1;
}
Vector::Vector(int n,double *values,bool orientation = true)
{
  this->n = n;
  this->m = 1;
  this->values = new double*[n];
  for(int i = 0;i < n;i++)
  {
    this->values[i] = new double[1];
    this->values[i][0] = values[i];
  }
}

