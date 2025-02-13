#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include "paciente.h"
#include "medico.h"
#include "citas.h"

void menuPacientes();
void menuMedicos();
void menuCitas();
void cargarDatos();
void guardarDatos();

void eliminarDatos() {
    listaPacientes.clear();
    listaMedicos.clear();
    listaCitas.clear();

    std::ofstream archivoPacientes("pacientes.txt", std::ofstream::trunc);
    if (!archivoPacientes.is_open()) {
        std::cerr << "Error al eliminar los datos de pacientes.\n";
    }
    else {
        archivoPacientes.close();
        std::cout << "Datos de pacientes eliminados correctamente.\n";
    }

    std::ofstream archivoMedicos("medicos.txt", std::ofstream::trunc);
    if (!archivoMedicos.is_open()) {
        std::cerr << "Error al eliminar los datos de medicos.\n";
    }
    else {
        archivoMedicos.close();
        std::cout << "Datos de medicos eliminados correctamente.\n";
    }

    std::ofstream archivoCitas("citas.txt", std::ofstream::trunc);
    if (!archivoCitas.is_open()) {
        std::cerr << "Error al eliminar los datos de citas.\n";
    }
    else {
        archivoCitas.close();
        std::cout << "Datos de citas eliminados correctamente.\n";
    }
}

//---------------------------------------------

void menuPacientes() {
    int opcion;
    do {
        std::cout << "Menu Pacientes\n1. Registrar\n2. Modificar\n3. Eliminar paciente\n4. Alta/Baja\n5. Buscar por ID\n6. Listar todos los pacientes\n7. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            registrarPaciente();
            guardarPacientes();
            break;
        case 2:
            modificarPaciente();
            guardarPacientes();
            break;
        case 3:
            eliminarPaciente();
            guardarPacientes();
            break;
        case 4:
            altaBajaPaciente();
            guardarPacientes();
            break;
        case 5:
            buscarPaciente();
            break;
        case 6:
            listarPacientes();
            break;
        case 7:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
}

//---------------------------------------------

void menuMedicos() {
    int opcion;
    do {
        std::cout << "Menu Medicos\n1. Registrar\n2. Modificar\n3. Eliminar medico\n4. Alta/Baja\n5. Buscar por ID\n6. Listar todos los medicos\n7. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            registrarMedico();
            guardarMedicos();
            break;
        case 2:
            modificarMedico();
            guardarMedicos();
            break;
        case 3:
            eliminarMedico();
            guardarMedicos();
            break;
        case 4:
            altaBajaMedico();
            guardarMedicos();
            break;
        case 5:
            buscarMedico();
            break;
        case 6:
            listarMedicos();
            break;
        case 7:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
}

//---------------------------------------------

void menuCitas() {
    int opcion;
    do {
        std::cout << "\nMenu de Citas\n1. Agregar Cita\n2. Eliminar Cita\n3. Modificar Cita\n4. Mostrar Citas por Urgencia\n5. Listar citas\n6. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarCita();
            guardarCitas();
            break;
        case 2:
            eliminarCita();
            guardarCitas();
            break;
        case 3:
            modificarCita();
            guardarCitas();
            break;
        case 4:
            mostrarXUrgencia();
            break;
        case 5:
            listarCitas();
            break;
        case 6:
            return;
        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);
}

//---------------------------------------------

void cargarDatos() {
    cargarPacientes();
    cargarMedicos();
    cargarCitas();
}

void guardarDatos() {
    guardarMedicos();
    guardarPacientes();
    guardarCitas();
}

//---------------------------------------------

int main() {
    cargarDatos();

    int opcion;
    do {
        std::cout << "\nMenu Principal\n1. Menu de Pacientes\n2. Menu de Medicos\n3. Menu de Citas\n4. Eliminar todos los datos\n5. Salir\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            menuPacientes();
            guardarPacientes();
            break;
        case 2:
            menuMedicos();
            guardarMedicos();
            break;
        case 3:
            menuCitas();
            guardarCitas();
            break;
        case 4:
            eliminarDatos();
            break;
        case 5:
            guardarDatos();
            std::cout << "Saliendo del programa...\n";
            return 0;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}
