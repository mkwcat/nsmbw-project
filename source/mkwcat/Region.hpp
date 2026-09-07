//
//  mkwcat/Region.hpp
//  nsmbw-project
//

#pragma once

namespace mkwcat {

enum class Region {
    P1, // PAL revision 1
    P2, // PAL revision 2
    E1, // USA revision 1
    E2, // USA revision 2
    J1, // JPN revision 1
    J2, // JPN revision 2
    K,  // KOR
    W,  // TWN
    C,  // CHN (Nvidia Shield TV release)
    Error,
};

} // namespace mkwcat
