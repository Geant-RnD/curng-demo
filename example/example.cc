//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/example/example.cc
 * \brief  example class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "curng/config.h"
#include "curng/Kernel.h"
#include "curng/KernelParams.h"
#include "curng/MultiStateVector.h"

#include <iostream>

int main(int , char* [])
{
    using curng::KernelParams;
    using std::cerr;
    using std::endl;

    int num_particles = 100;
    curng::MultiStateVector vec(num_particles);
    KernelParams kernel;
#ifdef HAVE_CUDA
    kernel.target = KernelParams::kDevice;
    kernel.blocks = 4;
    kernel.threads_per_block = 32;
#else
    kernel.target = KernelParams::kHost;
    kernel.blocks = 1;
    kernel.threads_per_block = 1;
#endif

    switch (kernel.target)
    {
        case KernelParams::kDevice:
#ifdef HAVE_CUDA
            break;
#else
            cerr << "Can't run on device: CUDA is not enabled" << endl;
            return 1;
#endif
        case KernelParams::kHost:
            break;
    }

    return 0;
}

//---------------------------------------------------------------------------//
// end of curng/example/example.cc
//---------------------------------------------------------------------------//
