#include <iostream>
#include "../headers/matrix.h"
using namespace std;

int main()
{
  int n,m;
  n = 2;
  m = 2;
  double **val;
  val = new double*[n];
  for(int i = 0;i<n;i++)
  {
    val[i] = new double[m];
    for(int j = 0;j<m;j++)
    {
      val[i][j] = i*n+j;
    }
  }
  Matrix a(n,m,val);
  a.print();
  cout << endl;
  a.adj().print();
  cout << a.det();
}
