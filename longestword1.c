#include <stdio.h>
#include <string.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseSubstring(char *str, int start, int end)
{
    while (start < end)
    {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}
void generateCombinations(char *str, int size) 
{
    int i, j;
    while (1) {
        printf("%s\n", str);
        for (i = size - 2; i >= 0; i--) 
        {
            if (str[i] < str[i + 1]) 
            {
                break;
            }
        }
        if (i == -1) {
            break;
        }
        for (j = size - 1; j > i; j--) 
        {
            if (str[j] > str[i]) 
            {
                break;
            }
        }
        swap(&str[i], &str[j]);
        reverseSubstring(str, i + 1, size - 1);
    }
}

int main() {
    int size;
    char drawn_letters[size];
    printf("Enter the letters : ");
    scanf("%s",drawn_letters);
    size = strlen(drawn_letters);
    printf("The results :\n");
    generateCombinations(drawn_letters,size);

    return 0;
}
