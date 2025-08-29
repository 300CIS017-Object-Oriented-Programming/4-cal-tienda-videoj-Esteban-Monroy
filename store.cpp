#include "store.h"

// --- Arrays para el catálogo de juegos (definiciones) ---
const int CODIGOS_JUEGOS[MAX_JUEGOS_CATALOGO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const string NOMBRES_JUEGOS[MAX_JUEGOS_CATALOGO] = {
        "The Last of Us Part II", "God of War Ragnarok", "Ghost of Tsushima",
        "Red Dead Redemption 2", "The Witcher 3", "Cyberpunk 2077",
        "FIFA 25", "NBA 2K25", "Forza Horizon 5",
        "Starcraft II", "Civilization VI", "Age of Empires IV"
};
const string CATEGORIAS_JUEGOS[MAX_JUEGOS_CATALOGO] = {
        "Aventura", "Aventura", "Aventura",
        "Accion", "Accion", "Accion",
        "Deportes", "Deportes", "Deportes",
        "Estrategia", "Estrategia", "Estrategia"
};
const string PLATAFORMAS_JUEGOS[MAX_JUEGOS_CATALOGO] = {
        "PS5", "PS5", "PS5",
        "PC", "PC", "PS5",
        "Xbox", "PS5", "Xbox",
        "PC", "PC", "PC"
};
const double PRECIOS_JUEGOS[MAX_JUEGOS_CATALOGO] = {59.99, 69.99, 49.99, 59.99, 39.99, 49.99, 69.99, 69.99, 59.99, 29.99, 29.99, 29.99};

// --- Implementaciones de funciones ---

/**
 * @brief Muestra el catálogo completo de juegos disponibles.
 */
void mostrarCatalogoJuegos() {
    cout << "\n--- Catalogo de Videojuegos ---" << endl;
    cout << setw(8) << "Codigo" << setw(40) << "Nombre" << setw(15) << "Plataforma" << setw(15) << "Categoria" << setw(10) << "Precio" << endl;
    cout << setfill('-') << setw(98) << "" << setfill(' ') << endl;

    for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
        cout << setw(8) << CODIGOS_JUEGOS[i] << setw(40) << NOMBRES_JUEGOS[i] << setw(15) << PLATAFORMAS_JUEGOS[i] << setw(15) << CATEGORIAS_JUEGOS[i] << setw(10) << fixed << setprecision(2) << PRECIOS_JUEGOS[i] << endl;
    }
}

/**
 * @brief Lee y valida el código de un juego.
 * @return El código del juego ingresado.
 */
int leerCodigoJuego() {
    int codigo;
    bool valido = false;
    do {
        cout << "Ingrese el codigo del juego: ";
        cin >> codigo;
        for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
            if (codigo == CODIGOS_JUEGOS[i]) {
                valido = true;
                break;
            }
        }
        if (!valido) {
            cout << "Codigo no valido. Por favor, intente de nuevo." << endl;
        }
    } while (!valido);
    return codigo;
}

/**
 * @brief Lee y valida la cantidad de juegos.
 * @return La cantidad ingresada.
 */
int leerCantidadJuegos() {
    int cantidad;
    do {
        cout << "Ingrese la cantidad a comprar: ";
        cin >> cantidad;
        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor a 0. Intente de nuevo." << endl;
        }
    } while (cantidad <= 0);
    return cantidad;
}

/**
 * @brief Obtiene el nombre de un juego a partir de su código.
 * @param codigoJuego El código del juego.
 * @return El nombre del juego.
 */
string obtenerNombreJuego(int codigoJuego) {
    for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
        if (codigoJuego == CODIGOS_JUEGOS[i]) {
            return NOMBRES_JUEGOS[i];
        }
    }
    return "Juego no encontrado";
}

/**
 * @brief Obtiene el precio de un juego a partir de su código.
 * @param codigoJuego El código del juego.
 * @return El precio del juego.
 */
double obtenerPrecioJuego(int codigoJuego) {
    for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
        if (codigoJuego == CODIGOS_JUEGOS[i]) {
            return PRECIOS_JUEGOS[i];
        }
    }
    return 0.0;
}

