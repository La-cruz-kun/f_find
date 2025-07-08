#include "c_find.h"
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool f_parse_ex(const char *pattern, const char *path, unsigned int depth) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Unable to open path");
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        switch (entry->d_type) {

        case DT_REG:
            char file_path[512] = {0};
            strcat(file_path, path);
            strcat(file_path, "/");
            strcat(file_path, entry->d_name);
            f_parse_file_title(pattern, file_path);

            switch (f_get_file_extension(file_path)) {

            case F_TXT:
                f_parse_txt(pattern, file_path);
                break;

            case F_PDF:
                f_parse_pdf(pattern, file_path);
                break;

            default:
                // TODO
                break;
            }
            break;

        case DT_DIR:
            char new_path[512] = {0};
            strcat(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, entry->d_name);

            if (depth > 0) {
                f_parse_ex(pattern, new_path, depth - 1);
            }
            break;
        }
    }
    free(entry);
    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    char pattern[64] = {0};
    char path[512] = {0};
    unsigned int depth = 1;
    if (argc == 1) {
        printf("TODO USAGE\n");
        return -1;
    }

    else if (argc == 2) {
        strcpy(pattern, argv[1]);
        strcpy(path, ".");
        printf("pattern is: %s\n", pattern);
        printf("argc 2\n");
        f_parse_ex(pattern, path, depth);
    }

    else if (argc == 3) {
        strcpy(pattern, argv[1]);
        depth = atoi(argv[2]);
        strcpy(path, ".");
        f_parse_ex(pattern, path, depth);
    }
    else if (argc == 4) {
        strcpy(pattern, argv[1]);
        depth = atoi(argv[2]);
        strcpy(path, argv[3]);
        f_parse_ex(pattern, ".", depth);
    }

    /* if (!parse_dir(path)) */
    /*   return -1; */

    printf("\n");

    return 0;
}
bool f_parse_txt(const char *pattern, const char *file) {
    FILE *f = fopen(file, "r");

    if (!f) {
        perror("fopen txt");
        return -1;
    }

    char line[1024] = {0};
    unsigned int count = 0;
    while (fgets(line, sizeof(line), f)) {
        count++;
        if (strstr(line, pattern) != NULL) {
            printf("FOUND '%s' in file %s at line %u\n", pattern, file, count);
            printf("\n");
            printf("READ: %s", line);
            fclose(f);
            return true;
        }
    }
    fclose(f);

    return true;
}
bool f_parse_file_title(const char *pattern, const char *file) {
    if (strstr(file, pattern) != NULL) {
        printf("FOUND file '%s' \n", file);
        return true;
    }

    return false;
}

// TODO
void f_parse_pdf(const char *pattern, const char *file) {}
F_EXT f_get_file_extension(const char *file) {
    if (file == NULL) {
        perror("can't get extension file doesn't exist");
        return F_NONE;
    }
    const char *delim = ".";
    char *token;
    char *last = NULL;

    if (strpbrk(file, delim) == NULL)
        return F_NONE;

    token = strtok(strdup(file), delim);
    while (token != NULL) {
        last = token;
        token = strtok(NULL, delim);
    }
    if (!last) {
        perror("can't get extension no extension");
        return F_NONE;
    }

    if (strcmp(last, "txt") == 0) {
        return F_TXT;
    }

    return F_NONE;
}
