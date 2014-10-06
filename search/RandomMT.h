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

/*!
  @file TTB_RandomMT.h
  @brief Class declaration for a Mersenne Twister random number generator.
  */


#ifndef RANDOMMT_H
#define RANDOMMT_H

//! Mersenne Twister random number generator.
class RandomMT
{
	public:

		//! Constructor.
		RandomMT (const unsigned long  nnSeed);

		//! Destructor.
		~RandomMT (void);


		//! Return a uniform random number on the interval [0,0xffffffff].
		unsigned long  genrnd_int32 (void);

		//! Return a uniform random number on the interval [0,1).
		double genrnd_double (void);

		//! Return a uniform random number on the interval [0,1].
		double  genrnd_doubleInclusive (void);

		//! Return a uniform random number on the interval [0,1).
		/*!
		 *  Calling this method generates the same stream of random samples as
		 *  the following Matlab code:
		 *    > rstrm = RandStream('mt19937ar', 'Seed', 1);
		 *    > rand (rstrm, 1, 10);
		 *
		 *  Note that the C++ instance must be constructed with the same seed as
		 *  Matlab, and the seed must be positive.  The Matlab generator skips
		 *  every other Mersenne Twister value, so this method runs twice as slow
		 *  as genrnd_double().
		 *
		 *  Matlab RandStream "features" were observed in version 7.10 (2010a).
		 */
		double  genMatlabMT (void);


	private:

		//! By design, there is no copy constructor.
		RandomMT (const RandomMT &);
		//! By design, there is no assignment operator.
		RandomMT &  operator=(const RandomMT &);
};


#endif     //-- RANDOMMT_H
