typedef struct resfriamento{
    float
    ph[3],
    NaCl, // Cloreto de s�dio
    CaSO4, // Sulfato de C�lcio
    MgSO4, // Sulfato de Magn�sio
    MgCl2, // Cloreto de Magn�sio
    lpm[3]; // Litros por minuto
}varresfriamento;
// O Cloreto de s�dio equivale a 80 % e o restante � relativo a 20%.