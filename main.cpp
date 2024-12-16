#include <iostream>
#include <vector>
#include "paciente.h"
#include "medico.h"

std::vector<Paciente> listaPacientes;
std::vector<Medico> listaMedicos;
int contador_paciente = 1;
int contador_medico = 1;

void registrarPaciente() {
    std::string nombre, direccion, genero, fecha_nacimiento, diagnostico;

    std::cout << "Ingrese nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese direccion del paciente: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese genero (M/F/Otro): ";
    std::getline(std::cin, genero);

    std::cout << "Ingrese fecha de nacimiento (dd-mm-yyyy): ";
    std::getline(std::cin, fecha_nacimiento);

    std::cout << "Ingrese diagnostico: ";
    std::getline(std::cin, diagnostico);

    Paciente nuevo_paciente(contador_paciente++, nombre, direccion, genero, fecha_nacimiento, diagnostico);
    listaPacientes.push_back(nuevo_paciente);
    std::cout << "Paciente registrado con exito.\n";
}

void modificarPaciente() {
    int ID;
    std::string nuevo_nombre, nueva_direccion, nuevo_diagnostico;

    std::cout << "Ingrese el ID del paciente a modificar: ";
    std::cin >> ID;

    for (auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            std::cout << "Ingrese nuevo nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nuevo_nombre);

            std::cout << "Ingrese nueva direccion: ";
            std::getline(std::cin, nueva_direccion);

            std::cout << "Ingrese nuevo diagnostico: ";
            std::getline(std::cin, nuevo_diagnostico);

            paciente.modificarDatos(nuevo_nombre, nueva_direccion, nuevo_diagnostico);
            std::cout << "Paciente modificado con exito.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void altaBajaPaciente() {
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

void buscarPaciente() {
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

void menuPacientes() {
    int opcion;
    do {
        std::cout << "Menu Pacientes\n1. Registrar\n2. Modificar\n3. Alta/Baja\n4. Buscar por ID\n5. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            registrarPaciente();
            break;
        case 2:
            modificarPaciente();
            break;
        case 3:
            altaBajaPaciente();
            break;
        case 4:
            buscarPaciente();
            break;
        case 5:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);
}

void registrarMedico() {
    std::string nombre, direccion, genero, especialidad;

    std::cout << "Ingrese nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese direccion del medico: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese genero (M/F/Otro): ";
    std::getline(std::cin, genero);

    std::cout << "Ingrese especialidad del medico: ";
    std::getline(std::cin, especialidad);

    Medico nuevo_medico(contador_medico++, nombre, direccion, genero, especialidad);
    listaMedicos.push_back(nuevo_medico);
    std::cout << "Medico registrado con exito.\n";
}

void modificarMedico() {
    int ID;
    std::string nueva_especialidad;

    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> ID;

    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            std::cout << "Ingrese nueva especialidad: ";
            std::cin.ignore();
            std::getline(std::cin, nueva_especialidad);

            medico.modificarDatos(nueva_especialidad);
            std::cout << "Medico modificado con exito.\n";
            return;
        }
    }
    std::cout << "Medico no encontrado.\n";
}

void altaBajaMedico() {
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

void buscarMedico() {
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
void menuMedicos() {
    int opcion;
    do {
        std::cout << "Menu Medicos\n1. Registrar\n2. Modificar\n3. Alta/Baja\n4. Buscar por ID\n5. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            registrarMedico();
            break;
        case 2:
            modificarMedico();
            break;
        case 3:
            altaBajaMedico();
            break;
        case 4:
            buscarMedico();
            break;
        case 5:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);
}



int main() {
    int opcion;
    do {
        std::cout << "\nMenu Principal\n";
        std::cout << "1. Menu de Pacientes\n";
        std::cout << "2. Menu de Medicos\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            menuPacientes();
            break;
        case 2:
            menuMedicos();
            break;
        case 3:
            std::cout << "Saliendo del programa...\n";
            return 0;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}