#ifndef paciente_h
#define paciente_h

#include "persona.h"
#include <string>

class Paciente : public Persona {
private:
    int IDPaciente;
    static int contadorPacientes;
    std::string fechaNacimiento; // Nueva fecha de nacimiento
    std::string genero; // Nuevo género

public:
    Paciente();

    int getIDPaciente() const;
    void registrarPersona() override;
    void mostrarPersona() const override;
};

#endif
