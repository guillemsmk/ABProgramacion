#include <iostream>
#include <fstream>
#include <sstream>
#include "paciente.h"
#include "medico.h"
#include "citas.h"

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
        {
            Paciente paciente;
            paciente.registrarPaciente();
            listaPacientes.push_back(paciente);
            guardarDatos();
        }
        break;
        case 2:
            if (!listaPacientes.empty()) {
                listaPacientes.back().modificarPaciente();
                guardarDatos();
            }
            else {
                std::cout << "No hay pacientes registrados.\n";
            }
            break;
        case 3:
            if (!listaPacientes.empty()) {
                listaPacientes.back().eliminarPaciente();
                guardarDatos();
            }
            else {
                std::cout << "No hay pacientes registrados.\n";
            }
            break;
        case 4:
            if (!listaPacientes.empty()) {
                listaPacientes.back().altaBajaPaciente();
                guardarDatos();
            }
            else {
                std::cout << "No hay pacientes registrados.\n";
            }
            break;
        case 5:
            if (!listaPacientes.empty()) {
                listaPacientes.back().buscarPaciente();
            }
            else {
                std::cout << "No hay pacientes registrados.\n";
            }
            break;
        case 6:
            if (!listaPacientes.empty()) {
                listaPacientes.back().listarPacientes();
            }
            else {
                std::cout << "No hay pacientes registrados.\n";
            }
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
        {
            Medico medico;
            medico.registrarMedico();
            listaMedicos.push_back(medico);
            guardarDatos();
        }
            break;
        case 2:
            if (!listaMedicos.empty()) {
                listaMedicos.back().modificarMedico();
                guardarDatos();
            }
            else {
                std::cout << "No hay medicos registrados.\n";
            }
            break;
        case 3:
            if (!listaMedicos.empty()) {
                listaMedicos.back().eliminarMedico();
                guardarDatos();
            }
            else {
                std::cout << "No hay medicos registrados.\n";
            }
            break;
        case 4:
            if (!listaMedicos.empty()) {
                listaMedicos.back().altaBajaMedico();
                guardarDatos();
            }
            else {
                std::cout << "No hay medicos registrados.\n";
            }
            break;
        case 5:
            if (!listaMedicos.empty()) {
                listaMedicos.back().buscarMedico();
            }
            else {
                std::cout << "No hay medicos registrados.\n";
            }
            break;
        case 6:
            if (!listaMedicos.empty()) {
                listaMedicos.back().listarMedicos();
            }
            else {
                std::cout << "No hay medicos registrados.\n";
            }
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
        {
            Cita cita;
            cita.agregarCita();
            listaCitas.push_back(cita);
            guardarDatos();
        }
            break;
        case 2:
            if (!listaCitas.empty()) {
                listaCitas.back().eliminarCita();
                guardarDatos();
            }
            else {
                std::cout << "No hay citas registradas.\n";
            }
            break;
        case 3:
            if (!listaCitas.empty()) {
                listaCitas.back().modificarCita();
                guardarDatos();
            }
            else {
                std::cout << "No hay citas registradas.\n";
            }
            break;
        case 4:
            if (!listaCitas.empty()) {
                listaCitas.back().mostrarXUrgencia();
            }
            else {
                std::cout << "No hay citas registradas.\n";
            }
            break;
        case 5:
            if (!listaCitas.empty()) {
                listaCitas.back().listarCitas();
            }
            else {
                std::cout << "No hay citas registradas.\n";
            }
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
    for (auto& paciente : listaPacientes) {
        paciente.cargarPacientes();
    }
    for (auto& medico : listaMedicos) {
        medico.cargarMedicos();
    }
    for (auto& cita : listaCitas) {
        cita.cargarCitas();
    }
}

void guardarDatos() {
    for (auto& medico : listaMedicos) {
        medico.guardarMedicos();
    }
    for (auto& paciente : listaPacientes) {
        paciente.guardarPacientes();
    }
    for (auto& cita : listaCitas) {
        cita.guardarCitas();
    }
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
            break;
        case 2:
            menuMedicos();
            break;
        case 3:
            menuCitas();
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
