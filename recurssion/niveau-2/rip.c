/*Assignment name: rip
Expected files: *.c *.h
Allowed functions: puts, write
--------------------------------------------------------------------------------
Write a program that will take as argument a string containing only parenthesis.
If parenthesis are unbalanced (for example "())") your program shall remove the
minimum number of parenthesis for the expression to be balanced.
By removing we mean replacing by spaces.
You will print all the solutions (can be more than one).
The order of the solutions is not important.
For example this should work:
(For readability reasons the '_' means space and the spaces are for readability only.)
$> ./rip '( ( )' | cat -e
_ ( ) $
( _ ) $
$> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
( ( ( ) ( ) ( ) ) ( ) ) $
$> ./rip '( ) ( ) ) ( )' | cat -e
( ) ( ) _ ( ) $
( ) ( _ ) ( ) $
( _ ( ) ) ( ) $
$> ./rip '( ( ) ( ( ) (' | cat -e
( ( ) _ _ ) _ $
( _ ) ( _ ) _ $
( _ ) _ ( ) _ $
_ ( ) ( _ ) _ $
_ ( ) _ ( ) _ $*/

#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putstr(char *s) 
{
     while (*s) write(1, s++, 1);
}

int is_valid(char *s)
{
    int     bal;
    
    bal = 0;
    while (*s)
    {
        if (*s == '(')
        {
            bal++;
        }
        if (*s == ')')
        {
            bal--;
            if (bal < 0)
                return (0);
        }
        s++;
    }
    if (bal == 0)
        return (1);
    else   
        return (0);
}

void backtracking (char *str, int start, int ldel, int rdel)
{
    int i;
    char tmp;

    i = start;
    
    if (ldel == 0 && rdel == 0)
    {
        if (is_valid(str))
        {
            ft_putstr(str);
            ft_putchar('\n');

        }    
        return ;
    }

    while (str[i])
    {
        if (i > start && str[i] == str[i-1])
        {
            i++;
            continue;
        }
        
            
        if (str[i] == '(')
        {
            if (ldel > 0)
            {
                tmp = str[i];
                str[i] = '_';
                backtracking(str,i+1,ldel-1, rdel);
                str[i] = tmp;
            }
        }
        if (str[i] == ')')
        {
            if (rdel > 0)
            {
                tmp = str[i];
                str[i] = '_';
                backtracking(str,i+1,ldel, rdel-1);
                str[i] = tmp;
            }
        }
        i++;
    }
}


int main(int ac, char **av)
{
    char *str = av[1];
    int ldel = 0;
    int rdel = 0; 
    int bal = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '(')
        {
            if (bal < 0)
                bal = 0;
            bal++;
        }
        else if (str[i] == ')')
        {
            bal--;
            if (bal < 0)
                rdel++;

        }
        i++;
    }
    if (bal > 0)
        ldel = bal;
    backtracking(str, 0,ldel, rdel);
    return (0);
}


    