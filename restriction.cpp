#include "restriction.h"
#include "speed_restriction.h"

std::unique_ptr<Restriction> Restriction::ReadFromStream(std::istream& is) {
    return SpeedRestriction::ReadFromStream(is);
}

std::ostream& operator<<(std::ostream& os, const Restriction& r) {
    os << r.ToString();
    return os;
}
