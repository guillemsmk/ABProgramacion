#include "persona.h"
#include <iostream>

void Persona::registrarPersona() {
    std::cout << "Ingrese el nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la direccion: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese el telefono: ";
    std::getline(std::cin, telefono);
}

void Persona::mostrarPersona() const {
    std::cout << "Nombre: " << nombre << "";
    std::cout << "Direccion: " << direccion << "";
    std::cout << "Telefono: " << telefono << "";
}
