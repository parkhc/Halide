#ifndef HALIDE_VAR_H
#define HALIDE_VAR_H

#include <string>
#include "Util.h"
#include "IR.h"

namespace Halide {
    using std::string;

    class Var {
        string _name;
    public:
        Var(const string &n) : _name(n) {}
        Var() : _name(Internal::unique_name('v')) {}
        const string &name() const {return _name;}
        bool operator==(const Var &other) {return _name == other._name;}
        bool operator!=(const Var &other) {return _name != other._name;}

        operator Expr() {
            return new Variable(Int(32), name());
        }
    };


}

#endif
