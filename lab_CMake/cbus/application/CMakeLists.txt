project(application)

add_executable(${PROJECT_NAME} main.c application.c)

target_link_libraries(${PROJECT_NAME}
  console
  generator
)
