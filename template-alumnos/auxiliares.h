#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

template <class T>
bool contiene(T, vector<T>);

bool esCasa(hogar);

int qDormitorios();

int qHabitaciones();

bool esSuHogar(hogar, individuo);

int cantHabitantes(hogar, eph_i);

int buscarIndiceHogarPara(eph_h, individuo);


//aux ej 1
bool esMatrizEphh(eph_h th);

bool esMatrizEphi(eph_i ti);

bool alMenosUnHogarEnEphh(eph_h th);

bool alMenosUnIndividuoEnEphi(eph_i ti);

bool cantColumnasIgualACantEnTablaItem(eph_h th, eph_i ti);

bool noHayIndividuosSinHogarYViceversa(eph_h th, eph_i ti);

bool noHayRepetidos(eph_h th, eph_i ti);

bool mismoAnioYTrimestre(eph_h th, eph_i ti);

bool cantMiembrosMenorIgualA20(eph_h th, eph_i ti);

bool cantDeHabMayorQueCantParaDormir(eph_h th);

bool valoresEnRangoH(eph_h th);

bool valoresEnRangoI(eph_i ti);


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

//aux ej 8
int ingresos(hogar h, eph_i ti);

void ordenarPorIngresos(vector<hogar> &res, eph_i ti);

//aux ej 10
int cantHogaresEnAnillo(int distDesde, int distHasta, pair<int, int> centro, eph_h th);

bool hogarEnAnillo(int distDesde, int distHasta, pair<int, int> centro, hogar h);

double distanciaEuclideana(pair<int, int> centro, int latitud, int longitud);


int ingresos(hogar, eph_i);

//Auxiliares 11

bool cumpleCondicionBusqueda(vector<pair<int, dato>>, individuo);

bool elHogarYaFueExcluido(hogar, pair < eph_h, eph_i >);

bool seDebeExcluirHogarDeOriginal(int, eph_i);

#endif //SOLUCION_AUXILIARES_H
