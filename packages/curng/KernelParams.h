//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/KernelParams.h
 * \brief  KernelParams declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_KernelParams_h
#define curng_KernelParams_h

namespace curng
{
//===========================================================================//
/*!
 * \struct KernelParams
 * \brief Parameters for launching and working with the kernel.
 */
//===========================================================================//

struct KernelParams
{
    enum KernelType {
        kHost,
        kDevice
    };

    int blocks = 0;
    int threads_per_block = 0;
    KernelType target = kHost;
};

//---------------------------------------------------------------------------//
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_KernelParams_h
//---------------------------------------------------------------------------//
// end of curng/KernelParams.h
//---------------------------------------------------------------------------//
