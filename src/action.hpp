/// Argument actions.
///
/// @file
#ifndef ARGPARSE_ACTION_HPP
#define ARGPARSE_ACTION_HPP

#include "util.hpp"


namespace argparse
{
    /// Abstract base class for an action.
    ///
    /// Each argument has an action associated with it that is executed when
    /// the argument is parsed, e.g. storing the argument value.
    ///
    class Action
    {
    public:
        /// Execute the action.
        ///
        /// @param args
        virtual void operator()(const ValueMap& args) = 0;

    protected:
        /// Default constructor.
        ///
        Action() = default;
    };

    /// Action to store command line arguments.
    ///
    class Store: public Action
    {
    public:
        /// Construct an object.
        ///
        /// @param data storage for argument values
        Store(ValueMap& data);

        /// Execute the action.
        ///
        /// The given values will be merged into the keyed storage attached to
        /// this object.
        ///
        /// @param args keyed values to be stored
        void operator()(const ValueMap& args) override;

    private:
        ValueMap& data;
    };
}


#endif  // ARGPARSE_ACTION_HPP
