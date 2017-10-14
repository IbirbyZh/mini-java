cmake_minimum_required(VERSION 3.7)
project(mini_java)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-ly")

file(MAKE_DIRECTORY src)
file(MAKE_DIRECTORY src/bison)
file(MAKE_DIRECTORY src/flex)

set(NodeSrc
        nodes/INode.hpp
        nodes/Nodes.hpp
        nodes/IdExpression.hpp nodes/IdExpression.cpp
        nodes/IntegerExpression.hpp nodes/IntegerExpression.cpp
        nodes/BooleanExpression.hpp nodes/BooleanExpression.cpp
        nodes/IntegerArithmeticOperation.hpp nodes/IntegerArithmeticOperation.cpp
        nodes/BooleanArithmeticOperation.hpp nodes/BooleanArithmeticOperation.cpp
        nodes/GetItemAtPosition.hpp nodes/GetItemAtPosition.cpp
        nodes/CallMethod.hpp nodes/CallMethod.cpp
        nodes/GetLength.cpp nodes/GetLength.hpp
        nodes/CreateNewObject.cpp nodes/CreateNewObject.hpp
        nodes/CreateNewArray.cpp nodes/CreateNewArray.hpp
        nodes/GetThisId.cpp nodes/GetThisId.hpp
        nodes/CallMethodParameters.cpp nodes/CallMethodParameters.hpp
        nodes/StatementSequence.cpp nodes/StatementSequence.hpp
        nodes/Assignment.cpp nodes/Assignment.hpp nodes/AssignmentAtPosition.cpp nodes/AssignmentAtPosition.hpp)


set(VisitorSrc
        visitors/IVisitor.hpp
        visitors/PrettyPrinter.hpp
        visitors/PrettyPrinter.cpp
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

include_directories(nodes visitors)

add_library(nodes STATIC ${NodeSrc})
add_library(visitors ${VisitorSrc})
add_library(flex_scanner ${FlexOutput})

add_executable(mini-java ${BisonOutput})

target_link_libraries(mini-java nodes)
target_link_libraries(mini-java visitors)
target_link_libraries(mini-java flex_scanner)




