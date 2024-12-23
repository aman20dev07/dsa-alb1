#include <stdio.h>

void moveDisks(int numDisks, char source, char temp, char destination);

int main() {
    int numDisks;

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Display the sequence of moves
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    moveDisks(numDisks, 'A', 'B', 'C');
    
    return 0;
}

// Recursive function to solve Tower of Hanoi problem
void moveDisks(int numDisks, char source, char temp, char destination) {
    // Base case: only one disk to move
    if (numDisks == 1) {
        printf("\nMove disk 1 from peg %c to peg %c", source, destination);
        return;
    }

    // Move n-1 disks from source to temporary peg
    moveDisks(numDisks - 1, source, destination, temp);

    // Move the nth disk from source to destination
    printf("\nMove disk %d from peg %c to peg %c", numDisks, source, destination);

    // Move the n-1 disks from temporary peg to destination
    moveDisks(numDisks - 1, temp, source, destination);
}
