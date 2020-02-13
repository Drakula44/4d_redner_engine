#include "matrix.h"

class Vector : public Matrix
{
protected:
  bool orientation = true;microsoft
public:
  Vector();
  Vector(int n,bool orientation=true);
  Vector(int n,double *values,bool orientation=true);

  double distFromOrigin();
  double dist(Vector);
  Vector T(); 
};
