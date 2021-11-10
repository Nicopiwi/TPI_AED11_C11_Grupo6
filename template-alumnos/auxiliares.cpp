#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

template <class T>
bool contiene(T elem, vector<T> v){
    for (int i = 0; i < v.size(); i++){
        if (elem == v[i]) return true;
    }
    return false;
}

bool esCasa(hogar h){
    return h[IV1] == CASA;
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


int buscarIndiceHogarPara(eph_h th, individuo ind){
    int i = 0;
    while (i < th.size() && th[i][HOGCODUSU]!=ind[INDCODUSU]){
        ++i;
    }
    return (i == th.size()) ? -1 : i;
}

// Auxiliares ejercicio 1
bool esMatrizEphh(eph_h th) {
    if (th.size() == 0 || th.size() == 1) {
        return true;
    }

    for (int i = 1; i < th.size(); ++i) {
        if (th[i].size() != th[0].size()) {
            return false;
        }
    }

    return true;
}

bool esMatrizEphi(eph_i ti) {
    if (ti.size() == 0 || ti.size() == 1) {
        return true;
    }

    for (int i = 1; i < ti.size(); ++i) {
        if (ti[i].size() != ti[0].size()) {
            return false;
        }
    }

    return true;
}

bool alMenosUnHogarEnEphh(eph_h th) {
    return th.size() > 0;
}

bool alMenosUnIndividuoEnEphi(eph_i ti) {
    return ti.size() > 0;
}

bool cantColumnasIgualACantEnTablaItem(eph_h th, eph_i ti) {
    return th[0].size() == FILAS_HOGAR && ti[0].size() == FILAS_INDIVIDUO;
}

bool noHayIndividuosSinHogarYViceversa(eph_h th, eph_i ti) {

    for (int i = 0; i < th.size(); ++i) {
        bool hogarEncontrado = false;

        for (int j = 0; j < ti.size(); ++j) {
            if (ti[j][INDCODUSU] == th[i][HOGCODUSU]) {
                hogarEncontrado = true;
                break;
            }
        }

        if (!hogarEncontrado) {
            return false;
        }
    }

    for (int k = 0; k < ti.size(); ++k) {
        bool individuoEncontrado = false;

        for (int l = 0; l < th.size(); ++l) {
            if (ti[l][INDCODUSU] == th[k][HOGCODUSU]) {
                individuoEncontrado = true;
                break;
            }
        }

        if (!individuoEncontrado) {
            return false;
        }
    }

    return true;
}

bool noHayRepetidos(eph_h th, eph_i ti) {
    for (int i = 0; i < th.size(); ++i) {
        for (int j = i + 1; j < th.size(); ++j) {
            if (th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                return false;
            }
        }   
    }

    for (int k = 0; k < ti.size(); ++k) {
        for (int l = k + 1; l < ti.size(); ++l) {
            if (ti[k][INDCODUSU] == ti[l][INDCODUSU] && ti[k][COMPONENTE] == ti[l][COMPONENTE]) {
                return false;
            }
        }   
    }

    return true;
}

bool mismoAnioYTrimestre(eph_h th, eph_i ti) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][HOGANIO] != th[0][HOGANIO] && th[i][HOGTRIMESTRE] != th[0][HOGTRIMESTRE]) {
            return false;
        }
    }

    for (int j = 0; j < ti.size(); ++j) {
        if (ti[j][INDANIO] != th[0][HOGANIO] && ti[j][INDTRIMESTRE] != th[0][HOGTRIMESTRE]) {
            return false;
        }
    }

    return true;
}

bool cantMiembrosMenorIgualA20(eph_h th, eph_i ti) {
    for (int i = 0; i < th.size(); ++i) {
        int cantDeMiembros = 0;

        for (int j = 0; j < ti.size(); ++j) {
            if (ti[j][INDCODUSU] == th[i][HOGCODUSU]) {
                cantDeMiembros++;
            }
        }

        if (cantDeMiembros > 20) {
            return false;
        }
    }

    return true;
}

bool cantDeHabMayorQueCantParaDormir(eph_h th) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][IV2] < th[i][II2]) {
            return false;
        }
    }

    return true;
}

bool valoresEnRangoH(eph_h th) {
    for (int i = 0; i < th.size(); ++i) {
        if (th[i][HOGCODUSU] <= 0) {
            return false;
        }

        if (th[i][HOGTRIMESTRE] <= 0 || th[i][HOGTRIMESTRE] > 4) {
            return false;
        }

        if (th[i][II7] <= 0 || th[i][II7] > 3) { //tenencia
            return false;
        }

        if ((th[i][REGION] < 40 || th[i][REGION] > 44) && th[i][REGION] != 1) {
            return false;
        }

        if (th[i][MAS_500] != 0 && th[i][MAS_500] != 1) {
            return false;
        }

        if (th[i][IV1] <= 0 || th[i][IV1] > 5) { //tipo
            return false;
        }

        if (th[i][IV2] <= 0) {
            return false;
        }

        if (th[i][II2] <= 0) {
            return false;
        }

        if (th[i][II3] != 1 && th[i][II3] != 2) {
            return false;
        }
    }

    return true;
}

