// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/Kernel.h
 * \brief  Kernel declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_Kernel_h
#define curng_Kernel_h

#include "Macros.h"

namespace curng
{
//---------------------------------------------------------------------------//

struct KernelParams;

inline namespace CURNG_LANG
{
//---------------------------------------------------------------------------//

class MultiStateView;

__host__ void launch_kernel(MultiStateView view, KernelParams params);

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_Kernel_h
//---------------------------------------------------------------------------//
// end of src/curng/Kernel.h
//---------------------------------------------------------------------------//
