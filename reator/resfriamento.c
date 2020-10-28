typedef struct resfriamento{
    float
    ph[3],
    NaCl, // Cloreto de sódio
    CaSO4, // Sulfato de Cálcio
    MgSO4, // Sulfato de Magnésio
    MgCl2, // Cloreto de Magnésio
    lpm[3]; // Litros por minuto
}varresfriamento;
// O Cloreto de sódio equivale a 80 % e o restante é relativo a 20%.