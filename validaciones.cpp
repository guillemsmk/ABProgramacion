#include "validaciones.h"
#include <iostream>
#include <regex>

bool validarFecha(const std::string& fechaNacimiento) {
    std::regex formatoFecha(R"(^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\d{4})$)");

    if (!std::regex_match(fechaNacimiento, formatoFecha)) {
        std::cout << "Formato invalido.\n";
        return false;
    }

    int dia = std::stoi(fechaNacimiento.substr(0, 2));
    int mes = std::stoi(fechaNacimiento.substr(3, 2));
    int anio = std::stoi(fechaNacimiento.substr(6, 4));

    if (mes == 2) {
        bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if (dia > (bisiesto ? 29 : 28)) return false;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return false;
    }
    else {
        if (dia > 31) return false;
    }
    return true;
}

bool validarGenero(const std::string& genero) {
    if (genero == "M" || genero == "F" || genero == "Otro") {
        return true;
    }
    else {
        std::cout << "Genero invalido.\n";
        return false;
    }
}

bool validarVacio(const std::string& entrada, const std::string& campo) {
    if (entrada.empty()) {
        std::cout << "El campo '" << campo << "' no puede estar vacio.\n";
        return false;
    }
    return true;
}

bool validarHora(const std::string& hora) {
    std::regex formatoHora(R"(^([01]\d|2[0-3]):([0-5]\d)$)");
    return std::regex_match(hora, formatoHora);
}