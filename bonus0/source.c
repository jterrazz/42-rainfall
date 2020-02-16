#include <string.h>
#include <stdio.h>
#include <unistd.h>

const char separator[] = " - ";

void p(char *userBuffer, char *toPrint)
{
  char readBuffer[0x1000];

  puts(toPrint);
  read(0, readBuffer, 0x1000);
  void *returnAddr = strchr(readBuffer, 0xa); // \n
  *returnAddr = 0;
  strncpy(userBuffer, readBuffer, 0x14); // 20
}

void pp(char *buffer)
{
  char buffer1[20];
  char buffer2[20];

  p(buffer1, separator);
  p(buffer2, separator);

  strcpy(buffer, buffer1);
  uint32 len = strlen(buffer);
  buffer[len] = " ";
  buffer[len + 1] = 0;
  strcat(buffer, buffer2);
}

int main(int argc, char *argv[])
{
  char buffer[42];

  pp(buffer);
  puts(buffer);
}
