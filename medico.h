#ifndef medico_h
#define medico_h

#include "persona.h"
#include <string>

class Medico : public Persona {
private:
    int IDMedico;
    static int contadorMedicos;
    std::string especialidad; // Nueva especialidad

public:
    Medico();

    int getIDMedico() const;
    void registrarPersona() override;
    void mostrarPersona() const override;
};

#endif
