#include <stdlib.h>
#include <stdio.h>

static int	get_len(long val, int base) {
	int size = 1;
	if (val == 0) {
		return 1;
	}
	while (val / base > 0) {
		size++;
		val /= base;
	}
	return size;
}

char	*ft_itoa_base(int value, int base) {
	long val;
	int	ind = 0;
	if (value < 0) {
		val = value;
		val = -val;
		if (base == 10) {
			ind = 1;
		}
	}
	else {
		val = value;
	}
	int len = get_len(val, base);
	len += ind;
	printf("%i\n", len);
	char *nr = (char*)malloc(sizeof(char) * (len + 1));
	nr[len] = '\0';
	if (ind == 1) {
		nr[0] = '-';
		len++;
	}
	if (val == 0) {
		nr[0] = '0';
		return (nr);
	}
	while (val != 0) {
		int c = val % base;
		if (c < 10) {
			nr[len - ++ind] = c + '0';
		}
		else {
			nr[len - ++ind] = c + 87;
		}
		val /= base;
	}
	return nr;
}

int	main(void) {
	printf("%s\n", ft_itoa_base(2147483647, 10));
	printf("%s\n", ft_itoa_base(-2147483648, 10));
	return 0;
}
