#include <iostream>
#include <cmath>
#include "Cart_Vector.h"
#include "Cart_Point.h"
using namespace std;

Cart_Vector::Cart_Vector()
{
  x=0.0;
  y=0.0;
}

Cart_Vector::Cart_Vector(double inputx,double inputy)
{
  x=inputx;;
  y=inputy;
}

ostream& operator<<(ostream& os, const Cart_Vector& v1) // I am overloading the output stream << operator to be able to output a Cart_Vector in the form <a,b>
{
  os <<'<'<<v1.x << ',' << v1.y << '>';
  return os;
}

Cart_Vector operator*(const Cart_Vector &v1 ,double d) // I am overloading the multiplication operator to be able to muliply the x and y components of a cart_vector by a scalar.
{
  Cart_Vector multiplication;
  multiplication.x=(v1.x*d);
  multiplication.y=(v1.y*d);
  return multiplication;
                                                                                                                                  
}

Cart_Vector operator/(const Cart_Vector &v1, double d) // I am overloading the division operator to be able to divide  the x and y components of a cart_vector by a scalar.
{
  if (d==0)
  {
    return v1;
  }
  else
    {
      Cart_Vector division;
      division.x=((v1.x)/(d));
      division.y=((v1.y)/(d));
      return division;
    }
}

