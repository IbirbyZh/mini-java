cmake_minimum_required(VERSION 3.7)
project(mini_java)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-ly")
set(CMAKE_CXX_FLAGS "-ll")


file(MAKE_DIRECTORY src)
file(MAKE_DIRECTORY src/bison)
file(MAKE_DIRECTORY src/flex)

set(NonTerminalNodes ${CMAKE_SOURCE_DIR}/nodes/non_terminal)
set(TerminalNodes ${CMAKE_SOURCE_DIR}/nodes/terminal)

set(NodeHeaders
        ${NonTerminalNodes}/IId.cpp
        )


set(NodeSrc
        ${NonTerminalNodes}/IId.cpp
        )


set(Visitors ${CMAKE_SOURCE_DIR}/visitors)

set(VisitorHeaders
        ${Visitors}/IVisitor.hpp
        ${Visitors}/PrettyPrinter.hpp
        )

set(VisitorSrc
        ${Visitors}/PrettyPrinter.cpp
        )


set(BisonFile ${CMAKE_SOURCE_DIR}/bison.y)
set(BisonOutput ${CMAKE_SOURCE_DIR}/src/bison/parser.cpp)
set(BisonTokens ${CMAKE_SOURCE_DIR}/src/bison/tokens.h)

set(FlexFile ${CMAKE_SOURCE_DIR}/flex.y)
set(FlexOutput ${CMAKE_SOURCE_DIR}/src/flex/scanner.c)

find_package(BISON 3.)
if (NOT BISON_FOUND)
    set(BISON_EXECUTABLE /usr/local/opt/bison/bin/bison)
    set(BISON_FOUND TRUE)
endif ()

if (BISON_FOUND)
    add_custom_command(
            OUTPUT ${BisonOutput} ${BisonTokens}
            COMMAND ${BISON_EXECUTABLE}
            --defines=${BisonTokens}
            --output=${BisonOutput}
            ${BisonFile}
            MAIN_DEPENDENCY ${BisonFile}
            COMMENT "Generating parser.cpp and tokens.h ${BisonFile}"

    )
endif ()

find_package(FLEX 2.6)
if (NOT FLEX_FOUND)
    set(FLEX_EXECUTABLE /usr/local/opt/flex/bin/flex)
    set(FLEX_FOUND TRUE)
endif ()

if (FLEX_FOUND)
    include_directories(${CMAKE_SOURCE_DIR}/src/bison)
    add_custom_command(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
            --outfile=${FlexOutput}
            ${FlexFile}
            MAIN_DEPENDENCY ${FlexFile} ${BisonTokens}
            COMMENT "Generating scanner.cpp from ${FlexFile}"
    )
endif ()

add_library(flex_scanner ${FlexOutput})
add_executable(mini-java ${BisonOutput})
target_link_libraries(mini-java flex_scanner)

include_directories(${NonTerminalNodes} ${Visitors})
add_library(nodes STATIC ${NodeHeaders} ${VisitorHeaders} ${NodeSrc} ${VisitorSrc})

