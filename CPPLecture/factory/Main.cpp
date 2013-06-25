#include "SpaceShipFactory.h"
#include "SpaceShips.h"
#include "Fleet.h"
#include <sstream>
#include <iostream>

int main()
{
	// Register SpaceShips by using the SpaceShipFactory::getInstance().registerSpaceShip with lambda functions.

	// TODO: Register TieFighter with SpaceShipFactory::getInstance().registerSpaceShip
	// The string parameter contains the pilot.
    auto tieFigher = [] (std::string pilotname) {
        std::shared_ptr<TieFighter> ptr(new TieFighter(pilotname));
        return ptr;
    };
    SpaceShipFactory::getInstance().registerSpaceShip("TieFighter", tieFigher);

	// TODO: Register DeathStar
	// The string parameter has to be interpreted a float, determining its buildProgress
    auto deathStar = [] (std::string progress) {
        std::stringstream sstr;
        sstr << progress;
        float f;
        sstr >> f;
        std::shared_ptr<DeathStar> ptr(new DeathStar(f));
        return ptr;
    };
    SpaceShipFactory::getInstance().registerSpaceShip("DeathStar", deathStar);

	// TODO: Register Destroyer
	// The string parameter has to be interpreted a int, determining the number of lasers
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.
    auto smallDestroyer = [] (std::string laserNumber) {
        std::stringstream sstr;
        sstr << laserNumber;
        int i;
        sstr >> i;
        std::shared_ptr<Destroyer> ptr(new Destroyer(false, i));
        return ptr;
    };
    SpaceShipFactory::getInstance().registerSpaceShip("Destroyer", smallDestroyer);
	// TODO: Register LargeDestroyer
	// The string parameter has to be interpreted a int, determining the number of lasers.
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.

    auto largeDestroyer = [] (std::string laserNumber) {
        std::stringstream sstr;
        sstr << laserNumber;
        int i;
        sstr >> i;
        std::shared_ptr<Destroyer> ptr(new Destroyer(true, i));
        return ptr;
    };
    SpaceShipFactory::getInstance().registerSpaceShip("LargeDestroyer", largeDestroyer);
	// Loads fleet from file
	Fleet imperialFleet("imperialships.txt");
}