/**
 * @brief Obtiene la plataforma de un juego a partir de su código.
 * @param codigoJuego El código del juego.
 * @return La plataforma del juego.
 */
string obtenerPlataforma(int codigoJuego) {
    for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
        if (codigoJuego == CODIGOS_JUEGOS[i]) {
            return PLATAFORMAS_JUEGOS[i];
        }
    }
    return "Plataforma no encontrada";
}

/**
 * @brief Obtiene la categoría de un juego a partir de su código.
 * @param codigoJuego El código del juego.
 * @return La categoría del juego.
 */
string obtenerCategoria(int codigoJuego) {
    for (int i = 0; i < MAX_JUEGOS_CATALOGO; ++i) {
        if (codigoJuego == CODIGOS_JUEGOS[i]) {
            return CATEGORIAS_JUEGOS[i];
        }
    }
    return "Categoria no encontrada";
}

/**
 * @brief Agrega un juego al carrito de compras, actualizando la cantidad si ya existe.
 * @param codigos[] El arreglo de códigos de juegos en el carrito.
 * @param cantidades[] El arreglo de cantidades en el carrito.
 * @param cantidadJuegosRegistrados La cantidad actual de juegos únicos en el carrito.
 */
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    if (cantidadJuegosRegistrados >= MAX_ARTICULOS_CARRITO) {
        cout << "\nError: El carrito esta lleno. No se pueden agregar mas articulos." << endl;
        return;
    }

    int codigo = leerCodigoJuego();
    int cantidad = leerCantidadJuegos();

    // Verificar si el juego ya está en el carrito
    for (int i = 0; i < cantidadJuegosRegistrados; ++i) {
        if (codigos[i] == codigo) {
            cantidades[i] += cantidad;
            cout << "\nJuego ya en el carrito. Cantidad actualizada." << endl;
            return;
        }
    }

    // Agregar nuevo juego al carrito
    codigos[cantidadJuegosRegistrados] = codigo;
    cantidades[cantidadJuegosRegistrados] = cantidad;
    cantidadJuegosRegistrados++;

    cout << "\nJuego agregado al carrito exitosamente." << endl;
}

/**
 * @brief Calcula el subtotal del carrito sin descuentos.
 * @param codigos[] El arreglo de códigos de juegos en el carrito.
 * @param cantidades[] El arreglo de cantidades en el carrito.
 * @param cantidadJuegosRegistrados La cantidad de juegos únicos en el carrito.
 * @return El subtotal de la compra.
 */
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double subtotal = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; ++i) {
        subtotal += obtenerPrecioJuego(codigos[i]) * cantidades[i];
    }
    return subtotal;
}

/**
 * @brief Lee y valida el tipo de cliente.
 * @return El tipo de cliente seleccionado.
 */
int leerTipoCliente() {
    int tipoCliente;
    do {
        cout << "\n--- Tipos de Cliente ---" << endl;
        cout << "1. Miembro Oro (15% de descuento)" << endl;
        cout << "2. Miembro Plata (8% de descuento)" << endl;
        cout << "3. Cliente Regular (0% de descuento)" << endl;
        cout << "Seleccione el tipo de cliente: ";
        cin >> tipoCliente;
        if (tipoCliente < 1 || tipoCliente > 3) {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (tipoCliente < 1 || tipoCliente > 3);
    return tipoCliente;
}

/**
 * @brief Obtiene el porcentaje de descuento según el tipo de cliente.
 * @param tipoCliente El tipo de cliente.
 * @return El porcentaje de descuento.
 */
double obtenerPorcentajeDescuento(int tipoCliente) {
    switch (tipoCliente) {
        case 1:
            return DESCUENTO_ORO;
        case 2:
            return DESCUENTO_PLATA;
        case 3:
            return DESCUENTO_REGULAR;
        default:
            return 0.0;
    }
}

/**
 * @brief Calcula los descuentos adicionales basados en plataformas y categorías específicas.
 * @param codigos[] El arreglo de códigos de juegos.
 * @param cantidades[] El arreglo de cantidades.
 * @param cantidadJuegosRegistrados La cantidad de juegos en el carrito.
 * @return El monto total de descuentos adicionales.
 */
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double descuentosAdicionales = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; ++i) {
        string plataforma = obtenerPlataforma(codigos[i]);
        string categoria = obtenerCategoria(codigos[i]);
        double precio = obtenerPrecioJuego(codigos[i]);

        // Descuento para juegos de PC de la categoría "Estrategia"
        if (plataforma == "PC" && categoria == "Estrategia") {
            descuentosAdicionales += (precio * cantidades[i]) * 0.10; // 10% de descuento adicional
        }
    }
    return descuentosAdicionales;
}

