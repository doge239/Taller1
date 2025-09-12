#include <iostream>
#include <iomanip>
#include "Sistema.h"
#include "Utilidades.h"

using namespace std;

Sistema::Sistema() {}
Sistema::~Sistema() {}

void Sistema::menu() {
    int opcion;
    do {
        cout << "=== SISTEMA DE GESTION ACADEMICA ===";
        cout << "1. Gestion de Alumnos";
        cout << "2. Gestion de Cursos";
        cout << "3. Inscripciones";
        cout << "4. Gestion de Notas";
        cout << "5. Reportes";
        cout << "0. Salir";
        cout << "Opcion: ";
        cin >> opcion;
        Utilidades::limpiarBuffer();
        
        switch (opcion) {
            case 1: {
                int opcionAlumno;
                cout << "--- GESTION DE ALUMNOS ---";
                cout << "1. Crear alumno";
                cout << "2. Buscar alumno";
                cout << "3. Eliminar alumno";
                cout << "4. Listar todos los alumnos";
                cout << "5. Listar alumnos por carrera";
                cout << "0. Volver";
                opcionAlumno = Utilidades::leerEntero("Opcion: ");
                
                switch (opcionAlumno) {
                    case 1: crearAlumno(); break;
                    case 2: buscarAlumno(); break;
                    case 3: eliminarAlumno(); break;
                    case 4: listarAlumnos(); break;
                    case 5: listarAlumnosPorCarrera(); break;
                }
                break;
            }
            case 2: {
                int opcionCurso;
                cout << "--- GESTION DE CURSOS ---";
                cout << "1. Crear curso";
                cout << "2. Buscar curso";
                cout << "3. Eliminar curso";
                cout << "4. Listar todos los cursos";
                cout << "0. Volver";
                opcionCurso = Utilidades::leerEntero("Opcion: ");
                
                switch (opcionCurso) {
                    case 1: crearCurso(); break;
                    case 2: buscarCurso(); break;
                    case 3: eliminarCurso(); break;
                    case 4: listarCursos(); break;
                }
                break;
            }
            case 3: {
                int opcionInscripcion;
                cout << "--- GESTION DE INSCRIPCIONES ---";
                cout << "1. Inscribir alumno en curso";
                cout << "2. Eliminar inscripcion";
                cout << "0. Volver";
                opcionInscripcion = Utilidades::leerEntero("Opcion: ");
                
                switch (opcionInscripcion) {
                    case 1: inscribirAlumno(); break;
                    case 2: eliminarInscripcion(); break;
                }
                break;
            }
            case 4: {
                agregarNota();
                break;
            }
            case 5: {
                int opcionReporte;
                cout << "--- REPORTES ---";
                cout << "1. Reporte de alumno";
                cout << "2. Promedios por curso";
                cout << "0. Volver";
                opcionReporte = Utilidades::leerEntero("Opcion: ");
                
                switch (opcionReporte) {
                    case 1: reporteAlumno(); break;
                    case 2: promediosCurso(); break;
                }
                break;
            }
        }
    } while (opcion != 0);
}

void Sistema::crearAlumno() {
    int id = Utilidades::leerEntero("ID: ");
    
    
    if (alumnos.buscarPorId(id)) {
        cout << "Error: Ya existe un alumno con este ID.\n";
        return;
    }
    
    string nom = Utilidades::leerString("Nombre: ");
    string ape = Utilidades::leerString("Apellido: ");
    string carr = Utilidades::leerString("Carrera: ");
    string fecha = Utilidades::leerString("Fecha ingreso (DD/MM/AAAA): ");
    
    alumnos.insertar(new Alumno(id, nom, ape, carr, fecha));
    cout << "Alumno creado exitosamente.";
}

