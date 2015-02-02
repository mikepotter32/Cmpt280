#include <stdio.h>

int main (int argc, char ** argv) {
    FILE * fp;
    char line[256];
    int chars, words, lines;
    float avg_word_len, avg_line_len;
    int i;

    chars = words = lines = 0;
    fp = fopen(argv[1], "r");

    while (fgets(line, 255, fp) != NULL) {
        lines++;

        for (i = 0; ; i++) {
            if (line[i] == '\n' || line[i] == '\0') {
                if (i > 0) words++;
                break;
            }
            else if (line[i] == ' ') {
                words++;
            }
            else chars++;
        }
    }

    avg_word_len = (float) chars / words;
    avg_line_len = (float) chars / lines;

    printf("Chars: %d\nWords: %d\tAvg Len: %.2f\n", chars, words, avg_word_len);
    printf("Lines: %d\tAvg Len: %.2f\n", lines, avg_line_len);

    return 0;
}
