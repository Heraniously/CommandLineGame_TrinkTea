#ifndef HEADERS_H
#define HEADERS_H
#define MAX_NAME_LEN 20
#define DESCRIPTION_LEN 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct

typedef struct
{
    int productNumber;
    char productName[MAX_NAME_LEN];
    float price;
    int quantity;
    char description[DESCRIPTION_LEN];
} Product;

typedef struct
{
    int orderNumber;
    int productNumber;
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    char productName[MAX_NAME_LEN];
    int orderQuantity;
    float orderPrice;

} Order;

// menu.c
void displayIntro();
void displayArt();

// orders.c
void placeOrder();
void viewOrders();

// warehouse.c
void addProduct();
void displayProducts();
void searchByPrice();

// utility.c
void toLowerCase();
void updateStock();
void clearInputBuffer();

#endif