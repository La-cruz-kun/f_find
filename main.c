#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *path = argc > 1 ? argv[1] : ".";
  DIR *dir = opendir(path);
  if (!dir) {
    perror("Unable to open path");
    return -1;
  }
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0) {
      continue;
    }
    if (strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    printf("%s\t", entry->d_name);
  }
  printf("\n");

  return 0;
}
