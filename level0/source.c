#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int nb = atoi(argv[1]);

  if (nb != 0x1a7) {
    fwrite("No !\n", 1, 5, stderr);
  } else {
    char *cmd = strdup("/bin/sh");
    gid_t gid = getegid();
    uid_t uid = geteuid();
    
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);
    execv("/bin/sh", cmd);
  }
  return 0;
}