void Sistema::buscarAlumno() {
    int opcion = Utilidades::leerEntero("Buscar por:1. ID 2. Nombre Opcion: ");
    
    if (opcion == 1) {
        int id = Utilidades::leerEntero("ID: ");
        
        // CORREGIDO: usar buscarPorId en lugar de buscarInt
        Alumno* alumno = alumnos.buscarPorId(id);
        if (alumno) {
            mostrarAlumno(alumno);
        } else {
            cout << "Alumno no encontrado.";
        }
    } else if (opcion == 2) {
        string nombre = Utilidades::leerString("Nombre: ");
        
        // CORREGIDO: usar buscarTodosPorNombre
        vector<Alumno*> resultados = alumnos.buscarTodosPorNombre(nombre);
        if (resultados.empty()) {
            cout << "No se encontraron alumnos con ese nombre.";
        } else {
            for (Alumno* alumno : resultados) {
                mostrarAlumno(alumno);
            }
        }
    }
}

void Sistema::eliminarAlumno() {
    int id = Utilidades::leerEntero("ID del alumno a eliminar: ");
    
    // CORREGIDO: usar eliminarPorId en lugar de eliminarInt
    if (alumnos.eliminarPorId(id)) {
        eliminarInscripcionesAlumno(id);
        cout << "Alumno eliminado exitosamente.";
    } else {
        cout << "Alumno no encontrado.";
    }
}

void Sistema::listarAlumnos() {
    Alumno* aux = alumnos.getCabeza();
    if (!aux) {
        cout << "No hay alumnos registrados.";
        return;
    }
    
    cout << "--- LISTA DE ALUMNOS ---";
    while (aux) {
        mostrarAlumno(aux);
        aux = aux->getSiguiente();
    }
}

void Sistema::listarAlumnosPorCarrera() {
    string carrera = Utilidades::leerString("Carrera: ");
    
    // CORREGIDO: usar buscarPorCarrera
    vector<Alumno*> resultados = alumnos.buscarPorCarrera(carrera);
    if (resultados.empty()) {
        cout << "No hay alumnos en esta carrera.";
    } else {
        cout << "--- ALUMNOS DE " << carrera << " ---";
        for (Alumno* alumno : resultados) {
            mostrarAlumno(alumno);
        }
    }
}

void Sistema::crearCurso() {
    string cod = Utilidades::leerString("Codigo: ");
    
    
    if (cursos.buscarPorCodigo(cod)) {
        cout << "Error: Ya existe un curso con este codigo.";
        return;
    }
    
    string nom = Utilidades::leerString("Nombre: ");
    int cupo = Utilidades::leerEntero("Cupo maximo: ");
    string carr = Utilidades::leerString("Carrera: ");
    string prof = Utilidades::leerString("Profesor: ");
    
    cursos.insertar(new Curso(cod, nom, cupo, carr, prof));
    cout << "Curso creado exitosamente.";
}

void Sistema::buscarCurso() {
    int opcion = Utilidades::leerEntero("Buscar por: 1. Codigo 2. Nombre Opcion: ");
    
    if (opcion == 1) {
        string codigo = Utilidades::leerString("Codigo: ");
        
        // CORREGIDO: usar buscarPorCodigo en lugar de buscarStr
        Curso* curso = cursos.buscarPorCodigo(codigo);
        if (curso) {
            mostrarCurso(curso);
        } else {
            cout << "Curso no encontrado.";
        }
    } else if (opcion == 2) {
        string nombre = Utilidades::leerString("Nombre: ");
        
        // CORREGIDO: usar buscarTodosPorNombre
        vector<Curso*> resultados = cursos.buscarTodosPorNombre(nombre);
        if (resultados.empty()) {
            cout << "No se encontraron cursos con ese nombre.";
        } else {
            for (Curso* curso : resultados) {
                mostrarCurso(curso);
            }
        }
    }
}

void Sistema::eliminarCurso() {
    string codigo = Utilidades::leerString("Codigo del curso a eliminar: ");
    
    // CORREGIDO: usar eliminarPorCodigo en lugar de eliminarStr
    if (cursos.eliminarPorCodigo(codigo)) {
        eliminarInscripcionesCurso(codigo);
        cout << "Curso eliminado exitosamente.";
    } else {
        cout << "Curso no encontrado.";
    }
}

