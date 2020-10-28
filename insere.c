#include <stdio.h>
#include "reator/reator.c"
#include "reator/rejeitos.c"
#include "reator/resfriamento.c"
#include "reator/turbina.c"

varresfriamento aguadomar;
varrejeitos rejeitos;
varreator reator;
varturbina turbina;

int Combustivel() {
    float uranio,
    temperatura     = 0,
    rpm             = 0,
    voltagem        = 0,
    aux             = 0,
    rejeito         = 0;
    do {
        puts("Porcentagem de uranio235:");
        scanf("%f", &uranio);

        if (uranio > 100 || uranio < -100)
            puts("Valor maximo: 100, minimo: -100");
    } while (uranio > 100 || uranio < -100);

    reator.uranio235 = uranio;
    reator.uranio238 = 100 - uranio;

    for (int y = 0; ; y++) {
        if (aux == reator.uranio235)
            break;

        for (int i = 0; i < 3; ++i) {
            if (i == 0) {
                temperatura     = 1;
                rpm             = (float)1.5;
                voltagem        = (float)2;
            }
            if (i == 1) {
                temperatura     = 2;
                rpm             = (float)2.5;
                voltagem        = (float)3;
            }
            if (i == 2) {
                temperatura     = 3;
                rpm             = (float)3.5;
                voltagem        = (float)4;
                rejeitos.HLW = rejeito;
                rejeitos.ILW = rejeito / 2;
                rejeitos.LLW = rejeito / 3;
            }

            reator.temperatura[i] += temperatura * reator.uranio238;
            turbina.rpm[i] += rpm * reator.uranio238;
            turbina.voltagem[i] += voltagem * reator.uranio238;
            reator.energia[i] = turbina.voltagem[i];
            turbina.reaproveitamento[i] += (voltagem - 2) * reator.uranio238;
            rejeito = temperatura + reator.uranio238;
         }
        if (y == 3)
            y = 0;

        aux++;
    }
    return 0;
}

int Resfriamento() {
    float litros,
    lpm              = 0,
    temperatura      = 0,
    rpm              = 0;
    do {
        puts("Litros por segundo:");
        scanf("%f", &litros);
        if (litros > 100 || litros < -100)
            puts("Vazao maxima 100 l, minima -100 l");
    } while (litros > 100 || litros < -100);

    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            lpm         = 1;
            temperatura = 10;
            rpm         = (float) 2.5;
        }
        if (i == 1) {
            lpm         = 2;
            temperatura = 20;
            rpm         = (float) 3.5;
        }
        if (i == 2) {
            lpm         = 3;
            temperatura = 30;
            rpm         = (float) 4.5;
        }

        aguadomar.lpm[i] = litros;
        reator.temperatura[i] -= temperatura * litros;
        turbina.rpm[i] -= rpm * litros;
        turbina.voltagem[i] -= lpm * litros * 2;
        turbina.reaproveitamento[i] -= (lpm - 2) * litros;
        aguadomar.ph[0] = 6;
        aguadomar.ph[1] = (float)6.5;
        aguadomar.ph[2] = 7;
        aguadomar.NaCl = 25;
        aguadomar.CaSO4 = 25;
        aguadomar.MgSO4 = 25;
        aguadomar.MgCl2 = 25;
        rejeitos.HLW /= litros / (litros - (float)1.8);
        rejeitos.ILW /= litros / (litros - (float)1.5);
        rejeitos.LLW /= litros / (litros - (float)1.2);
    }
    return 0;
}