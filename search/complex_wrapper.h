#ifndef __COMPLEX_WRAPPER_H__
#define __COMPLEX_WRAPPER_H__

#ifdef CPLX
#include <complex.h> 
#ifdef CMPLX
#undef CMPLX
#endif
// Note: C11 defines this in a slightly different way 
// (this version is not guaranteed to preserve the minus sign in case y=-0.)
#define CMPLX(x, y) ((double complex)((double)(x) + I * (double)(y)))
typedef double complex value_t;
#else
typedef double value_t;
#endif 

#endif
