#include "../headers/matrix.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(int n,int m)
{
  this->n = n;
  this->m = m;
  values = new double*[n];
  for(int i = 0;i < n;i++)
  {
    values[i] = new double[m];
  }
}

Matrix operator+(Matrix const &c1,Matrix const &c2)
{
  if(c1.n != c2.n || c1.m != c2.m)
    return Matrix();
  Matrix tmp(c1.n,c2.m);
  for(int i = 0;i < tmp.n;i++)
    {
      for(int j = 0;j < tmp.m;j++)
        {
          tmp.values[i][j] = c1.values[i][j] + c2.values[i][j];
        }
    }
  return tmp;
}

Matrix::Matrix(int n,int m,double** values)
{
  this->n = n;
  this->m = m;
  this->values = new double*[n];
  for(int i = 0;i < n;i++)
    {
      this->values[i] = new double[m];
      for(int j = 0;j < m;j++)
        {
          this->values[i][j] = values[i][j];
        }
    }
}

Matrix::Matrix()
{
  this->n = 0;
  this->m = 0;
}

Matrix::Matrix(const Matrix &other)
{
  this->n = other.n;
  this->m = other.m;
  this->values = new double*[this->n];
  for(int i = 0;i < n;i++)
    {
      this->values[i] = new double[this->m];
      for(int j = 0;j < m;j++)
        {
          this->values[i][j] = other.values[i][j];
        }
    }
}

void Matrix::print()
{
  for(int i = 0;i < n;i++)
    {
      for(int j = 0;j < m;j++)
        {
          std::cout << values[i][j] << " ";
        }
      std::cout << std::endl;
    }
}

Matrix operator*(Matrix const &c1,Matrix const &c2)
{
  if(c1.m!=c2.m)
    {
      return Matrix();
    }
  Matrix c3(c1.n,c2.m);
  for (int i = 0; i < c3.n; ++i) {
    for (int j = 0; j < c3.m; ++j) {
      c3.values[i][j] = 0;
      for (int k = 0; k < c1.m; ++k) {
        c3.values[i][j] += c1.values[i][k]*c2.values[k][j];
      }
    }
  }
  return c3;
}

Matrix Matrix::adj()
{
  Matrix tmp(n,m);
  for(int i = 0;i < n;i++)
    {
      for(int j = 0;j < m;j++)
        {
          std::cout << ((i+j)%2*2-1)*(-1)<< std::endl;
          tmp.values[i][j] = (this->krovcic(i,j)).det()*((i+j)%2*2-1)*(-1);
        }
    }
  return tmp.T();
}

Matrix Matrix::inv()
{
  return this->adj()*(1/this->det());
}

Matrix operator+(Matrix const &c1,double const &c2)
{
  Matrix tmp(c1.n,c1.m);
  for(int i = 0;i < tmp.n;i++)
    {
      for(int j = 0;j < tmp.m;j++)
        {
          tmp.values[i][j] = c1.values[i][j] + c2;
        }
    }
  return tmp;
}

Matrix operator*(Matrix const &c1,double const &c2)
{
  
  Matrix tmp(c1.n,c1.m);
  for(int i = 0;i < tmp.n;i++)
    {
      for(int j = 0;j < tmp.m;j++)
        {
          tmp.values[i][j] = c1.values[i][j] * c2;
        }
    }
  return tmp;
}

double Matrix::det()
{
  if(n != m)
    return nan("");
  if(n == 1)
    return values[0][0];
  double sum = 0;
  for(int i = 0;i < n;++i)
    {
      sum += (i%2*2-1)*(-1)*values[0][i] * (this->krovcic(0,i)).det();
    }
  return sum;
}

Matrix Matrix::krovcic(int x,int y)
{
  if(this->n == 1 || this->m == 1)
    return Matrix();
  Matrix tmp(this->n-1,this->m-1);
  int di,dj;
 for (int i = 0; i < this->n; ++i) {
   for (int j = 0; j < this->m; ++j) {
     if(x == i || y == j)
       continue;
     di = i > x;
     dj = j > y;
     tmp.values[i-di][j-dj] = this->values[i][j];
  }
}
 return tmp;
}

Matrix Matrix::T()
{
  Matrix tmp(m,n);
  for(int i = 0;i < n;i++)
    {
      for(int j = 0;j < m;j++)
        {
          tmp.values[j][i] = values[i][j];
        }
    }
  return tmp;
}


const Matrix& Matrix::operator=(const Matrix &t)
{
  if(&t == this) return *this;
  for (int i = 0; i < n; ++i)
    delete [] values[i];
  delete [] values;
  this->n = t.n;
  this->m = t.m;
  this->values = new double*[n];
  for(int i = 0;i < n;i++)
    {
          this->values[i] = new double[m];
      for(int j = 0;j < m;j++)
        {
          this->values[i][j] = t.values[i][j];
        }
    }
  return *this;
}
