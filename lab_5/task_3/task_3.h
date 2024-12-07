#ifndef TASK_3_H
#define TASK_3_H

#include <wchar.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 256
#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

int readInput(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int* char_count, int* line_count);
int countWords(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int line_count, wchar_t words[MAX_WORDS][MAX_WORD_LEN]);
void printLines(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int line_count);
void printWords(wchar_t words[MAX_WORDS][MAX_WORD_LEN], int word_count);

void task_3();

#endif // TASK_3_H
