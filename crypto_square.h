#pragma once

#include <string>

namespace crypto_square {

class cipher {
public:
    // Constructor que recibe el texto de entrada
    explicit cipher(const std::string& text);

    // Método que evalúa el test
    std::string normalized_cipher_text() const;

private:
    std::string text_;
};

} // namespace crypto_square