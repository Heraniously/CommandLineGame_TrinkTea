#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
order.c inlcudes
1) placeOrder
2) viewOrder
 */

// warehouse must be updated when orders are placed.
extern void displayProducts();
extern Product getProduct(int productNumber);
extern void toLowerCase();

// User can place an order.
void placeOrder()
{
    static int lastOrderNumber = 1000; // The order number starts from 1000.
    lastOrderNumber++;

    FILE *f_order = fopen("orders.txt", "a");
    printf("\n");
    displayProducts();

    Order newOrder;
    newOrder.orderNumber = lastOrderNumber;
    printf("===========================================================\n");
    printf("%c%c%c%c%c You can order products here.\n", 62, 62, 62, 62, 62);

    printf("Which product would you like? Enter the product number: ");
    scanf("%d", &newOrder.productNumber);
    printf("How many are you buying? : ");
    scanf("%d", &newOrder.orderQuantity);

    // Get product details from the product number
    Product product = getProduct(newOrder.productNumber);

    // When the product stock is not enough:
    if (product.quantity < newOrder.orderQuantity)
    {
        printf("%c%c%c%c%c Not enough stock available.\n", 62, 62, 62, 62, 62);
        fclose(f_order);
        return;
    }

    // Get Customer Name
    printf("Enter your first name: ");
    scanf("%19s", newOrder.firstName);
    toLowerCase(newOrder.firstName);
    // Converts the name to lower case.
    printf("Enter your last name: ");
    scanf("%19s", newOrder.lastName);
    toLowerCase(newOrder.lastName);
    // Converts the name to lower case.

    // Calculate the Price Sum.
    newOrder.orderPrice = product.price * newOrder.orderQuantity;
    fprintf(f_order, "%d %s %s %d %d %.2f\n", newOrder.orderNumber, newOrder.firstName, newOrder.lastName, newOrder.productNumber, newOrder.orderQuantity, newOrder.orderPrice);
    fclose(f_order);
    printf("Thank you for the order. The total price %.2f EUR is deducted from your account.\n", newOrder.orderPrice);
}

// User can view the already placed orders.
void viewOrders()
{

    char firstName[20], lastName[20];
    printf("%c%c%c%c%cEnter your name to see the order history.\n", 62, 62, 62, 62, 62);
    printf("=====================================================\n");
    printf("Enter first name: ");
    scanf("%19s", firstName);
    printf("Enter last name:");
    scanf("\n%19s", lastName);

    toLowerCase(firstName); // Makes the names to lower cases
    toLowerCase(lastName);  // Makes the names to lower cases

    FILE *f_orders = fopen("orders.txt", "r");
    char line[256];
    int found = 0;
    printf("\nOrder History for %s %s:\n", firstName, lastName);
    Order indivisualOrder;
    while (fgets(line, sizeof(line), f_orders) != NULL)
    {
        if (sscanf(line, "%d %s %s %d %d %f",
                   &indivisualOrder.orderNumber, indivisualOrder.firstName, indivisualOrder.lastName,
                   &indivisualOrder.productNumber, &indivisualOrder.orderQuantity, &indivisualOrder.orderPrice) == 6)
        {
            if (strcmp(firstName, indivisualOrder.firstName) == 0 && strcmp(lastName, indivisualOrder.lastName) == 0)
            {
                printf("Order(#%d) of %s %s is in total %.2fEUR.\n", indivisualOrder.orderNumber, firstName, lastName, indivisualOrder.orderPrice);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("%c%c%c%c%c No orders found for %s %s.\n", 62, 62, 62, 62, 62, firstName, lastName);
    }

    fclose(f_orders);
}
