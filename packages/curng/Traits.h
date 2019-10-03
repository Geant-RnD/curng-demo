//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/Traits.h
 * \brief  Traits class declaration.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_Traits_h
#define curng_Traits_h

#ifdef __NVCC__
#include <thrust/vector.h>
#endif

namespace curng
{
namespace cxx
{
template<class T>
class VectorTraits
{
    using value_type = T;
    using Vector     = std::vector<T>;
};
} // namespace cxx

#ifdef __NVCC__
namespace cuda
{
template<class T>
class VectorTraits
{
    using value_type = T;
    using Vector     = thrust::vector<T>;
};
} // namespace cuda
#endif
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_Traits_h
//---------------------------------------------------------------------------//
// end of curng/Traits.hh
//---------------------------------------------------------------------------//
