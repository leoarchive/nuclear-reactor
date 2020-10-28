#include <stdio.h>
#include <stdlib.h>
#include "insere.c"
#include "regras.c"
int Configuracoes();

int Controle() {
    for (; ;) {
        int opcao, aux = 0;
        for (int i = 0;; ++i) {
            printf("Resfriamento");
            printf("\t\tReator");
            printf("\t\t\tTurbina");
            printf("\t\t\tRejeitos\n");
            printf("-------------------");
            printf("\t-------------------");
            printf("\t-------------------");
            printf("\t-------------------\n");
            printf("pH %.2f   ", aguadomar.ph[i]);
            printf("\t\tU-235 %.2f %%", reator.uranio235);
            printf("\t\tRpm %.2f", turbina.rpm[i]);
            printf("\t\tHLW %.2f %%\n", rejeitos.HLW);
            printf("NaCl %.2f %%", aguadomar.NaCl);
            printf("\t\tU-238 %.2f %%", reator.uranio238);
            printf("\t\tEner %.2f V", turbina.voltagem[i]);
            printf("\t\tILW %.2f %%\n", rejeitos.ILW);
            printf("CaSO4 %.2f %%", aguadomar.CaSO4);
            printf("\t\tEner %.2f V", reator.energia[i]);
            printf("\t\tAprov %.2f V", turbina.reaproveitamento[i]);
            printf("\t\tLLW %.2f %%\n", rejeitos.LLW);
            printf("MgSO4 %.2f %%", aguadomar.MgSO4);
            printf("\t\tTemp %.2f C\n", reator.temperatura[i]);
            printf("MgCl2 %.2f %%\n", aguadomar.MgCl2);
            printf("Lpm %.2f l\n", aguadomar.lpm[i]);

            regras(i);

            aux++;
            if (aux > 22)
                break;
            if (i > 3)
                i = 0;
            system("cls");
        }

        do {
            printf("\n1 - Configuracoes\n"
                   "2 - Menu\n"
                   "3 - Sair\n"
            );
            scanf("%d", &opcao);
            if (opcao > 3 || opcao < 0)
                puts("Opcao invalida");
        } while (opcao > 3 || opcao < 0);

        switch (opcao) {
            case 1:
                Configuracoes();
                break;
            case 2:
                return 0;
            case 3:
                exit(0);
            default:
                puts("Valor invalido\n");
        }
    }
}

int Configuracoes() {
    int opcao = 0;
    do {
        printf("1 - Resfriamento"
               "\n"
               "2 - Reator"
               "\n"
               "3 - Zerar"
               "\n"
               "4 - Voltar"
               "\n"
        );
        scanf("%d", &opcao);
        if (opcao > 4 || opcao < 0)
            puts("Opcao invalida");
    } while (opcao > 4 || opcao < 0);

    switch (opcao) {
        case 1:
            Resfriamento();
            break;
        case 2:
            Combustivel();
            break;
        case 3:
            for (int i = 0; i < 3; ++i) {
                reator.energia[i] = 0;
                reator.temperatura[i] = 0;
                turbina.rpm[i] = 0;
                turbina.reaproveitamento[i] = 0;
                turbina.voltagem[i] = 0;
                aguadomar.ph[i] = 0;
                aguadomar.lpm[i] = 0;
            }
            aguadomar.MgCl2 = 0;
            aguadomar.CaSO4 = 0;
            aguadomar.MgSO4 = 0;
            aguadomar.NaCl = 0;
            reator.uranio235 = 0;
            reator.uranio238 = 0;
            rejeitos.HLW = 0;
            rejeitos.ILW = 0;
            rejeitos.LLW = 0;
        case 4:
            return 0;
        default:
            puts("Valor invalido\n");
    }

    return 0;
}