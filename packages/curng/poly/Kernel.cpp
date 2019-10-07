// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/Kernel.cpp
 * \brief  Kernel class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "Kernel.h"

#include "Macros.h"
#include "DeviceVars.h"
#include "MultiStateView.h"
#include "../Params.h"

namespace curng
{
namespace CURNG_LANG_NS
{
//---------------------------------------------------------------------------//
__device__ void kernel_impl(StateView state)
{
    state.set(1 + threadIdx.x * 10 + blockIdx.x * 1000);
}

//---------------------------------------------------------------------------//
__global__ void execute_kernel(MultiStateView view)
{
    // Call the kernel implementation for every item in the multistate view.
    // When running on device, the "stride" is the number of simultaneous
    // threads.
    const int stride = blockDim.x * gridDim.x;
    const int end    = view.size();
    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < end; i += stride)
    {
        kernel_impl(view[i]);
    }
}

//---------------------------------------------------------------------------//
__host__ void launch_kernel(MultiStateView view, const Params& params)
{
#ifdef __CUDACC__
    REQUIRE(params.blocks > 0 && params.threads_per_block >= 32);
    REQUIRE(params.target == Params::kDevice);
    execute_kernel<<<params.blocks, params.threads_per_block>>>(view);
#else
    REQUIRE(params.target == Params::kHost);
    REQUIRE(params.blocks == 1 && params.threads_per_block == 1);
    execute_kernel(view);
#endif
}

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
// end of src/curng/Kernel.cpp
//---------------------------------------------------------------------------//
