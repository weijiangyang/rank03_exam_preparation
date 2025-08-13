#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

static void skip_spaces()
{
    char c;
    while (read(0, &c, 1) == 1 && isspace((unsigned char)c))
        ; // ignore espaces et retours à la ligne
    lseek(0, -1, SEEK_CUR); // remet le curseur un caractère en arrière
}

static int read_int(int *out)
{
    char c;
    int sign = 1;
    long num = 0;
    int read_any = 0;

    skip_spaces();
    if (read(0, &c, 1) != 1) return 0;
    if (c == '-') { sign = -1; read(0, &c, 1); }
    while (isdigit((unsigned char)c))
    {
        num = num * 10 + (c - '0');
        read_any = 1;
        if (read(0, &c, 1) != 1) break;
    }
    *out = (int)(num * sign);
    if (!isspace((unsigned char)c))
        lseek(0, -1, SEEK_CUR);
    return read_any;
}

static int read_char(char *out)
{
    skip_spaces();
    return (read(0, out, 1) == 1);
}

static int read_string(char *out)
{
    char c;
    int count = 0;

    skip_spaces();
    while (read(0, &c, 1) == 1 && !isspace((unsigned char)c))
    {
        out[count++] = c;
    }
    out[count] = '\0';
    return count > 0;
}

static int read_float(float *out)
{
    char buffer[64];
    int i = 0;
    char c;

    skip_spaces();
    while (read(0, &c, 1) == 1 && (isdigit((unsigned char)c) || c == '.' || c == '-'))
    {
        if (i < 63) buffer[i++] = c;
    }
    buffer[i] = '\0';
    *out = atof(buffer);
    return i > 0;
}

int ft_scanf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd')
                count += read_int(va_arg(args, int *));
            else if (*format == 'c')
                count += read_char(va_arg(args, char *));
            else if (*format == 's')
                count += read_string(va_arg(args, char *));
            else if (*format == 'f')
                count += read_float(va_arg(args, float *));
        }
        format++;
    }
    va_end(args);
    return count;
}

#ifdef TEST
#include <stdio.h>
int main(void)
{
    int age;
    char initial;
    char name[50];
    float height;

    write(1, "Entrez: age initial nom taille -> ", 34);
    int res = ft_scanf("%d %c %s %f", &age, &initial, name, &height);

    printf("Résultat: %d valeurs lues\n", res);
    printf("Age: %d\nInitial: %c\nNom: %s\nTaille: %.2f\n",
           age, initial, name, height);
}
#endif

