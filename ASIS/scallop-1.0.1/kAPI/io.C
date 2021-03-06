#include "ioNDIM.h"

/*
ostream& operator << (ostream& o, const GridNDIM<double> &G)

output a grid of data
*/

#define DIMNDIM

#ifdef DIM2
ostream& operator << (ostream& o, const GridNDIM<double> &G)
{
   assert (G.owner() == mpMyID());

   o << (G.upper(0) - G.lower(0) + 1) << " " << (G.upper(1) - G.lower(1) + 1)
     << " 1" << endl;
   o.setf(ios::scientific, ios::floatfield);
   o.precision(8);
   for (int i = G.lower(0); i<=G.upper(0); i++) {
     for (int j = G.lower(1); j<=G.upper(1); j++)
        o << G(i,j) << endl;
     o << endl;
   }
   o << endl << flush;

   return(o);
}
#else
ostream& operator << (ostream& o, const GridNDIM<double> &G)
{
   assert (G.owner() == mpMyID());

   o << (G.upper(0) - G.lower(0) + 1) << " " << (G.upper(1) - G.lower(1) + 1)
	 << " " << (G.upper(2) - G.lower(2) + 1) << endl;
   o.setf(ios::scientific, ios::floatfield);
   o.precision(8);
   for (int k = G.lower(2); k <=G.upper(2); k++) {
    o << "/k = " << k << endl;
    for (int j = G.upper(1); j >=G.lower(1); j--) {
     for (int i = G.lower(0); i <=G.upper(0); i++)
        o << G(i,j,k) << "  ";
     o << endl;
    }
    o << endl;
   }
   o << endl << flush;

   return(o);
}
#endif

