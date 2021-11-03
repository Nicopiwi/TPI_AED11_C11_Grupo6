#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esCasa(hogar);

int qDormitorios();

int qHabitaciones();

bool esSuHogar(hogar, individuo);

int cantHabitantes(hogar, eph_i);

hogar buscarHogarPara(eph_h, individuo);

//aux ej 2

bool estaEnLaRegion(hogar, int);

int maxCantHabitacionesEnRegion(eph_h, int);


//aux ej 3
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);

bool esHogarValido(hogar h, int region);

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region);

int cantHogaresValidos(eph_h th, int region);

bool hogarConHacinamientoCritico(hogar h, eph_i ti);

//aux ej 4

bool esCasaODepartamento(hogar);

bool realizaSusTareasEnEsteHogar(individuo);

bool tieneEspaciosReservadosParaElTrabajo(individuo);

bool trabaja(individuo);

bool hogarEsDeCiudadGrande(hogar);

bool esDepartamento(hogar);

float proporcionTeleworking(eph_h, eph_i);

#endif //SOLUCION_AUXILIARES_H
