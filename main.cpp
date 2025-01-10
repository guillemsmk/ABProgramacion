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
bool validarFecha(const std::string& fechaNacimiento);
bool validarGenero(const std::string& genero);
bool validarVacio(const std::string& entrada, const std::string& campo);

std::vector<Paciente> listaPacientes;
int contadorPaciente = 1;
std::vector<Medico> listaMedicos;
int contadorMedico = 1;
std::vector<Cita> listaCitas;
int contadorCita = 1;

const std::string rutaP = "pacientes.txt";
const std::string rutaM = "medicos.txt";
const std::string rutaC = "citas.txt";

void eliminarDatos() {
    listaPacientes.clear();
    listaMedicos.clear();

    std::ofstream archivoPacientes(rutaP, std::ofstream::trunc);
    if (!archivoPacientes.is_open()) {
        std::cerr << "Error al eliminar los datos de pacientes.\n";
    }
    else {
        archivoPacientes.close();
        std::cout << "Datos de pacientes eliminados correctamente.\n";
    }

    std::ofstream archivoMedicos(rutaM, std::ofstream::trunc);
    if (!archivoMedicos.is_open()) {
        std::cerr << "Error al eliminar los datos de medicos.\n";
    }
    else {
        archivoMedicos.close();
        std::cout << "Datos de medicos eliminados correctamente.\n";
    }
}

//---------------------------------------------

void registrarPaciente() {
    std::string nombre, direccion, genero, fechaNacimiento, diagnostico;

    do {
        std::cout << "Ingrese nombre del paciente: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
    } while (!validarVacio(nombre, "Nombre"));

    do {
        std::cout << "Ingrese direccion del paciente: ";
        std::getline(std::cin, direccion);
    } while(!validarVacio(direccion, "Direccion"));

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

void modificarPaciente() {
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
            std::cout << "Ingrese nuevo diagnostico: ";
            std::getline(std::cin, nuevoDiagnostico);

            paciente.modificarDatos(nuevoNombre, nuevaDireccion, nuevoDiagnostico);
            std::cout << "Paciente modificado con exito.\n";
            return;
        }
    }
    if (!encontrado) {
        std::cout << "Paciente no encontrado.\n";
    }
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

void cargarPacientes() {
    std::ifstream archivo(rutaP);
    if (!archivo.is_open()) {
        std::cout << "No se encontro el archivo, creando uno nuevo...\n";
        return;
    }

    listaPacientes.clear();
    std::string linea;
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
    }

    archivo.close();
    std::cout << "Datos de los pacientes cargados correctamente.\n";
}

void guardarPacientes() {
    std::ofstream archivo(rutaP);
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

void menuPacientes() {
    int opcion;
    do {
        std::cout << "Menu Pacientes\n1. Registrar\n2. Modificar\n3. Alta/Baja\n4. Buscar por ID\n5. Volver\nSeleccione una opcion: ";
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
            altaBajaPaciente();
            guardarPacientes();
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

//---------------------------------------------

void registrarMedico() {
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

void modificarMedico() {
    int ID;
    std::string nuevoNombre, nuevaDireccion, nuevaEspecialidad;

    std::cout << "Ingrese el ID del medico a modificar: ";
    std::cin >> ID;

    bool encontrado = false;
    for (auto& medico : listaMedicos) {
        if (medico.getIDMedico() == ID) {
            encontrado = true;

            do{
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

void cargarMedicos() {
    std::ifstream archivo(rutaM);
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

void guardarMedicos() {
    std::ofstream archivo(rutaM);
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

void menuMedicos() {
    int opcion;
    do {
        std::cout << "Menu Medicos\n1. Registrar\n2. Modificar\n3. Alta/Baja\n4. Buscar por ID\n5. Volver\nSeleccione una opcion: ";
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
            altaBajaMedico();
            guardarMedicos();
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

//---------------------------------------------

void agregarCita() {
    int IDPaciente, IDMedico;
    std::string fechaCita, hora, motivo;
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
    std::cin >> fechaCita;
    std::cout << "Ingrese hora (hh:mm): ";
    std::cin >> hora;
    std::cout << "Ingrese motivo: ";
    std::cin.ignore();
    std::getline(std::cin, motivo);
    std::cout << "Cita urgente? (1 Si, 0 No): ";
    std::cin >> urgencia;

    listaCitas.emplace_back(contadorCita++, *paciente, *medico, fechaCita, hora, motivo, urgencia);
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
        std::cout << "\nMenu de Citas\n1. Agregar Cita\n2. Eliminar Cita\n3. Modificar Cita\n4. Mostrar Citas por Urgencia\n5. Volver\nSeleccione una opcion: ";
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

//---------------------------------------------

void cargarDatos() {
    cargarPacientes();
    cargarMedicos();
}

void guardarDatos() {
    guardarMedicos();
    guardarPacientes();
}

bool validarFecha(const std::string& fechaNacimiento) {
    std::regex formatoFecha(R"(^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\d{4})$)");

    if (!std::regex_match(fechaNacimiento, formatoFecha)) {
        std::cout << "Formato invalido.\n";
        return false;
    }

    int dia = std::stoi(fechaNacimiento.substr(0, 2));
    int mes = std::stoi(fechaNacimiento.substr(3, 2));
    int anio = std::stoi(fechaNacimiento.substr(6, 4));

    if (mes == 2) {
        bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if (dia > (bisiesto ? 29 : 28)) return false;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return false;
    }
    else {
        if (dia > 31) return false;
    }
    return true;
}

bool validarGenero(const std::string& genero) {
    if (genero == "M" || genero == "F" || genero == "Otro") {
        return true;
    }
    else {
        std::cout << "Genero invalido.\n";
        return false;
    }
}

bool validarVacio(const std::string& entrada, const std::string& campo) {
    if (entrada.empty()) {
        std::cout << "El campo '" << campo << "' no puede estar vacio.\n";
        return false;
    }
    return true;
}

//---------------------------------------------

int main() {
    cargarDatos();

    int opcion;
    do {
        std::cout << "\nMenu Principal\n1. Menu de Pacientes\n2. Menu de Medicos\n3. Menu de Citas\n4. Eliminar Datos\n5. Salir\nSeleccione una opcion: ";
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