/**
 * @brief Calcula el total final de la compra con todos los descuentos aplicados.
 * @param subtotal El subtotal de la compra.
 * @param porcentajeDescuento El porcentaje de descuento del cliente.
 * @param descuentosAdicionales El monto de los descuentos adicionales.
 * @return El total final a pagar.
 */
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales) {
    double total = subtotal - (subtotal * porcentajeDescuento) - descuentosAdicionales;
    return total > 0 ? total : 0;
}

/**
 * @brief Muestra un resumen detallado de la compra, incluyendo subtotales y descuentos.
 * @param codigos[] El arreglo de códigos de juegos.
 * @param cantidades[] El arreglo de cantidades.
 * @param cantidadJuegosRegistrados La cantidad de juegos en el carrito.
 * @param porcentajeDescuento El porcentaje de descuento del cliente.
 */
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento) {
    double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
    double descuentosAdicionales = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);
    double totalFinal = calcularTotalFinal(subtotal, porcentajeDescuento, descuentosAdicionales);

    cout << "\n--- Resumen de la Compra ---" << endl;
    cout << setw(30) << "Juego" << setw(10) << "Cant." << setw(10) << "Precio" << setw(15) << "Subtotal" << endl;
    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

    for (int i = 0; i < cantidadJuegosRegistrados; ++i) {
        string nombre = obtenerNombreJuego(codigos[i]);
        double precio = obtenerPrecioJuego(codigos[i]);
        double subtotalItem = precio * cantidades[i];
        cout << setw(30) << nombre << setw(10) << cantidades[i] << setw(10) << fixed << setprecision(2) << precio << setw(15) << fixed << setprecision(2) << subtotalItem << endl;
    }

    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;
    cout << setw(55) << "Subtotal:" << setw(10) << fixed << setprecision(2) << subtotal << endl;
    cout << setw(55) << "Descuento Cliente (" << porcentajeDescuento * 100 << "%):" << setw(10) << fixed << setprecision(2) << (subtotal * porcentajeDescuento) << endl;
    cout << setw(55) << "Descuentos Adicionales:" << setw(10) << fixed << setprecision(2) << descuentosAdicionales << endl;
    cout << setw(55) << "Total a Pagar:" << setw(10) << fixed << setprecision(2) << totalFinal << endl;
}

/**
 * @brief Carga una compra de demostración en el carrito.
 * @param codigos[] El arreglo de códigos de juegos.
 * @param cantidades[] El arreglo de cantidades.
 * @param cantidadJuegosRegistrados La cantidad de juegos en el carrito (se reinicia).
 */
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    limpiarCarrito(codigos, cantidades, cantidadJuegosRegistrados);
    cantidadJuegosRegistrados = 2;
    codigos[0] = 1; // The Last of Us Part II
    cantidades[0] = 1;
    codigos[1] = 10; // Starcraft II
    cantidades[1] = 2;
}

/**
 * @brief Limpia el carrito de compras.
 * @param codigos[] El arreglo de códigos de juegos.
 * @param cantidades[] El arreglo de cantidades.
 * @param cantidadJuegosRegistrados La cantidad de juegos en el carrito (se reinicia a cero).
 */
void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    cantidadJuegosRegistrados = 0;
}
