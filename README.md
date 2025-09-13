git clone https://github.com/doge239/Taller1


# Sistema de Gestión Académica

## Integrantes del Grupo
- **Nicolás Cortes Vergara** - 21.193.893-5
- **Enzo Moroso Inostroza** - 20.938.335-7

## Descripción del Proyecto
Sistema de gestión académica diseñado para administrar y organizar las calificaciones de los estudiantes. Su objetivo principal es proporcionar a los docentes una herramienta eficiente que facilite el registro, consulta y análisis de las notas, mejorando significativamente la organización y el flujo de trabajo en el ámbito educativo.

## Metodología de Desarrollo
Durante el desarrollo del proyecto, adoptamos una estrategia de colaboración basada en reuniones semanales presenciales, lo que nos permitió avanzar de manera coordinada y eficiente. Debido a esta dinámica de trabajo y al uso de un compilador g++ para pruebas locales, la frecuencia de commits fue menor de lo habitual. No obstante, cada commit realizado representa avances significativos y funcionales en el proyecto.

## Comandos Utilizados
### Configuración Inicial
```bash
git config --global user.name "Enzo Inostroza"
git config --global user.email "Enzo.moroso@alumnos.ucn.cl"


Inicialización del Repositorio

git init
git branch -M main

Sincronización de Cambios

git add NombreDelArchivo
git commit -m "Primer commit - subiendo proyecto"

Vinculación con Repositorio Remoto

git remote set-url origin https://github.com/doge239/Taller1.git
git push -u origin main

Este flujo de trabajo nos permitió mantener un historial de versiones claro y consistente, asegurando la integridad del proyecto en cada etapa de su desarrollo.


## Características del formato:
- **Encabezado claro** con nombres y números de identificación
- **Secciones organizadas** con headers Markdown (`##`)
- **Código formateado** en bloques para mejor legibilidad
- **Texto estructurado** para fácil lectura
- **Información completa** pero concisa

Principalmente para compilar en G++ el proyecto terminado es de la siguente Forma:

g++ -std=c++11 main.cpp Alumno.cpp Curso.cpp Inscripcion.cpp ListaAlumnos.cpp ListaCursos.cpp ListaInscripciones.cpp ListaNotas.cpp Nota.cpp Sistema.cpp Utilidades.cpp -o sistema



