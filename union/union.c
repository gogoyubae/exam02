#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int k;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while(argv[1][i])
	{
		k = 0;
		while (k < i && argv[1][k] != argv[1][i])
			k++;
		if (i == k)
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while(argv[2][j])
	{
		k = 0;
		while (k < i && argv[1][k] != argv[2][j])
			k++;
		if (i == k)
		{
			while (k - i < j && argv[2][k - i] != argv[2][j])
				k++;
			if (k - i== j)
				write(1, &argv[2][j], 1);
		}
		j++;
	}
	write(1, "\n", 1);
}
