#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int choice=0, b=1, q, s, d, t, c, i, s1=0, d1=0, t1=0, c1=0, i1=0, tBill=0;

void menu() {
    printf(YELLOW "-----------Menu------------\n" RESET);
    printf(GREEN "1. Hakka noodles 120/-\n" RESET);
    printf(GREEN "2. Samosa 35/-\n" RESET);
    printf(GREEN "3. Tea 10/-\n" RESET);
    printf(GREEN "4. Coffee 50/-\n" RESET);
    printf(GREEN "5. Ice cream 30/-\n" RESET);
    printf(GREEN "0. Exit\n" RESET);
}

void quantity(int choice) {
    switch(choice) {
        case 1:
        case 2:
            printf("Plates = ");
            break;
        case 3:
        case 4:
            printf("Cups = ");
            break;
        case 5:
            printf("Servings = ");
            break;
    }
}

void billing(int cBill) {
    tBill += cBill;
}

void printBill() {
    printf(CYAN "G Total = %d\n" RESET, tBill);
}

void order() {
    while (b) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf(MAGENTA "You have ordered Hakka noodles\n" RESET);
                printf("How many ");
                quantity(choice);
                scanf("%d", &s);
                s1 += s;
                printf("Ok, anything else?\n");
                billing(s * 120);
                break;
            case 2:
                printf(MAGENTA "You have ordered Samosa\n" RESET);
                printf("How many ");
                quantity(choice);
                scanf("%d", &d);
                d1 += d;
                printf("Ok, anything else?\n");
                billing(d * 35);
                break;
            case 3:
                printf(MAGENTA "You have ordered Tea\n" RESET);
                printf("How many ");
                quantity(choice);
                scanf("%d", &t);
                t1 += t;
                printf("Ok, anything else?\n");
                billing(t * 10);
                break;
            case 4:
                printf(MAGENTA "You have ordered Coffee\n" RESET);
                printf("How many ");
                quantity(choice);
                scanf("%d", &c);
                c1 += c;
                printf("Ok, anything else?\n");
                billing(c * 50);
                break;
            case 5:
                printf(MAGENTA "You have ordered Ice cream\n" RESET);
                printf("How many ");
                quantity(choice);
                scanf("%d", &i);
                i1 += i;
                printf("Ok, anything else?\n");
                billing(i * 30);
                break;
            case 0:
                printf(RED "Exit\n" RESET);
                b = 0;
                break;
            default:
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    }
}

void table() {
    printf(BLUE " Item          | Qty  | Rate | Total\n" RESET);
    printf(BLUE "--------------------------------------\n" RESET);
    if (s1) {
        printf(" Hakka Noodles  | %d  | 120  | %d\n", s1, s1 * 120);
    }
    if (d1) {
        printf(" Samosa         | %d  | 35   | %d\n", d1, d1 * 35);
    }
    if (t1) {
        printf(" Tea            | %d  | 10   | %d\n", t1, t1 * 10);
    }
    if (c1) {
        printf(" Coffee         | %d  | 50   | %d\n", c1, c1 * 50);
    }
    if (i1) {
        printf(" Ice Cream      | %d  | 30   | %d\n", i1, i1 * 30);
    }
    printf(BLUE "--------------------------------------\n" RESET);
}

void money() {
    int cash, rCash;
    printf("Enter your cash: ");
    scanf("%d", &cash);
    rCash = cash - tBill;
    printf(GREEN "Return cash = %d\n\n" RESET, rCash);

    int note;
    int i; // Declare the loop variable outside the for loop.
    for(i = 100; i != 0; i = i / 2) {
        note = rCash / i;
        if (note != 0) {
            printf("There are %d Note(s) of %d\n", note, i);
        }
        rCash = rCash % i;
        if (i == 50) {
            i = 40;
        }
    }
}

int main() {
    printf(CYAN "WELCOME TO CAFE\n" RESET);
    order();
    table();
    printBill();
    money();
    return 0;
}

