// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/MultiStateVector.h
 * \brief  MultiStateVector declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_MultiStateVector_h
#define curng_poly_MultiStateVector_h

#include "Macros.h"
#include "MultiStateView.h"
#include "HostTraits.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//===========================================================================//
/*!
 * \class MultiStateVector
 * \brief Manages and stores the states of multiple particle tracks.
 */
//===========================================================================//

class MultiStateVector
{
  public:
    //@{
    //! Public types
    using Traits_t     = HostTraits<int>;
    using HostVector_t = Traits_t::HostVector;
    using value_type   = Traits_t::value_type;
    using size_type    = Traits_t::size_type;
    //@}

  private:
    // Device storage
    Traits_t::DeviceVector storage_;

  public:
    // Constructor
    explicit __host__ MultiStateVector(size_type num_particles);

    // Default destructor defined in .cpp file
    __host__ ~MultiStateVector();

    // Copy a chunk of data to the host
    __host__ void copy_range(size_type start, size_type stop,
                             HostVector_t::iterator dst);

    //! Number of state elements
    __host__ size_type size() const { return storage_.size(); }

    //! Get a view to the on-device state data
    __host__ MultiStateView view()
    {
        return {raw_pointer_cast(storage_.data()), storage_.size()};
    }
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_MultiStateVector_h
//---------------------------------------------------------------------------//
// end of MultiStateVector.h
//---------------------------------------------------------------------------//
