#include <iostream>
#include <string>
#include <fstream>
#include <limits>

class Cliente {
private:
    std::string nombre;
    std::string apellidos;
    int edad;

public:
    Cliente() : nombre(""), apellidos(""), edad(0) {}

    Cliente(const std::string& nombre, const std::string& apellidos, int edad)
        : nombre(nombre), apellidos(apellidos), edad(edad) {}

    std::string obtenerDatos() const {
        return "Nombre: " + nombre + "\n" +
               "Apellidos: " + apellidos + "\n" +
               "Edad: " + std::to_string(edad) + " años\n";
    }
};

int main() {
    std::string nombre, apellidos;
    int edad;

    std::cout << "Introduzca el nombre del cliente:\n";
    std::getline(std::cin, nombre);

    std::cout << "Introduzca los apellidos del cliente:\n";
    std::getline(std::cin, apellidos);

    std::cout << "Introduzca la edad del cliente:\n";
    std::cin >> edad;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (edad <= 0 || edad > 100) {
        std::cout << "La edad debe ser entre 1 y 100.\n";
        return 1;
    }

    Cliente cliente(nombre, apellidos, edad);

    std::ofstream archivo("clientes.txt", std::ios::app);

    if (archivo.is_open()) {
        archivo << cliente.obtenerDatos() << "\n";
        std::cout << "Cliente guardado correctamente en 'clientes.txt'.\n";
    } else {
        std::cout << "Error al abrir el archivo.\n";
    }

    return 0;
}
