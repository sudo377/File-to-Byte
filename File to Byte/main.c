#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char path[1024];

    printf("[+] Enter file path >> ");

    if (fgets(path, sizeof(path), stdin) == NULL)
        return 1;

    for (char* p = path; *p; p++)
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
    }

    FILE* input = fopen(path, "rb");
    if (!input)
    {
        printf("\n[-] Failed to open file.\n");
        return 1;
    }

    FILE* output = fopen("output.h", "w");
    if (!output)
    {
        fclose(input);
        printf("\n[-] Failed to create output.h.\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    long size = ftell(input);
    rewind(input);

    fprintf(output, "#pragma once\n\n");
    fprintf(output, "unsigned char data[] = {\n    ");

    int byte;
    long count = 0;

    while ((byte = fgetc(input)) != EOF)
    {
        fprintf(output, "0x%02X", (unsigned char)byte);

        count++;

        if (count != size)
            fprintf(output, ", ");

        if (count % 16 == 0 && count != size)
            fprintf(output, "\n    ");
    }

    fprintf(output, "\n};\n\n");
    fprintf(output, "unsigned int data_size = %ld;\n", size);

    fclose(input);
    fclose(output);

    printf("\n[+] Successfully created 'output.h' (%ld bytes).\n", size);

    system("pause");
    return 0;
}