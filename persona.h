#ifndef persona_h
#define persona_h
#include <string>

class Persona {
protected:
    std::string nombre;
    std::string direccion;
    std::string telefono;

public:
    virtual ~Persona() = default;

    virtual void registrarPersona();
    virtual void mostrarPersona() const;
};

#endif
