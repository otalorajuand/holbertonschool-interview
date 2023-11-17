#include "regex.h"

int regex_match(char const *str, char const *pattern) {
    if (*str == '\0' && *pattern == '\0') {
        return 1;
    }

    if (*pattern == '*' && *(pattern + 1) == '\0') {
        return 1;
    }

    if (*pattern == '*' && *(pattern + 1) != '*') {
        while (*str != '\0') {
            if (*str == *(pattern + 1) || *(pattern + 1) == '.') {
                if (regex_match(str + 1, pattern + 2)) {
                    return 1;
                }
            } else {
                break;
            }
            str++;
        }
        return regex_match(str, pattern + 2);
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return regex_match(str + 1, pattern + 1);
    }

    return 0;
}
