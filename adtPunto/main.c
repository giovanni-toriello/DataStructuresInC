
#include "punto.h"
#include "list.h"
#include "esame.h"

int main() {
    list l = inputList(8);
    list k = inputList(2);
    l = inserisci_lista(l, k, 3);
    outputList(l);
}