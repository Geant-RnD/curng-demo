//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/cxx/HostTraits.h
 * \brief  HostTraits class declaration.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_cxx_HostTraits_h
#define curng_cxx_HostTraits_h

#include <vector>

namespace curng
{
inline namespace cxx
{
//===========================================================================//
/*!
 * \struct HostTraits
 * \brief Class types used in host managment code.
 *
 * \note To reduce compilation costs and improve compatibility, the host traits
 * should only be included by host code.
 */
//===========================================================================//

template<class T>
struct HostTraits
{
    using size_type     = std::size_t;
    using value_type    = T;
    using HostVector    = std::vector<T>;
    using DeviceVector  = std::vector<T>;
    using DevicePointer = T*;
};

//! Get a raw pointer from a DevicePointer
template<class T>
inline T* raw_pointer_cast(T* ptr)
{
    return ptr;
}

//---------------------------------------------------------------------------//
} // namespace cxx
} // namespace curng

#endif // curng_cxx_HostTraits_h
//---------------------------------------------------------------------------//
// end of HostTraits.h
//---------------------------------------------------------------------------//
