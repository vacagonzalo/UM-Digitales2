#include "ctee.h"

#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int Ctee_run(CteeConfig_t *config)
{
    int fd;
    if (1 == config->append)
    {
        fd = open(config->fileName, O_APPEND | O_WRONLY);
    }
    else
    {
        fd = open(config->fileName, O_CREAT | O_WRONLY | O_TRUNC,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    }
    if (fd < 0)
    {
        return fd;
    }
    char buffer[BUFFER_SIZE] = {0};
    int numr = 0;
    while ((numr = read(STDIN_FILENO, (void *)buffer, BUFFER_SIZE)) > 0)
    {
        write(fd, (const void *)buffer, numr);
        write(STDOUT_FILENO, (const void *)buffer, numr);
    }
    close(fd);
    return 0;
}
