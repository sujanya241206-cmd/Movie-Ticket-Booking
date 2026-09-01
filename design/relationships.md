# Relationship Analysis

The relationships are selected using the lifetime test:

- Composition: the part is owned by the whole and does not have an independent lifetime.
- Aggregation: the part can exist independently of the whole.
- Association: the objects interact, but neither object owns the other.
- Inheritance: the child is a specialized form of the parent.

| Pair | Relationship | Justification |
|---|---|---|
| Cinema — Screen | Composition | A Cinema owns its Screen objects. If the Cinema object is destroyed, its owned Screens are also destroyed. Therefore, the Screen has no independent lifetime within this design. |
| Screen — Seat | Composition | A Screen owns its physical Seat objects. If the Screen is destroyed, the Seats belonging to that Screen are also destroyed. |
| Show — Movie | Aggregation | A Show uses an existing Movie. The Movie can exist independently and can be associated with multiple Shows, so destroying a Show does not destroy the Movie. |
| Show — Screen | Aggregation | A Show uses an existing Screen for a particular screening. The Screen continues to exist after the Show ends or is destroyed. |
| Show — ShowSeat | Composition | A Show owns its ShowSeat objects, which represent the status of seats for that particular Show. If the Show is destroyed, its ShowSeats are no longer needed and are destroyed. |
| Booking — Customer | Association | A Booking is associated with a Customer, but the Customer can exist independently of the Booking. Destroying a Booking does not destroy the Customer. |
| Booking — ShowSeat | Aggregation | A Booking refers to existing ShowSeat objects. The ShowSeats belong to the Show and can exist independently of a particular Booking. Destroying a Booking does not destroy the ShowSeats. |
| Booking — Payment | Association | A Booking uses a Payment object to perform payment, but payment processing is a separate responsibility. Destroying a Booking does not imply that the payment object itself must be destroyed. |
| Payment — UpiPayment | Inheritance | UpiPayment is a specialized type of Payment and implements the Payment contract. |
| BookingService — Booking | Association | BookingService coordinates the booking process but does not own the lifetime of Booking objects. A Booking can exist independently after the service finishes the operation. |
| Customer — BookingService | Association | The Customer interacts with BookingService to perform booking operations, but neither object owns the other. |
| Payment — CardPayment | Inheritance | CardPayment is a specialized type of Payment and provides its own implementation of the payment operation. |
| Payment — CashPayment | Inheritance | CashPayment is a specialized type of Payment and provides its own implementation of the payment operation. |

## Lifetime Test Summary

### Composition
- Cinema -> Screen
- Screen -> Seat
- Show -> ShowSeat

In these relationships, the whole owns the part. If the whole is destroyed, the corresponding part is also destroyed.

### Aggregation
- Show -> Movie
- Show -> Screen
- Booking -> ShowSeat

In these relationships, the referenced object has an independent lifetime and can exist without the whole.

### Association
- Booking -> Customer
- Booking -> Payment
- BookingService -> Booking
- Customer -> BookingService

These objects interact or use one another without owning each other's lifetime.

### Inheritance
- Payment -> UpiPayment
- Payment -> CardPayment
- Payment -> CashPayment

The three payment classes are specialized implementations of the abstract Payment class.