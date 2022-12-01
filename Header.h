#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <math.h> 

using namespace std;

class RaceHorse {
private:
    string name;
    int age;
    double speed;
    int placeInRace;
public:
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    double getSpeed() const {
        return speed;
    }
    void setPlace(int place) {
        placeInRace = place;
    }
    double getPlace() const {
        return placeInRace;
    }
    RaceHorse(string name, double speed, int age) :name(name), speed(speed), age(age) {};
};

void print(RaceHorse horse) {
    cout << "Name: " << horse.getName() << " age: " << horse.getAge() << " speed: " << horse.getSpeed() << endl;
}

bool operator == (const RaceHorse& h1, const RaceHorse& h2) {
    return h1.getName() == h2.getName() && h1.getAge() == h2.getAge() && h1.getSpeed() == h2.getSpeed();
}

bool cmp_speed(RaceHorse h1, RaceHorse h2) {
    if (h1.getSpeed() == h2.getSpeed()) {
        if (h1.getAge() == h2.getAge()) {
            return h1.getName() > h2.getName();
        }
        return h1.getAge() > h2.getAge();
    }
    return h1.getSpeed() > h2.getSpeed();
}
class Race {
private:
    vector<RaceHorse> horses;
    //first comes a horse who is faster. If two horses have an equal speed, younger one wins. If they are the same age, the one whose name comes first alphabeticaly - wins; 

public:

    int numOfHorses() {
        return horses.size();
    }
    //true if you can add a horse and false if you cant 
    bool addHorse(RaceHorse horse) {
        int age = horse.getAge();
        if (3 <= age && age <= 7) {
            horses.push_back(horse);
            return 1;
        }
        else {
            cout << "Can't add horse: " << horse.getAge() << endl;
            return 0;
        }
    }

    void deleteHorse(RaceHorse horse) {
        horses.erase(remove(horses.begin(), horses.end(), horse), horses.end());
    }

    void startRace() {

        sort(horses.begin(), horses.end(), cmp_speed);
        if (horses.size() > 0) { cout << "1-st: " << horses[0].getName() << endl; horses[0].setPlace(1); }
        if (horses.size() > 1) { cout << "2-nd: " << horses[1].getName() << endl; horses[1].setPlace(2); }
        if (horses.size() > 2) { cout << "3-rd: " << horses[2].getName() << endl; horses[2].setPlace(3); }
        for (int i = 3; i < horses.size(); i++) {
            cout << i + 1 << "-th: " << horses[i].getName() << endl;
            //we can give each horse a place 
            horses[i].setPlace(i + 1);
            //or we can just do this 
            //horses[i].setPlace(0); 
        }
    }
    RaceHorse getWinnerFastest() {
        sort(horses.begin(), horses.end(), cmp_speed);
        return horses[0];
    }
    RaceHorse getWinnerClosestAge() {
        double average = 0, min = 1000000000;
        int id;
        for (int i = 0; i < horses.size(); i++) {
            average += horses[i].getAge();
        }
        average /= horses.size();
        for (int i = 0; i < horses.size(); i++) {
            if (fabs(horses[i].getAge() - average) < min) {
                min = fabs(horses[i].getAge() - average);
                id = i;
            }
        }
        return horses[id];
    }

};