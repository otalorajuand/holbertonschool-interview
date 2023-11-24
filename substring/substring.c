#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * compare_words - compares strings in arr and substr
 * @arr: array of words
 * @n: number of words in arr
 * @substr: substring
 * Return: 1 if words are identical, 0 otherwise
 */
int compare_words(char const **arr, int n, char const *substr)
{
    int i, len, cmp;

    len = strlen(arr[0]);

    for (i = 0; i < n; i++)
    {
        cmp = strncmp(arr[i], substr, len);
        if (cmp == 0)
        {
            substr += len;
            continue;
        }
        return (0);
    }
    return (1);
}

/**
 * find_substring - finds all the possible substrings containing a list of words
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the returned array
 * Return: an allocated array, storing each index in s, at which a substring was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int len_s, len_word, total_len, count, i, j, k;
    int *indices, *matches;

    if (!s || !words || !*words || nb_words == 0)
        return (NULL);

    len_s = strlen(s);
    len_word = strlen(words[0]);
    total_len = len_word * nb_words;
    indices = malloc(sizeof(int) * len_s);

    if (!indices)
        return (NULL);

    for (i = 0; i <= len_s - total_len; i++)
    {
        matches = malloc(sizeof(int) * nb_words);
        if (!matches)
            return (NULL);

        memset(matches, 0, sizeof(int) * nb_words);

        count = 0;
        for (j = 0; j < nb_words; j++)
        {
            for (k = 0; k < len_s; k += len_word)
            {
                if (matches[k / len_word])
                    continue;

                if (compare_words(words, nb_words, s + i + k))
                {
                    matches[k / len_word] = 1;
                    count++;
                    break;
                }
            }
        }

        if (count == nb_words)
            indices[*n] = i, (*n)++;

        free(matches);
    }

    if (*n == 0)
    {
        free(indices);
        return (NULL);
    }

    return (indices);
}
