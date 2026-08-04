#include "vehicle_purchase.h"

namespace vehicle_purchase
{

    // needs_license determines whether a license is needed to drive a type of
    // vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind)
    {
        if ("car" == kind)
            return true;
        else if ("truck" == kind)
            return true;
        else
            return false;
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends the
    // vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2)
    {

        std::string remark{" is clearly the better choice."};
        // Return lower value due to lex order
        if (option1 > option2)
            return option2 + remark;
        else
            return option1 + remark;
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a
    // certain age.
    double calculate_resell_price(double original_price, double age)
    {
        //At least 10 years
        if (10 <= age)
            return original_price * 0.5;
        // Less than 10 but more than 3.
        else if (3 < age)
            return original_price * 0.7;
        // Less than 3
        else
            return original_price * 0.8;
    }

} // namespace vehicle_purchase