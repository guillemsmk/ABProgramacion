#ifndef paciente_h
#define paciente_h

#include <string>
#include <iostream>
#include <vector>

class Paciente {
private: 
	int IDPaciente;
	std::string nombre;
	std::string direccion;
	std::string genero;
	std::string fechaNacimiento;
	std::string diagnostico;
	bool estado;

public:
	Paciente(int IDPaciente, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& fechaNacimiento, const std::string& diagnostico);
	Paciente() = default;

	int getIDPaciente() const;
	std::string getNombre() const;
	std::string getDireccion() const;
	std::string getGenero() const;
	std::string getFechaNacimiento() const;
	std::string getDiagnostico() const;
	std::string getEstado() const;

	void modificarDatos(const std::string& nuevoNombre, const std::string& nuevaDireccion, const std::string& nuevoDiagnostico);
	void darDeAlta();
	void darDeBaja();
	void mostrarInformacion() const;

	void registrarPaciente();
	void modificarPaciente();
	void eliminarPaciente();
	void altaBajaPaciente();
	void buscarPaciente();
	void listarPacientes();
	void cargarPacientes();
	void guardarPacientes();

};

extern int contadorPaciente;
extern std::vector<Paciente> listaPacientes;

#endif