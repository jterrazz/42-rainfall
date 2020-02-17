#include <string.h>
#include <stdio.h>
#include <unistd.h>

const char separator[] = " - ";

void p(char *userBuffer, char *toPrint)
{
  u_int8_t readBuffer[0x1000];
  u_int8_t *returnAddr;

  puts(toPrint);
  read(0, readBuffer, 0x1000);
  returnAddr = strchr(readBuffer, 0xa); // \n
  *returnAddr = 0;
  strncpy(userBuffer, readBuffer, 0x14); // 20
}

void pp(char *buffer)
{
  u_int8_t buffer1[20];
  u_int8_t buffer2[20];
  uint32_t len;

  p(buffer1, separator);
  p(buffer2, separator);

  strcpy(buffer, buffer1);
  len = strlen(buffer);
  buffer[len] = " ";
  buffer[len + 1] = 0;
  strcat(buffer, buffer2);
}

int main(int argc, char *argv[])
{
  u_int8_t buffer[42];

  pp(buffer);
  puts(buffer);
}
