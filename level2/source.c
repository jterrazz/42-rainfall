#include <stdio.h>
#include <string.h>

void p(void)
{
  char buffer[0x4c]; // 76

  fflush(stdout);
  gets(buffer);

  unsigned int p_ret_address = buffer[0x50]; // 80
  
  if (p_ret_address & 0xb0000000 != 0xb0000000) { // if is a stack address
    printf("(%p)\n", p_ret_address);
    exit(1);
  } else {
    puts(buffer);
    strdup(buffer);
  }
}

int main(int argc, char *argv[])
{
  p();
}
