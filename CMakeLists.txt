cmake_minimum_required(VERSION 3.7)
project(mini_java)

set(BisonFile ${CMAKE_SOURCE_DIR}/bison.y)
set(BisonOutput ${CMAKE_SOURCE_DIR}/src/bison/parser.c)
set(BisonTokens ${CMAKE_SOURCE_DIR}/src/bison/tokens.h)

set(FlexFile ${CMAKE_SOURCE_DIR}/flex.y)
set(FlexOutput ${CMAKE_SOURCE_DIR}/src/flex/scanner.c)

find_package(BISON REQUIRED)
if(BISON_FOUND)
    add_custom_command(
            OUTPUT ${BisonOutput}
            COMMAND ${BISON_EXECUTABLE}
            --defines=${BisonTokens}
            --output=${BisonOutput}
            ${BisonFile}
            MAIN_DEPENDENCY ${BisonFile}
            COMMENT "Generating parser.cpp and tokens.h from ${BisonFile}"

    )
endif()

find_package(FLEX REQUIRED)

if(FLEX_FOUND)
    include_directories(${CMAKE_SOURCE_DIR}/src/bison)
    add_custom_command(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
            --outfile=${FlexOutput}
            ${FlexFile}
            MAIN_DEPENDENCY ${FlexFile}
            COMMENT "Generating scanner.cpp from ${FlexFile}"
    )
endif()

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-ly")
add_executable(mini-java ${BisonOutput} ${FlexOutput})

