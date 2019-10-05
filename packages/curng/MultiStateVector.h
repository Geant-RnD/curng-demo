//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/MultiStateVector.h
 * \brief  MultiStateVector declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_MultiStateVector_h
#define curng_MultiStateVector_h

#include "Macros.h"
#include "MultiStateView.h"
#include "HostTraits.h"

namespace curng
{
inline namespace CURNG_LANG
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
    //! Constructor
    MultiStateVector(size_type num_particles)
        : storage_(num_particles)
    {
        REQUIRE(num_particles > 0);
    }

    // Default destructor defined in .cpp file
    ~MultiStateVector();

    //! Copy a chunk of data to the host
    void get_range(size_type start, size_type stop, HostVector_t& dst)
    {
        REQUIRE(start <= stop);
        REQUIRE(stop <= this->size());
        dst.assign(storage_.begin() + start, storage_.begin() + stop);
    }

    //! Number of state elements
    size_type size() const { return storage_.size(); }

    //! Get a view to the on-device state data
    MultiStateView view()
    {
        return {raw_pointer_cast(storage_.data()), storage_.size()};
    }
};

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_MultiStateVector_h
//---------------------------------------------------------------------------//
// end of MultiStateVector.h
//---------------------------------------------------------------------------//
