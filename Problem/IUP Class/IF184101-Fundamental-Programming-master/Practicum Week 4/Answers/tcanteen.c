#include <stdio.h>
#include <string.h>

struct Menu {
    char name[1000];
    long long price;
    long long exist;
};

int main() {
    // add a new menu
    // get the info of available menu
    // storing customer orders
    // view total earnings

    // each menu in the canteen consists of name and price
    // each menu will be contained in their own shelves with a number x (0 - 30)
    // menu name can contain space character
    
    // dummy characters exist because we still need to prompt the user to input the menu
    // even though the menu already exists
    struct Menu menu[1000];
    char dummy1[1000];
    long long total = 0, dummy2 = 0;
    for (long long i = 0; i < 1000; i++) {
        menu[i].exist = 0;
    }

    for (int i = 0; 1; i++) {
        char command[1000];
        scanf(" %s", command);
        if (strcmp(command, "ADD") == 0) {
            long long n = 0;
            scanf(" %lli", &n);
            if (menu[n].exist == 1) {
                scanf(" %[^\n]", dummy1);
                scanf(" %lli", &dummy2);
                printf("Menu #%lli is already exist\n", n);
            } else {
                menu[n].exist = 1;
                scanf(" %[^\n]", menu[n].name);
                scanf(" %lli", &menu[n].price);
                printf("Added menu #%lli %s\n", n, menu[n].name);
            }
        }
        else if (strcmp(command, "INFO") == 0) {
            long long n = 0;
            scanf(" %lli", &n);
            if (menu[n].exist == 0) {
                printf("Menu #%lli doesn't exist\n", n);
            } else {
                printf("#%lli %s Rp %lli\n", n, menu[n].name, menu[n].price);
            }
        }
        else if (strcmp(command, "ORDER") == 0) {
            long long n = 0, m = 0;
            scanf(" %lli", &n);
            scanf(" %lli", &m);
            if (menu[n].exist == 0) {
                printf("Menu #%lli doesn't exist\n", n);
            } else {
                printf("Ordered %llix %s for Rp %lli\n", m, menu[n].name, menu[n].price * m);
                total += menu[n].price * m;
            }
        }
        else if (strcmp(command, "CLOSE") == 0) {
            printf("Earnings: Rp %lli\nTCanteen is closing.. thank you for the visit ^-^\n", total);
            break;
        }
    }

    return 0;
}