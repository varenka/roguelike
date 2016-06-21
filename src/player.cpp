#include "../include/player.h"

void Player::Update()
{
    UpdateTemperature();
    if(health <= 0)
    {
        health = 0;
        alive = false;
    }
}

double dabs(double d)
{
    if(d < 0)
        return d * -1;
    else
        return d;
}

void Player::UpdateTemperature()
{
    /* cool/warm player based on environmental temperature */
    double tempChange = (envTemp - temperature) / (insulation + BODY_INSULATION);

    if(dabs(tempChange) > INSIGNIFICANT_TEMP)
    {
        temperature += tempChange;
        cout << "Temp change: " << tempChange << endl;
    }

    /* update TemperatureState enum */
    /* < 35: hypothermic, > 40: fever */
    if(temperature < 30)
    {
        tempState = Frozen;
        health -= 3;
    }
    else if(temperature >= 30 && temperature < 32)
    {
        tempState = Frostbitten;
    }
    else if(temperature >= 32 && temperature < 35)
    {
        tempState = Hypothermic;
    }
    else if(temperature >= 35 && temperature < 36)
    {
        tempState = Cold;
    }
    else if(temperature >= 36 && temperature < 38)
    {
        tempState = Normal;
    }
    else if(temperature >= 38 && temperature < 38.5)
    {
        tempState = Warm;
    }
    else if(temperature >= 38.5 && temperature < 39)
    {
        tempState = Hot;
    }
    else if(temperature >= 39 && temperature < 43)
    {
        tempState = Fever;
    }
    else if(temperature > 43)
    {
        tempState = Burning;
        health -= 3;
    }
    else
    {
        cout << "Could not find match for temp of " << temperature << endl;
        tempState = Unknown;
    }
}

string Player::GetTemperatureMessage()
{
    switch(tempState)
    {
        case Frozen:
            return "You have frozen!";
        case Frostbitten:
            return "You are frostbitten!";
        case Hypothermic:
            return "You are hypothermic!";
        case Cold:
            return "You feel cold.";
        case Normal:
            return "You feel comfortable.";
        case Warm:
            return "You feel warm.";
        case Hot:
            return "You are too hot!";
        case Fever:
            return "You feel like you have a fever!";
        case Burning:
            return "You are burning alive!";
        case Unknown:
            return "Unknown Temp";
    };
    return "Unknown Temp";
}
