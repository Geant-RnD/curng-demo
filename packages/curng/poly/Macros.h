// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/Macros.h
 * \brief  Macros declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/
#ifndef curng_poly_Macros_h
#define curng_poly_Macros_h
/* clang-format off */
/*---------------------------------------------------------------------------*/

/* TODO: add assertions */
#define REQUIRE(x) do { (void)sizeof(x); } while (0)

#if defined(__CUDACC__)
  /* CUDA is ENABLED */
#  define CURNG_LANG_NS cuda
#else
  /* CUDA is DISABLED */
#  define CURNG_LANG_NS cxx

#  include "../cxx/CudaMacros.h"
#endif

/*---------------------------------------------------------------------------*/
/* clang-format on */
#endif // curng_poly_Macros_h

/*---------------------------------------------------------------------------*
 * end of curng/include/Macros.h
 *---------------------------------------------------------------------------*/
