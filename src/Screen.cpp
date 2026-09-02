#include <iostream>
#include <vector>
using namespace std;

class Seat;

class Screen {
private:
    int screenNumber;
    vector<Seat*> seats;

public:
    Screen(int screenNumber)
        : screenNumber(screenNumber) {}

    int getScreenNumber() {
        return screenNumber;
    }

    void addSeat(Seat* seat) {
        seats.push_back(seat);
    }

    vector<Seat*> getSeats() {
        return seats;
    }
};