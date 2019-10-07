// vim: set ft=cuda: -------------*-CUDA-*-----------------------------------//
/*!
 * \file   curng/poly/Kernel.h
 * \brief  Kernel declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_poly_Kernel_h
#define curng_poly_Kernel_h

#include "Macros.h"

namespace curng
{
//---------------------------------------------------------------------------//

struct Params;

namespace CURNG_LANG_NS
{
//---------------------------------------------------------------------------//

class MultiStateView;

__host__ void launch_kernel(MultiStateView view, const Params& params);

//---------------------------------------------------------------------------//
} // namespace CURNG_LANG_NS
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_poly_Kernel_h
//---------------------------------------------------------------------------//
// end of src/curng/Kernel.h
//---------------------------------------------------------------------------//
