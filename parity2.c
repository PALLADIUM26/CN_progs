#include <stdio.h>
#include <string.h>

int main() {
    char received_binary[100];
    int i, count = 0;
    char parity_choice;

    // Input received binary number as a string
    printf("Enter the received binary number (with parity bit): ");
    scanf("%s", received_binary);

    // Ask the user for parity type
    printf("Choose parity even (e) or odd (o): ");
    scanf(" %c", &parity_choice);  // Added space before %c to consume the newline character

    // Count number of 1s in the received binary string
    for (i = 0; i < strlen(received_binary); i++) {
        if (received_binary[i] == '1') {
            count++;
        }
    }

    // Check parity
    if (parity_choice == 'e') {
        // Even parity
        if (count % 2 == 0) {
            printf("No error detected.\n");
        } else {
            printf("Error detected in the received data.\n");
        }
    } else if (parity_choice == 'o') {
        // Odd parity
        if (count % 2 == 1) {
            printf("No error detected.\n");
        } else {
            printf("Error detected in the received data.\n");
        }
    } else {
        printf("Invalid parity choice!\n");
        return 1;
    }

    return 0;
}