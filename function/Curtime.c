#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Curtime.h"

const char *Curtime() {
  char res[100] = "";
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80] = "";

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%Y-%m-%d %H:%M", timeinfo);
  sprintf(res, "| %s ", buffer);
  const char *ans = res;
  return ans;
}
