//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/Runner.cpp
 * \brief  Runner class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "Runner.h"

#include <iostream>
#include <curng/config.h>

namespace curng
{
//---------------------------------------------------------------------------//
//! Default destructor
Runner::~Runner() = default;

//---------------------------------------------------------------------------//
// FREE FUNCTIONS
//---------------------------------------------------------------------------//
// Note: these factory functions are declared in RunnerImpl.h, but since the
// header can only declare them once, we declare them both explicitly here. If
// CUDA isn't enabled,
namespace cuda
{
std::unique_ptr<Runner> MakeRunnerImpl(Params p);
}

namespace cxx
{
std::unique_ptr<Runner> MakeRunnerImpl(Params p);
}

//---------------------------------------------------------------------------//
/*!
 * \brief Factory class for Runner.
 */
std::unique_ptr<Runner> MakeRunner(Params params)
{
    switch (params.target)
    {
        case Params::kDevice:
#ifdef HAVE_CUDA
            return curng::cuda::MakeRunnerImpl(std::move(params));
#else
            std::cerr << "Can't run on device: CUDA is not enabled\n";
            return nullptr;
#endif
        case Params::kHost:
            return curng::cxx::MakeRunnerImpl(std::move(params));
    }
}

//---------------------------------------------------------------------------//
} // namespace curng

//---------------------------------------------------------------------------//
// end of curng/Runner.cpp
//---------------------------------------------------------------------------//
