// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/MultiStateVector.cpp
 * \brief  MultiStateVector class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "MultiStateVector.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//---------------------------------------------------------------------------//
/*!
 * \brief  Constructor
 */
__host__ MultiStateVector::MultiStateVector(size_type num_particles)
    : storage_(num_particles)
{
    REQUIRE(num_particles > 0);
}

//---------------------------------------------------------------------------//
//! Default destructor
__host__ MultiStateVector::~MultiStateVector() = default;

//---------------------------------------------------------------------------//
/*!
 * \brief Copy a chunk of data to the host.
 *
 * The namespace of `copy` is determined by automatic lookup of its argument's
 * namespaces: if compiling with CUDA it will be \c thrust; otherwise \c std.
 */
__host__ void MultiStateVector::copy_range(size_type              start,
                                           size_type              stop,
                                           HostVector_t::iterator dst)
{
    REQUIRE(start <= stop);
    REQUIRE(stop <= this->size());
    copy(storage_.begin() + start, storage_.begin() + stop, dst);
}

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
// end of curng/MultiStateVector.cpp
//---------------------------------------------------------------------------//
