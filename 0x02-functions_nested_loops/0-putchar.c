#include <unistd.h>
#include <main.h>

int main(void)

{
	char i[] = "_putchar\n";

	write(STDOUT_FILENO, i, sizeof(i) - 1);

	return (0);
}
