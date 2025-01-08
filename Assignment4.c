#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50

int vowelStart(const char *name) {
    char firstChar = name[0];
    return (firstChar == 'A' || firstChar == 'E' || firstChar == 'I' || 
            firstChar == 'O' || firstChar == 'U' ||
            firstChar == 'a' || firstChar == 'e' || 
            firstChar == 'i' || firstChar == 'o' || 
            firstChar == 'u');
}

int getStringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
void StringCopy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

int main() {
    int R, C;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];

    printf("Enter number of rows (1-10): ");
    scanf("%d", &R);
    if (R < 1 || R > MAX_ROWS) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    printf("Enter number of columns (1-101): ");
    scanf("%d", &C);
    if (C < 1 || C > MAX_COLS) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    printf("Enter the names:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    int vowelCount = 0;
    char longestName[MAX_NAME_LENGTH] = "";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (vowelStart(names[i][j])) {
                vowelCount++;
            }
            if (getStringLength(names[i][j]) > getStringLength(longestName)) {
                StringCopy(longestName, names[i][j]);
            }
        }
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name is: %s\n", longestName);

    return 0;
}
