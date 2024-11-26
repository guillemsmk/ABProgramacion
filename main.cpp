#include <iostream>
#include <vector>
#include "paciente.h"
#include "medico.h"

std::vector<Paciente> listaPacientes;
std::vector<Medico> listaMedicos;

void registrarPaciente() {
    Paciente paciente;
    paciente.registrarPersona();
    listaPacientes.push_back(paciente);
    std::cout << "Paciente registrado. ID: " << paciente.getIDPaciente() << "\n";
}

void registrarMedico() {
    Medico medico;
    medico.registrarPersona();
    listaMedicos.push_back(medico);
    std::cout << "Medico registrado. ID: " << medico.getIDMedico() << "\n";
}

void listarPacientes() {
    if (listaPacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
    }
    else {
        std::cout << "\nLista de Pacientes\n";
        for (const auto& paciente : listaPacientes) {
            paciente.mostrarPersona();
            std::cout << "ID: " << paciente.getIDPaciente() << "\n\n";
        }
    }
}

void listarMedicos() {
    if (listaMedicos.empty()) {
        std::cout << "No hay medicos registrados.\n";
    }
    else {
        std::cout << "\nLista de Medicos\n";
        for (const auto& medico : listaMedicos) {
            medico.mostrarPersona();
            std::cout << "ID: " << medico.getIDMedico() << "\n\n";
        }
    }
}

void modificarPaciente() {
    int ID;
    std::cout << "Ingrese el ID del paciente a modificar: ";
    std::cin >> ID;

    for (auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            std::cout << "Paciente encontrado:\n";
            paciente.mostrarPersona();
            std::cout << "Ingrese los nuevos datos del paciente:\n";
            paciente.registrarPersona();
            std::cout << "Datos del paciente actualizados.\n";
            return;
        }
    }
    std::cout << "Paciente con ID " << ID << " no encontrado.\n";
}

void modificarMedico() {
    int ID;
    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> ID;

    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            std::cout << "Medico encontrado:\n";
            medico.mostrarPersona();
            std::cout << "Ingrese los nuevos datos del medico:\n";
            medico.registrarPersona();
            std::cout << "Datos del medico actualizados.\n";
            return;
        }
    }
    std::cout << "Medico con ID " << ID << " no encontrado.\n";
}

bool menuPacientes() {
    int opcion;
    do {
        std::cout << "\nMenu de Pacientes\n";
        std::cout << "1. Listar Pacientes\n";
        std::cout << "2. Modificar Paciente\n";
        std::cout << "3. Volver al Menu Principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            listarPacientes();
            break;
        case 2:
            modificarPaciente();
            break;
        case 3:
            return false;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (true);
}

bool menuMedicos() {
    int opcion;
    do {
        std::cout << "\nMenu de Medicos\n";
        std::cout << "1. Listar Medicos\n";
        std::cout << "2. Modificar Medico\n";
        std::cout << "3. Volver al Menu Principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            listarMedicos();
            break;
        case 2:
            modificarMedico();
            break;
        case 3:
            return false;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (true);
}

bool menuPersonas() {
    int opcion;
    do {
        std::cout << "\nMenu de Personas\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Registrar Medico\n";
        std::cout << "3. Volver al Menu Principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            registrarPaciente();
            break;
        case 2:
            registrarMedico();
            break;
        case 3:
            return false;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (true);
}

void menuPrincipal() {
    int opcion;
    do {
        std::cout << "\nMenu Principal\n";
        std::cout << "1. Menu de Personas\n";
        std::cout << "2. Menu de Pacientes\n";
        std::cout << "3. Menu de Medicos\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            if (!menuPersonas()) break;
            break;
        case 2:
            if (!menuPacientes()) break;
            break;
        case 3:
            if (!menuMedicos()) break;
            break;
        case 4:
            std::cout << "Saliendo del programa...\n";
            return;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (true);
}

int main() {
    menuPrincipal();
    return 0;
}
