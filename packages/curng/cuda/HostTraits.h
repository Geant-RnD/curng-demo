//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/cuda/HostTraits.h
 * \brief  HostTraits class declaration.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_cuda_HostTraits_h
#define curng_cuda_HostTraits_h

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/device_ptr.h>

namespace curng
{
namespace cuda
{
template<class T>
struct HostTraits
{
    using size_type     = std::size_t;
    using value_type    = T;
    using HostVector    = thrust::host_vector<T>;
    using DeviceVector  = thrust::device_vector<T>;
    using DevicePointer = thrust::device_ptr<T>;
};
} // namespace cuda
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_cuda_HostTraits_h
//---------------------------------------------------------------------------//
// end of HostTraits.h
//---------------------------------------------------------------------------//
