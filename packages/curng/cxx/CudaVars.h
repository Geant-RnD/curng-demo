// vim: set ft=cuda: --------------*-C++-*-----------------------------------//
/*!
 * \file   curng/cxx/CudaVars.h
 * \brief  CudaVars declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_cxx_CudaVars_h
#define curng_cxx_CudaVars_h

#include "CudaTypes.h"
#include "CudaMacros.h"

//! Dimensions of the grid (1,1,1)
#define gridDim (::curng::cxx::UnitDim3())
//! Index of the block in the thread (0,0,0)
#define blockIdx (::curng::cxx::ZeroUint3())
//! Dimensions of the block (1,1,1)
#define blockDim (::curng::cxx::UnitDim3())
//! Index of the thread (0,0,0)
#define threadIdx (::curng::cxx::ZeroUint3())
//! Number of threads per warp (1)
#define warpSize (::curng::cxx::UnitInt())

namespace curng
{
inline namespace cxx
{
//---------------------------------------------------------------------------//

//! Return unit dimensions (1,1,1)
constexpr __forceinline__ dim3 UnitDim3()
{
    return dim3();
}

constexpr __forceinline__ uint3 ZeroUint3()
{
    return {0,0,0};
}

constexpr __forceinline__ int UnitInt()
{
    return 1;
}

//---------------------------------------------------------------------------//
} // namespace cxx
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_cxx_CudaVars_h
//---------------------------------------------------------------------------//
// end of src/curng/cxx/CudaVars.h
//---------------------------------------------------------------------------//
