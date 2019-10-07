// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/RunnerImpl.h
 * \brief  Runner declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_RunnerImpl_h
#define curng_poly_RunnerImpl_h

#include "curng/Runner.h"

#include "Macros.h"
#include "MultiStateVector.h"
#include "curng/Params.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//===========================================================================//
/*!
 * \class RunnerImpl
 * \brief Implementation of runner
 */
//===========================================================================//

class RunnerImpl : public Runner
{
  private:
    // >>> DATA

    Params           params_;
    MultiStateVector states_;

  public:
    // Construct with params
    explicit RunnerImpl(Params params);
    // Default destructor
    ~RunnerImpl();

    // Run a batch
    result_type operator()() override;
};

//---------------------------------------------------------------------------//
std::unique_ptr<Runner> MakeRunnerImpl(Params p);

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_RunnerImpl_h
//---------------------------------------------------------------------------//
// end of RunnerImpl.h
//---------------------------------------------------------------------------//
