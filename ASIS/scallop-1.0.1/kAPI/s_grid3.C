/* *** This file is automatically generated by dimensions.sh from a ***
   *** dimension-independent file.  Edit at your peril.             *** */


#include "s_grid3.h"

#define f_fill F77_FUNC_(f_fill3d, F_FILL3D)
#define FORTRAN_ARGS FORTRAN_ARGS3
#define FortranRegion FortranRegion3

extern "C" {
    void f_fill(const double* const, FORTRAN_ARGS,
		FORTRAN_ARGS, const double* const);
}

void s_grid3::fill(const double val, const Region3& R)
{
   FortranRegion FR(R);
   FortranRegion Fthis(this->region());
   f_fill(FORTRAN_DATA(*this),FORTRAN_REGION3(Fthis),FORTRAN_REGION3(FR),&val);
};

/* 
void s_grid3::negate()

negate all the values in the grid 
*/
#define f_negate F77_FUNC_(f_negate3d, F_NEGATE3D)

extern "C" {
    void f_negate(const double* const u, FORTRAN_ARGS);
}

void s_grid3::negate()
{
   FortranRegion Fthis(this->region());
   f_negate(FORTRAN_DATA(*this),FORTRAN_REGION3(Fthis));
};


/* 
void s_grid3::mult(double s)

multiply all the values in the grid by s
*/
#define f_mult F77_FUNC_(f_mult3d, F_MULT3D)


extern "C" {
    void f_mult(const double* const u, FORTRAN_ARGS, double* s);
}

void s_grid3::mult(double s)
{
   FortranRegion Fthis(this->region());
   f_mult(FORTRAN_DATA(*this), FORTRAN_REGION3(Fthis), &s);
};


/*
double s_grid3::norm(const int p)

returns the p-norm of this grid.
*/
#define f_norm F77_FUNC_(f_norm3d, F_NORM3D)

extern "C" {
    double f_norm(double* result, const int* p,
		  const double* const u, FORTRAN_ARGS);
}

double s_grid3::norm(const int p)
{
   double result;

   FortranRegion Fthis(this->region());

   f_norm(&result, &p, FORTRAN_DATA(*this), FORTRAN_REGION3(Fthis));

   return(result);
};
