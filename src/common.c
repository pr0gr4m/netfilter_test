#include "common.h"

static void printchar(unsigned char c)
{
	if (isprint(c))
		printf("%c", c);
	else
		printf(".");
}

/*
 * Prototype : void dumpcode(u_char *buf, int len)
 * Last Modified 2017/07/29
 * Written by ohhara
 * Modified by pr0gr4m
 *
 * dump code from buf
 * buf is start address, len is length to print hex
 */
void dumpcode(const u_char *buf, int len)
{
    int i;

    printf("%7s", "offset ");
    for (i = 0; i < 16; i++)
    {
        printf("%02x ", i);

        if (!(i % 16 - 7))
            printf("- ");
    }
    printf("\n\r");

    for (i = 0; i < len; i++)
    {
        if (!(i % 16))
            printf("0x%04x ", i);

        printf("%02x ", buf[i]);

        if (!(i % 16 - 7))
            printf("- ");

        if (!(i % 16 - 15))
        {
			int j;
			printf(" ");
			for (j = i - 15; j <= i; j++)
				printchar(buf[j]);

            printf("\n\r");
        }
    }

	if (i % 16)
	{
		int j;
		int spaces = (len - i + 16 - i % 16) * 3 + 2;
		for (j = 0; j < spaces; j++)
			printf(" ");
		for (j = i - i % 16; j < len; j++)
			printchar(buf[j]);
	}

    printf("\n\r");
}
