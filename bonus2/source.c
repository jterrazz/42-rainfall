#include <string.h>
#include <stdio.h>
#include <stdlib.h>

u_int32_t language = 0;

typedef enum e_lang {
    en,
    fi,
    nl,
} t_lang;

void greetuser(char *welcome_message)
{
    char greeting_str[0x48]; // 72

    if (language == en) {
        strcpy(greeting_str, "Hello ");
    } else if (language == fi) {
        strcpy(greeting_str, "Hyv\u00e4\u00e4 p\u00e4iv\u00e4\u00e4 ");
    } else if (language == nl) {
        strcpy(greeting_str, "Goedemiddag! ");
    }
    strcat(welcome_message, greeting_str);
    puts(welcome_message);
}

int main(int argc, char *argv[])
{
    char str1[0x28]; // 40
    char str2[0x20]; // 32

    if (argc != 3)
        return 1;
    strncpy(str1, argv[1], 0x28);
    strncpy(str2, argv[2], 0x20);

    char *env = getenv("LANG");

    if (env) {
        if (memcmp(env, "fi", 2)) {
            language = fi;
        } else if (memcmp(env, "nl", 2)) {
            language = nl;
        }
    }
    greetuser(str1);
}