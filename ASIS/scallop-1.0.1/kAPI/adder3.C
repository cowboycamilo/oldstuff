/* *** This file is automatically generated by dimensions.sh from a ***
   *** dimension-independent file.  Edit at your peril.             *** */


#include "adder3.h"

#define f_add F77_FUNC_(f_add3d, F_ADD3D)
#define FORTRAN_ARGS FORTRAN_ARGS3
#define FortranRegion FortranRegion3

extern "C" {
    void f_add(double *, FORTRAN_ARGS, const double *const, FORTRAN_ARGS,
	       FORTRAN_ARGS);
}


/*
void adder3::unpack(s_grid3& G, const Region3& R, double *buf)

add buf to s_grid g when called
*/
void adder3::unpack(s_grid3& G, const Region3& R, double *buf)
{
   FortranRegion g_extents(G.region());
   FortranRegion b_extents(R);
   f_add(FORTRAN_DATA(G), FORTRAN_REGION3(g_extents),
	 buf, FORTRAN_REGION3(b_extents), FORTRAN_REGION3(b_extents));
}


/*
void adder3::copy(const s_grid3& S, const Region3& F, s_grid3& D, const Region3& T)

add s_grid D to s_grid S when called
*/
void adder3::copy(const s_grid3& S, const Region3& F, s_grid3& D, const Region3& T)
{
   FortranRegion s_extents(S.region());
   FortranRegion d_extents(D.region());
   FortranRegion t_extents(T);

   f_add(FORTRAN_DATA(D), FORTRAN_REGION3(d_extents),
	 FORTRAN_DATA(S), FORTRAN_REGION3(s_extents),
         FORTRAN_REGION3(t_extents));
}
