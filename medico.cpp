#include "medico.h"
#include <iostream>

int Medico::contadorMedicos = 0;

Medico::Medico() : IDMedico(++contadorMedicos) {}

int Medico::getIDMedico() const {
    return IDMedico;
}

void Medico::registrarPersona() {
    Persona::registrarPersona();

    std::cout << "Ingrese la especialidad: ";
    std::cin.ignore();
    std::getline(std::cin, especialidad);
}

void Medico::mostrarPersona() const {
    Persona::mostrarPersona();
    std::cout << "Especialidad: " << especialidad << "\n";
}
