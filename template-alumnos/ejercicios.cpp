#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {

  if (!esMatrizEphh(th) || !esMatrizEphi(ti)) {
    return false;
  }

  if (!alMenosUnHogarEnEphh(th) || !alMenosUnIndividuoEnEphi(ti)) {
    return false;
  }

  if (!cantColumnasIgualACantEnTablaItem(th, ti)) {
    return false;
  }

  if (!noHayIndividuosSinHogarYViceversa(th, ti)) {
    return false;
  }

  if (!noHayRepetidos(th, ti)) {
    return false;
  }

  if (!mismoAnioYTrimestre(th, ti)) {
    return false;
  }

  if (!cantMiembrosMenorIgualA20(th, ti)) {
    return false;
  }

  if (!cantDeHabMayorQueCantParaDormir(th)) {
    return false;
  }

  if (!valoresEnRangoH(th) || !valoresEnRangoI(ti)) {
    return false;
  }
	
	return true;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado = {};
    int maxHabitaciones = maxCantHabitacionesEnRegion(th, region);
    for (int i = 0; i < maxHabitaciones; i++){
        resultado.push_back(0);
    }
    for (int i = 0; i < th.size(); i++){
        if (estaEnLaRegion(th[i], region) && esCasa(th[i])) {
            int cantHabitaciones = th[i][IV2];
            resultado[cantHabitaciones - 1]++;
        }
    }
	
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {
    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
    for (int i = 0; i < resp.size(); ++i) {
        resp[i].second = proporcionDeCasasConHC(th, ti, resp[i].first);
    }
	
    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    bool resp = proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
    return resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto) {
	int cantidadDeCasasCandidatas = 0;

  for (int i = 0; i < th.size(); ++i) {
    if (th[i][II7] == 1 && (cantHabitantes(th[i], ti) - 2 > th[i][II2])) {
      cantidadDeCasasCandidatas++;
    }
  }
	
  return cantidadDeCasasCandidatas * monto;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	  join_hi resp = {};

    for (int j = 0; j < th.size(); ++j) {
        h = th[j];
        for (int k = 0; k < ti.size(); ++k) {
            i = ti[k];
            if (h[HOGCODUSU] == i[INDCODUSU]){
                resp.push_back(make_pair(h,i));
            }
        }
    }
	
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector<hogar> muestraHomogenea (eph_h &th, eph_i &ti) {
    if (th.size() < 3) {
      return {};
    }

    vector<hogar> secuenciaMasLarga = {};
    vector<hogar> secuenciaMasLargaActual = {th[0], th[1]};
    int difIngresosActual = ingresos(th[1], ti) - ingresos(th[0], ti);

    for (int i = 2; i < th.size(); ++i) {
      if (ingresos(th[i], ti) - ingresos(th[i - 1], ti) == difIngresosActual) {
        secuenciaMasLargaActual.push_back(th[i]);
      } else {
        if (secuenciaMasLargaActual.size() > secuenciaMasLarga.size()) {
          secuenciaMasLarga = secuenciaMasLargaActual;
        }

        secuenciaMasLargaActual = {};
        difIngresosActual = ingresos(th[i], ti) - ingresos(th[i - 1], ti);
      }
    }

    if (secuenciaMasLargaActual.size() > secuenciaMasLarga.size()) {
      secuenciaMasLarga = secuenciaMasLargaActual;
    }

    return secuenciaMasLarga.size() >= 3 ? secuenciaMasLarga : {};
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
