//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/Runner.h
 * \brief  Runner declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_Runner_h
#define curng_Runner_h

#include <memory>

#include "Params.h"

namespace curng
{
//===========================================================================//
/*!
 * \class Runner
 * \brief Abstract base class for running the code.
 *
 * Derived classes in the CUDA/CXX namespaces actually implement this
 * interface.
 */
//===========================================================================//

class Runner
{
  public:
    using result_type = void;

  public:
    virtual ~Runner();

    // Run a batch
    virtual result_type operator()() = 0;
};

//---------------------------------------------------------------------------//
/*!
 * \brief Factory class for Runner.
 */
std::unique_ptr<Runner> MakeRunner(Params p);

//---------------------------------------------------------------------------//
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_Runner_h
//---------------------------------------------------------------------------//
// end of curng/Runner.h
//---------------------------------------------------------------------------//
