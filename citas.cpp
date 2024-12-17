#include "citas.h"
#include <iostream>
#include <ctime>

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