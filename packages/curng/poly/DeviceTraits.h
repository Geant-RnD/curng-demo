// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/DeviceTraits.h
 * \brief  DeviceTraits declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_DeviceTraits_h
#define curng_poly_DeviceTraits_h

#include <cstddef>

namespace curng
{
namespace CURNG_LANG_NS
{
//===========================================================================//
/*!
 * \struct DeviceTraits
 * \brief Class types used in compiled kernel code.
 */
//===========================================================================//

template<class T>
struct DeviceTraits
{
    using value_type         = T;
    using pointer_type       = value_type*;
    using const_pointer_type = const value_type*;
    using size_type          = std::size_t;
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_DeviceTraits_h
//---------------------------------------------------------------------------//
// end of curng/DeviceTraits.h
//---------------------------------------------------------------------------//
