#ifndef medico_h
#define medico_h

#include <string>
#include <iostream>

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

    int getIDMedico() const;
    std::string getNombre() const;
    std::string getDireccion() const;
    std::string getGenero() const;
    std::string getEspecialidad() const;
    std::string getEstado() const;

    void modificarDatos(const std::string& nuevaDireccion, const std::string& nuevaEspecialidad);
    void darDeAlta();
    void darDeBaja();
    void mostrarInformacion() const;
};

#endif