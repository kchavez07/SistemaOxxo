#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

namespace Input {

    inline void limpiarLinea() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline std::string leerTexto(const std::string& prompt) {
        std::cout << prompt;
        std::string s;
        std::getline(std::cin, s);
        return s;
    }

    inline int leerInt(const std::string& prompt, int min, int max) {
        while (true) {
            std::cout << prompt;
            int v{};
            if (std::cin >> v && v >= min && v <= max) {
                limpiarLinea();
                return v;
            }
            std::cin.clear();
            limpiarLinea();
            std::cout << "Entrada inválida. Intenta de nuevo.\n";
        }
    }

    inline double leerDouble(const std::string& prompt, double min) {
        while (true) {
            std::cout << prompt;
            double v{};
            if (std::cin >> v && v >= min) {
                limpiarLinea();
                return v;
            }
            std::cin.clear();
            limpiarLinea();
            std::cout << "Entrada inválida. Intenta de nuevo.\n";
        }
    }

    inline bool leerSiNo(const std::string& prompt) {
        while (true) {
            std::cout << prompt << " (s/n): ";
            char c{};
            if (std::cin >> c) {
                limpiarLinea();
                c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                if (c == 's') return true;
                if (c == 'n') return false;
            }
            std::cin.clear();
            limpiarLinea();
            std::cout << "Entrada inválida. Intenta de nuevo.\n";
        }
    }

}
