#include "substring.h"

void free_arr(char **arr, int len)
{
    int i;

    for (int i = 0; i < len; i++)
        free(arr[i]);
}
char **copy_memn(char **src, int len, int idx)
{
    int i, j;
    char **result;

    if (idx == -1)
        result = malloc(sizeof(char *) * (len));
    else
        result = malloc(sizeof(char *) * (len - 1));
    for (i = 0, j = 0; i < len; i++)
    {
        if (i == idx)
            continue;
        result[j++] = strdup(src[i]);
    }

    return result;
}
int is_a_match(char const *s, char **words, int nb_words, int len_word)
{
    int i, match;
    char **tmp;

    if (nb_words == 0)
        return (1);

    for (i = 0; i < nb_words; i++)
    {
        if (memcmp(s, words[i], len_word) == 0)
        {
            tmp = copy_memn(words, nb_words, i);
            match = is_a_match(s + len_word, tmp, nb_words - 1, len_word);
            free_arr(tmp, nb_words - 1);
            free(tmp);
            return (match);
        }
    }
    return (0);
}
/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string
 * @s: the string to scan
 * @words: the array of words all substringsmust be a concatenation
 * arrangement of
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements 
 * in the returned array
 * Return: return an allocated array, storing each index in s, at which
 * a substring was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int i, len_s, len_word, len_result = 0, *result;
    char **tmp;

    if (!s || !words || !n || nb_words == 0)
        return (NULL);
    len_s = strlen(s);
    result = malloc(len_s * sizeof(int));
    len_word = strlen(words[0]);
    tmp = copy_memn((char **)words, nb_words, -1);
    for (i = 0; i < len_s - (len_word * nb_words) + 1; i++)
    {
        if (is_a_match(s + i, tmp, nb_words, len_word))
        {
            result[len_result++] = i;
        }
    }
    free_arr(tmp, nb_words);
    free(tmp);
    *n = len_result;
    return (result);
}
