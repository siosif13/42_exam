#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *nr;
int k;
int nr_count;
int op_count;

static int	is_pm(char c) {
	return ((c == '+' || c == '-'));
}

static int	is_op(char c) {
	return ((c == '+' || c == '-' || c == '*' || c == '/' || c == '%'));
}

static int	is_digit(char c) {
	return ((c >= '0' && c <= '9'));
}

static int	is_blank(char c) {
	return ((c == ' ' || c == '\t'));
}

static int	do_op(char c) {
	switch (c) {
		case '+': return (nr[k - 2] + nr[k - 1]);
		case '-': return (nr[k - 2] - nr[k - 1]);
		case '*': return (nr[k - 2] * nr[k - 1]);
		case '/': return (nr[k - 2] / nr[k - 1]);
		case '%': return (nr[k - 2] % nr[k - 1]);
	}
	return 0;
}

static int	check_div(char c) {
	return (!((c == '/' || c == '%') && nr[k - 1] == 0));
}

static int	check(char *str) {
	int	i = 0;
	while (str[i]) {
		if (is_pm(str[i]) && is_digit(str[i + 1])) {
			i++;
			while (is_digit(str[i])) {
				i++;
			}
			if (!is_blank(str[i]) && str[i]) {
				return 0;
			}
			if (str[i]) {
				i++;
			}
			nr_count++;
		}
		else if (is_digit(str[i])) {
			while (is_digit(str[i])) {
				i++;
			}
			if (!is_blank(str[i]) && str[i]) {
				return 0;
			}
			if (str[i]) {
				i++;
			}
			nr_count++;
		}
		else if (is_op(str[i])) {
			i++;
			if (!is_blank(str[i]) && str[i]) {
				return 0;
			}
			if (str[i]) {
				i++;
			}
			op_count++;
		}
		else if (is_blank(str[i])) {
			i++;
		}
		else {
			return 0;
		}
	}
	if (nr_count - 1 != op_count) {
		return 0;
	}
	return 1;
}

static int	solve(char *str) {
	nr = (int*)malloc(sizeof(int) * nr_count);
	int	i = 0;
	while (str[i]) {
		if (is_pm(str[i]) && is_digit(str[i + 1])) {
			nr[k++] = atoi(str + i);
			i++;
			while (is_digit(str[i])) {
				i++;
			}
			if (str[i]) {
				i++;
			}
		}
		else if (is_digit(str[i])) {
			nr[k++] = atoi(str + i);
			while (is_digit(str[i])) {
				i++;
			}
			if (str[i]) {
				i++;
			}
		}
		else if (is_op(str[i])) {
			if (k < 2 || !check_div(str[i])) {
				return 0;
			}
			nr[k - 2] = do_op(str[i]);
			k--;
			i++;
			if (str[i]) {
				i++;
			}
		}
		else if (is_blank(str[i])) {
			i++;
		}
	}
	return 1;
}

int			main(int ac, char **av) {
	if (ac == 2) {
		if (check(av[1])) {
			if (solve(av[1])) {
				printf("%i\n", nr[0]);
				return 0;
			}
		}
	}
	printf("Error\n");
	return 0;
}
