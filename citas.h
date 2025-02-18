#ifndef citas_h
#define citas_h

#include <string>
#include <iostream>
#include <vector>
#include "paciente.h"
#include "medico.h"

class Cita {
private:
	int IDCita;
	Paciente paciente;
	Medico medico;
	std::string fechaCita;
	std::string hora;
	std::string motivo;
	bool urgencia;

public:
	Cita(int IDCita, const Paciente& paciente, const Medico& medico, const std::string fechaCita, const std::string hora, std::string motivo, bool urgencia);

	int getIDCita() const;
	Paciente getP() const;
	Medico getM() const;
	std::string getF() const;
	std::string getH() const;
	std::string getMo() const;
	bool esUrgente() const;

	void modificarCita(const std::string& nuevaFecha, const std::string& nuevaHora, const std::string nuevoMotivo, bool nuevaUrgencia);
	void mostrarInformacion() const;

	static void agregarCita(std::vector<Cita>& listaCitas, int& contadorCita, const std::vector<Paciente>& listaPacientes, const std::vector<Medico>& listaMedicos);
	static void modificarCita(std::vector<Cita>& listaCitas);
	static void eliminarCita(std::vector<Cita>& listaCitas);
	static void mostrarXUrgencia(const std::vector<Cita>& listaCitas);
	static void listarCitas(const std::vector<Cita>& listaCitas);
	static void cargarCitas(std::vector<Cita>& listaCitas, int& contadorCita, const std::vector<Paciente>& listaPacientes, const std::vector<Medico>& listaMedicos);
	static void guardarCitas(const std::vector<Cita>& listaCitas);
};

#endif