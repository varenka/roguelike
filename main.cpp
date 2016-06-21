#include <iostream>
#include "include/player.h"

using namespace std;

int main()
{
    Player p;
    string in;
    int i = 0;
    while(!(in == "exit"))
    {
        cout << "Ticks elapsed: " << i << endl;
        cout << "Temp: " << p.temperature << ". " << p.GetTemperatureMessage() << endl;
        p.Update();
        getline(cin, in);
        i++;
    }
    return 0;
}
