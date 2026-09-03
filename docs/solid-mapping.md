# SOLID Principle Mapping

## 1. Single Responsibility Principle (SRP)

Each class has a focused responsibility.

- `Movie` stores movie details.
- `Seat` stores seat details.
- `ShowSeat` stores the status of a seat for a particular show.
- `Booking` stores booking information and status.
- `PriceCalculator` calculates ticket prices.
- `TicketPrinter` prints tickets.
- `BookingService` coordinates booking and cancellation.
- Payment classes handle their own payment method.

## 2. Open/Closed Principle (OCP)

`Payment` is an abstract base class. UPI, Card and Cash are separate subclasses. A new method such as `NetBankingPayment` can be added by creating another subclass without changing the booking logic.

## 3. Liskov Substitution Principle (LSP)

`UpiPayment`, `CardPayment` and `CashPayment` implement the `Payment` interface. The booking service can work with a `Payment&` without depending on a particular payment class.

## 4. Dependency Inversion Principle (DIP)

`BookingService` receives a `Payment&` from the caller instead of creating a UPI, Card or Cash payment object itself.

## 5. Interface Segregation Principle (ISP)

ISP is not separately applied in this small console application because there is no need for several large interfaces. An artificial interface structure was deliberately avoided.

## Deliberately Not Done

Refund processing is deliberately not implemented because it is not one of the required features. Cancellation releases the seats and changes the booking status, but does not perform a refund.
