//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/DeviceVars.h
 * \brief  When compiling a non-CUDA kernel, define CUDA variables.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_DeviceVars_h
#define curng_DeviceVars_h

#if !defined(__CUDACC__)
#  include "cxx/CudaVars.h"
#endif

//---------------------------------------------------------------------------//
#endif // curng_DeviceVars_h
//---------------------------------------------------------------------------//
// end of curng/DeviceVars.h
//---------------------------------------------------------------------------//
