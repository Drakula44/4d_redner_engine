class Matrix
{
public:
  Matrix();
  Matrix(const Matrix &other);
  Matrix(int n,int m);
  Matrix(int n,int m,double **values);
  Matrix adj();
  Matrix inv();
  double det();
  Matrix T();
  Matrix krovcic(int i,int j);
  const Matrix& operator=(const Matrix &t);
  friend Matrix operator+(Matrix const &,Matrix const &);
  friend Matrix operator*(Matrix const &,Matrix const &);
  friend Matrix operator*(Matrix const &,double const &);
  friend Matrix operator+(Matrix const &,double const &);
  // TODO dodati ako bude bilo potrebe
  // i ako treba dodati /,^,itd
  // friend Matrix operator*(double const &,Matrix const &);
  // friend Matrix operator+(double const &,Matrix const &);
  // TODO dodati sledece matrice
  // static Matrix Rx(double angle);
  // static Matrix Ry(double angle);
  // static Matrix Rz(double angle);
  // static Matrix E(int n);
  
  void print();
protected:
  int n,m;
  double **values;
};
