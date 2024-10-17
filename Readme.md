(_OBS_: para ver um guia sobre a criação de testes de unidade, veja [Testes.md](Testes.md))

# A minimal C library template using Modern CMake

An example to demonstrate how to organize files for writing a library in the C language using Modern CMake.

## Project structure

```bash
.
|-- CMakeLists.txt
|-- main.c
|-- LICENSE
|-- Readme.md
`-- libprg
    |-- CMakeLists.txt
    `-- src
        |-- include
        |   `-- libprg
        |       `-- libprg.h
        |        -- lista_linear.h
        `-- libprg
            `-- lista_linear.c
```

## How to use this library in a C application using CMake

CMake [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) can download this library directly from his GitHub repository and you must indicate from which branch or tag. In this example I will use the `main` branch or the `0.0.1` tag.

Create a new project (C executable) using CMake and your `CMakeLists.txt` file should look like this:

```cmake
cmake_minimum_required(VERSION 3.21)
project(myapp C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    libprg
    GIT_REPOSITORY https://github.com/IFSC-Engtelecom-Prg2/libprg.git
    GIT_TAG origin/main 
    # or GIT_TAG 0.0.1
    
    # You can reference a local directory instead
    # URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../libprg
)
FetchContent_MakeAvailable(libprg)

add_executable(myapp main.c)

# linking libprg
target_link_libraries(myapp PUBLIC libprg)
```

And your `main.c`  should look like this:
```c
#include <stdio.h>
#include <libprg/libprg.h>

int main(void) {
    lista_linear_t * lista = lista_linear_cria();

    lista_linear_adiciona(lista, "um");
    lista_linear_adiciona(lista, "teste");
    lista_linear_adiciona(lista, "simples");

    for (int j=0; j < lista_linear_comprimento(); j++) {
      printf("lista[%d] = %s\n", j, lista_linear_obtem(lista, j);
    }

    lista_linear_destroi(lista);

    return 0;
}
```

# References

- https://cliutils.gitlab.io/modern-cmake/
- https://blog.feabhas.com/2021/08/cmake-part-3-source-file-organisation/
- https://iakko.medium.com/creating-a-c-shared-library-with-cmake-50c6d2f97ee8
