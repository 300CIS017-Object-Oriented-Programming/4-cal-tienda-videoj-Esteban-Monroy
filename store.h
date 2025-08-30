//
// Created by Jesus Esteban Monroy on 29/08/2025.
//

#ifndef INC_4_CAL_TIENDA_VIDEOJ_ESTEBAN_MONROY_STORE_H
#define INC_4_CAL_TIENDA_VIDEOJ_ESTEBAN_MONROY_STORE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// --- Constantes del sistema ---
const int MAX_JUEGOS_CATALOGO = 12;
const int MAX_ARTICULOS_CARRITO = 10;
const double DESCUENTO_ORO = 0.15;
const double DESCUENTO_PLATA = 0.08;
const double DESCUENTO_REGULAR = 0.0;

// --- Arrays para el catálogo de juegos (declaraciones externas) ---
extern const int CODIGOS_JUEGOS[MAX_JUEGOS_CATALOGO];
extern const string NOMBRES_JUEGOS[MAX_JUEGOS_CATALOGO];
extern const string CATEGORIAS_JUEGOS[MAX_JUEGOS_CATALOGO];
extern const string PLATAFORMAS_JUEGOS[MAX_JUEGOS_CATALOGO];
extern const double PRECIOS_JUEGOS[MAX_JUEGOS_CATALOGO];

// --- Prototipos de funciones para generar la numeracion de juegos ---
void mostrarCatalogoJuegos();
int leerCodigoJuego();
int leerCantidadJuegos();
string obtenerNombreJuego(int codigoJuego);
double obtenerPrecioJuego(int codigoJuego);
string obtenerPlataforma(int codigoJuego);
string obtenerCategoria(int codigoJuego);
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);


#endif //INC_4_CAL_TIENDA_VIDEOJ_ESTEBAN_MONROY_STORE_H
