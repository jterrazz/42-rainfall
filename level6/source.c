#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void n(void)
{
  system("/bin/cat /home/user/level7/.pass");
}

void m(void)
{
  puts("Nope");
}

int main(int argc, char *argv[])
{
  char *str = malloc(0x40); // 64
  uint32_t *addr = malloc(0x4); // 4

  *addr = m;
  strcpy(str, argv[1]);

  ((uint32_t (*)())*addr)();
}
