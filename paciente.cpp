#include "paciente.h"
#include "validaciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Paciente::Paciente(int ID, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& fechaNacimiento, const std::string& diagnostico)
    : IDPaciente(ID), nombre(nombre), direccion(direccion), genero(genero), fechaNacimiento(fechaNacimiento), diagnostico(diagnostico), estado(true) {
}

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

void Paciente::registrarPaciente(std::vector<Paciente>& listaPacientes, int& contadorPaciente) {
    std::string nombre, direccion, genero, fechaNacimiento, diagnostico;

    do {
        std::cout << "Ingrese nombre del paciente: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
    } while (!validarVacio(nombre, "Nombre"));

    do {
        std::cout << "Ingrese direccion del paciente: ";
        std::getline(std::cin, direccion);
    } while (!validarVacio(direccion, "Direccion"));

    do {
        std::cout << "Ingrese genero (M/F/Otro): ";
        std::getline(std::cin, genero);
    } while (!validarGenero(genero));

    do {
        std::cout << "Ingrese fecha de nacimiento (dd-mm-yyyy): ";
        std::getline(std::cin, fechaNacimiento);
    } while (!validarFecha(fechaNacimiento));

    do {
        std::cout << "Ingrese diagnostico: ";
        std::getline(std::cin, diagnostico);
    } while (!validarVacio(diagnostico, "Diagnostico"));

    Paciente nuevoPaciente(contadorPaciente++, nombre, direccion, genero, fechaNacimiento, diagnostico);
    listaPacientes.push_back(nuevoPaciente);
    std::cout << "Paciente registrado con exito.\n";
}

void Paciente::modificarPaciente(std::vector<Paciente>& listaPacientes) {
    int ID;
    std::string nuevoNombre, nuevaDireccion, nuevoDiagnostico;
    std::cout << "Ingrese el ID del paciente a modificar: ";
    std::cin >> ID;

    bool encontrado = false;
    for (auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            encontrado = true;

            do {
                std::cout << "Ingrese nuevo nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoNombre);
            } while (!validarVacio(nuevoNombre, "Nombre"));

            do {
                std::cout << "Ingrese nueva direccion: ";
                std::getline(std::cin, nuevaDireccion);
            } while (!validarVacio(nuevaDireccion, "Direccion"));

            do {
                std::cout << "Ingrese nuevo diagnostico: ";
                std::getline(std::cin, nuevoDiagnostico);
            } while (!validarVacio(nuevoDiagnostico, "Diagnostico"));

            paciente.modificarDatos(nuevoNombre, nuevaDireccion, nuevoDiagnostico);
            std::cout << "Paciente modificado con exito.\n";
            return;
        }
    }
    if (!encontrado) {
        std::cout << "Paciente no encontrado.\n";
    }
}

void Paciente::eliminarPaciente(std::vector<Paciente>& listaPacientes) {
    int IDPaciente;
    std::cout << "Ingrese el ID del paciente a eliminar: ";
    std::cin >> IDPaciente;

    auto it = std::find_if(listaPacientes.begin(), listaPacientes.end(),
        [IDPaciente](const Paciente& p) {
            return p.getIDPaciente() == IDPaciente;
        });

    if (it != listaPacientes.end()) {
        listaPacientes.erase(it);
        std::cout << "El paciente seleccionado ha sido eliminado.\n";
    }
    else {
        std::cout << "El paciente seleccionado no ha sido encontrado.\n";
    }
}

void Paciente::altaBajaPaciente(std::vector<Paciente>& listaPacientes) {
    int ID;
    int opcion;

    std::cout << "Ingrese ID del paciente: ";
    std::cin >> ID;

    for (auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            std::cout << "Seleccione:\n1. Dar de alta\n2. Dar de baja\nOpcion: ";
            std::cin >> opcion;

            if (opcion == 1) {
                paciente.darDeAlta();
                std::cout << "Paciente dado de alta.\n";
            }
            else if (opcion == 2) {
                paciente.darDeBaja();
                std::cout << "Paciente dado de baja.\n";
            }
            else {
                std::cout << "Opcion invalida.\n";
            }
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Paciente::buscarPaciente(const std::vector<Paciente>& listaPacientes) {
    int ID;

    std::cout << "Ingrese el ID del paciente a buscar: ";
    std::cin >> ID;

    for (const auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            paciente.mostrarInformacion();
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Paciente::listarPacientes(const std::vector<Paciente>& listaPacientes) {
    if (listaPacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }

    std::cout << "Lista de Pacientes: \n";
    for (const auto& paciente : listaPacientes) {
        paciente.mostrarInformacion();
        std::cout << "------------------\n";
    }
}

void Paciente::cargarPacientes(std::vector<Paciente>& listaPacientes, int& contadorPaciente) {
    std::ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        std::cout << "No se encontro el archivo, creando uno nuevo...\n";
        return;
    }

    listaPacientes.clear();
    std::string linea;
    int maxID = 0;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string IDPaciente, nombre, direccion, genero, fechaNacimiento, diagnostico, estado;

        std::getline(ss, IDPaciente, '|');
        std::getline(ss, nombre, '|');
        std::getline(ss, direccion, '|');
        std::getline(ss, genero, '|');
        std::getline(ss, fechaNacimiento, '|');
        std::getline(ss, diagnostico, '|');
        std::getline(ss, estado, '|');

        bool estadoBool = (estado == "Activo");
        listaPacientes.emplace_back(std::stoi(IDPaciente), nombre, direccion, genero, fechaNacimiento, diagnostico);
        if (!estadoBool) {
            listaPacientes.back().darDeBaja();
        }
        maxID = std::max(maxID, std::stoi(IDPaciente));
    }

    contadorPaciente = maxID + 1;
    archivo.close();
    std::cout << "Datos de los pacientes cargados correctamente.\n";
}

void Paciente::guardarPacientes(const std::vector<Paciente>& listaPacientes) {
    std::ofstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo de pacientes.\n";
        return;
    }
    for (const auto& paciente : listaPacientes) {
        archivo << paciente.getIDPaciente() << "|"
            << paciente.getNombre() << "|"
            << paciente.getDireccion() << "|"
            << paciente.getGenero() << "|"
            << paciente.getFechaNacimiento() << "|"
            << paciente.getDiagnostico() << "|"
            << paciente.getEstado() << "\n";
    }

    archivo.close();
    std::cout << "Los datos de los pacientes han sido guardados correctamente.\n";
}