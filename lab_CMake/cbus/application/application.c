#include "application.h"

#include "console/console.h"
#include "generator/generator.h"

static GeneratorConfig_t generatorConfig = {.publisher = &Console_send};

void Application_run()
{
    Console_init();
    Generator_init(&generatorConfig);
    Generator_generate();
    Generator_generate();
    Generator_generate();
}