void Sistema::listarCursos() {
    Curso* aux = cursos.getCabeza();
    if (!aux) {
        cout << "No hay cursos registrados.";
        return;
    }
    
    cout << "--- LISTA DE CURSOS ---";
    while (aux) {
        mostrarCurso(aux);
        aux = aux->getSiguiente();
    }
}

void Sistema::inscribirAlumno() {
    int idAlumno = Utilidades::leerEntero("ID del alumno: ");
    string codigoCurso = Utilidades::leerString("Codigo del curso: ");
    
    
    Alumno* alumno = alumnos.buscarPorId(idAlumno);
   
    Curso* curso = cursos.buscarPorCodigo(codigoCurso);
    
    if (!alumno) {
        cout << "Alumno no encontrado.";
        return;
    }
    
    if (!curso) {
        cout << "Curso no encontrado.";
        return;
    }
    
    
    if (alumno->getCarrera() != curso->getCarrera()) {
        cout << "Error: El alumno y el curso deben ser de la misma carrera.";
        return;
    }
    
    
    Inscripcion* aux = inscripciones.getCabeza();
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno && aux->getCurso()->getCodigo() == codigoCurso) {
            cout << "Error: El alumno ya está inscrito en este curso.";
            return;
        }
        aux = aux->getSiguiente();
    }
    
    inscripciones.insertar(new Inscripcion(alumno, curso));
    cout << "Alumno inscrito exitosamente.";
}

void Sistema::eliminarInscripcion() {
    int idAlumno = Utilidades::leerEntero("ID del alumno: ");
    string codigoCurso = Utilidades::leerString("Codigo del curso: ");
    
    Inscripcion* aux = inscripciones.getCabeza();
    Inscripcion* prev = nullptr;
    
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno && aux->getCurso()->getCodigo() == codigoCurso) {
            if (prev) {
                prev->setSiguiente(aux->getSiguiente());
            } else {
                inscripciones.setCabeza(aux->getSiguiente());
            }
            delete aux;
            cout << "Inscripcion eliminada exitosamente.";
            return;
        }
        prev = aux;
        aux = aux->getSiguiente();
    }
    
    cout << "Inscripcion no encontrada.";
}

void Sistema::agregarNota() {
    int idAlumno = Utilidades::leerEntero("ID del alumno: ");
    string codigoCurso = Utilidades::leerString("Codigo del curso: ");
    
    Inscripcion* inscripcion = nullptr;
    Inscripcion* aux = inscripciones.getCabeza();
    
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno && aux->getCurso()->getCodigo() == codigoCurso) {
            inscripcion = aux;
            break;
        }
        aux = aux->getSiguiente();
    }
    
    if (!inscripcion) {
        cout << "El alumno no está inscrito en este curso.";
        return;
    }
    
    float nota = Utilidades::leerFloat("Nota (1.0 - 7.0): ");
    
    if (nota < 1.0 || nota > 7.0) {
        cout << "Error: La nota debe estar entre 1.0 y 7.0.";
        return;
    }
    
    inscripcion->agregarNota(nota);
    cout << "Nota agregada exitosamente.";
}

void Sistema::reporteAlumno() {
    int idAlumno = Utilidades::leerEntero("ID del alumno: ");
    
    // CORREGIDO: usar buscarPorId en lugar de buscarInt
    Alumno* alumno = alumnos.buscarPorId(idAlumno);
    if (!alumno) {
        cout << "Alumno no encontrado.";
        return;
    }
    
    mostrarAlumno(alumno);
    mostrarInscripcionesAlumno(idAlumno);
}

