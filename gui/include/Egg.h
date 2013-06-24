#ifndef EGG_H
#define	EGG_H

#include "AObject.hpp"
#include "IRessourceManager.h"

class Egg : public AObject {
private:
    gdl::Image texture_;
    IRessourceManager *manager_;

public:
    Egg(int, int, int, IRessourceManager*);
    virtual ~Egg();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* EGG_H */

