#include "Fleet.h"
#include "SpaceShipFactory.h"

#include <fstream>
#include <assert.h>
#include <sstream>

Fleet::Fleet(const std::string& fleetFilename) {

    std::ifstream myfile;
    myfile.open(fleetFilename);
    std::string line;
    while(myfile.good()) {
        getline(myfile,line);
        std::istringstream tmp(line);
        std::string s1;
        std::string s2;
        getline(tmp,s1,' ');
        getline(tmp,s2,' ');
        auto spaceShip = SpaceShipFactory::getInstance().buildSpaceShip(s1,s2);
        m_spaceShips.push_back(spaceShip);
    }
    myfile.close();

}