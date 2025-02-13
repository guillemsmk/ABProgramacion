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
	Cita() = default;

	int getIDCita() const;
	Paciente getP() const;
	Medico getM() const;
	std::string getF() const;
	std::string getH() const;
	std::string getMo() const;
	bool esUrgente() const;

	void modificarCita(const std::string& nuevaFecha, const std::string& nuevaHora, const std::string nuevoMotivo, bool nuevaUrgencia);
	void mostrarInformacion() const;

	void agregarCita();
	void modificarCita();
	void eliminarCita();
	void mostrarXUrgencia();
	void listarCitas();
	void cargarCitas();
	void guardarCitas();

}; 

extern int contadorCita;
extern std::vector<Cita> listaCitas;

#endif