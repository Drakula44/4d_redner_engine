#include <iostream>
#include "../headers/vector.h"
using namespace std;

int main()
{
  int n,m;
  n = 2;
  m = 2;
  double *val;
  val = new double[n];
  for(int i = 0;i<n;i++)
  {
    val[i] = i;
  }
  Vector a(n,val);
  Vector b = a.T();
  a.print();
  a = a.T();
  a.print();
  b.print();
}
