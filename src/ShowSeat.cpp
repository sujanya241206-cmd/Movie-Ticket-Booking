#include <iostream>
#include <string>
using namespace std;

class Seat;

class ShowSeat {
private:
    Seat* seat;
    string status;

public:
    ShowSeat(Seat* seat)
        : seat(seat), status("AVAILABLE") {}

    Seat* getSeat() {
        return seat;
    }

    string getStatus() {
        return status;
    }

    void setStatus(string status) {
        this->status = status;
    }

    bool isAvailable() {
        return status == "AVAILABLE";
    }
};