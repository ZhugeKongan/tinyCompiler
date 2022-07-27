cmake_minimum_required(VERSION 3.21)
project(tinyCompiler)

set(CMAKE_CXX_STANDARD 11)

add_executable(tinyCompiler main.cpp Tokenizer.h Tokenizer.cpp Token.h Token.cpp Enum.h print.h AST.h Parser.h Parser.cpp Tools.h Transformer.h Transformer.cpp Complier.h Complier.cpp Tools.cpp print.cpp CodeGenerator.h CodeGenerator.cpp)
