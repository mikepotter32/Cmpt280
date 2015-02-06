#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char ** argv) {
  int LINE_SIZE = 256;
  FILE * fp;
    char *line;
    int chars, words, lines;
    float avg_word_len, avg_line_len;
    int i;

    line = malloc(LINE_SIZE * sizeof(char));
    if (line == NULL){
      printf("line malloc failed\n");
      return 0;
    }

    words = lines = 0;

    if (argv[1] == NULL){
      printf("No file provided\n");
      return 0;
    }

    fp = fopen(argv[1], "r");
    assert(fp != NULL && "File can't be opened");

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

    fclose(fp);

    if (words != 0 && lines != 0){
      avg_word_len = (float) chars / words;
      avg_line_len = (float) chars / lines;
    } else {
      avg_word_len = 0;
      avg_line_len = 0;
    }

    printf("Chars: %d\nWords: %d\tAvg Len: %.2f\n", chars, words, avg_word_len);
    printf("Lines: %d\tAvg Len: %.2f\n", lines, avg_line_len);

    return 0;
}
