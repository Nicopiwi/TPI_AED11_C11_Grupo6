#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

bool esCasa(hogar h){
    return h[IV1] == 1;
}

int qDormitorios(){
    return II2;
}

int qHabitaciones(){
    return IV2;
}

int region(){
    return REGION;
}

bool esSuHogar(hogar h, individuo i){
    return h[HOGCODUSU] == i[INDCODUSU];
}

int cantHabitantes(hogar h, eph_i ti){
    int cantidad = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (esSuHogar(h, ti[i])){
            cantidad += 1;
        }
    }
    return cantidad;
}

hogar buscarHogarPara(eph_h th, individuo ind){
    int i = 0;
    while (i < th.size() && th[i][HOGCODUSU]!=ind[INDCODUSU]){
        ++i;
    }
    return th[i];
}

//Auxiliares Ej. 2

bool estaEnLaRegion(hogar h, int r){
    return h[region()] == r;
}

int maxCantHabitacionesEnRegion(eph_h th, int region){
    int max = 1;
    for (int i = 1; i < th.size(); i++){
        int habitaciones = th[i][qHabitaciones()];
        if (estaEnLaRegion(th[i], region) && habitaciones>max){
            max = habitaciones;
        }
    }
    return max;
}

//Auxiliares ej 3
float proporcionDeCasasConHC(eph_h th, eph_i ti, int region){
    if (cantHogaresValidos(th, region) > 0){
        return cantHogaresValidosConHC(th, ti, region) / cantHogaresValidos(th, region);
    }
    else{
        return 0;
    }
}

bool esHogarValido(hogar h, int region){
    return esCasa(h) && (h[REGION] == region) && (h[MAS_500] == 0);
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    int cantidad = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti)){
            cantidad += 1;
        }
    }
    return cantidad;
}

int cantHogaresValidos(eph_h th, int region){
    int cantidad = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region)){
            cantidad += 1;
        }
    }
    return cantidad;
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    return cantHabitantes(h, ti) > (3 * h[qDormitorios()]);
}

//Auxiliares Ej. 4

float proporcionTeleworking(eph_h th, eph_i ti){
    float cantIndividuosTrabajandoEnSuVivienda = 0;
    float cantIndividuosQueTrabajan = 0;
    for (int i = 0; i < ti.size(); i++){
        hogar suHogar = buscarHogarPara(th, ti[i]);
        bool condicionTrabaja = trabaja(ti[i])
                                && esCasaODepartamento(suHogar)
                                && hogarEsDeCiudadGrande(suHogar);
        if(condicionTrabaja){
            cantIndividuosQueTrabajan++;
            if (realizaSusTareasEnEsteHogar(ti[i]) && tieneEspaciosReservadosParaElTrabajo(suHogar)){
                cantIndividuosTrabajandoEnSuVivienda++;
            }
        }
    }
    return (cantIndividuosQueTrabajan > 0) ? cantIndividuosTrabajandoEnSuVivienda/cantIndividuosQueTrabajan : 0;
}

/*
int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti){
    int res = 0;
    for (int i = 0; i < ti.size(); i++){
        hogar suHogar = buscarHogarPara(th, ti[i]);
        bool condicionTeleworking = trabaja(ti[i])
                                    && esCasaODepartamento(suHogar)
                                    && hogarEsDeCiudadGrande(suHogar)
                                    && realizaSusTareasEnEsteHogar(ti[i])
                                    && tieneEspaciosReservadosParaElTrabajo(suHogar);
        res += condicionTeleworking ? 1 : 0;
    }
    return res;
}

int cantIndividuosQueTrabajan(eph_h th, eph_i ti){
    int res = 0;
    for (int i = 0; i < ti.size(); i++){
        hogar suHogar = buscarHogarPara(th, ti[i]);
        bool condicionTrabaja = trabaja(ti[i])
                                    && esCasaODepartamento(suHogar)
                                    && hogarEsDeCiudadGrande(suHogar);
        res += condicionTrabaja ? 1 : 0;
    }
    return res;
}
 */

bool esDepartamento(hogar h){
    return h[IV1] == 2;
}

bool esCasaODepartamento(hogar h){
    return esCasa(h) || esDepartamento(h);
}

bool realizaSusTareasEnEsteHogar(individuo i){
    return i[PP04G]==6;
}

bool tieneEspaciosReservadosParaElTrabajo(individuo i){
    return i[II3]==1;
}

bool trabaja(individuo i){
    return i[ESTADO]==1;
}

bool hogarEsDeCiudadGrande(hogar h){
    return h[MAS_500]==1;
}



