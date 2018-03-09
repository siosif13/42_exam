#include <unistd.h>

static int	brackets(char *str) {
	int i = -1;
	int o = -1;
	while (str[++i]) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			o = i;
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (o != -1 && ((str[o] == '(' && str[i] == ')') || (str[o] == '[' && str[i] == ']') || (str[o] == '{' && str[i] == '}'))) {
				str[o] = ' ';
				str[i] = ' ';
				o = -1;
				i = -1;
			}
			else {
				return (0);
			}
		}
	}
	if (o != -1) {
		return (0);
	}
	else {
		return (1);
	}
}

int main(int ac, char **av) {
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			if (!brackets(av[i])) {
				write (1, "Error\n", 6);
			}
			else {
				write (1, "OK\n", 3);
			}
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
