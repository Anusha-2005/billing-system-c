#include <stdio.h>
#include <stdlib.h>
void displayMenu();
float calculateTotal(float amount);
void displayBillNotification(float amount);
void sendNotificationByEmail(float amount, char *email);
void sendNotificationBySMS(float amount, char *phoneNumber);
void saveBillToFile(float amount, char *filename);
void loadBillFromFile(char *filename);
void printReceipt(float amount);
void displayMenu() {
    printf("1. Enter bill amount\n");
    printf("2. Load bill from file\n");
    printf("3. Save bill to file\n");
    printf("4. Print receipt\n");
    printf("5. Exit\n");
}
float calculateTotal(float amount) {
    return amount;
}
void displayBillNotification(float amount) {
    printf("Dear customer, your bill amount is $%.2f.\n", amount);
}
void sendNotificationByEmail(float amount, char *email) {
    printf("Sending email notification to: %s\n", email);
}
void sendNotificationBySMS(float amount, char *phoneNumber) {
    printf("Sending SMS notification to: %s\n", phoneNumber);
}
void saveBillToFile(float amount, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%.2f", amount);
        fclose(file);
        printf("Bill saved to file.\n");
    } else {
        printf("Error: Unable to save bill to file.\n");
    }
}
void loadBillFromFile(char *filename) {
    float amount;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fscanf(file, "%f", &amount);
        fclose(file);
        printf("Bill loaded from file: $%.2f\n", amount);
    } else {
        printf("Error: Unable to load bill from file.\n");
    }
}
void printReceipt(float amount) {
    printf("********** Receipt **********\n");
    printf("Total amount: $%.2f\n", amount);
    printf("Thank you for your purchase!\n");
    printf("****************************\n");
}
int main() {
    float billAmount;
    char email[50];
    char phoneNumber[15];
    char filename[50];
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your bill amount: ");
                scanf("%f", &billAmount);
                billAmount = calculateTotal(billAmount);
                displayBillNotification(billAmount);
                printf("Enter your email address: ");
                scanf("%s", email);
                sendNotificationByEmail(billAmount, email);
                printf("Enter your phone number: ");
                scanf("%s", phoneNumber);
                sendNotificationBySMS(billAmount, phoneNumber);
                break;
            case 2:
                printf("Enter filename to load bill from: ");
                scanf("%s", filename);
                loadBillFromFile(filename);
                break;
            case 3:
                printf("Enter filename to save bill to: ");
                scanf("%s", filename);
                saveBillToFile(billAmount, filename);
                break;
            case 4:
                printReceipt(billAmount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
