#include <windows.h>

#include "storage.h"

int main() {
    // Allow output encoded in UTF-8
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    // Start the program
    Storage().start();

    return 0;
}
