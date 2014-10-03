//@HEADER
// ************************************************************************
//     C++ Tensor Toolbox
//     Software package for tensor math by Sandia National Laboratories
// 
// Sandia National Laboratories is a multiprogram laboratory operated by
// Sandia Corporation, a wholly owned subsidiary of Lockheed Martin Corporation,
// for the United States Department of Energy's National Nuclear Security
// Administration under contract DE-AC04-94AL85000.
//
// Copyright 2013, Sandia Corporation.
//
// This class implements the Mersenne Twister random number generator
// from http://www.math.keio.ac.jp/matumoto/emt.html.
//
// Based on version mt19937ar, dated 26 Jan 2002.
// Not all methods are implemented.
//
// To cite as a reference:
//   M. Matsumoto and T. Nishimura,
//   "Mersenne Twister: A 623-Dimensionally Equidistributed Uniform  
//    Pseudo-Random Number Generator",
//   ACM Transactions on Modeling and Computer Simulation,
//   Vol. 8, No. 1, January 1998, pp 3--30.
// ************************************************************************
//@HEADER

#include  "RandomMT.h"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  File-global Data
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static const int  N = 624;
static const int  M = 397;

#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long  _mt[N];     //-- State vector
static int            _mti;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++  Class Definition:  RandomMT
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//-----------------------------------------------------------------------------
//  Constructor
//-----------------------------------------------------------------------------
RandomMT::RandomMT (const unsigned long  nnSeed)
{
    _mti = N + 1;

    _mt[0]= nnSeed & 0xffffffffUL;
    for (_mti = 1; _mti < N; _mti++)
    {
        _mt[_mti] = 
            (1812433253UL * (_mt[_mti - 1] ^ (_mt[_mti - 1] >> 30)) + _mti);
        _mt[_mti] &= 0xffffffffUL;
    }

    return;
}


//-----------------------------------------------------------------------------
//  Destructor
//-----------------------------------------------------------------------------
RandomMT::~RandomMT (void)
{
    return;
}


//-----------------------------------------------------------------------------
//  Method:  genrnd_int32
//-----------------------------------------------------------------------------
/** The core random number generator, called by the other methods.
 */
unsigned long  RandomMT::genrnd_int32 (void)
{
    static unsigned long  mag01[2]={0x0UL, MATRIX_A};
    unsigned long  y;

    if (_mti >= N) { /* generate N words at one time */
        int  kk;

        for (kk = 0; kk < N-M; kk++)
        {
            y = (_mt[kk] & UPPER_MASK) | (_mt[kk+1] & LOWER_MASK);
            _mt[kk] = _mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for ( ; kk < N-1; kk++)
        {
            y = (_mt[kk] & UPPER_MASK) |(_mt[kk+1] & LOWER_MASK);
            _mt[kk] = _mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (_mt[N-1] & UPPER_MASK) |(_mt[0] & LOWER_MASK);
        _mt[N-1] = _mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        _mti = 0;
    }
  
    y = _mt[_mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return( y );
}


//-----------------------------------------------------------------------------
//  Method:  genrnd_double
//-----------------------------------------------------------------------------
double  RandomMT::genrnd_double (void)
{
    //---- DIVIDE BY 2^32 TO CONFORM WITH [0,1).
    return( genrnd_int32() * (1.0 / 4294967296.0) );
}


//-----------------------------------------------------------------------------
//  Method:  genrnd_doubleInclusive
//-----------------------------------------------------------------------------
double  RandomMT::genrnd_doubleInclusive (void)
{
    //---- DIVIDE BY 2^32 - 1 TO CONFORM WITH [0,1].
    return( genrnd_int32() * (1.0 / 4294967295.0) );
}


//-----------------------------------------------------------------------------
//  Method:  genMatlabMT
//-----------------------------------------------------------------------------
double  RandomMT::genMatlabMT (void)
{
    double  dResult = genrnd_double();
    genrnd_double();
    return( dResult );
}
