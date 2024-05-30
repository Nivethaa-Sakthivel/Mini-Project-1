#include <stdio.h>
#include <stdbool.h>

// Structure to represent a month
struct Month {
    char name[15];
    int days;
};

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

// Function to find the day of the week for January 1st of a given year
int findFirstDay(int year) {
    int day;
    day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day; // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
}

// Function to print the calendar for a given year
void printCalendar(int year) {
    // Define an array of Month structures representing all twelve months
    struct Month months[12] = {
        {"January", 31},
        {"February", 28 + isLeapYear(year)},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}
    };

    int firstDay = findFirstDay(year);

    // Print calendar header
    printf("\n================ Calendar for %d =================\n\n", year);

    // Loop through each month
    for (int month = 0; month < 12; month++) {
        // Print month name
        printf("------------- %s -------------\n", months[month].name);

        // Print days of the week header
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces to align the first day of the month
        for (int i = 0; i < firstDay; i++) {
            printf("     "); // 5 spaces for each day
        }

        // Print the days of the month
        for (int day = 1; day <= months[month].days; day++) {
            printf("%-5d", day); // Left-aligned day with 5 spaces
            if ((firstDay + day) % 7 == 0 || day == months[month].days) {
                printf("\n"); // Start a new line after Saturday or end of month
            }
        }

        // Calculate the starting day of the next month
        firstDay = (firstDay + months[month].days) % 7;

        printf("\n"); // Print a blank line after each month
    }
}

int main() {
    int year;

    // Input year from the user
    printf("Enter the year: ");
    scanf("%d", &year);

    // Print the calendar for the given year
    printCalendar(year);

    return 0;
}
