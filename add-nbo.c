#include <stdio.h>
#include <stdint.h>

void ConvertToHostByteOrder(char *file_name, uint32_t *data)
{
    FILE *fp = fopen(file_name, "rb");
    uint8_t tmp;
    
    for (int idx = 0; idx < 4; idx++)
    {
        fread(&tmp, 1, 1, fp);
        *((uint8_t *)data + (3 - idx)) = tmp;
    }

    fclose(fp);
}

int main(int argc, char** argv)
{
    uint32_t data[2];

    for (int idx = 1; idx < argc; idx++)
        ConvertToHostByteOrder(argv[idx], &data[idx - 1]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", data[0], data[0], data[1], data[1], data[0] + data[1], data[0] + data[1]);

    return 0;
}
