#include "structs.h"

int valorString(string str){
    int valor = 0;
    int tam = str.size();
    for(int i=0; i< tam; i++){
        valor = 31*valor + static_cast<int>(str[i]);
    }
    return valor;
}
