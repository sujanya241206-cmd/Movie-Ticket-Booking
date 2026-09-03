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
Show* selectShow(Show* show1, Show* show2);
Booking* bookTicket(BookingService& bookingService, Customer* customer, Show* show, PriceCalculator& priceCalculator);
void cancelBooking(BookingService& bookingService, vector<Booking*>& bookings);

int main() {
    Cinema cinema("GEHU Cinema");

    Movie movie1("Interstellar", "English", 169);
    Movie movie2("3 Idiots", "Hindi", 170);

    // Composition: Screen owns these Seat objects through its seat collection.
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

    // Aggregation: a Show refers to an existing Movie and Screen.
    Show* show1 = new Show(&movie1, screen1, "10:00 AM");
    Show* show2 = new Show(&movie2, screen1, "2:00 PM");

    // Composition: each Show creates its own ShowSeat objects.
    for (Seat* seat : screen1->getSeats()) {
        show1->addShowSeat(new ShowSeat(seat));
        show2->addShowSeat(new ShowSeat(seat));
    }

    Customer customer("Customer", "9999999999");
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    BookingService bookingService(&priceCalculator, &ticketPrinter);

    // Aggregation: Booking objects keep references to ShowSeat objects.
    vector<Booking*> bookings;

    int choice;

    cout << "\nMovie Ticket Booking System\n";
    cout << "Welcome to " << cinema.getName() << "\n";

    while (true) {
        cout << "\n1. View Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Seats\n";
        cout << "4. Book Tickets\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            displayMovies(movie1, movie2);
        }
        else if (choice == 2) {
            displayShows(show1, show2);
        }
        else if (choice == 3) {
            Show* show = selectShow(show1, show2);
            if (show != nullptr) {
                displaySeats(show);
            }
        }
        else if (choice == 4) {
            Show* show = selectShow(show1, show2);
            if (show != nullptr) {
                Booking* booking = bookTicket(
                    bookingService, &customer, show, priceCalculator);
                if (booking != nullptr) {
                    bookings.push_back(booking);
                }
            }
        }
        else if (choice == 5) {
            cancelBooking(bookingService, bookings);
        }
        else if (choice == 6) {
            cout << "Thank you for using the Movie Ticket Booking System.\n";
            break;
        }
        else {
            cout << "Invalid menu choice. Please try again.\n";
        }
    }

    return 0;
}

void displayMovies(Movie& movie1, Movie& movie2) {
    cout << "\nMovies currently playing:\n";
    cout << "1. " << movie1.getTitle() << " - "
         << movie1.getLanguage() << " - "
         << movie1.getDuration() << " minutes\n";
    cout << "2. " << movie2.getTitle() << " - "
         << movie2.getLanguage() << " - "
         << movie2.getDuration() << " minutes\n";
}

void displayShows(Show* show1, Show* show2) {
    cout << "\nSelect a movie:\n";
    cout << "1. " << show1->getMovie()->getTitle() << "\n";
    cout << "2. " << show2->getMovie()->getTitle() << "\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nMovie: " << show1->getMovie()->getTitle() << "\n";
        cout << "Screen: " << show1->getScreen()->getScreenNumber() << "\n";
        cout << "Show Time: " << show1->getStartTime() << "\n";
    }
    else if (choice == 2) {
        cout << "\nMovie: " << show2->getMovie()->getTitle() << "\n";
        cout << "Screen: " << show2->getScreen()->getScreenNumber() << "\n";
        cout << "Show Time: " << show2->getStartTime() << "\n";
    }
    else {
        cout << "Invalid movie choice.\n";
    }
}

Show* selectShow(Show* show1, Show* show2) {
    cout << "\nSelect a movie:\n";
    cout << "1. " << show1->getMovie()->getTitle() << " - " << show1->getStartTime() << "\n";
    cout << "2. " << show2->getMovie()->getTitle() << " - " << show2->getStartTime() << "\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        return show1;
    }
    else if (choice == 2) {
        return show2;
    }

    cout << "Invalid movie choice.\n";
    return nullptr;
}

