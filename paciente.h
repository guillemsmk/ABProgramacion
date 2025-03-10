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

	static void registrarPaciente(std::vector<Paciente>& listaPacientes, int& contadorPaciente);
	static void modificarPaciente(std::vector<Paciente>& listaPacientes);
	static void eliminarPaciente(std::vector<Paciente>& listaPacientes);
	static void altaBajaPaciente(std::vector<Paciente>& listaPacientes);
	static void buscarPaciente(const std::vector<Paciente>& listaPacientes);
	static void listarPacientes(const std::vector<Paciente>& listaPacientes);
	static void cargarPacientes(std::vector<Paciente>& listaPacientes, int& contadorPaciente);
	static void guardarPacientes(const std::vector<Paciente>& listaPacientes);
};

#endif