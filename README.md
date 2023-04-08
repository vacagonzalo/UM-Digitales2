# UM-Digitales2

Repositorio de la cátedra **Digitales II** de la [Universidad de Morón](https://www.unimoron.edu.ar/)

## Laboratorio FreeRTOS

### Requerimientos

#### Trabajo en docker compose

* docker

#### Trabajo en host

* git
* gcc
* make

### Preparar el ambiente de trabajo

Sin importar el modo de trabajo preferido (docker o host), usted debe clonar este repositorio.

#### Trabajo en docker compose

* Ejecutar el comando `docker compose up`
* Cuando se cree el entorno, abrir otra terminal y ejecutar `docker exec -it td2lab bash`
* Seguir los pasos de *trabajo en host*

#### Trabajo en host
* Ejecutar el comando `make`

En este punto usted debería contar con todas las dependencias necesarias y todos los proyectos compilados.

### Uso del laboratorio

Con el ambiente de trabajo preparado, usted puede ingresar a la carpeta `lab_FreeRTOS`.
En ella encontrará proyectos de ejemplo ya compilados en el paso anterior.
Si desea experimentar con alguno en particular, ingrese dentro de la carpeta del proyecto de su interés y ejecute el comando `make`.
Encontrará en la carpeta `build` el binario listo para ejecutar.
