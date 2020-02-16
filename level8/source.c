#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *service;
void *auth;

int main(int argc, char *argv[])
{
  char buffer[0x80];

  printf("%p, %p \n", service, auth);
  if (!(fgets(buffer, 0x80, STDIN)))
    return;
  
  while (1) {
    if (strncmp("auth ", buffer, 5)) {
      auth = malloc(4);
      *auth = 0;
    }
  // Something here
    if (strncmp("reset", buffer, 5) {
      free(auth);
    }
    if (strncmp("service", buffer, 6) {
      strdup(buffer + 7);
    }
// Incomplete
    if (strncmp("login", buffer, 5) {
      if (*(auth + 0x20)) {
        system("/bin/sh")
      }
    }
  }
}
