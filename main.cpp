#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <math.h> 
#include "Header.h"

using namespace std;

int main() {
    RaceHorse bucephal = RaceHorse("Bucephalus", 65.3, 3);
    RaceHorse pegasus = RaceHorse("Pegasus", 72, 6);
    RaceHorse tulpar = RaceHorse("Tulpar", 41.3, 4);
    RaceHorse sleipnir = RaceHorse("Sleipnir", 46.1, 6);

    Race race;
    race.addHorse(bucephal);
    race.addHorse(pegasus);
    race.addHorse(tulpar);
    race.addHorse(sleipnir);
    race.startRace();

    print(race.getWinnerFastest());
    print(race.getWinnerClosestAge());

    race.deleteHorse(pegasus);
    race.startRace();
}