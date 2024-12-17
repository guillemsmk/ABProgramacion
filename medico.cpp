#include "medico.h"
#include <iostream>

Medico::Medico(int ID, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& especialidad)
    : IDMedico(ID), nombre(nombre), direccion(direccion), genero(genero), especialidad(especialidad), estado(true) {}

int Medico::getIDMedico() const { return IDMedico; }
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getDireccion() const { return direccion; }
std::string Medico::getGenero() const { return genero; }
std::string Medico::getEspecialidad() const { return especialidad; }
std::string Medico::getEstado() const { return estado ? "Activo" : "Inactivo"; }

void Medico::modificarDatos(const std::string& nuevaDireccion, const std::string& nuevaEspecialidad) {
    direccion = nuevaDireccion;
    especialidad = nuevaEspecialidad;
}

void Medico::darDeAlta() { estado = true; }
void Medico::darDeBaja() { estado = false; }

void Medico::mostrarInformacion() const {
    std::cout << "ID: " << IDMedico << "\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Direccion: " << direccion << "\n";
    std::cout << "Genero: " << genero << "\n";
    std::cout << "Especialidad: " << especialidad << "\n";
    std::cout << "Estado: " << getEstado() << "\n";
}