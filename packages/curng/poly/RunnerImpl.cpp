// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/RunnerImpl.cpp
 * \brief  Runner class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#include "RunnerImpl.h"

#include <fstream>
#include <memory>
#include "Kernel.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//---------------------------------------------------------------------------//
/*!
 * \brief Build with parameters
 */
RunnerImpl::RunnerImpl(Params params)
    : params_(std::move(params))
    , states_(params_.size)
{
    REQUIRE(params_.chunk_size > 0);
    REQUIRE(params_.size >= params_.chunk_size);
}

//---------------------------------------------------------------------------//
//!  Default destructor
RunnerImpl::~RunnerImpl() = default;

//---------------------------------------------------------------------------//
/*!
 * \brief Run a batch.
 */
auto RunnerImpl::operator()() -> result_type
{
    using HostVec = MultiStateVector::HostVector_t;
    using size_type = MultiStateVector::size_type;

    // >>> Launch the kernel

    launch_kernel(states_.view(), params_);

    // Write/copy out the data in chunks
    HostVec buffer(params_.chunk_size);

    std::ofstream outf("out.txt");
    const size_type max_size   = params_.size;
    const size_type chunk_size = params_.chunk_size;
    size_type       start      = 0;
    size_type       stop       = std::min(max_size, chunk_size);
    while (start != stop)
    {
        // Copy data
        states_.copy_range(start, stop, buffer.begin());

        // Write buffer to disk
        for (auto val : buffer)
        {
            outf << val << '\n';
        }

        start = stop;
        stop  = std::min(max_size, start + chunk_size);
    }
}

//---------------------------------------------------------------------------//
// FREE FUNCTIONS
//---------------------------------------------------------------------------//
std::unique_ptr<Runner> MakeRunnerImpl(Params p)
{
    return std::unique_ptr<Runner>(new RunnerImpl(std::move(p)));
}

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
// end of RunnerImpl.cpp
//---------------------------------------------------------------------------//
