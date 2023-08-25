#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Include the header for isdigit function

void print_error() {
    printf("Error\n");
    exit(98);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error();
    }

    // Check if num1 and num2 are composed of digits
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit((unsigned char)argv[1][i])) {  // Cast to unsigned char for isdigit
            print_error();
        }
    }
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (!isdigit((unsigned char)argv[2][i])) {  // Cast to unsigned char for isdigit
            print_error();
        }
    }

    // Convert num1 and num2 to integers
    unsigned long long num1 = strtoull(argv[1], NULL, 10);
    unsigned long long num2 = strtoull(argv[2], NULL, 10);

    // Perform multiplication
    unsigned long long result = num1 * num2;

    // Print the result
    printf("%llu\n", result);

    return 0;
}
