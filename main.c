#include <stdio.h>
#include "headers.h"
#include <unistd.h>

// Placeholder for other includes and function declarations

void displayArt();
void displayIntro();
void viewOrders();
void placeOrder();
void addProduct();
void searchProducts();

int main()
{
    displayArt();
    int choice;
    while (choice != 5)
    {
        // Intro
        displayIntro();

        // Menu
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            displayProducts();
            break;
        case 1:
            placeOrder();
            updateStock();
            break;
        case 2:
            viewOrders();
            break;
        case 3:
            addProduct();
            break;
        case 4:
            int minPrice, maxPrice;
            printf("Let's find products within your budget! \n\n");
            printf("Enter minimum price (EUR): ");
            scanf("%d", &minPrice);
            printf("Enter maximum price (EUR): ");
            scanf("%d", &maxPrice);
            printf("\n");
            searchByPrice(minPrice, maxPrice);
            break;
        case 5:
            printf("Thank you for visiting TRINK TEA. We hope to see you again!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        usleep(1500000); // 500000 microseconds = 0.5 seconds
    }
    return 0;
}