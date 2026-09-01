# Requirement Analysis

## Functional Requirements

### FR1 - List Movies
The system shall display all movies currently playing in the cinema when the customer selects the "View Movies" option.

### FR2 - List Shows
The system shall display all available shows for a selected movie, including the screen number and show start time.

### FR3 - Display Seat Availability
The system shall display the seat layout for a selected show and identify each seat as either AVAILABLE or BOOKED.

### FR4 - Book Seats
The system shall allow the customer to select one or more available seats for a show and shall reject any seat that is already BOOKED.

### FR5 - Calculate Booking Price
The system shall calculate the total booking amount according to the selected seat types:
- SILVER: ₹150 per seat
- GOLD: ₹250 per seat
- PLATINUM: ₹400 per seat

### FR6 - Make Payment
The system shall support payment through UPI, Card, or Cash. If the payment fails, the booking shall not be confirmed and the selected seats shall be released.

### FR7 - Print Ticket
The system shall print a ticket containing the booking ID, movie name, screen number, show time, selected seat numbers, and total amount.

### FR8 - Cancel Booking
The system shall allow a customer to cancel a confirmed booking, after which all seats belonging to that booking shall become AVAILABLE again.

---

## Non-Functional Requirements

### NFR1 - Modularity
The system shall be modular, with each major class implemented in a separate source file so that individual components can be modified without unnecessarily affecting other components.

### NFR2 - Extensibility
The payment system shall allow a new payment method to be added by creating a new payment class without modifying the existing booking flow.

### NFR3 - Input Validation
The system shall validate menu choices, seat numbers, and booking-related input and display a clear error message for invalid input without crashing.

### NFR4 - Maintainability
Each function shall perform a single well-defined task, and the code shall use meaningful names and avoid unnecessary duplication.
