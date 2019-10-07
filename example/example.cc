//---------------------------------*-C++-*-----------------------------------//
/*!
 * \file   curng/example/example.cc
 * \brief  example class definitions.
 * \note   Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
//---------------------------------------------------------------------------//

#include "curng/config.h"
#include "curng/Params.h"
#include "curng/Runner.h"

#include <iostream>
#include <string>
#include <vector>

using curng::Params;

Params process_args(std::vector<std::string> args)
{
    (void)sizeof(args);
    return {};
}

int main(int argc, char* argv[])
{
    using std::cerr;
    using std::endl;

    auto run = curng::MakeRunner(process_args({argv + 1, argv + argc}));
    if (!run)
    {
        return 1;
    }

    (*run)();
    return 0;
}

//---------------------------------------------------------------------------//
// end of curng/example/example.cc
//---------------------------------------------------------------------------//
