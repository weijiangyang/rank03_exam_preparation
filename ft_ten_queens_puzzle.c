#include <unistd.h>
#include <stdio.h>

int	no_attack(int tab[10], int col, int row)// pour verifier si un point n'attck pas les ancients
{
	int	pre_col;
	int	pre_row;

	pre_col = 0;
	while (pre_col < col)// parcourir pre_col
	{
		pre_row = tab[pre_col];
		if (row == pre_row || row - pre_row == col - pre_col || pre_row - row == col - pre_col)
			return (0);
		pre_col++;
	}
	return (1);
}

void solution(int tab[10], int col, int *nb_solution)
{
	int	i;
	char	digit;
	int	row;

	row = 0;
	i = 0;
	if (col == 10)// quand col atteint 10, commencer a affichier , et auguement la solution et change la ligne et return . 
	{
		while (i < 10)
		{
			digit = tab[i] + '0';
			write (1, &digit, 1);
			i++;
		}
		(*nb_solution)++;
		write (1, "\n", 1);
		return ;
	}
	while (row < 10)// essayer de 0 au 10 pour row , si no_attack, on continue. 
	{
		tab[col] = row;
		if (no_attack(tab, col, row))
			solution (tab, col + 1, nb_solution);
		row++;
	}
}

int	ft_ten_queens_puzzle()
{
	int	tab[10];
	int	nb_solution;

	nb_solution = 0;
	solution(tab, 0, &nb_solution);
	return nb_solution;
}

int main(void)
{
	int	nb_solution;

	nb_solution = ft_ten_queens_puzzle();
	printf("%d\n", nb_solution);
	return (0);
}

