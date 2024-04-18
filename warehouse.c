#include "headers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/*
warehouse.c inlcudes
1) displayProducts
2) updateStock
3) addProduct
4) searchProducts.
 */

void displayProducts()
{

    char line[256];
    int productNumber;
    char productName[20];
    float price;
    int quantity;
    char description[200];

    // Display table

    printf("%-12s%-20s%-15s%-10s%s\n", "Product No.", "Product Name", "Price (EUR)", "Quantity", "Description");

    FILE *file = fopen("products.txt", "r");
    while (fgets(line, sizeof(line), file)) // while the line exists, visit each line.
    {
        if (sscanf(line, "%d %[^ ] %f %d \"%[^\"]\"", &productNumber, productName, &price, &quantity, description) == 5)
        {
            printf("%-12d%-20s%-15.2f%-10d%s\n", productNumber, productName, price, quantity, description);
        }
    }
    printf("\n");
    fclose(file);
}

void updateStock()
{
    //  the rest quantity of the product decreases in products.txt.
    char line[256];
    Order lastOrder;
    FILE *f_orders = fopen("orders.txt", "r");

    // Take the last order info from orders.txt
    while (fgets(line, sizeof(line), f_orders))
    {
        sscanf(line, "%d %s %s %d %d %f",
               &lastOrder.orderNumber, lastOrder.firstName, lastOrder.lastName,
               &lastOrder.productNumber, &lastOrder.orderQuantity, &lastOrder.orderPrice);
    }
    fclose(f_orders);

    // deduct the quantity of first line product
    FILE *f_products = fopen("products.txt", "r");
    Product stockProduct[20];
    int numProducts = 0;
    while (fgets(line, sizeof(line), f_products) != NULL)
    {
        sscanf(line, "%d %[^ ] %f %d %[^\n]", &stockProduct[numProducts].productNumber, stockProduct[numProducts].productName, &stockProduct[numProducts].price,
               &stockProduct[numProducts].quantity, stockProduct[numProducts].description);
        if (stockProduct[numProducts].productNumber == lastOrder.productNumber)
        {
            stockProduct[numProducts].quantity -= lastOrder.orderQuantity; // Update quantity
        }
        numProducts++;
    }
    fclose(f_products);

    FILE *f_update = fopen("products.txt", "w");
    for (int i = 0; i < numProducts; i++)
    {
        fprintf(f_update, "%d %s %.2f %d %s\n", stockProduct[i].productNumber,
                stockProduct[i].productName, stockProduct[i].price, stockProduct[i].quantity, stockProduct[i].description);
    }
    fclose(f_update);
}

void addProduct()
{
    char firstName[MAX_NAME_LEN], lastName[MAX_NAME_LEN];
    printf("=====================================================\n");
    printf("Only administrators are allowed to add products.\nMake sure you know the login credential of administrators.\n\n");
    printf("%c%c%c%c%c Enter your admin login information.\n", 62, 62, 62, 62, 62);
    printf("Admin id: ");
    scanf("%s", firstName);
    printf("Admin pw: ");
    scanf("%s", lastName);
    toLowerCase(firstName);
    toLowerCase(lastName);

    if (strcmp(firstName, "admin") == 0 && strcmp(lastName, "admin") == 0)
    {
        Product newProduct;
        printf("What is the name of the product? (less than 20 letters, no empty space allowed in the name)\n");
        scanf("%s", newProduct.productName);
        clearInputBuffer();
        printf("How much do you charge for it? \n");
        scanf("%f", &newProduct.price);
        clearInputBuffer();
        printf("How many do you want to add? \n");
        scanf("%d", &newProduct.quantity);
        clearInputBuffer();
        printf("Describe the product (less than 100 letters): ");
        scanf(" %[^\n]", newProduct.description);
        clearInputBuffer();

        // Read the last product number from products.txt
        FILE *f_products = fopen("products.txt", "r");
        char line[256];

        while (fgets(line, sizeof(line), f_products)) // while the line exists, visit each line.
        {
            Product lastProduct;
            if (sscanf(line, "%d %[^ ] %f %d \"%[^\"]\"",
                       &lastProduct.productNumber, lastProduct.productName, &lastProduct.price, &lastProduct.quantity, lastProduct.description) == 5)
            {
                newProduct.productNumber = lastProduct.productNumber + 1;
            }
        }

        fclose(f_products);

        // Append the new product information in products.txt
        FILE *f_append = fopen("products.txt", "a");
        fprintf(f_append, "%d %s %.2f %d \"%s\"\n", newProduct.productNumber, newProduct.productName, newProduct.price, newProduct.quantity, newProduct.description);
        fclose(f_append);

        printf("Product added successfully! It is ready to be sold! \n");
    }
    else
    {
        printf("%c%c%c%c%c Access denied. Only admins can add products.\n%c%c%c%c%c Please study the README text file to find admin login information. :) \n", 62, 62, 62, 62, 62, 62, 62, 62, 62, 62);
    }
}

void searchByPrice(int minPrice, int maxPrice)
{

    FILE *file = fopen("products.txt", "r");
    char line[256];
    Product product;
    int found = 0;
    printf("\n%c%c%c%c%cProducts priced between %d EUR and %d EUR:\n", 62, 62, 62, 62, 62, minPrice, maxPrice);

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%d %[^ ] %f %d \"%[^\"]\"",
                   &product.productNumber, product.productName, &product.price, &product.quantity, product.description) == 5)
        {
            if (product.price >= minPrice && product.price <= maxPrice)
            {
                printf("Our %s(Prod. No: %d) is $%.2f EUR and %d of them are curretnly available.\n", product.productName, product.productNumber, product.price, product.quantity);

                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("Sorry, there is no product at this price range.\n\n");
    }

    fclose(file);
}