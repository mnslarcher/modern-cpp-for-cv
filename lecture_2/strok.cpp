#include <stdio.h>
#include <string.h>

int main() {
  char filename[] = "00205.txt";
  char *pch;
  pch = strtok(filename, ".");
  while (pch != NULL) {
    printf("%s\n", pch);
    pch = strtok(NULL, ".");
  }
  return 0;
}