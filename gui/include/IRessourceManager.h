#ifndef IRessourceManager_H
#define	IRessourceManager_H

#include "AObject.hpp"

struct t_Ressource {
    eType name;
    gdl::Image image;
};

class IRessourceManager {
public:
    IRessourceManager();
    virtual ~IRessourceManager();

    gdl::Image getRessource(eType);
};

#endif	/* IRessourceManager_H */

