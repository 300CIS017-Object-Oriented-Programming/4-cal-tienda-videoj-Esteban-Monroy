#include "store.h"

int main() {
    int codigosCarrito[MAX_ARTICULOS_CARRITO];
    int cantidadesCarrito[MAX_ARTICULOS_CARRITO];
    int cantidadJuegosRegistrados = 0;
    int opcion, tipoCliente;
    double subtotal, porcentajeDescuento, descuentosAdicionales, totalFinal;

    do {
        cout << "\n--- Menu Principal GameStore ---" << endl;
        cout << "1. Mostrar catalogo de juegos" << endl;
        cout << "2. Agregar juego al carrito" << endl;
        cout << "3. Ver carrito y calcular compra" << endl;
        cout << "4. Cargar compra de demostracion" << endl;
        cout << "5. Limpiar carrito" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarCatalogoJuegos();
                break;
            case 2:
                agregarJuegoAlCarrito(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados);
                break;
            case 3:
                if (cantidadJuegosRegistrados > 0) {
                    tipoCliente = leerTipoCliente();
                    subtotal = calcularSubtotalCarrito(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados);
                    porcentajeDescuento = obtenerPorcentajeDescuento(tipoCliente);
                    descuentosAdicionales = calcularDescuentosAdicionales(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados);
                    totalFinal = calcularTotalFinal(subtotal, porcentajeDescuento, descuentosAdicionales);
                    mostrarResumenCompra(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados, porcentajeDescuento);
                } else {
                    cout << "\nEl carrito esta vacio. Agregue juegos primero." << endl;
                }
                break;
            case 4:
                cargarCompraDemo(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados);
                cout << "\nCompra de demostracion cargada exitosamente." << endl;
                break;
            case 5:
                limpiarCarrito(codigosCarrito, cantidadesCarrito, cantidadJuegosRegistrados);
                cout << "\nEl carrito ha sido limpiado." << endl;
                break;
            case 6:
                cout << "\nGracias por visitar GameStore. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}