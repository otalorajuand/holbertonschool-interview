#include <stdio.h>
#include <stdlib.h>

void print_error() {
    printf("Error\n");
    exit(98);
}

int main(int argc, char *argv[]) {
    unsigned long num1, num2, result;
    int i;

    if (argc != 3) {
        print_error();
    }


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


    num1 = strtoul(argv[1], NULL, 10);
    num2 = strtoul(argv[2], NULL, 10);


    result = num1 * num2;


    printf("%lu\n", result);

    return 0;
}
