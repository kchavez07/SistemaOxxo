#include "SistemaOxxo.h"
#include "Menu.h"

int main() {
    SistemaOxxo sistema;
    Menu menu(sistema);
    menu.ejecutar();
    return 0;
}
