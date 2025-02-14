#ifndef validaciones_h
#define validaciones_h

#include <string>

bool validarFecha(const std::string& fechaNacimiento);
bool validarGenero(const std::string& genero);
bool validarVacio(const std::string& entrada, const std::string& campo);
bool validarHora(const std::string& hora);

#endif
