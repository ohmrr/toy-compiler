#pragma once

#include <string>

// Use `enum class` to avoid values leaking into namespace
enum class TokenKind {
    Identifier,
    Number,

    Plus,
    Minus,
    Star,
    Slash,

    Equal,
    Semicolon,

    EndOfFile,
    Invalid
};

struct Token {
    TokenKind kind;
    std::string text;
    int line;
    int column;
};
