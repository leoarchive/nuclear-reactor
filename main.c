#include <stdio.h>
#include <stdlib.h>
#include "controle.c"

int inicia() {
    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            aguadomar.MgCl2 = 0;
            aguadomar.CaSO4 = 0;
            aguadomar.MgSO4 = 0;
            aguadomar.NaCl = 0;
            reator.uranio235 = 0;
            reator.uranio238 = 0;
            rejeitos.HLW = 0;
            rejeitos.ILW = 0;
            rejeitos.LLW = 0;
        }
        reator.energia[i] = 0;
        reator.temperatura[i] = 0;
        turbina.rpm[i] = 0;
        turbina.reaproveitamento[i] = 0;
        turbina.voltagem[i] = 0;
        aguadomar.ph[i] = 0;
        aguadomar.lpm[i] = 0;
    }
    return 0;
}

int main() {
    inicia();

    int menu;
    printf("  .. ..  \n"
           " ... ... \n"
           "    o        Reator Nuclear Simulador \n"
           "    .    \n"
           "   ...   \n"
    );

    puts("\n1 - Iniciar \n"
         "2 - Sair \n"
    );
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            Controle();
        case 2:
            exit(0);
        default:
            puts("Opcao inexistente");
    }
}
