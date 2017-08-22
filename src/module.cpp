/// Implementation of the sample library module.
///
#include "module.hpp"

using argparse::SampleClass;


int SampleClass::add(int x) const
{
    return argparse::add(num, x);
}


int argparse::add(int x, int y)
{
    return x + y;
}
