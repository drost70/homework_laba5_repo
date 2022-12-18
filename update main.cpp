#include "Header.h"
int main() {
    RaceHorse bucephal = RaceHorse("Bucephalus", 65.3, 3);
    RaceHorse pegasus = RaceHorse("Pegasus", 72, 6);
    RaceHorse tulpar = RaceHorse("Tulpar", 41.3, 4);
    RaceHorse sleipnir = RaceHorse("Sleipnir", 46.1, 6);

    Race race;
    race.AddHorse(bucephal);
    race.AddHorse(pegasus);
    race.AddHorse(pegasus);
    race.AddHorse(pegasus);
    race.AddHorse(tulpar);
    race.AddHorse(sleipnir);
    race.StartRace();

    print(race.getWinnerFastest());
    print(race.getWinnerClosestAge());

    race.DeleteHorse(pegasus);
    race.StartRace();
}
