#include <iostream>
#include <string.h>

static void print_usage(const char *caller)
{
    std::cout << "Usage:\n\t" << caller << std::endl;
}

int main(int argc, char **argv)
{
    if (argc >= 2 && !strcmp(argv[1], "-h")) {
        print_usage(argv[0]);
        return 0;
    }
}
