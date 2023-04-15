project(console)

add_library(${PROJECT_NAME} src/console.c)

target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)