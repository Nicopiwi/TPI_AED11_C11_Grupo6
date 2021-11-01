#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esCasa(hogar h);

int qDormitorios();

bool esSuHogar(hogar h, individuo i);

int cantHabitantes(hogar h, eph_i ti);


//aux ej 3
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);

bool esHogarValido(hogar h, int region);

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region);

int cantHogaresValidos(eph_h th, int region);

bool hogarConHacinamientoCritico(hogar h, eph_i ti);

#endif //SOLUCION_AUXILIARES_H
