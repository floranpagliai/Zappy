#ifndef RESSOURCES_H
#define	RESSOURCES_H

#include "AObject.hpp"
#include "IRessourceManager.h"

class Ressources : public AObject {
private:
    gdl::Image texture_;
    IRessourceManager *manager_;
    int ressources_[7];
public:
    Ressources(int, int, IRessourceManager*);
    virtual ~Ressources();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void setRessources(int *);
    int *getRessources();

    void dropRessource(eRessource);
    void getRessource(eRessource);
};

#endif	/* RESSOURCES_H */

