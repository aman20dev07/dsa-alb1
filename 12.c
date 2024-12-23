#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Size of the hash table

int create(int num, int m) {
    return num % m;  // this is a Hash fun
}

void linear_prob(int a[MAX], int key, int num, int m) {
    int i;

    // If the calculated index is empty, insert the number
    if (a[key] == -1)
        a[key] = num;

    else {
        // Collision occurred, use linear probing
        for (i = (key + 1) % m; i != key; i = (i + 1) % m) {
            if (a[i] == -1) {
                a[i] = num;
                return;  // Inserted successfully
            }
        }
        // If we reach here, the table is full
        printf("\nHash table is full\n");
        exit(1);
    }
}

void display(int a[MAX], int m) {
    printf("\nThe hash table is...\n");
    printf("Index\tEmployee ID\n");
    for (int i = 0; i < m; i++) {
        if (a[i] != -1) {  // Only display filled slots
            printf("%d\t%d\n", i, a[i]);
        }
    }
}

int main() {
    int a[MAX], num, key, ans;
    int m = 10;  // Size of the hash table (can be changed)

    // Initialize the hash table
    for (int i = 0; i < m; i++) a[i] = -1;

    printf("Collision handling by linear probing\n");
    do {
        printf("\nEnter the four-digit number: ");
        scanf("%d", &num);

        // Validate that it is a four-digit number
        if (num < 1000 || num > 9999) {
            printf("Please enter a valid four-digit number.\n");
            continue;  // if that happens, Skip the rest of the loop
        }

        key = create(num, m);
        linear_prob(a, key, num, m);
        
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &ans);
    
    } while (ans == 1);
    
    display(a, m);
    return 0;
}