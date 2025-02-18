#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "paciente.h"
#include "medico.h"
#include "citas.h"
#include "validaciones.h"

std::vector<Paciente> listaPacientes;
int contadorPaciente = 1;
std::vector<Medico> listaMedicos;
int contadorMedico = 1;
std::vector<Cita> listaCitas;
int contadorCita = 1;


void cargarDatos() {
    Paciente::cargarPacientes(listaPacientes, contadorPaciente);
    Medico::cargarMedicos(listaMedicos, contadorMedico);
    Cita::cargarCitas(listaCitas, contadorCita, listaPacientes, listaMedicos);
}

void guardarDatos() {
    Medico::guardarMedicos(listaMedicos);
    Paciente::guardarPacientes(listaPacientes);
    Cita::guardarCitas(listaCitas);
}

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

void menuPacientes() {
    int opcion;
    do {
        std::cout << "Menu Pacientes\n1. Registrar\n2. Modificar\n3. Eliminar paciente\n4. Alta/Baja\n5. Buscar por ID\n6. Listar todos los pacientes\n7. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            Paciente::registrarPaciente(listaPacientes, contadorPaciente);
            Paciente::guardarPacientes(listaPacientes);
            break;
        case 2:
            Paciente::modificarPaciente(listaPacientes);
            Paciente::guardarPacientes(listaPacientes);
            break;
        case 3:
            Paciente::eliminarPaciente(listaPacientes);
            Paciente::guardarPacientes(listaPacientes);
            break;
        case 4:
            Paciente::altaBajaPaciente(listaPacientes);
            Paciente::guardarPacientes(listaPacientes);
            break;
        case 5:
            Paciente::buscarPaciente(listaPacientes);
            break;
        case 6:
            Paciente::listarPacientes(listaPacientes);
            break;
        case 7:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
}

void menuMedicos() {
    int opcion;
    do {
        std::cout << "Menu Medicos\n1. Registrar\n2. Modificar\n3. Eliminar medico\n4. Alta/Baja\n5. Buscar por ID\n6. Listar todos los medicos\n7. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
			Medico::registrarMedico(listaMedicos, contadorMedico);
            Medico::guardarMedicos(listaMedicos);
            break;
        case 2:
            Medico::modificarMedico(listaMedicos);
            Medico::guardarMedicos(listaMedicos);
            break;
        case 3:
            Medico::eliminarMedico(listaMedicos);
            Medico::guardarMedicos(listaMedicos);
            break;
        case 4:
            Medico::altaBajaMedico(listaMedicos);
            Medico::guardarMedicos(listaMedicos);
            break;
        case 5:
            Medico::buscarMedico(listaMedicos);
            break;
        case 6:
            Medico::listarMedicos(listaMedicos);
            break;
        case 7:
            return;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
}

void menuCitas() {
    int opcion;
    do {
        std::cout << "\nMenu de Citas\n1. Agregar Cita\n2. Eliminar Cita\n3. Modificar Cita\n4. Mostrar Citas por Urgencia\n5. Listar citas\n6. Volver\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            Cita::agregarCita(listaCitas, contadorCita, listaPacientes, listaMedicos);
            Cita::guardarCitas(listaCitas);
            break;
        case 2:
            Cita::eliminarCita(listaCitas);
            Cita::guardarCitas(listaCitas);
            break;
        case 3:
            Cita::modificarCita(listaCitas);
            Cita::guardarCitas(listaCitas);
            break;
        case 4:
            Cita::mostrarXUrgencia(listaCitas);
            break;
        case 5:
            Cita::listarCitas(listaCitas);
            break;
        case 6:
            return;
        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);
}

void generarReporteCitasPendientes() {
    int IDMedico;

    std::cout << "Ingrese el ID del medico: ";
	std::cin >> IDMedico;

    bool encontrado = false;
    std::cout << "Citas pendientes del medico: " << IDMedico << "\n";

    for (const auto& cita : listaCitas) {
        if (cita.getM().getIDMedico() == IDMedico) {
            cita.mostrarInformacion();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No hay citas pendientes para el medico con ID " << IDMedico << ".\n";
    }
}

int main() {
    cargarDatos();

    int opcion;
    do {
        std::cout << "\nMenu Principal\n1. Menu de Pacientes\n2. Menu de Medicos\n3. Menu de Citas\n4. Generar reporte de citas pendientes de medicos\n5. Eliminar todos los datos\n6. Salir\nSeleccione una opcion: ";
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
            generarReporteCitasPendientes();
            break;
        case 5:
            eliminarDatos();
            break;
        case 6:
            guardarDatos();
            std::cout << "Saliendo del programa...\n";
            return 0;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (opcion != 6);

    return 0;
}
