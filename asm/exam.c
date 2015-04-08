# include <stdio.h>

void mycpy(const char * source, char * dest) {
    int i = 0;
    while (source[i] != '\0')
        dest[i++] = source[i];
    dest[i] = 0;
}

void main(void)
{

    char str[100];
    mycpy("desserts I",str); printf("%s\n", str);

    mirror(str); printf("%s\n", str);

    mirror(str); printf("%s\n", str);

}

