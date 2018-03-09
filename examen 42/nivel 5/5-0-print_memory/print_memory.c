#include <unistd.h>

static void print_hexa(unsigned char c) {
	unsigned char c1 = c / 16, c2 = c % 16;

	if (c1 < 10) {
		unsigned char q = c1 + '0';
		write(1, &q, 1);
	}
	else {
		unsigned char q = c1 + 87;
		write(1, &q, 1);
	}
	if (c2 < 10) {
		unsigned char q = c2 + '0';
		write(1, &q, 1);
	}
	else {
		unsigned char q = c2 + 87;
		write(1, &q, 1);
	}
}

static void	print_char(unsigned char c) {
	if (c >= ' ' && c <= '~') {
		write (1, &c, 1);
	}
	else {
		write (1, ".", 1);
	}
}

void	print_memory(const void *addr, size_t size) {
	unsigned char *str = (unsigned char*)addr;

	size_t i = 0;
	while (i < size) {
		for (size_t j = 0; j < 16; j++) {
			if (i + j < size) {
				print_hexa(str[i + j]);
			}
			else {
				write (1, "  ", 2);
			}
			if (j % 2) {
				write(1, " ", 1);
			}
		}
		for (size_t j = 0; j < 16; j++) {
			if (i + j < size) {
				print_char(str[i + j]);
			}
		}
		write (1, "\n", 1);
		i += 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}
