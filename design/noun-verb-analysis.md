# Noun-Verb Analysis

## Problem Statement Analysis

The problem statement describes a movie ticket booking system for a single cinema. 
The main nouns represent entities or concepts in the system, while the verbs represent 
actions or behaviours that can become methods or operations.

### Nouns Identified

| Noun | Keep as Class? | Reason |
|---|---|---|
| Cinema | Yes | Represents the theatre and owns its screens. |
| Movie | Yes | Has its own identity and data such as title, language and duration. |
| Show | Yes | Represents a particular screening of a movie on a screen at a specific time. |
| Screen | Yes | Represents an auditorium and owns its physical seats. |
| Seat | Yes | Represents one physical seat with a number and seat type. |
| ShowSeat | Yes | Represents the status of one physical seat for one particular show. |
| Customer | Yes | Represents the customer making a booking and stores customer information. |
| Booking | Yes | Represents a customer's reservation and contains booking details. |
| Payment | Yes | Represents the payment contract and is implemented through different payment methods. |
| UpiPayment | Yes | Represents payment using UPI. |
| CardPayment | Yes | Represents payment using a card. |
| CashPayment | Yes | Represents payment using cash. |
| PriceCalculator | Yes | Performs the calculation of the total booking price. |
| TicketPrinter | Yes | Handles formatting and printing of tickets. |
| BookingService | Yes | Coordinates the complete ticket booking process. |
| Seat layout | No | It is a view of the seats belonging to a Show, not an independent entity. |
| Ticket | No | The assignment only requires ticket printing; ticket information can be produced from a Booking. |
| Menu | No | It is part of the console interface and does not require independent entity data. |
| Payment method | No | It is represented through the Payment hierarchy and its subclasses. |

---

## Verbs Identified

| Verb / Action | Possible Method or Responsibility |
|---|---|
| see / display movies | listMovies() |
| pick a show | selectShow() |
| list shows | listShows() |
| display seats | displaySeats() |
| book seats | bookSeats() |
| reject booked seat | validateSeatAvailability() |
| calculate price | calculateTotal() |
| pay | pay() |
| confirm booking | confirmBooking() |
| print ticket | printTicket() |
| cancel booking | cancelBooking() |
| release seats | releaseSeats() |
| validate input | validateInput() |

---

## Design Observation

The noun-verb analysis helps separate **data/entities** from **behaviour**.

The main entity classes represent things that have their own identity and state,
while service classes perform operations on those entities. For example, a `Seat`
stores its number and type, while `PriceCalculator` performs the price calculation.

Some nouns are deliberately rejected as classes because they are better represented
as a responsibility, view, or part of another class. For example, "seat layout" is
a view of a show's seats and therefore does not need an independent class.
