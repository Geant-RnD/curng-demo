// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/MultiStateView.h
 * \brief  MultiStateView declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_MultiStateView_h
#define curng_poly_MultiStateView_h

#include "Macros.h"
#include "DeviceTraits.h"
#include "StateView.h"

namespace curng
{
namespace CURNG_LANG_NS
{
class MultiStateVector;
//===========================================================================//
/*!
 * \class MultiStateView
 * \brief Host/device class that allows state data to be accessed.
 */
//===========================================================================//

class MultiStateView
{
  public:
    //@{
    //! Public types
    using Traits_t            = DeviceTraits<int>;
    using value_type          = Traits_t::value_type;
    using device_pointer_type = Traits_t::pointer_type;
    using size_type           = Traits_t::size_type;
    //@}

  private:
    device_pointer_type data_;
    size_type           size_;

  public:
    __host__ __device__ MultiStateView(const MultiStateView&) = default;

    //! Number of states being stored
    __host__ __device__ size_type size() const { return size_; }

    //! Access a single state
    __host__ __device__ StateView operator[](size_type index) const
    {
        REQUIRE(index < this->size());
        return StateView{data_ + index};
    }

  private:
    // >>> Construct only from friends
    __host__ MultiStateView(device_pointer_type data, size_type size)
        : data_(data)
        , size_(size)
    {
        REQUIRE(data != nullptr);
        REQUIRE(size > 0);
    }

    friend class MultiStateVector;
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_MultiStateView_h
//---------------------------------------------------------------------------//
// end of MultiStateView.h
//---------------------------------------------------------------------------//
