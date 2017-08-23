#include "action.hpp"

using namespace argparse;


Store::Store(ValueMap& data):
    data(data)
{}


void Store::operator()(const ValueMap& args)
{
    data.merge(args);
    return;
}
