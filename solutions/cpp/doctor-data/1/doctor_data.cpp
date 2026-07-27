// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

/*
hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
hp2,öjmpö.
*/
#include "doctor_data.h"

// Vessel (std::string name, int n)
//{};
heaven::Vessel::Vessel(std::string name, int n, star_map::System a_star)
    : name(std::move(name)), n(n), current_system(a_star) {};

heaven::Vessel heaven::Vessel::replicate(std::string name)
{
    Vessel clone = *this;
    clone.name = name;
    clone.generation += 1;
    return clone;
}

void heaven::Vessel::make_buster()
{
    busters += 1;
}

bool heaven::Vessel::shoot_buster()
{
    if (0 < busters) 
    {
        busters -= 1;
        return true;
    }
    else
        return false;
}

std::string heaven::get_older_bob(Vessel vessel1, Vessel vessel2)
{
    if (vessel1.n < vessel2.n )
    {
        return vessel1.name;
    }
    else 
        return vessel2.name;
}

bool heaven::in_the_same_system(Vessel vessel1, Vessel vessel2)
{
    return (vessel1.current_system == vessel2.current_system);
}