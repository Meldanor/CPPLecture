#include "SpaceShipFactory.h"

// If SpaceShips.h would be not included, the SpaceShip's destructor would be unknown.
// This leads normally to a warning
#include "SpaceShips.h"

#include <cstddef>


void SpaceShipFactory::registerSpaceShip(const std::string& spaceShipTypeName, const CreateSpaceShipFunc& createSpaceShipFunc) {
    std::pair<std::string,CreateSpaceShipFunc> tmp (spaceShipTypeName, createSpaceShipFunc);
    m_createSpaceShipFuncRegister.insert(tmp);
}

std::shared_ptr<SpaceShip> SpaceShipFactory::buildSpaceShip(const std::string& spaceShipTypeName, const std::string& parameter) {
    std::unordered_map<std::string,CreateSpaceShipFunc>::const_iterator got = m_createSpaceShipFuncRegister.find(spaceShipTypeName);
    if (got == m_createSpaceShipFuncRegister.end())
        return 0;
    else {
        auto func = got->second;
        return func(parameter);
    }
  
}