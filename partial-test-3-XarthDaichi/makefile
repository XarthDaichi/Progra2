# Makefile created by Maikol Guzmán Alán
# No modificar este archivo. Se utiliza para el autograde

CXX 			= g++
CPPFLAGS 		= -std=c++11
TEST_SOURCES 	= tst/main.cpp tst/01_CargaPacientesTest.cpp tst/02_CargaEnfermedadesTest.cpp tst/03_Analisis1.cpp tst/04_Analisis2.cpp tst/05_Analisis3.cpp
SOURCES 		= src/AnalisisBaseNitrogenada.cpp src/AnalisisConcordancia.cpp src/AnalisisEnfermedades.cpp src/ArchivoManager.cpp src/Enfermedad.cpp src/Paciente.cpp src/Persona.cpp src/ReporteManager.cpp

all: a.out

a.out:
	$(CXX) $(CPPFLAGS) $(SOURCES) $(TEST_SOURCES)

CargaPacientes: a.out
	./a.out "[CargaPacientes]"

CargaPacientesError: a.out
	./a.out "[CargaPacientesError]"

CargaEnfermedades: a.out
	./a.out "[CargaEnfermedades]"

CargaEnfermedadesError: a.out
	./a.out "[CargaEnfermedadesError]"

AnalisisEnfermedades: a.out
	./a.out "[AnalisisEnfermedades]"

AnalisisBaseNitrogenada: a.out
	./a.out "[AnalisisBaseNitrogenada]"

AnalisisConcordancia: a.out
	./a.out "[AnalisisConcordancia]"

clean:
	rm a.out