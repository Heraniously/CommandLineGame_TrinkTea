#include <stdio.h>
#include <stdbool.h>
#include "headers.h"

/*
menu.c inlcudes
1) displayArt
2) displayIntro
 */

void displayArt() // Pixel Art
{
    printf("======================================================\n");
    printf("|  _____ ____  ___ _   _ _  __  _____ _____    _     |\n");
    printf("| |_   _|  _ \\|_ _| \\ | | |/ / |_   _| ____|  / \\    |\n");
    printf("|   | | | |_/ || ||  \\| | \' /    | | |  _|   / _ \\   |\n");
    printf("|   | | |  _ < | || |\\  | . \\    | | | |___ / ___ \\  |\n");
    printf("|   |_| |_| \\_\\___|_| \\_|_|\\_\\   |_| |_____/_/   \\_\\ |\n");
    printf("| \t\t\t\t\t\t     | \n");
    printf("======================================================\n");
}

void displayIntro() // User's choices
{
    printf("======================================================\n");
    printf("|  Welcome to our tea shop! How can we help you?     |\n");
    printf("|  0: See Available Products                         |\n");
    printf("|  1: Place Order                                    |\n");
    printf("|  2: View My Order                                  |\n");
    printf("|  3: Add Products                                   |\n");
    printf("|  4: Search Products by Price                       |\n");
    printf("|  5: Exit                                           |\n");
    printf("======================================================\n\n");
}
