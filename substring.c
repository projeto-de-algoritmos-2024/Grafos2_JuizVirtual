#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void calcularFrequencias(char* palavra, int tamanho, int frequencias[]) {
    for (int i = 0; i < tamanho; i++) {
        frequencias[palavra[i] - 'a']++;
    }
}

long long validSubstringCount(char* word1, char* word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
    if (len2 > len1) return 0;

    int freq2[ALPHABET_SIZE] = {0};
    calcularFrequencias(word2, len2, freq2);

    int freqWindow[ALPHABET_SIZE] = {0};
    long long count = 0;

    for (int i = 0; i <= len1 - len2; i++) {
        if (i == 0) {
            calcularFrequencias(word1, len2, freqWindow);
        } else {
            freqWindow[word1[i - 1] - 'a']--;
            freqWindow[word1[i + len2 - 1] - 'a']++;
        }

        int valid = 1;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (freqWindow[j] != freq2[j]) {
                valid = 0;
                break;
            }
        }
        if (valid) count++;
    }

    return count;
}
