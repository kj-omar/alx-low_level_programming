#include <unistd.h>

int _puts(char c)
{
	return (write(1, &c, 1));
}
