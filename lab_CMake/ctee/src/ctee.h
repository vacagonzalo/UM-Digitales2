#ifndef CTEE_H
#define CTEE_H

typedef struct CteeConfig
{
    int append;
    char *fileName;
} CteeConfig_t;

int Ctee_run(CteeConfig_t *config);

#endif // CTEE_H
