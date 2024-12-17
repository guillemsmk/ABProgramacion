#include <iostream>
#include <vector>
#include "paciente.h"
#include "medico.h"
#include "citas.h"
void menuCitas();

std::vector<Paciente> listaPacientes;
int contadorPaciente = 1;
std::vector<Medico> listaMedicos;
int contadorMedico = 1;
std::vector<Cita> listaCitas;
int contadorCita = 1;

void registrarPaciente() {
    std::string nombre, direccion, genero, fechaNacimiento, diagnostico;

    std::cout << "Ingrese nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese direccion del paciente: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese genero (M/F/Otro): ";
    std::getline(std::cin, genero);

    std::cout << "Ingrese fecha de nacimiento (dd-mm-yyyy): ";
    std::getline(std::cin, fechaNacimiento);

    std::cout << "Ingrese diagnostico: ";
    std::getline(std::cin, diagnostico);

    Paciente nuevoPaciente(contadorPaciente++, nombre, direccion, genero, fechaNacimiento, diagnostico);
    listaPacientes.push_back(nuevoPaciente);
    std::cout << "Paciente registrado con exito.\n";
}

void modificarPaciente() {
    int ID;
    std::string nuevoNombre, nuevaDireccion, nuevoDiagnostico;

    std::cout << "Ingrese el ID del paciente a modificar: ";
    std::cin >> ID;

    for (auto& paciente : listaPacientes) {
        if (paciente.getIDPaciente() == ID) {
            std::cout << "Ingrese nuevo nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nuevoNombre);

            std::cout << "Ingrese nueva direccion: ";
            std::getline(std::cin, nuevaDireccion);

            std::cout << "Ingrese nuevo diagnostico: ";
            std::getline(std::cin, nuevoDiagnostico);

            paciente.modificarDatos(nuevoNombre, nuevaDireccion, nuevoDiagnostico);
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

    Medico nuevoMedico(contadorMedico++, nombre, direccion, genero, especialidad);
    listaMedicos.push_back(nuevoMedico);
    std::cout << "Medico registrado con exito.\n";
}

void modificarMedico() {
    int ID;
    std::string nuevaDireccion, nuevaEspecialidad;

    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> ID;

    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            std::cout << "Ingrese nueva direccion: ";
            std::cin.ignore();
            std::getline(std::cin, nuevaDireccion);
            std::cout << "Ingrese nueva especialidad: ";
            std::cin.ignore();
            std::getline(std::cin, nuevaEspecialidad);

            medico.modificarDatos(nuevaDireccion, nuevaEspecialidad);
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

void agregarCita() {
    int IDPaciente, IDMedico;
    std::string fecha, hora, motivo;
    bool urgencia;

    std::cout << "Ingrese ID del paciente: ";
    std::cin >> IDPaciente;
    std::cout << "Ingrese ID del medico: ";
    std::cin >> IDMedico;

    Paciente* paciente = nullptr;
    Medico* medico = nullptr;

    for (auto& p : listaPacientes) {
        if (p.getIDPaciente() == IDPaciente) {
            paciente = &p;
            break;
        }
    }
    for (auto& m : listaMedicos) {
        if (m.getIDMedico() == IDMedico) {
            medico = &m;
            break;
        }
    }

    if (!paciente || !medico) {
        std::cout << "Paciente o Medico no encontrado.\n";
        return;
    }
    
    std::cout << "Ingrese fecha (dd-mm-yyyy) ";
    std::cin >> fecha;
    std::cout << "Ingrese hora (hh:mm): ";
    std::cin >> hora;
    std::cout << "Ingrese motivo: ";
    std::cin.ignore();
    std::getline(std::cin, motivo);
    std::cout << "Cita urgente? (1 Si, 0 No): ";
    std::cin >> urgencia;

    listaCitas.emplace_back(contadorCita++, *paciente, *medico, fecha, hora, motivo, urgencia);
    std::cout << "Cita agregada.\n";
}

void modificarCita() {
    int IDCita;
    std::cout << "Ingrese ID de la cita a modificar: ";
    std::cin >> IDCita;

    for (auto& cita : listaCitas) {
        if (cita.getIDCita() == IDCita) {
            std::string nuevaFecha, nuevaHora, nuevoMotivo;
            bool nuevaUrgencia;

            std::cout << "Ingrese nueva fecha (dd-mm-yyyy) ";
            std::cin >> nuevaFecha;
            std::cout << "Ingrese hora (hh:mm): ";
            std::cin >> nuevaHora;
            std::cout << "Ingrese motivo: ";
            std::cin.ignore();
            std::getline(std::cin, nuevoMotivo);
            std::cout << "Cita urgente? (1 Si, 0 No): ";
            std::cin >> nuevaUrgencia;

            cita.modificarCita(nuevaFecha, nuevaHora, nuevoMotivo, nuevaUrgencia);
            std::cout << "Cita modificada.\n";
            return;
        }
    }
    std::cout << "Cita no encontrada.\n";
}

void eliminarCita() {
    int IDCita;
    std::cout << "Ingrese ID de la cita a eliminar: ";
    std::cin >> IDCita;

    for (auto it = listaCitas.begin(); it != listaCitas.end(); ++it) {
        if (it->getIDCita() == IDCita) {
            listaCitas.erase(it);
            std::cout << "Cita eliminada.\n";
            return;
        }
    }
    std::cout << "Cita no encontrada.\n";
}

void mostrarXUrgencia() {
    std::cout << "Citas urgentes: ";
    for (const auto& cita : listaCitas) {
        if (cita.esUrgente()) {
            cita.mostrarInformacion();
        }
    }
}

void menuCitas() {
    int opcion;
    do {
        std::cout << "\nMenu de Citas\n";
        std::cout << "1. Agregar Cita\n";
        std::cout << "2. Eliminar Cita\n";
        std::cout << "3. Modificar Cita\n";
        std::cout << "4. Mostrar Citas por Urgencia\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarCita();
            break;
        case 2:
            eliminarCita();
            break;
        case 3:
            modificarCita();
            break;
        case 4:
            mostrarXUrgencia();
            break;
        case 5:
            return;
        default:
            std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
}

int main() {
    int opcion;
    do {
        std::cout << "\nMenu Principal\n";
        std::cout << "1. Menu de Pacientes\n";
        std::cout << "2. Menu de Medicos\n";
        std::cout << "3. Menu de Citas\n";
        std::cout << "4. Salir\n";
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
            menuCitas();
            break;
        case 4:
            std::cout << "Saliendo del programa...\n";
            return 0;
        default:
            std::cout << "Intente de nuevo.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}