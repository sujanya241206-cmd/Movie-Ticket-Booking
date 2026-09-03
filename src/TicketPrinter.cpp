#include <iostream>
#include <vector>
using namespace std;

class Show;
class ShowSeat;
class Booking;

class TicketPrinter {
public:
    void printTicket(Booking* booking) {
        cout << "\nMOVIE TICKET\n";
        cout << "Booking ID : " << booking->getBookingId() << endl;

        Show* show = booking->getShow();

        cout << "Movie      : "
             << show->getMovie()->getTitle() << endl;
        cout << "Screen     : "
             << show->getScreen()->getScreenNumber() << endl;
        cout << "Show Time  : "
             << show->getStartTime() << endl;

        cout << "Seats      : ";
        vector<ShowSeat*> seats = booking->getSelectedSeats();

        for (ShowSeat* showSeat : seats) {
            cout << showSeat->getSeat()->getSeatNumber() << " ";
        }

        cout << endl;
        cout << "Amount     : Rs. " << booking->getTotalAmount() << endl;
        cout << "Status     : " << booking->getStatus() << endl;
        cout << "Thank you! Enjoy your movie!\n";
    }
};
