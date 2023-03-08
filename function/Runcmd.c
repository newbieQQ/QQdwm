#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Runcmd.h"

const char* Runcmd(const char *cmd) {
  FILE *fp;
  char res[1024];
  char *r = res;
  fp = popen(cmd, "r");

  if (fp == NULL) {
    perror("popen failed");
    char *a = "error";
    r = a;
  } else  {
    while (fgets(res, sizeof(res), fp) != NULL) ;
    char *p = strtok(res, "\n");
    r = p;
    pclose(fp);
  }
    return r;
}
