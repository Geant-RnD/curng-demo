/*----------------------------------*-C-*------------------------------------*/
/*!
 * \file   curng/Macros.h
 * \brief  Macros declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/
#ifndef curng_Macros_h
#define curng_Macros_h
/*---------------------------------------------------------------------------*/

#if !defined(__CUDACC__) && !defined(__NVCC__)

/* CUDA is disabled */
#define __device__
#define __host__

#define CURNG_LANG cxx

#else

#define CURNG_LANG cuda

#endif

/*---------------------------------------------------------------------------*/
#endif // curng_Macros_h

/*---------------------------------------------------------------------------*
 * end of curng/include/Macros.h
 *---------------------------------------------------------------------------*/
