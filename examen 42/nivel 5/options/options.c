#include <unistd.h>

static int	is_valid(char c) {
	return ((c >= 'a' && c <= 'z'));
}

static int	is_h(char c) {
	return ((c == 'h'));
}

static int	is_arg(char *str) {
	return ((str[0] == '-'));
}

static int	valid_arg(char *str) {
	for (int i = 1; str[i]; i++) {
		if (!is_valid(str[i])) {
			return 0;
		}
	}
	return 1;
}

static void	print_usage() {
	write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}

static void	print_invalid() {
	write(1, "Invalid Option\n", 15);
}

static void	print_nr(int nr) {
	for(int i = 31; i >= 0; i--) {
		if (nr & (1 >> i)) {
			write(1, "1", 1);
		}
		else {
			write(1, "0", 1);
		}
		if (i % 8 == 0 && i) {
			write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}

static void	insert_bit(int *nr, char c) {
	*nr |= 1 << (c - 'a');
}

static int	solve(int *nr, char *str) {
	for (int i = 1; str[i]; i++) {
		if (!is_h(str[i])) {
			insert_bit(nr, str[i]);
		}
		else {
			print_usage();
			return 1;
		}
	}
	return 0;
}

int			main(int ac, char **av) {
	int	arg_count = 0;
	int	nr = 0;
	for (int i = 1; i < ac; i++) {
		if (is_arg(av[i])) {
			arg_count++;
			if (valid_arg(av[i])) {
				if (solve(&nr, av[i])) {
					return 0;
				}
			}
			else {
				print_invalid();
				return 0;
			}
		}
	}
	if (arg_count == 0) {
		print_usage();
	}
	else {
		print_nr(nr);
	}
	return 0;
}
