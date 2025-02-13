#include "citas.h"
#include "validaciones.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

Cita::Cita(int IDCita, const Paciente& paciente, const Medico& medico, const std::string fechaCita, const std::string hora, std::string motivo, bool urgencia)
	: IDCita(IDCita), paciente(paciente), medico(medico), fechaCita(fechaCita), hora(hora), motivo(motivo), urgencia(urgencia) {}


int Cita::getIDCita() const { return IDCita; }
Paciente Cita::getP() const { return paciente; }
Medico Cita::getM() const { return medico; }
std::string Cita::getF() const { return fechaCita; }
std::string Cita::getH() const { return hora; }
std::string Cita::getMo() const { return motivo; }
bool Cita::esUrgente() const { return urgencia; }

void Cita::modificarCita(const std::string& nuevaFecha, const std::string& nuevaHora, const std::string nuevoMotivo, bool nuevaUrgencia) {
	fechaCita = nuevaFecha;
	hora = nuevaHora;
	motivo = nuevoMotivo;
	urgencia = nuevaUrgencia;
}

void Cita::mostrarInformacion() const {
	std::cout << "ID Cita: " << IDCita << "\n"
		<< "Paciente: " << paciente.getNombre() << " (ID: " << paciente.getIDPaciente() << ")\n"
		<< "Medico: " << medico.getNombre() << " (ID: " << medico.getIDMedico() << ")\n"
		<< "Fecha: " << fechaCita << "\n"
		<< "Hora: " << hora << "\n"
		<< "Motivo: " << motivo << "\n"
		<< "Urgencia: " << (urgencia ? "Urgente" : "No urgente") << "\n";
}

std::vector<Cita> listaCitas;
int contadorCita = 1;

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

void listarCitas() {
    if (listaCitas.empty()) {
        std::cout << "No hay citas registradas.\n";
        return;
    }

    std::cout << "Lista de Citas: \n";
    for (const auto& cita : listaCitas) {
        cita.mostrarInformacion();
        std::cout << "------------------\n";
    }
}

void cargarCitas() {
    std::ifstream archivo("citas.txt");
    if (!archivo) {
        std::cerr << "No se encontro el archivo, creando uno nuevo...\n";
        return;
    }

    listaCitas.clear();
    std::string linea;
    int maxIDCita = 0;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string IDCita, IDPaciente, IDMedico, fechaCita, hora, motivo, urgencia;

        std::getline(ss, IDCita, '|');
        std::getline(ss, IDPaciente, '|');
        std::getline(ss, IDMedico, '|');
        std::getline(ss, fechaCita, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, motivo, '|');
        std::getline(ss, urgencia, '|');

        int IDCitaInt = std::stoi(IDCita);
        int IDPacienteInt = std::stoi(IDPaciente);
        int IDMedicoInt = std::stoi(IDMedico);
        bool urgenciaBool = (urgencia == "1");

        Paciente* paciente = nullptr;
        Medico* medico = nullptr;

        for (auto& p : listaPacientes) {
            if (p.getIDPaciente() == IDPacienteInt) {
                paciente = &p;
                break;
            }
        }

        for (auto& m : listaMedicos) {
            if (m.getIDMedico() == IDMedicoInt) {
                medico = &m;
                break;
            }
        }

        if (paciente && medico) {
            listaCitas.emplace_back(IDCitaInt, *paciente, *medico, fechaCita, hora, motivo, urgenciaBool);
            maxIDCita = std::max(maxIDCita, IDCitaInt);
        }
        else {
            std::cerr << "Error: No se encontró el paciente o médico para la cita con ID " << IDCita << ".\n";
        }
    }

    contadorCita = maxIDCita + 1;
    archivo.close();
    std::cout << "Datos de las citas cargados correctamente.\n";
}

void guardarCitas() {
    std::ofstream archivo("citas.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de medicos.\n";
        return;
    }

    for (const auto& cita : listaCitas) {
        archivo << cita.getIDCita() << "|"
            << cita.getP().getIDPaciente() << "|"
            << cita.getM().getIDMedico() << "|"
            << cita.getF() << "|"
            << cita.getH() << "|"
            << cita.getMo() << "|"
            << (cita.esUrgente() ? "1" : "0") << "\n";
    }

    archivo.close();
    std::cout << "Los datos de las citas han sido guardados correctamente.\n";
}