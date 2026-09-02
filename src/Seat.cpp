#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    string seatType;

public:
    Seat(string seatNumber, string seatType)
        : seatNumber(seatNumber), seatType(seatType) {}

    string getSeatNumber() {
        return seatNumber;
    }

    string getSeatType() {
        return seatType;
    }
};