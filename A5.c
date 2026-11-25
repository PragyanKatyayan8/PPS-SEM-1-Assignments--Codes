
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int choice, i;
    char str1[100], str2[100], sub[50], ch;
    char *ptr;

    while (1) {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Find Length\n2. Copy String\n3. Concatenate\n");
        printf("4. Compare Strings\n5. Find Character\n6. Find Substring\n");
        printf("7. Tokenize String\n8. Uppercase\n9. Lowercase\n10. Exit\n");
        printf("Enter choice: ");
        
        char input[20];
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        if (choice == 10) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Length = %zu\n", strlen(str1));
                break;

            case 2:
                printf("Enter Source String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                strcpy(str2, str1);
                printf("Copied String: %s\n", str2);
                break;

            case 3:
                printf("Enter First String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Second String: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcat(str1, str2);
                printf("Concatenated String: %s\n", str1);
                break;

            case 4:
                printf("Enter First String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Second String: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                printf("%s\n", strcmp(str1, str2) == 0 ? "Strings are equal" : "Strings are unequal");
                break;

            case 5:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Character: ");
                fgets(input, sizeof(input), stdin);
                ch = input[0];
                ptr = strchr(str1, ch);
                if (ptr) printf("Found at position: %ld\n", (long)(ptr - str1 + 1));
                else printf("Not Found\n");
                break;

            case 6:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Substring: ");
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';
                ptr = strstr(str1, sub);
                if (ptr) printf("Found at position: %ld\n", (long)(ptr - str1 + 1));
                else printf("Not Found\n");
                break;

            case 7:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                ptr = strtok(str1, " ");
                printf("Tokens:\n");
                while (ptr != NULL) {
                    printf("%s\n", ptr);
                    ptr = strtok(NULL, " ");
                }
                break;

            case 8:
            case 9:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (i = 0; str1[i] != '\0'; i++)
                    str1[i] = choice == 8 ? toupper((unsigned char)str1[i]) : tolower((unsigned char)str1[i]);
                printf("Result: %s\n", str1);
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
