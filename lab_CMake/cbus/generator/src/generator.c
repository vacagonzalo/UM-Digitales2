#include "generator/generator.h"

#ifndef GENERATOR_DATA_SIZE
#define GENERATOR_DATA_SIZE 5U
#endif

GeneratorPublisher_t generatorPublisher;

uint32_t data[GENERATOR_DATA_SIZE] = {0};

void Generator_init(GeneratorConfig_t *config)
{
    generatorPublisher = config->publisher;
}

void Generator_generate()
{
    for (uint32_t i = 0; i < (uint32_t)GENERATOR_DATA_SIZE; ++i)
    {
        data[i] = data[i] + i;
    }
    (*generatorPublisher)(data, (uint32_t)GENERATOR_DATA_SIZE);
}
