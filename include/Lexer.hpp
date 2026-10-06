#pragma once

#include <vector>
#include <string>

class Lexer {
    std::vector<std::string> source;

    Lexer();

    void tokenize();
};
