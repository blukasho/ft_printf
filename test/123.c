#include <stdio.h>
#include <string.h>

typedef struct						s_uint80
{
	size_t		: 52;
	size_t		sign : 1;
	size_t		hi : 11;
	size_t		lo;
}	__attribute__((aligned(128)))	t_uint80;

int 			main(void)
{
	long double ld;
	//__int128	*a;
	t_uint80	b;

	ld = 345.865;
	//a = (__int128 *)&ld;
	//b = *a;
	b = *(t_uint80*)(&ld);
	return (0);
}
