#include <stdio.h>

void bar() { printf("This is function:bar at line %d\n", __LINE__); }

int main(int argc, char **argv) {
    bar();
    return 0;
}