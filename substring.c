#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

long long validSubstringCount(char* word1, char* word2) {
    unsigned int need = 0, have = 0;
    int count[26] = {0}, missing = 0, left = 0;
    long long total = 0;

    for (int i = 0; word2[i]; i++) {
        int idx = word2[i] - 'a';
        if (!(need & (1 << idx))) missing++;
        need |= 1 << idx;
        count[idx]++;
    }

    for (int i = 0; word1[i]; i++) {
        int idx = word1[i] - 'a';
        if (need & (1 << idx)) {
            count[idx]--;
            if (count[idx] == 0) {
                have |= 1 << idx;
                missing--;
            }
        }

        if (missing == 0) {
            while (left <= i) {
                int left_idx = word1[left] - 'a';
                if (!(need & (1 << left_idx)) || count[left_idx] < 0) {
                    if (need & (1 << left_idx)) count[left_idx]++;
                    left++;
                } else break;
            }
            total += left + 1;
        }
    }

    return total;
}
