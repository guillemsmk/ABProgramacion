#ifndef medico_h
#define medico_h

#include <string>
#include <iostream>
#include <vector>

class Medico {
private:
    int IDMedico;
    std::string nombre;
    std::string direccion;
    std::string genero;
    std::string especialidad;
    bool estado;

public:
    Medico(int IDMedico, const std::string& nombre, const std::string& direccion, const std::string& genero, const std::string& especialidad);
    Medico() = default;

    int getIDMedico() const;
    std::string getNombre() const;
    std::string getDireccion() const;
    std::string getGenero() const;
    std::string getEspecialidad() const;
    std::string getEstado() const;

    void modificarDatos(const std::string& nuevoNombre, const std::string& nuevaDireccion, const std::string& nuevaEspecialidad);
    void darDeAlta();
    void darDeBaja();
    void mostrarInformacion() const;

	void registrarMedico();
	void modificarMedico();
	void eliminarMedico();
	void altaBajaMedico();
	void buscarMedico();
    void listarMedicos();
	void cargarMedicos();
	void guardarMedicos();

};

extern int contadorMedico;
extern std::vector<Medico> listaMedicos;

#endif