void displaySeats(Show* show) {
    cout << "\nSeats for " << show->getMovie()->getTitle() << ":\n";

    for (ShowSeat* showSeat : show->getShowSeats()) {
        cout << showSeat->getSeat()->getSeatNumber()
             << " - "
             << showSeat->getSeat()->getSeatType()
             << " - "
             << showSeat->getStatus() << "\n";
    }
}

Booking* bookTicket(BookingService& bookingService,
                   Customer* customer,
                   Show* show,
                   PriceCalculator& priceCalculator) {
    displaySeats(show);

    int numberOfSeats;
    cout << "\nHow many seats do you want to book? ";
    cin >> numberOfSeats;

    if (cin.fail() || numberOfSeats <= 0 || numberOfSeats > 5) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid number of seats.\n";
        return nullptr;
    }

    vector<ShowSeat*> selectedSeats;

    for (int i = 0; i < numberOfSeats; i++) {
        string seatNumber;
        cout << "Enter seat number " << i + 1 << ": ";
        cin >> seatNumber;

        ShowSeat* selectedSeat = nullptr;

        for (ShowSeat* showSeat : show->getShowSeats()) {
            if (showSeat->getSeat()->getSeatNumber() == seatNumber) {
                selectedSeat = showSeat;
                break;
            }
        }

        if (selectedSeat == nullptr) {
            cout << "Invalid seat number.\n";
            return nullptr;
        }

        if (!selectedSeat->isAvailable()) {
            cout << "Seat " << seatNumber << " is already BOOKED.\n";
            return nullptr;
        }

        for (ShowSeat* seat : selectedSeats) {
            if (seat == selectedSeat) {
                cout << "Seat " << seatNumber << " was selected twice.\n";
                return nullptr;
            }
        }

        selectedSeats.push_back(selectedSeat);
    }

    int silverSeats = 0;
    int goldSeats = 0;
    int platinumSeats = 0;

    for (ShowSeat* showSeat : selectedSeats) {
        string type = showSeat->getSeat()->getSeatType();
        if (type == "SILVER") {
            silverSeats++;
        }
        else if (type == "GOLD") {
            goldSeats++;
        }
        else if (type == "PLATINUM") {
            platinumSeats++;
        }
    }

    // Compile-time polymorphism: overloaded calculatePrice is used here.
    int total = priceCalculator.calculatePrice(
        silverSeats, goldSeats, platinumSeats);

    cout << "Total Amount: Rs. " << total << "\n";

    int paymentChoice;
    cout << "\nSelect payment method:\n";
    cout << "1. UPI\n";
    cout << "2. Card\n";
    cout << "3. Cash\n";
    cout << "Enter your choice: ";
    cin >> paymentChoice;

    Payment* payment = nullptr;

    if (paymentChoice == 1) {
        string upiId;
        cout << "Enter UPI ID (enter fail to simulate failure): ";
        cin >> upiId;
        payment = new UpiPayment(upiId);
    }
    else if (paymentChoice == 2) {
        string cardNumber;
        string cardType;
        cout << "Enter card number (enter fail to simulate failure): ";
        cin >> cardNumber;
        cout << "Enter card type: ";
        cin >> cardType;
        payment = new CardPayment(cardNumber, cardType);
    }
    else if (paymentChoice == 3) {
        double cash;
        cout << "Enter cash amount: Rs. ";
        cin >> cash;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid cash amount.\n";
            return nullptr;
        }
        payment = new CashPayment(cash);
    }
    else {
        cout << "Invalid payment choice. Booking cancelled.\n";
        return nullptr;
    }

    // Association: Customer uses BookingService to create a booking.
    Booking* booking = bookingService.createBooking(
        customer, show, selectedSeats, *payment);

    delete payment;
    return booking;
}

void cancelBooking(BookingService& bookingService,
                   vector<Booking*>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings available to cancel.\n";
        return;
    }

    string bookingId;
    cout << "\nEnter booking ID to cancel: ";
    cin >> bookingId;

    for (Booking* booking : bookings) {
        if (booking->getBookingId() == bookingId) {
            bookingService.cancelBooking(booking);
            return;
        }
    }

    cout << "Booking ID not found.\n";
}
