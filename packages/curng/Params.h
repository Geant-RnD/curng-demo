//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/Params.h
 * \brief  KernelParams declarations.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//
#ifndef curng_Params_h
#define curng_Params_h

namespace curng
{
//===========================================================================//
/*!
 * \struct Params
 * \brief Parameters for running this app.
 */
//===========================================================================//

struct Params
{
    enum KernelType {
        kHost,
        kDevice
    };

    // >>> RUN OPTIONS

    //! Number of elements in the state vector
    int size = 1024;
    //! Number of elements to transfer from device->host per call
    int chunk_size = 128;

    // >>> KERNEL OPTIONS

    KernelType target            = kHost;
    int        blocks            = 1;
    int        threads_per_block = 1;
};

//---------------------------------------------------------------------------//
} // namespace curng

//---------------------------------------------------------------------------//
#endif // curng_Params_h
//---------------------------------------------------------------------------//
// end of curng/KernelParams.h
//---------------------------------------------------------------------------//
