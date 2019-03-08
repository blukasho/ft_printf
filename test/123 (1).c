#include <stdio.h>
#include <string.h>

typedef struct						s_uint80
{
	size_t		hi;
	size_t		sign : 1;
	size_t		lo : 11;
	size_t		: 64 - 11 - 1;

}	__attribute__((aligned(128)))	t_uint80;

int 			main(void)
{
	long double ld;
	t_uint80	b;

	ld = 345.865;
	b = *(t_uint80*)(&ld);
STOP:	return (0);
}
