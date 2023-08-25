#include <stdio.h>
#include <stdlib.h>

void print_error() {
    printf("Error\n");
    exit(98);
}

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        print_error();
    }

    // Check if num1 and num2 are composed of digits
    for (i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            print_error();
        }
    }
    for (i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9') {
            print_error();
        }
    }

    // Convert num1 and num2 to integers
    unsigned long num1 = strtoul(argv[1], NULL, 10);
    unsigned long num2 = strtoul(argv[2], NULL, 10);

    // Perform multiplication
    unsigned long result = num1 * num2;

    // Print the result
    printf("%lu\n", result);

    return 0;
}
