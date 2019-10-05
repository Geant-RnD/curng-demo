//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/HostTraits.h
 * \brief  HostTraits class declaration.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_HostTraits_h
#define curng_HostTraits_h

#ifdef __CUDACC__
#include "cuda/HostTraits.h"
#else
#include "cxx/HostTraits.h"
#endif

//---------------------------------------------------------------------------//
#endif // curng_HostTraits_h
//---------------------------------------------------------------------------//
// end of HostTraits.h
//---------------------------------------------------------------------------//
