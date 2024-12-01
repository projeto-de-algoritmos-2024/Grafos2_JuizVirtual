#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

long long validSubstringCount(char* word1, char* word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
    if (len2 > len1) return 0;

    int freq2[ALPHABET_SIZE] = {0};
    for (int i = 0; i < len2; i++) {
        freq2[word2[i] - 'a']++;
    }

    int freqWindow[ALPHABET_SIZE] = {0};
    long long count = 0;

    for (int i = 0; i < len2; i++) {
        freqWindow[word1[i] - 'a']++;
    }

    int valid = 1;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freqWindow[i] < freq2[i]) {
            valid = 0;
            break;
        }
    }
    if (valid) count++;

    for (int i = len2; i < len1; i++) {
        freqWindow[word1[i - len2] - 'a']--;
        freqWindow[word1[i] - 'a']++;

        valid = 1;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (freqWindow[j] < freq2[j]) {
                valid = 0;
                break;
            }
        }
        if (valid) count++;
    }

    return count;
}
