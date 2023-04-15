#ifndef GENERATOR_GENERATOR_H
#define GENERATOR_GENERATOR_H

#include <stdint.h>

typedef void (*GeneratorPublisher_t)(uint32_t *data, uint32_t size);

typedef struct GeneratorConfig
{
    GeneratorPublisher_t publisher;
} GeneratorConfig_t;

void Generator_init(GeneratorConfig_t *config);

void Generator_generate();

#endif // GENERATOR_GENERATOR_H
