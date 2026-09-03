#include <iostream>
#include <vector>
using namespace std;

class Show;
class ShowSeat;
class Booking;
class Customer;
class Payment;
class PriceCalculator;
class TicketPrinter;

class BookingService {
private:
    PriceCalculator* priceCalculator;
    TicketPrinter* ticketPrinter;

public:
    BookingService(PriceCalculator* priceCalculator,
                   TicketPrinter* ticketPrinter) {
        this->priceCalculator = priceCalculator;
        this->ticketPrinter = ticketPrinter;
    }

    Booking* createBooking(Customer* customer,
                           Show* show,
                           vector<ShowSeat*> selectedSeats,
                           Payment& payment) {
        if (selectedSeats.empty()) {
            cout << "No seats selected." << endl;
            return nullptr;
        }

        for (ShowSeat* showSeat : selectedSeats) {
            if (!showSeat->isAvailable()) {
                cout << "Seat "
                     << showSeat->getSeat()->getSeatNumber()
                     << " is already BOOKED." << endl;
                return nullptr;
            }
        }

        double totalAmount = 0;

        for (ShowSeat* showSeat : selectedSeats) {
            totalAmount += priceCalculator->calculatePrice(
                showSeat->getSeat()->getSeatType());
        }

        cout << "\nTotal Amount: Rs. " << totalAmount << endl;

        // Dependency inversion: BookingService receives Payment through the base type.
        bool paymentSuccessful = payment.pay(totalAmount);

        if (!paymentSuccessful) {
            cout << "Booking failed. Seats remain AVAILABLE." << endl;
            return nullptr;
        }

        Booking* booking =
            new Booking(show, selectedSeats, totalAmount);

        for (ShowSeat* showSeat : selectedSeats) {
            showSeat->setStatus("BOOKED");
        }

        cout << "\nBooking confirmed successfully!" << endl;
        ticketPrinter->printTicket(booking);

        return booking;
    }

    void cancelBooking(Booking* booking) {
        if (booking == nullptr) {
            cout << "Invalid booking." << endl;
            return;
        }

        if (booking->getStatus() == "CANCELLED") {
            cout << "Booking is already cancelled." << endl;
            return;
        }

        vector<ShowSeat*> seats = booking->getSelectedSeats();

        for (ShowSeat* showSeat : seats) {
            showSeat->setStatus("AVAILABLE");
        }

        booking->cancel();

        cout << "Booking "
             << booking->getBookingId()
             << " cancelled successfully." << endl;
        cout << "Seats are AVAILABLE again." << endl;
    }
};
