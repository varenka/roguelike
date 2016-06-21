#ifndef GAME_H
#define GAME_H

#include "player.h"

using namespace std;

class Game
{
public:
    Game();
    virtual ~Game();

    Player currentPlayer;

};

#endif // GAME_H
