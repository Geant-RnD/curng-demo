// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/Macros.h
 * \brief  Macros declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/
#ifndef curng_Macros_h
#define curng_Macros_h
/* clang-format off */
/*---------------------------------------------------------------------------*/

/* TODO: add assertions */
#define REQUIRE(x) do { (void)sizeof(x); } while (0)

#if defined(__CUDACC__)
  /* CUDA is ENABLED */
#  define CURNG_LANG cuda
#else
  /* CUDA is DISABLED */
#  define CURNG_LANG cxx

#  include "cxx/CudaMacros.h"
#endif

/*---------------------------------------------------------------------------*/
/* clang-format on */
#endif // curng_Macros_h

/*---------------------------------------------------------------------------*
 * end of curng/include/Macros.h
 *---------------------------------------------------------------------------*/
