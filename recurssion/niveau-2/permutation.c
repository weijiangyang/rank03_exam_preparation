#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}
int ft_strlen(char *str)
{
    // calculer la taille d'un str
    int size;

    size = 0;
    while (str[size])
        size++;
    return (size);
}

int is_doublon(char *str)
{
    int i;
    int j;
    int len;

    len = ft_strlen(str);

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (j < len)
        {
            if (str[j] == str[i])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void permute(char *str, char *result, int depth, int *used)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (depth == len)
    {
        result[depth] = '\0';
        if (!is_doublon(result))
        {
            ft_putstr(result);
        ft_putchar('\n');
        }
        
        return ;
    }

    while (i < len)
    {
        if (!used[i])
        {
            used[i] = 1;
            result[depth] = str[i];
            permute(str, result, depth + 1, used);
            used[i] = 0;
        }
        i++;
    }

}



int main(void)
{
    char *str = "abc";
    int len = ft_strlen(str);
    char *result = malloc(ft_strlen(str) + 1);
    int *used;
    int i;

    i = 0;
    used = malloc (len * sizeof(int));
    while (i < len)
    {
        used[i] = 0;
        i++;
    }

    
    permute(str, result, 0, used);
    free(used);
    free(result);
    return (0);
}
