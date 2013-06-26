#ifndef PLAYER_H
#define	PLAYER_H

#include "AObject.hpp"
#include "IRessourceManager.h"

struct t_Dir {
    eDir dir;
    int idle;
    int min;
    int max;
};

class Player : public AObject {
private:
    gdl::Image texture_;
    gdl::Model model_;
    IRessourceManager *manager_;
    eDir dir_;
    int lvl_;
    bool isMoving_;
    int posAnim_;

public:
    Player(int, int, int, eDir, int, IRessourceManager *);
    virtual ~Player(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void setLvl(int);
    void setDir(eDir);

    int getLvl(void) const;
};

#endif	/* Player_H */

