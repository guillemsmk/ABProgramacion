#include "reportes.h"
#include "citas.h"
#include "medico.h"
#include <iostream>
#include <vector>

void reporteCitasPendientes() {
	int IDMedico;
	std::cout << "Ingrese el ID del medico: ";
	std::cin >> IDMedico;

    std::vector<Cita> citasPendientes;

    for (const auto& citas : listaCitas) {
        if (citas.getM().getIDMedico() == IDMedico) {
            citasPendientes.push_back(citas);
        }
    }

    if (citasPendientes.empty()) {
        std::cout << "No hay citas pendientes para el medico con ID " << IDMedico << ".\n";
    }
    else {
        std::cout << "Citas pendientes para el medico con ID " << IDMedico << ":\n";
        for (const auto& cita : citasPendientes) {
            cita.mostrarInformacion();
            std::cout << "------------------\n";
        }
    }
}
