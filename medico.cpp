#include "medico.h"
#include "validaciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Medico::Medico(int ID, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& especialidad)
    : IDMedico(ID), nombre(nombre), direccion(direccion), genero(genero), especialidad(especialidad), estado(true) {}

int Medico::getIDMedico() const { return IDMedico; }
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getDireccion() const { return direccion; }
std::string Medico::getGenero() const { return genero; }
std::string Medico::getEspecialidad() const { return especialidad; }
std::string Medico::getEstado() const { return estado ? "Activo" : "Inactivo"; }

void Medico::modificarDatos(const std::string& nuevoNombre, const std::string& nuevaDireccion, const std::string& nuevaEspecialidad) {
    nombre = nuevoNombre;
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

std::vector<Medico> listaMedicos;
int contadorMedico = 1;

void Medico::registrarMedico() {
    std::string nombre, direccion, genero, especialidad;

    do {
        std::cout << "Ingrese nombre del medico: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
    } while (!validarVacio(nombre, "Nombre"));

    do {
        std::cout << "Ingrese direccion del medico: ";
        std::getline(std::cin, direccion);
    } while (!validarVacio(direccion, "Direccion"));

    do {
        std::cout << "Ingrese genero (M/F/Otro): ";
        std::getline(std::cin, genero);
    } while (!validarGenero(genero));

    do {
        std::cout << "Ingrese especialidad del medico: ";
        std::getline(std::cin, especialidad);
    } while (!validarVacio(especialidad, "Especialidad"));

    Medico nuevoMedico(contadorMedico++, nombre, direccion, genero, especialidad);
    listaMedicos.push_back(nuevoMedico);
    std::cout << "Medico registrado con exito.\n";
}

void Medico::modificarMedico() {
    int ID;
    std::string nuevoNombre, nuevaDireccion, nuevaEspecialidad;

    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> ID;

    bool encontrado = false;
    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            encontrado = true;

            do {
                std::cout << "Ingrese nuevo nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoNombre);
            } while (!validarVacio(nuevoNombre, "Nombre"));

            do {
                std::cout << "Ingrese nueva direccion: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaDireccion);
            } while (!validarVacio(nuevaDireccion, "Direccion"));

            do {
                std::cout << "Ingrese nueva especialidad: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaEspecialidad);
            } while (!validarVacio(nuevaEspecialidad, "Especialidad"));

            medico.modificarDatos(nuevoNombre, nuevaDireccion, nuevaEspecialidad);
            std::cout << "Medico modificado con exito.\n";
            return;
        }
    }
    if (!encontrado) {
        std::cout << "Medico no encontrado.\n";
    }
}

void Medico::eliminarMedico() {
    int IDMedico;
    std::cout << "Ingrese el ID del medico a eliminar: ";
    std::cin >> IDMedico;

    auto it = std::find_if(listaMedicos.begin(), listaMedicos.end(),
        [IDMedico](const Medico& m) {
            return m.getIDMedico() == IDMedico;
        });

    if (it != listaMedicos.end()) {
        listaMedicos.erase(it);
        std::cout << "El medico seleccionado ha sido eliminado.\n";
    }
    else {
        std::cout << "El medico seleccionado no ha sido encontrado.\n";
    }
}

void Medico::altaBajaMedico() {
    int ID;
    int opcion;

    std::cout << "Ingrese ID del medico: ";
    std::cin >> ID;

    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            std::cout << "Seleccione:\n1. Dar de alta\n2. Dar de baja\nOpcion: ";
            std::cin >> opcion;

            if (opcion == 1) {
                medico.darDeAlta();
                std::cout << "Medico dado de alta.\n";
            }
            else if (opcion == 2) {
                medico.darDeBaja();
                std::cout << "Medico dado de baja.\n";
            }
            else {
                std::cout << "Opcion invalida.\n";
            }
            return;
        }
    }
    std::cout << "Medico no encontrado.\n";
}

void Medico::buscarMedico() {
    int ID;

    std::cout << "Ingrese el ID del medico a buscar: ";
    std::cin >> ID;

    for (const auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            medico.mostrarInformacion();
            return;
        }
    }
    std::cout << "Medico no encontrado.\n";
}

void Medico::listarMedicos() {
    if (listaMedicos.empty()) {
        std::cout << "No hay medicos registrados.\n";
        return;
    }

    std::cout << "Lista de Medicos: \n";
    for (const auto& medico : listaMedicos) {
        medico.mostrarInformacion();
        std::cout << "------------------\n";
    }
}

void Medico::cargarMedicos() {
    std::ifstream archivo("medicos.txt");
    if (!archivo.is_open()) {
        std::cout << "No se encontro el archivo, creando uno nuevo...\n";
        return;
    }

    listaMedicos.clear();
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string IDMedico, nombre, direccion, genero, especialidad, estado;

        std::getline(ss, IDMedico, '|');
        std::getline(ss, nombre, '|');
        std::getline(ss, direccion, '|');
        std::getline(ss, genero, '|');
        std::getline(ss, especialidad, '|');
        std::getline(ss, estado, '|');

        bool estadoBool = (estado == "Activo");
        listaMedicos.emplace_back(std::stoi(IDMedico), nombre, direccion, genero, especialidad);
        if (!estadoBool) {
            listaMedicos.back().darDeBaja();
        }
    }

    archivo.close();
    std::cout << "Datos de los medicos cargados correctamente.\n";
}

void Medico::guardarMedicos() {
    std::ofstream archivo("medicos.txt");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo de medicos.\n";
        return;
    }
    for (const auto& medico : listaMedicos) {
        archivo << medico.getIDMedico() << "|"
            << medico.getNombre() << "|"
            << medico.getDireccion() << "|"
            << medico.getGenero() << "|"
            << medico.getEspecialidad() << "|"
            << medico.getEstado() << "\n";
    }

    archivo.close();
    std::cout << "Los datos de los medicos han sido guardados correctamente.\n";
}