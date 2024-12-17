#include "paciente.h"
#include <iostream>

Paciente::Paciente(int ID, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& fechaNacimiento, const std::string& diagnostico)
    : IDPaciente(ID), nombre(nombre), direccion(direccion), genero(genero), fechaNacimiento(fechaNacimiento), diagnostico(diagnostico), estado(true) {}

int Paciente::getIDPaciente() const { return IDPaciente; }
std::string Paciente::getNombre() const { return nombre; }
std::string Paciente::getDireccion() const { return direccion; }
std::string Paciente::getGenero() const { return genero; }
std::string Paciente::getFechaNacimiento() const { return fechaNacimiento; }
std::string Paciente::getDiagnostico() const { return diagnostico; }
std::string Paciente::getEstado() const { return estado ? "Activo" : "Inactivo"; }

void Paciente::modificarDatos(const std::string& nuevoNombre, const std::string& nuevaDireccion, const std::string& nuevoDiagnostico) {
    nombre = nuevoNombre;
    direccion = nuevaDireccion;
    diagnostico = nuevoDiagnostico;
}

void Paciente::darDeAlta() { estado = true; }
void Paciente::darDeBaja() { estado = false; }

void Paciente::mostrarInformacion() const {
    std::cout << "ID: " << IDPaciente << "\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Direccion: " << direccion << "\n";
    std::cout << "Genero: " << genero << "\n";
    std::cout << "Fecha de Nacimiento: " << fechaNacimiento << "\n";
    std::cout << "Diagnostico: " << diagnostico << "\n";
    std::cout << "Estado: " << getEstado() << "\n";
}