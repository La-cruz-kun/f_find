#ifndef C_FIND_H
#define C_FIND_H
#include <stdbool.h>

typedef enum {
    OPT_EXCLUSIVE = 1000,
    OPT_PATH,
    OPT_PARSE_FILES,
} OPTION;

typedef enum { F_TXT,
               F_PDF,
               F_PY,
               F_CPP,
               F_RS,
               F_H,
               F_C,
               F_NONE
             } F_EXT;

F_EXT f_get_file_extension(const char *file);
bool f_parse_file_title(const char *pattern, const char *file);
bool f_parse_ex(const char *pattern, const char *path,unsigned int depth);
bool f_parse_txt(const char *pattern, const char *file);
void f_parse_pdf(const char *pattern, const char *file);
void print_help();
#endif // C_FIND_H
