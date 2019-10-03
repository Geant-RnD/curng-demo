// vim: set ft=cuda: --------------*-C++-*-----------------------------------//
/*!
 * \file   curng/Macros.h
 * \brief  Macros declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/
#ifndef curng_Macros_h
#define curng_Macros_h
//clang-format off
/*---------------------------------------------------------------------------*/

#if defined(__CUDACC__) || defined(__NVCC__)
  /* CUDA is ENABLED */

#  define CURNG_LANG cuda

#else
  /* CUDA is DISABLED */

#  define CURNG_LANG cxx

#  ifndef __forceinline__
#    if defined(_MSC_VER)
#      define __forceinline__ inline __forceinline
#    elif defined(__clang__) || defined(__GNUC__)
       /* GCC and Clang use same syntax */
#      define __forceinline__ inline __attribute__((always_inline))
#    elif defined(__INTEL_COMPILER)
       /* Intel depends on compiler version */
#      if __INTEL_COMPILER >= 1200
#        define __forceinline__ inline __attribute__((always_inline))
#      else
#        define __forceinline__ inline __forceinline
#      endif
#    else
       /* Otherwise set to "inline" */
#      define __forceinline__ inline
#    endif
#  endif

/* Undefine device qualifiers */
#  define __device__
#  define __host__
#  define __global__

#endif

/*---------------------------------------------------------------------------*/
//clang-format on
#endif // curng_Macros_h

/*---------------------------------------------------------------------------*
 * end of curng/include/Macros.h
 *---------------------------------------------------------------------------*/
