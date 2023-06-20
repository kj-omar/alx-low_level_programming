#include <unistd.h>

int main() {
    char i[] = "_putchar\n";
    write(STDOUT_FILENO, i, sizeof(i) - 1);

    return 0;
}
