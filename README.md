# Movie Ticket Booking System

System Design Assignment 1 - Movie Ticket Booking System

## Project

This is a menu-driven C++ console application for booking movie tickets in a single cinema.

## Features

- View movies currently playing
- View shows for each movie
- View seat type and availability
- Book one or more seats
- Reject already-booked or invalid seats
- Calculate Silver, Gold and Platinum prices
- Pay using UPI, Card or Cash
- Demonstrate failed payment without confirming a booking
- Print a ticket after successful payment
- Cancel a booking and make its seats available again

## Prices

- SILVER: Rs. 150
- GOLD: Rs. 250
- PLATINUM: Rs. 400

## File Structure

`m.cpp` is the main program. Each class is kept in a separate `.cpp` file inside `src/`, as required by the assignment. No header files are used.

## Compile and Run

Open the terminal in the project folder and run:

```text
g++ m.cpp -o movie
.\movie.exe
```

## Payment Failure Test

For UPI or Card, entering `fail` makes the payment fail. The booking is not confirmed and the selected seats remain available.

For Cash, entering an amount smaller than the total makes the payment fail.

## OOP Concepts Used

- Encapsulation through private class data and public methods
- Abstraction through the abstract `Payment` class
- Inheritance through UPI, Card and Cash payment classes
- Runtime polymorphism through `Payment*` and the virtual `pay()` method
- Compile-time polymorphism through overloaded `calculatePrice()` methods
- Static member for generating booking IDs
- `this` keyword in class constructors and methods
- Composition: Cinema-Screen, Screen-Seat and Show-ShowSeat relationships
- Aggregation: Show-Movie and Booking-ShowSeat relationships
- Association: Customer and BookingService

## SOLID Mapping

- Single Responsibility: BookingService coordinates booking, while PriceCalculator and TicketPrinter handle separate responsibilities.
- Open/Closed: a new payment method can be added as another `Payment` subclass.
- Liskov Substitution: UPI, Card and Cash can be used through the `Payment` interface.
- Dependency Inversion: BookingService receives a `Payment&` instead of creating a specific payment class.
- Interface Segregation is not separately implemented because this small console project does not need multiple large interfaces. No artificial interface was added just to force the principle.

## Deliberately Not Implemented

Refund processing is deliberately not implemented because it is outside the required assignment features. Cancellation only releases the seats and changes the booking status.
