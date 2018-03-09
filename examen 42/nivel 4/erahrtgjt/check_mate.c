#include <unistd.h>
#include <stdlib.h>

typedef struct	pos
{
	int x;
	int y;
}				pos;

static int	valid(pos *king, char **av, int ac) {
	king->x = -1;
	king->y = -1;
	for (int i = 1; i < ac; i++) {
		int j;
		for (j = 0; av[i][j]; j++) {
			if (av[i][j] == 'K') {
				king->x = j;
				king->y = i;
			}
		}
		if (j != ac - 1) {
			return 0;
		}
	}
	if (king->x == -1 || king->y == -1) {
		return 0;
	}
	return 1;
}

static void	solve(pos king, char **av, int ac) {
	int	ul = 1, u = 1, ur = 1, r = 1, dr = 1, d = 1, dl = 1, l = 1;
	for (int i = 1; ul || u || ur || r || dr || d || dl || l; i++) {

		if (ul && king.y - i > 0 && king.x - i >= 0) {
			if (ul && (av[king.y - i][king.x - i] == 'B' || av[king.y - i][king.x - i] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y - i][king.x - i] != '.') {
				ul = 0;
			}
		}
		else {
			ul = 0;
		}

		if (u && king.y - i > 0) {
			if (u && (av[king.y - i][king.x] == 'R' || av[king.y - i][king.x] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y - i][king.x] != '.') {
				u = 0;
			}
		}
		else {
			u = 0;
		}

		if (ur && king.y - i > 0 && king.x + i < ac - 1) {
			if (ur && (av[king.y - i][king.x + i] == 'B' || av[king.y - i][king.x + i] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y - i][king.x + i] != '.') {
				ur = 0;
			}
		}
		else {
			ur = 0;
		}

		if (r && king.x + i < ac - 1) {
			if (r && (av[king.y][king.x + i] == 'R' || av[king.y][king.x + i] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y][king.x + i] != '.') {
				r = 0;
			}
		}
		else {
			r = 0;
		}

		if (dr && king.y + i < ac && king.x + i < ac - 1) {
			if (dr && (av[king.y + i][king.x + i] == 'B' || av[king.y + i][king.x + i] == 'Q' || (av[king.y + i][king.x + i] == 'P' && i == 1))) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y + i][king.x + i] != '.') {
				dr = 0;
			}
		}
		else {
			dr = 0;
		}

		if (d && king.y + i < ac) {
			if (d && (av[king.y + i][king.x] == 'R' || av[king.y + i][king.x] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y + i][king.x] != '.') {
				d = 0;
			}
		}
		else {
			d = 0;
		}

		if (dl && king.y + i < ac && king.x - i >= 0) {
			if (dl && (av[king.y + i][king.x - i] == 'B' || av[king.y + i][king.x - i] == 'Q' || (av[king.y + i][king.x - i] == 'P' && i == 1))) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y + i][king.x - i] != '.') {
				dl = 0;
			}
		}
		else {
			dl = 0;
		}

		if (l && king.x - i >= 0) {
			if (l && (av[king.y][king.x - i] == 'R' || av[king.y][king.x - i] == 'Q')) {
				write(1, "Success\n", 8);
				exit(0);
			}
			else if (av[king.y][king.x - i] != '.') {
				l = 0;
			}
		}
		else {
			l = 0;
		}
	}
	write (1, "Fail\n", 5);
}

int	main(int ac, char **av) {
	if (ac > 1) {
		pos	king;
		if (valid(&king, av, ac)) {
			solve(king, av, ac);
		}
		else {
			write(1, "1\n", 2);
			return 0;
		}

	}
	else {
		write(1, "\n", 1);
	}
	return 0;
}
