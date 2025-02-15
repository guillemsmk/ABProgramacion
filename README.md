## 1.	Introducción
Este proyecto consiste en un sistema de gestión hospitalaria donde encontramos clases como pacientes, médicos y citas en código C++. Tienen diversas funcionalidades con pequeñas diferencias, registrar, modificar, eliminar, buscar, listar y estados. Además, se pueden manejar citas médicas asignadas a pacientes y médicos únicos. Todos los datos registrados se guardan en archivos para su posterior recuperación.

## 2.	Características principales
### Menú Médicos:
-	Registro de nuevos médicos al sistema
-	Modificación de la información del médico seleccionado
-	Eliminación de los médicos seleccionándolos por ID
-	Gestión del estado de los médicos (activo/inactivo)
-	Buscador de médicos por ID
-	Listado de todos los médicos
### Menú Pacientes:
-	Registro de nuevos pacientes al sistema
-	Modificación de la información del paciente seleccionado
-	Eliminación de los pacientes seleccionándolos por ID
-	Gestión del estado de los pacientes (activo/inactivo)
-	Buscador de pacientes por ID
-	Listado de todos los pacientes
### Menú Citas:
-	Registro de nuevas citas
-	Modificación de la cita seleccionada
-	Eliminación de la cita seleccionada
-	Listado de citas de urgencia
-	Listado de todas las citas

### Funcionalidades globales:
-	Validación de fecha
-	Validación de género
-	Validación de vacío
-	Validación de hora
-	Guardado de datos en archivos

### 3.	Requisitos del sistema
Software:
-	Compilador C++: Estándar C++11 o superior
-	Sistema operativo: Windows, Linux
-	IDE: Visual Studio / Code

### 4.	Instrucciones de instalación y uso
Instalación:
Puede o clonar el repositorio del proyecto o compilar los archivos fuente a través de los siguientes comandos:
-	Clonación: git clone https://github.com/guillemsmk/ABProgramacion cd “proyecto”
-	Compilar archivos fuente: g++ main.cpp medico.cpp paciente.cpp citas.cpp validaciones.cpp -o sistema.propio

Uso:
Ejecutas el programa y verás una interfaz simple donde simplemente tienes que insertar él número referente a la acción seleccionada. Los datos se guardan automáticamente.
