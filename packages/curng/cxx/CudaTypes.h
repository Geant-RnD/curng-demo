//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/cxx/CudaTypes.h
 * \brief  CudaTypes declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_cxx_CudaTypes_h
#define curng_cxx_CudaTypes_h

namespace curng
{
namespace cxx
{
//---------------------------------------------------------------------------//
//! Integers with 3 components
struct uint3
{
    unsigned int x, y, z;
};

//! Like uint3, but the constructor initializes non-specified components to 1
struct dim3
{
    unsigned int x = 1;
    unsigned int y = 1;
    unsigned int z = 1;
};

//! Float with 3 components
struct float3
{
    float x, y, z;
};

//! Double with 3 components
struct double3
{
    double x, y, z;
};

//---------------------------------------------------------------------------//
} // namespace cxx
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_cxx_CudaTypes_h
//---------------------------------------------------------------------------//
// end of src/curng/cxx/CudaTypes.h
//---------------------------------------------------------------------------//
