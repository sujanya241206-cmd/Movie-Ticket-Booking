#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Show;
class ShowSeat;

class Booking {
private:
    static int nextBookingId;
    string bookingId;
    Show* show;
    vector<ShowSeat*> selectedSeats;
    double totalAmount;
    string status;

public:
    Booking(Show* show, vector<ShowSeat*> selectedSeats, double totalAmount) {
        this->show = show;
        this->selectedSeats = selectedSeats;
        this->totalAmount = totalAmount;
        this->status = "CONFIRMED";

        bookingId = "B" + to_string(nextBookingId++);
    }

    string getBookingId() {
        return bookingId;
    }

    Show* getShow() {
        return show;
    }

    vector<ShowSeat*> getSelectedSeats() {
        return selectedSeats;
    }

    double getTotalAmount() {
        return totalAmount;
    }

    string getStatus() {
        return status;
    }

    void cancel() {
        status = "CANCELLED";
    }
};

// Static member: shared booking ID counter.
int Booking::nextBookingId = 1001;