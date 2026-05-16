// FILE EDITOR
// COPYRIGHT MATVEYUCHIK (C) 100%

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("usage: fileditor <filename>");
        return 1;
    }

    const char* filename = argv[1];
    if (!filename) return 1;

    FILE* file = fopen(filename, "w");
    if (!file)
    {
        printf("error: file cannot open :c\n");
        return 1;
    }

    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin))
    {
        printf("error: cannot write string to buf\n");
        return 1;
    }
    if (!fprintf(file, "%s", buf))
    {
        printf("error: cannot write to file %s\n", filename);
        return 1;
    }

    printf("succesfully written to %s\n", filename);
    fclose(file);
    return 0;
}