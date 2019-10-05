//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/cuda/HostTraits.h
 * \brief  HostTraits class declaration.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_cuda_HostTraits_h
#define curng_cuda_HostTraits_h

#include <thrust/vector.h>
#include <thrust/device_ptr.h>

namespace curng
{
inline namespace cuda
{
template<class T>
struct VectorTraits
{
    using size_type     = std::size_t;
    using value_type    = T;
    using HostVector    = thrust::host_vector<T>;
    using DeviceVector  = thrust::device_vector<T>;
    using DevicePointer = thrust::device_pointer<T>;
};
} // namespace cuda
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_cuda_HostTraits_h
//---------------------------------------------------------------------------//
// end of HostTraits.h
//---------------------------------------------------------------------------//
