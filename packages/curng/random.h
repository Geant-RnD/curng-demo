//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/random.h
 * \brief  random CUDA-device class declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_include_curng_random_cuh
#define curng_include_curng_random_cuh

#include "Macros.h"

#ifdef __NVCC__
#include "cuda/random.cuh"
#else
#include "cpp/random.h"
#endif

//---------------------------------------------------------------------------//
#endif // curng_include_curng_random_cuh
//---------------------------------------------------------------------------//
// end of random.h
//---------------------------------------------------------------------------//
