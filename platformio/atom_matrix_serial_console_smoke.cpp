#include <Arduino.h>

#include "../examples/atom_matrix_serial_console/atom_matrix_serial_console.h"

void setup() {
    atom_matrix_serial_console::setupConsole();
    atom_matrix_serial_console::setupButtonIncrement();
}

void loop() {
    atom_matrix_serial_console::loop();
    atom_matrix_serial_console::pollButtonIncrement();
    atom_matrix_serial_console::pollDemoDisplay();
    atom_matrix_serial_console::pollEnduranceTest();
    atom_matrix_serial_console::pollReconnectTest();
    atom_matrix_serial_console::pollBenchmark();
}
