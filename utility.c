#include "headers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
utility.c inlcudes
1) toLowerCase
2) clearInputBuffer
3) getProduct
 */

extern void displayProducts();
extern Product getProduct(int productNumber);

// To Lower Case
void toLowerCase(char *str)
{
    while (*str)
    {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// Clear input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Continue reading until a newline is found or end of file is reached
    }
}

// get product detail information from the product number.
Product getProduct(int prodNum)
{
    FILE *file = fopen("products.txt", "r");
    Product product;
    char line[1024]; // Buffer to hold each line from the file

    while (fgets(line, sizeof(line), file))
    {
        // Parse the line with sscanf.
        if (sscanf(line, "%d %[^ ] %f %d \"%[^\"]\"", &product.productNumber,
                   product.productName, &product.price, &product.quantity,
                   product.description) == 5)
        {
            if (product.productNumber == prodNum)
            {
                fclose(file);
                return product; // Return the found product
            }
        }
    }
    fclose(file);
    // If no product matches, return an error indicator
    return (Product){.productNumber = -1};
}
