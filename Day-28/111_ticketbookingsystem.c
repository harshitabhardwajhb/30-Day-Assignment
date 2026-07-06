#include <stdio.h>
#include <string.h>

#define MAX_TICKETS 100

typedef struct {
    int ticketId;
    char passengerName[50];
    char destination[50];
    int seats;
    int booked;
} Ticket;

Ticket tickets[MAX_TICKETS];
int count = 0;

void readInput(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int findTicket(int ticketId) {
    for (int i = 0; i < count; i++) {
        if (tickets[i].ticketId == ticketId) {
            return i;
        }
    }
    return -1;
}

void addTicket() {
    if (count >= MAX_TICKETS) {
        printf("Ticket list is full.\n");
        return;
    }

    Ticket t;
    printf("Enter Ticket ID: ");
    scanf("%d", &t.ticketId);
    getchar();

    printf("Enter Passenger Name: ");
    readInput(t.passengerName, sizeof(t.passengerName));

    printf("Enter Destination: ");
    readInput(t.destination, sizeof(t.destination));

    printf("Enter Number of Seats: ");
    scanf("%d", &t.seats);
    getchar();

    t.booked = 1;
    tickets[count++] = t;
    printf("Ticket booked successfully!\n");
}

void displayTickets() {
    if (count == 0) {
        printf("No tickets booked yet.\n");
        return;
    }

    printf("\nBooked Tickets:\n");
    printf("ID\tPassenger\t\tDestination\t\tSeats\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s%-20s%d\n",
               tickets[i].ticketId,
               tickets[i].passengerName,
               tickets[i].destination,
               tickets[i].seats);
    }
}

void cancelTicket() {
    int id;
    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &id);
    getchar();

    int index = findTicket(id);
    if (index == -1) {
        printf("Ticket not found.\n");
    } else {
        for (int i = index; i < count - 1; i++) {
            tickets[i] = tickets[i + 1];
        }
        count--;
        printf("Ticket cancelled successfully!\n");
    }
}

void searchTicket() {
    int id;
    printf("Enter Ticket ID to search: ");
    scanf("%d", &id);
    getchar();

    int index = findTicket(id);
    if (index == -1) {
        printf("Ticket not found.\n");
    } else {
        printf("\nTicket Found:\n");
        printf("ID: %d\n", tickets[index].ticketId);
        printf("Passenger: %s\n", tickets[index].passengerName);
        printf("Destination: %s\n", tickets[index].destination);
        printf("Seats: %d\n", tickets[index].seats);
    }
}

int main() {
    int choice;

    printf("===============================\n");
    printf("Ticket Booking System\n");
    printf("===============================\n");

    do {
        printf("\n1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addTicket();
                break;
            case 2:
                displayTickets();
                break;
            case 3:
                searchTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
