// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/State.h
 * \brief  State class.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_State_h
#define curng_poly_State_h

#include "Macros.h"
#include "Types.h"
#include "StateReference.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//===========================================================================//
/*!
 * \class State
 * \brief Managed container of type-deleted state data.
 */
//===========================================================================//

class State
{
  public:
    using VectorTraits_t     = VectorTraits<value_type>;
    using size_type          = VectorTraits_t::size_type;
    using DevicePointer      = VectorTraits<value_type>::DevicePointer;
    using pointer_type       = VectorTraits<value_type>::pointer_type;
    using const_pointer_type = const pointer_type;

  public:
    //! Constructor
    State() {}

    //! Get a reference to the state data
    __host__ StateReference reference() const
    {
        return StateReference(raw_pointer_cast(storage_.data()));
    }

  private:
    // Device storage
    DeviceVector storage_;
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_State_h
//---------------------------------------------------------------------------//
// end of curng/State.h
//---------------------------------------------------------------------------//
