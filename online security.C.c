#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Caesar Cipher encryption
void encrypt(char *data, int shift) {
    for (int i = 0; data[i] != '\0'; i++) {
        if (isalpha(data[i])) {
            char offset = isupper(data[i]) ? 'A' : 'a';
            data[i] = (data[i] - offset + shift) % 26 + offset;
        } else if (isdigit(data[i])) {
            data[i] = (data[i] - '0' + shift) % 10 + '0';
        }
    }
}

// Function to validate the card number
int validate_card_number(const char *card_number) {
    int length = strlen(card_number);
    if (length != 16) {
        return 0; // Invalid if the card number is not 16 digits
    }
    for (int i = 0; i < length; i++) {
        if (!isdigit(card_number[i])) {
            return 0; // Invalid if it contains non-digit characters
        }
    }
    return 1; // Card number is valid
}

// Function to validate the CVV (3 digits)
int validate_cvv(const char *cvv) {
    int length = strlen(cvv);
    if (length != 3) {
        return 0; // Invalid if the CVV is not 3 digits
    }
    for (int i = 0; i < length; i++) {
        if (!isdigit(cvv[i])) {
            return 0; // Invalid if it contains non-digit characters
        }
    }
    return 1; // CVV is valid
}

// Function to process payment
void process_payment(char *name, char *card_number, char *exp_date, char *cvv) {
    // Validate the card number and CVV
    if (!validate_card_number(card_number)) {
        printf("Error: Invalid card number!\n");
        return;
    }
    if (!validate_cvv(cvv)) {
        printf("Error: Invalid CVV!\n");
        return;
    }

    // Encrypt sensitive data (Card Number and CVV)
    encrypt(card_number, 3);  // Simple Caesar Cipher with shift 3
    encrypt(cvv, 3);

    // Simulate storing or processing the data (just print it here)
    printf("\nProcessing payment for %s...\n", name);
    printf("Encrypted Card Number: %s\n", card_number);
    printf("Encrypted CVV: %s\n", cvv);

    // Mock transaction success
    printf("Payment successful!\n");
}

int main() {
    char name[50];
    char card_number[17]; // 16 digits + null terminator
    char exp_date[6];     // Format MM/YY
    char cvv[4];          // 3 digits + null terminator

    printf("Welcome to the Online Payment System\n\n");

    // Get user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character from input

    printf("Enter your 16-digit card number: ");
    fgets(card_number, sizeof(card_number), stdin);
    card_number[strcspn(card_number, "\n")] = 0; // Remove newline character

    printf("Enter your card's expiration date (MM/YY): ");
    fgets(exp_date, sizeof(exp_date), stdin);
    exp_date[strcspn(exp_date, "\n")] = 0; // Remove newline character

    printf("Enter your 3-digit CVV: ");
    fgets(cvv, sizeof(cvv), stdin);
    cvv[strcspn(cvv, "\n")] = 0; // Remove newline character

    // Process the payment
    process_payment(name, card_number, exp_date, cvv);

    return 0;
}