#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *CMDS[] = {
  "",
  "uname -r | awk -F '-' '{print $1}'",
  "amixer sget Master | awk -F '[][]' '/Mono:/{print $2}'",
  "current_brightness=$(cat /sys/class/backlight/intel_backlight/brightness) && max_brightness=$(cat /sys/class/backlight/intel_backlight/max_brightness) && brightness_percent=$(( 100 * current_brightness / max_brightness )) && echo $brightness_percent",
};

const char* RunCMD(const char *cmd) {
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

const char *GetDatetime() {
  char res[100];
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%Y-%m-%d %H:%M", timeinfo);
  sprintf(res, "| %s ", buffer);
  const char *ans = res;
  return ans;
}


int main () {

  char command[1024 * 512];
  while (1) {
    int len = sizeof(CMDS) / sizeof(CMDS[0]);
    memset(command, 0, sizeof(command));
    strcat(command, CMDS[0]);
    // 第一列
    strcat(command, "  "); 
    strcat(command, RunCMD(CMDS[1]));
    // 第二列
    strcat(command, "| ");
    strcat(command, RunCMD(CMDS[2]));
    // 第三列
    strcat(command, "| ");
    strcat(command, RunCMD(CMDS[3]));
    strcat(command, "%");
    // 时间
    strcat(command, GetDatetime());

    char cmd[1024 * 512];
    sprintf(cmd, "xsetroot -name \"%s\"", command);
    printf("%s\n", cmd);
    system(cmd);
    system("sleep 1");
  }
  return 0;
}