bool valoresEnRangoI(eph_i ti) {
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i][INDCODUSU] <= 0) {
            return false;
        }

        if (ti[i][COMPONENTE] <= 0) {
            return false;
        }

        if (ti[i][INDTRIMESTRE] <= 0 || ti[i][INDTRIMESTRE] > 4) {
            return false;
        }

        if (ti[i][CH4] != 1 && ti[i][CH4] != 2) {
            return false;
        }

        if (ti[i][CH6] < 0) {
            return false;
        }

        if (ti[i][NIVEL_ED] != 0 && ti[i][NIVEL_ED] != 1) {
            return false;
        }

        if (ti[i][ESTADO] < -1 || ti[i][NIVEL_ED] > 1) {
            return false;
        }

        if (ti[i][CAT_OCUP] < 0 || ti[i][CAT_OCUP] > 4) {
            return false;
        }

        if (ti[i][p47T] < -1) {
            return false;
        }

        if (ti[i][PP04G] < 0 || ti[i][PP04G] > 10) {
            return false;
        }

    }

    return true;
}

//Auxiliares Ej. 2

bool estaEnLaRegion(hogar h, int r){
    return h[REGION] == r;
}

int maxCantHabitacionesEnRegion(eph_h th, int region){
    int max = 0;
    for (int i = 0; i < th.size(); i++){
        int habitaciones = th[i][IV2];
        if (estaEnLaRegion(th[i], region) && habitaciones > max){
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
    return cantHabitantes(h, ti) > (3 * h[II2]);
}

//Auxiliares Ej. 4

float proporcionTeleworking(eph_h th, eph_i ti){
    float cantIndividuosTrabajandoEnSuVivienda = 0;
    float cantIndividuosQueTrabajan = 0;
    for (int i = 0; i < ti.size(); i++){
        int hogarIndex = buscarIndiceHogarPara(th, ti[i]);
        hogar suHogar = th[hogarIndex];
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

bool esDepartamento(hogar h){
    return h[IV1] == DEPARTAMENTO;
}

bool esCasaODepartamento(hogar h){
    return esCasa(h) || esDepartamento(h);
}

bool realizaSusTareasEnEsteHogar(individuo i){
    return i[PP04G] == EN_ESTE_HOGAR;
}

bool tieneEspaciosReservadosParaElTrabajo(individuo i){
    return i[II3]==1;
}

bool trabaja(individuo i){
    return i[ESTADO]==OCUPADO;
}

bool hogarEsDeCiudadGrande(hogar h){
    return h[MAS_500]==1;
}

//Auxiliares Ej. 8
int ingresos(hogar h, eph_i ti) {
    int ingresosTotales = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1) {
            ingresosTotales += ti[i][p47T];
        }
    }

    return ingresosTotales;
}

void ordenarPorIngresos(vector<hogar> &res, eph_i ti){
    for (int i = 0; i < res.size() - 1; ++i) {
        for (int j = 0; j < res.size() - i - 1; ++j) {
            if(ingresos(res[j], ti) > ingresos(res[j+1], ti)){
                swap(res[j], res[j+1]);
            }
        }
    }
}

//Auxiliares Ej. 10
int cantHogaresEnAnillo(int distDesde, int distHasta, pair<int, int> centro, eph_h th){
    int cantidad = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (hogarEnAnillo(distDesde, distHasta, centro, th[i])){
            cantidad += 1;
        }
    }
    return cantidad;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair<int, int> centro, hogar h){
    double dist = distanciaEuclideana(centro, h[HOGLATITUD], h[HOGLONGITUD]);
    return (distDesde < dist) && (dist <= distHasta);
}

double distanciaEuclideana(pair<int, int> centro, int latitud, int longitud){
    double dist = pow(centro.first - latitud, 2) + pow(centro.second - longitud, 2);
    dist = sqrt(dist);
    return dist;

}
//Auxiliares ej.11
bool cumpleCondicionBusqueda(vector<pair<int, dato>> busqueda, individuo ind){
    for (int j = 0; j < busqueda.size(); j++){
        if(ind[busqueda[j].first]!=busqueda[j].second) return false;
    }
    return true;
}


bool elHogarYaFueExcluido(hogar h, pair < eph_h, eph_i > excluidos){
    for (int j = 0; j < excluidos.first.size(); j++){
        if (excluidos.first[j][HOGCODUSU] == h[HOGCODUSU]) {
            return true;
        }
    }
    return false;
}

bool noHayIndividuoParaHogar(int codigoHogar, eph_i ti){
    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDCODUSU] == codigoHogar) return false;
    }
    return true;
}

