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



