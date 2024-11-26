#include "paciente.h"
#include <iostream>

int Paciente::contadorPacientes = 0;

Paciente::Paciente() : IDPaciente(++contadorPacientes) {}

int Paciente::getIDPaciente() const {
    return IDPaciente;
}

void Paciente::registrarPersona() {
    Persona::registrarPersona();

    std::cout << "Ingrese la fecha de nacimiento (DD/MM/AAAA): ";
    std::cin.ignore();
    std::getline(std::cin, fechaNacimiento);

    std::cout << "Ingrese el genero (M/F/Otro): ";
    std::getline(std::cin, genero);
}

void Paciente::mostrarPersona() const {
    Persona::mostrarPersona();
    std::cout << "Fecha de Nacimiento: " << fechaNacimiento << "\n";
    std::cout << "Genero: " << genero << "\n";
}
