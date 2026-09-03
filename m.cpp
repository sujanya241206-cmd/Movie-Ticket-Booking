#include <iostream>
#include <vector>
#include <string>
using namespace std;

// No header files are used, as required by the assignment.

#include "src/Payment.cpp"
#include "src/Movie.cpp"
#include "src/Seat.cpp"
#include "src/Screen.cpp"
#include "src/ShowSeat.cpp"
#include "src/Show.cpp"
#include "src/Cinema.cpp"
#include "src/Customer.cpp"
#include "src/Booking.cpp"
#include "src/PriceCalculator.cpp"
#include "src/UpiPayment.cpp"
#include "src/CardPayment.cpp"
#include "src/CashPayment.cpp"
#include "src/TicketPrinter.cpp"
#include "src/BookingService.cpp"


void displayMovies(Movie& movie1, Movie& movie2);
void displayShows(Show* show1, Show* show2);
void displaySeats(Show* show);


int main() {
    Cinema cinema("GEHU Cinema");

    Movie movie1("Interstellar", "English", 169);
    Movie movie2("3 Idiots", "Hindi", 170);

    Seat* a1 = new Seat("A1", "SILVER");
    Seat* a2 = new Seat("A2", "SILVER");
    Seat* a3 = new Seat("A3", "GOLD");
    Seat* a4 = new Seat("A4", "GOLD");
    Seat* a5 = new Seat("A5", "PLATINUM");

    Screen* screen1 = new Screen(1);

    screen1->addSeat(a1);
    screen1->addSeat(a2);
    screen1->addSeat(a3);
    screen1->addSeat(a4);
    screen1->addSeat(a5);

    cinema.addScreen(screen1);

    Show* show1 = new Show(&movie1, screen1, "10:00 AM");
    Show* show2 = new Show(&movie2, screen1, "2:00 PM");

    for (Seat* seat : screen1->getSeats()) {
        show1->addShowSeat(new ShowSeat(seat));
        show2->addShowSeat(new ShowSeat(seat));
    }

    Customer customer("Customer", "9999999999");

    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

    BookingService bookingService(&priceCalculator, &ticketPrinter);

    cout << "\nMovie Ticket Booking System\n";
    cout << "Welcome to " << cinema.getName() << "\n\n";

    cout << "1. View Movies\n";
    cout << "2. View Shows\n";
    cout << "3. View Seats\n";
    cout << "4. Book Tickets\n";
    cout << "5. Cancel Booking\n";
    cout << "6. Exit\n";

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
    displayMovies(movie1, movie2);
    }
    else if (choice == 2) {
    displayShows(show1, show2);
    }
    else if (choice == 3) {
    displaySeats(show1);
    }

    return 0;
}


void displayMovies(Movie& movie1, Movie& movie2) {
    cout << "\nMovies currently playing:\n";
    cout << "1. " << movie1.getTitle() << endl;
    cout << "2. " << movie2.getTitle() << endl;
}

void displayShows(Show* show1, Show* show2) {
    cout << "\nSelect a movie:\n";
    cout << "1. " << show1->getMovie()->getTitle() << endl;
    cout << "2. " << show2->getMovie()->getTitle() << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nMovie: " << show1->getMovie()->getTitle() << endl;
        cout << "Screen: " << show1->getScreen()->getScreenNumber() << endl;
        cout << "Show Time: " << show1->getStartTime() << endl;
    }
    else if (choice == 2) {
        cout << "\nMovie: " << show2->getMovie()->getTitle() << endl;
        cout << "Screen: " << show2->getScreen()->getScreenNumber() << endl;
        cout << "Show Time: " << show2->getStartTime() << endl;
    }
    else {
        cout << "Invalid movie choice." << endl;
    }
}

void displaySeats(Show* show) {
    cout << "\nSeats for " << show->getMovie()->getTitle() << ":\n";

    for (ShowSeat* showSeat : show->getShowSeats()) {
        cout << showSeat->getSeat()->getSeatNumber()
             << " - "
             << showSeat->getSeat()->getSeatType()
             << " - "
             << showSeat->getStatus()
             << endl;
    }
}