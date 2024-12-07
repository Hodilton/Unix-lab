#include "task_3.h"
#include "input.h"

#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>
#include <locale.h>

int readInput(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int* char_count, int* line_count) {
    *char_count = 0;
    *line_count = 0;

    int total_chars = 0;
    
    wprintf(L"Введите текст (закончите ввод, нажав <CTRL>+<d>):\n");

    while (fgetws(lines[*line_count], MAX_LINE_LEN, stdin) != NULL) {
        int line_len = wcslen(lines[*line_count]);

        // Уменьшаем количество символов, если последним символом является '\n'
        if (lines[*line_count][line_len - 1] == L'\n') {
            line_len--;
        }

        total_chars += line_len;
        (*line_count)++;
        
        if (*line_count >= MAX_LINES) {
            wprintf(L"Достигнут лимит строк (%d).\n", MAX_LINES);
            break;
        }
    }
    
    *char_count = total_chars;
    return *line_count;
}

int countWords(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int line_count, wchar_t words[MAX_WORDS][MAX_WORD_LEN]) {
    int word_count = 0;
    wchar_t word[MAX_WORD_LEN];
    int in_word = 0;
    int word_len = 0;

    for (int i = 0; i < line_count; i++) {
        int line_len = wcslen(lines[i]);
        
        for (int j = 0; j < line_len; j++) {
            wchar_t c = lines[i][j];
            
            if (iswalpha(c)) { // Проверяем, является ли символ буквой
                if (word_len < MAX_WORD_LEN - 1) {
                    word[word_len++] = c;
                }
                in_word = 1;
            } else if (in_word) {
                // Завершаем текущее слово
                word[word_len] = L'\0';
                wcsncpy(words[word_count], word, MAX_WORD_LEN);

                word_count++;
                word_len = 0;
                in_word = 0;

                if (word_count >= MAX_WORDS) {
                    wprintf(L"Достигнут лимит слов (%d).\n", MAX_WORDS);
                    return word_count;
                }
            }
        }

        // Если строка заканчивается словом
        if (in_word) {
            word[word_len] = L'\0';
            wcsncpy(words[word_count], word, MAX_WORD_LEN);
            word_count++;
            word_len = 0;
            in_word = 0;

            if (word_count >= MAX_WORDS) {
                wprintf(L"Достигнут лимит слов (%d).\n", MAX_WORDS);
                return word_count;
            }
        }
    }

    return word_count;
}

void printLines(wchar_t lines[MAX_LINES][MAX_LINE_LEN], int line_count) {
    wprintf(L"\nВведенные строки:\n");
    for (int i = 0; i < line_count; i++) {
        wprintf(L"%ls", lines[i]);
    }
}

void printWords(wchar_t words[MAX_WORDS][MAX_WORD_LEN], int word_count) {
    wprintf(L"\nВведенные слова:\n");
    for (int i = 0; i < word_count; i++) {
        wprintf(L"%ls\n", words[i]);
    }
}

void task_3() {
    setlocale(LC_ALL, "");

    wchar_t lines[MAX_LINES][MAX_LINE_LEN];
    wchar_t words[MAX_WORDS][MAX_WORD_LEN];

    int char_count = 0;
    int line_count = 0;
    int word_count = 0;

    line_count = readInput(lines, &char_count, &line_count);

    word_count = countWords(lines, line_count, words);

    wprintf(L"\nВведено символов: %d\n", char_count);
    wprintf(L"Введено строк: %d\n", line_count);
    wprintf(L"Введено слов: %d\n", word_count);

    printLines(lines, line_count);
    printWords(words, word_count);
}
