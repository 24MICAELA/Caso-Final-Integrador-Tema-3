#include "script_loader.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

// Crear un log de errores
void log_error(const std::string& error_message) {
    std::ofstream log_file("error_log.txt", std::ios::app);
    if (log_file.is_open()) {
        log_file << error_message << std::endl;
        log_file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo de log" << std::endl;
    }
}

// Cargar script desde un archivo
void load_script(const char* filename, bool show_script) {
    std::string script;
    FILE* f = nullptr;

    try {
        f = fopen(filename, "rb");
        if (!f) {
            std::string error_message = "Error de apertura del archivo: ";
            error_message += filename;
            log_error(error_message);
            std::cerr << error_message << std::endl;
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = 0;
            script.append(buf);
        }

        fclose(f);

        if (show_script) {
            std::cout << script << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::string error_message = "Error durante la lectura del archivo: ";
        error_message += e.what();
        log_error(error_message);
        std::cerr << error_message << std::endl;
    }
}

// Función de carga de script solicitando el nombre del archivo
void load_script() {
    char filename[500];
    std::cout << "Cargar un script:\nIntroduce el nombre del archivo: ";
    std::cin >> filename;
    load_script(filename, true);
}
