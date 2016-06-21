#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdlib.h>

/** all units are metric system **/

/* the range which a player's body temp can
   be without being affected by the environment temp */
#define HEALTHY_TEMP_LOW 36.4
#define HEALTHY_TEMP_HIGH 37.6

/* the default body temp */
#define BODY_TEMP 37

/* starting body insulation */
#define BODY_INSULATION 10000

/* if the temperature change value is lower than this, don't change it */
#define INSIGNIFICANT_TEMP 0.001

using namespace std;

enum TemperatureState { Unknown, Frozen, Frostbitten, Hypothermic, Cold, Normal, Warm, Hot, Fever, Burning };

class Player
{
public:
    Player() { health = 100; temperature = BODY_TEMP; insulation = 0; tempState = Normal; alive = true; envTemp = 0; }
    virtual ~Player() {}

    void Update();
    void UpdateTemperature();

    string GetTemperatureMessage();

    int health;

    double temperature;
    double insulation;
    double envTemp;

    bool alive;
    TemperatureState tempState;

};

double dabs(double d);

#endif // PLAYER_H
