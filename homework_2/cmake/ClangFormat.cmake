# Adapted fromm  https://github.com/ttroy50/cmake-examples/
find_program(CLANG_FORMAT "clang-format")
if(NOT CLANG_FORMAT)
  message(SEND_ERROR "clang-format not found on your \$\{PATH\}")
endif()

# Split the regex into multiple parts
set(EXCLUDE_BUILD "-path ./build -prune -o")
set(CPP_EXT "'.*\\.(cpp|cxx|cc|hpp|hxx|h)'")
set(TRIM_OUT "-print |  tr '\\n' ';'")

if (APPLE)
set(REGEX "-regex")
set(BASH_COMMAND "find -E . ${EXCLUDE_BUILD} ${REGEX} ${CPP_EXT} ${TRIM_OUT}")
else()
set(REGEX "-regextype posix-extended -regex")
set(BASH_COMMAND "find . ${EXCLUDE_BUILD} ${REGEX} ${CPP_EXT} ${TRIM_OUT}")
endif()

# Get all project files
execute_process(
  COMMAND bash -c "${BASH_COMMAND}"
  OUTPUT_VARIABLE ALL_SOURCES
  OUTPUT_STRIP_TRAILING_WHITESPACE
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_custom_target(${PROJECT_NAME}_format ALL
                  COMMENT "Checking clang-format changes"
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                  COMMAND ${CLANG_FORMAT} -Werror
                          --dry-run --ferror-limit=1 -style=file ${ALL_SOURCES})
