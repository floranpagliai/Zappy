#ifndef IRessourceManager_H
#define	IRessourceManager_H

#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include "Image.hpp"

enum e_Ressource {
    GROUND,
    FEUILLE,
    TREE,
    TRANTORIEN
};

struct t_Ressource {
    e_Ressource name;
    gdl::Image image;
};

class IRessourceManager {
public:
    IRessourceManager();
    virtual ~IRessourceManager();

    gdl::Image getRessource(e_Ressource);
};

#endif	/* IRessourceManager_H */

