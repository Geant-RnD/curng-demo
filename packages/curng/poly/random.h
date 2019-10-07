//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/poly/random.h
 * \brief  random CUDA-device class declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_include_curng_random_cuh
#define curng_include_curng_random_cuh

#include "Macros.h"

#ifdef __CUDACC__
#include "../cuda/random.cuh"
#else
#include "../cxx/random.h"
#endif

//---------------------------------------------------------------------------//
#endif // curng_include_curng_random_cuh
//---------------------------------------------------------------------------//
// end of random.h
//---------------------------------------------------------------------------//
