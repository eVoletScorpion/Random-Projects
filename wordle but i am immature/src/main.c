// wordle but its always penis

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("Welcome to wordle but worse\nEnter a 5 letter word to start guessing\n");
    
    char word[6];
    char correct[6] = "penis";
    char display[24];
    
    for (int iii = 0; iii < 6; iii++) {
        scanf("%5s", word);
    
        if (strlen(word) != 5) {
            printf("\ni said 5 letters\n");
            iii -= 1;
            continue;
        }

        int pos = 0;
        for (int i = 0; i < 5; i++) {
            if (word[i] == correct[i]) {
                pos += sprintf(&display[pos], "■");
            } else {
                bool found = false;
                for (int ii = 0; ii < 5; ii++) {
                    if (word[i] == correct[ii]) {
                        found = true;
                    }
                }
                if (found) {
                    pos += sprintf(&display[pos], "▨");
                } else {
                    pos += sprintf(&display[pos], "□");
                }
            } 
        }
        display[pos] = '\0';
            
        printf("\nAttempt %d:\n%s\n%s\n", iii + 1, display, word);
    }
    
    // no congrats for winning, im too lazy
    
    return 0;
}
