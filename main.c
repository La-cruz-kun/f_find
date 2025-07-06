#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool parse_dir(const char *path) {
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
    if (entry->d_name[0] == '.') {
      continue;
    }
    if (strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    switch (entry->d_type) {
    case DT_REG:
      FILE *file;

      char file_path[512] = {0};
      strcat(file_path, path);
      strcat(file_path, "/");
      strcat(file_path, entry->d_name);

      file = fopen(file_path, "r");
      if (file == NULL) {
        printf("couldn't open %s\n", file_path);
      } else {
        printf("file %s opened \n", file_path);
      };
      break;

    case DT_DIR:
      char new_path[512] = {0};
      strcat(new_path, path);
      strcat(new_path, "/");
      strcat(new_path, entry->d_name);
      parse_dir(new_path);
      break;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char pattern[64] = {0};
  char path[512] = {0};
  if (argc == 1) {
    printf("TODO USAGE\n");
    printf("argc 1\n");
    return -1;
  }
  if (argc == 2) {
    strcpy(pattern, argv[1]);
    strcpy(path, ".");
    printf("pattern is: %s\n", pattern);
    printf("argc 2\n");
    return -1;
  }
  if (argc == 3) {
    strcpy(pattern, argv[1]);
    strcpy(path, argv[2]);
    printf("pattern is: %s\n", pattern);
    printf("path is: %s\n", path);
    printf("argc 3\n");
    return -1;
  }
  /* if (!parse_dir(path)) */
  /*   return -1; */

  printf("\n");

  return 0;
}
