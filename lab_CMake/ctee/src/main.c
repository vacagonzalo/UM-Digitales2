#include "ctee.h"
#include <stdio.h>
#include <unistd.h>

static CteeConfig_t cteeConfig = {.append = 0, .fileName = "\0"};

void PrintUsage();
int ConfigInit(CteeConfig_t *config, int argc, char **argv);

int main(int argc, char **argv)
{
    int res = ConfigInit(&cteeConfig, argc, argv);
    if (res)
    {
        PrintUsage();
        return -1;
    }
    return Ctee_run(&cteeConfig);
}

void PrintUsage()
{
    printf("ctee - a simple clone of tee(1)\n\r");
    printf("This program will read the stdin and write its content into the stdout and a file\n\r");
    printf("Usage: ctee -a <fileName> | ctee -n <fileName>\n\r");
    printf("Example: echo hello | ctee -n file.txt\n\r");
}

int ConfigInit(CteeConfig_t *config, int argc, char **argv)
{
    if (argc < 3)
    {
        return -1;
    }
    int option;
    if (-1 != (option = getopt(argc, argv, "an")))
    {
        switch (option)
        {
        case 'a':
            config->append = 1;
            break;
        case 'n':
            config->append = 0;
            break;
        default:
            return -1;
        }
        config->fileName = argv[2];
    }
    return 0;
}