void Sistema::promediosCurso() {
    string codigoCurso = Utilidades::leerString("Codigo del curso: ");
    
    // CORREGIDO: usar buscarPorCodigo en lugar de buscarStr
    Curso* curso = cursos.buscarPorCodigo(codigoCurso);
    if (!curso) {
        cout << "Curso no encontrado.";
        return;
    }
    
    cout << "--- PROMEDIOS DEL CURSO " << curso->getNombre() << " ---";
    
    Inscripcion* aux = inscripciones.getCabeza();
    bool tieneInscripciones = false;
    float promedioGeneral = 0.0f;
    int count = 0;
    
    while (aux) {
        if (aux->getCurso()->getCodigo() == codigoCurso) {
            float promedio = aux->calcularPromedio();
            cout << aux->getAlumno()->getNombre() << " " << aux->getAlumno()->getApellido();
            cout << ": " << setprecision(2) << promedio << endl;
            
            promedioGeneral += promedio;
            count++;
            tieneInscripciones = true;
        }
        aux = aux->getSiguiente();
    }
    
    if (!tieneInscripciones) {
        cout << "No hay alumnos inscritos en este curso.";
    } else if (count > 0) {
        cout << "Promedio general del curso: " << setprecision(2) << (promedioGeneral / count) << endl;
    }
}

void Sistema::mostrarAlumno(Alumno* alumno) const {
    cout << "ID: " << alumno->getId() << " | ";
    cout << "Nombre: " << alumno->getNombre() << " " << alumno->getApellido() << " | ";
    cout << "Carrera: " << alumno->getCarrera() << " | ";
    cout << "Fecha ingreso: " << alumno->getFechaIngreso() << endl;
}

void Sistema::mostrarCurso(Curso* curso) const {
    cout << "Codigo: " << curso->getCodigo() << " | ";
    cout << "Nombre: " << curso->getNombre() << " | ";
    cout << "Cupo: " << curso->getCupoMaximo() << " | ";
    cout << "Carrera: " << curso->getCarrera() << " | ";
    cout << "Profesor: " << curso->getProfesor() << endl;
}

void Sistema::mostrarInscripcionesAlumno(int idAlumno) const {
    Inscripcion* aux = inscripciones.getCabeza();
    bool tieneInscripciones = false;
    
    cout << "--- CURSOS INSCRITOS ---";
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno) {
            cout << "Curso: " << aux->getCurso()->getNombre();
            cout << " (" << aux->getCurso()->getCodigo() << ")";
            
            float promedio = aux->calcularPromedio();
            if (promedio > 0) {
                cout << " | Promedio: " << setprecision(2) << promedio;
            } else {
                cout << " | Sin notas";
            }
            cout << endl;
            
            tieneInscripciones = true;
        }
        aux = aux->getSiguiente();
    }
    
if (!tieneInscripciones) {
    cout << "El alumno no está inscrito en ningún curso.";
}
}

void Sistema::eliminarInscripcionesAlumno(int idAlumno) {
    Inscripcion* aux = inscripciones.getCabeza();
    Inscripcion* prev = nullptr;
    
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno) {
            Inscripcion* temp = aux;
            if (prev) {
                prev->setSiguiente(aux->getSiguiente());
            } else {
                inscripciones.setCabeza(aux->getSiguiente());
            }
            aux = aux->getSiguiente();
            delete temp;
        } else {
            prev = aux;
            aux = aux->getSiguiente();
        }
    }
}

void Sistema::eliminarInscripcionesCurso(const std::string& codigoCurso) {
    Inscripcion* aux = inscripciones.getCabeza();
    Inscripcion* prev = nullptr;
    
    while (aux) {
        if (aux->getCurso()->getCodigo() == codigoCurso) {
            Inscripcion* temp = aux;
            if (prev) {
                prev->setSiguiente(aux->getSiguiente());
            } else {
                inscripciones.setCabeza(aux->getSiguiente());
            }
            aux = aux->getSiguiente();
            delete temp;
        } else {
            prev = aux;
            aux = aux->getSiguiente();
        }
    }
}