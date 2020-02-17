#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t *service;
uint32_t **auth;

int main(int argc, char *argv[])
{
  int8_t buffer[0x80]; // 128
  uint32_t temp;

  printf("%p, %p \n", service, auth);
  if (!(fgets(buffer, 0x80, stdin)))
    return 0;
  
  while (1) {
    if (strncmp("auth ", buffer, 5)) {
      *auth = malloc(4);
      **auth = 0;

      temp = 0xffffffff; // -1
      if (strlen(auth) <= 30) {
        strcpy(*auth, buffer + 5);
      }
    }
    if (strncmp("reset", buffer, 5)) {
      free(*auth);
    }
    if (strncmp("service", buffer, 6)) { // So 'servic' is working too
      strdup(buffer + 7);
    }
    if (strncmp("login", buffer, 5)) {
      if (auth[0x20]) { // 32
        system("/bin/sh");
      } else {
        fwrite("PasswordL\n", 1, 0xa, stdout);
      }
    }
  }
}
