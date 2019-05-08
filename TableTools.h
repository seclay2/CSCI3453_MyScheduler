//
// Created by Scott Clay on 2019-05-07.
//

#ifndef OSLAB03_TABLETOOLS_H
#define OSLAB03_TABLETOOLS_H

#include <string>
#include <sstream>

namespace TableTools {

    /* Convert double to string with specified number of places after the decimal
       and left padding. */
    std::string pri(const int &x, const int width) {
        std::stringstream ss;
        ss << std::fixed << std::right;
        ss.fill(' ');        // fill space around displayed #
        ss.width(width);     // set  width around displayed #
        ss << x;
        return ss.str();
    }

    /* Convert double to string with specified number of places after the decimal
       and left padding. */
    std::string prd(const double &x, const int decDigits, const int width) {
        std::stringstream ss;
        ss << std::fixed << std::right;
        ss.fill(' ');        // fill space around displayed #
        ss.width(width);     // set  width around displayed #
        ss.precision(decDigits); // set # places after decimal
        ss << x;
        return ss.str();
    }

    /* Center-aligns string within a field of width w. Pads with blank spaces
        to enforce alignment. */
    std::string center(const std::string &s, const int w) {
        std::stringstream ss, spaces;
        int padding = w - s.size();                 // count excess room to pad
        for(int i=0; i<padding/2; ++i)
            spaces << " ";
        ss << spaces.str() << s << spaces.str();    // format with padding
        if(padding>0 && padding%2!=0)               // if odd #, add 1 space
            ss << " ";
        return ss.str();
    }

}

#endif //OSLAB03_TABLETOOLS_H
