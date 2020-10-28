#include <stdio.h>

int regras(int i) {
    int normal = 0, trip = 0;
    puts("\nStatus:");
    puts("-------------------");
    if (aguadomar.ph[i] > 8) {
        puts("ATENCAO!\nAltos niveis de pH da agua\n");
        normal = 1;
    }
    if (aguadomar.NaCl > 25 || aguadomar.MgSO4 > 25 || aguadomar.CaSO4 > 25 || aguadomar.MgCl2 > 25) {
        puts("ATENCAO!\nAltos niveis de substancias na agua\nResfriamento alterado\n");
        normal = 1;
    }
    if (turbina.rpm[i] > 1800) {
        puts("ATENCAO!\nTurbina instavel\nAltos niveis de rotacao\n");
        normal = 1;
    }
    if (turbina.rpm < 0) {
        puts("ATENCAO!\nTRIP: Rotacao em niveis anormais\n");
        normal = 1;
        trip = 1;
    }
    if (turbina.voltagem[i] > 2400) {
        puts("ATENCAO!\nTurbina instavel\nAltos niveis de voltagem\n");
        normal = 1;
    }
    if (turbina.voltagem[i] < 0) {
        puts("ATENCAO!\nTRIP: Voltagem em niveis anormais\n");
        normal = 1;
        trip = 1;
    }
    if (turbina.reaproveitamento[i] > turbina.voltagem[i]) {
        puts("ATENCAO!\nTRIP: Hambiente anormal\n");
        normal = 1;
        trip = 1;
    }
    if (reator.uranio235 > 10) {
        puts("ATENCAO!\nTRIP: Alto nivel de reacao\nRISCO DE EXPLOSAO\n");
        normal = 1;
        trip = 1;
    }
    if (reator.uranio235 < 0) {
        puts("ATENCAO!\nTRIP: Niveis anormais de reacao\n");
        normal = 1;
        trip = 1;
    }
    if (reator.temperatura[i] > 1500) {
        puts("ATENCAO!\nTRIP: Alto nivel de temperatura\nRISCO DE EXPLOSAO\n");
        normal = 1;
        trip = 1;
    }
    if (reator.temperatura[i] < 0) {
        puts("ATENCAO!\nTRIP: Niveis anormais de temperatura\n");
        normal = 1;
        trip = 1;
    }
    if (rejeitos.HLW > 80) {
        puts("ATENCAO!\nReator instavel\nAltos niveis de rejeitos de nivel alto\n");
        normal = 1;
    }
    if (rejeitos.ILW > 85) {
        puts("ATENCAO!\nReator instavel\nAltos niveis de rejeitos de nível intermediário\n");
        normal = 1;
    }
    if (rejeitos.LLW > 90) {
        puts("ATENCAO!\nReator instavel\nAltos niveis de rejeitos de nível baixo\n");
        normal = 1;
    }

    if (trip > 0)
        puts("Reator desligado risco de explosao");

    if (normal == 0 && aguadomar.lpm[i] != 0)
        puts("Reator em operacao ideal");

    if (aguadomar.lpm[i] == 0)
        puts("Reator desligado");
    puts("-------------------");

    return 0;
}
