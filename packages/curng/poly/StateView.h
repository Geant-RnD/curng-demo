// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/StateView.h
 * \brief  StateReference declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_StateView_h
#define curng_poly_StateView_h

#include "Macros.h"
#include "DeviceTraits.h"

namespace curng
{
namespace CURNG_LANG_NS
{
class MultiStateView;
//===========================================================================//
/*!
 * \struct StateView
 * \brief *On-device* view to a single State.
 *
 * This is constructed from a State and should be passed directly into device
 * code.
 */
//===========================================================================//

class StateView
{
  public:
    //@{
    //! Public types
    using Traits_t     = DeviceTraits<int>;
    using value_type   = Traits_t::value_type;
    using pointer_type = Traits_t::pointer_type;
    //@}

  private:
    // >>> DATA

    pointer_type data_;

  public:
    StateView(const StateView&) = default;

    __host__ __device__ value_type get() const { return *data_; }
    __host__ __device__ void set(value_type val) { *data_ = val; }

  private:
    // >>> CONSTRUCT ONLY FROM FRIENDS
    explicit __host__ __device__ StateView(pointer_type data)
        : data_(data)
    {
        REQUIRE(data_ != nullptr);
    }

    friend class MultiStateView;
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_StateView_h
//---------------------------------------------------------------------------//
// end of StateView.h
//---------------------------------------------------------------------------//
