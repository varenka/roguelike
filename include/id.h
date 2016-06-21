#ifndef ID_H
#define ID_H

/** tile id definitions **/
#define NONE 0
#define AIR 1
#define STONE 2

/** item id definitions **/
#define STICK 3
#define RED_SHIRT 4

string describe(int id)
{
    switch(id)
    {
        case AIR:
            return "Air.";
        case STONE:
            return "Stone.";
        case STICK:
            return "A small branch.";
        case RED_SHIRT:
            return "A nondescript red t-shirt.";
        default:
            return "ERROR: ITEM NOT DEFINED";
    }
}

#endif
