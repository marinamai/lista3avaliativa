#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[20];
    char diaSemana[25];

    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = '\0'; 

    fgets(diaSemana, sizeof(diaSemana), stdin);
    diaSemana[strcspn(diaSemana, "\n")] = '\0'; 

    int diaInvalido = (strcmp(diaSemana, "SEGUNDA-FEIRA") != 0 &&
                       strcmp(diaSemana, "TERCA-FEIRA") != 0 &&
                       strcmp(diaSemana, "QUARTA-FEIRA") != 0 &&
                       strcmp(diaSemana, "QUINTA-FEIRA") != 0 &&
                       strcmp(diaSemana, "SEXTA-FEIRA") != 0 &&
                       strcmp(diaSemana, "SABADO") != 0 &&
                       strcmp(diaSemana, "DOMINGO") != 0);

    int placaValida = 0;
    int placaAntiga = 0;
    int placaMercosul = 0;

    if ((strlen(placa) == 8 || strlen(placa) == 9) && (placa[3] == '-' || placa[3] == '\0') &&
        isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) {
        placaAntiga = 1;
        placaValida = 1;
    } else if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) &&
               isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])) {
        placaMercosul = 1;
        placaValida = 1;
    }

    if (!placaValida) {
        printf("Placa invalida\n");
        if (diaInvalido) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    int ultimoDigito;
    if (placaAntiga) {
        if (strlen(placa) == 8) {
            ultimoDigito = placa[7] - '0';
        } else {
            ultimoDigito = placa[8] - '0';
        }
    } else {
        ultimoDigito = placa[6] - '0';
    }

    if (diaInvalido) {
        printf("Dia da semana invalido\n");
    } else if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        if (strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) {
            if (ultimoDigito == 0 || ultimoDigito == 1) {
                printf("%s nao pode circular segunda-feira\n", placa);
            } else {
                printf("%s pode circular segunda-feira\n", placa);
            }
        } else if (strcmp(diaSemana, "TERCA-FEIRA") == 0) {
            if (ultimoDigito == 2 || ultimoDigito == 3) {
                printf("%s nao pode circular terca-feira\n", placa);
            } else {
                printf("%s pode circular terca-feira\n", placa);
            }
        } else if (strcmp(diaSemana, "QUARTA-FEIRA") == 0) {
            if (ultimoDigito == 4 || ultimoDigito == 5) {
                printf("%s nao pode circular quarta-feira\n", placa);
            } else {
                printf("%s pode circular quarta-feira\n", placa);
            }
        } else if (strcmp(diaSemana, "QUINTA-FEIRA") == 0) {
            if (ultimoDigito == 6 || ultimoDigito == 7) {
                printf("%s nao pode circular quinta-feira\n", placa);
            } else {
                printf("%s pode circular quinta-feira\n", placa);
            }
        } else if (strcmp(diaSemana, "SEXTA-FEIRA") == 0) {
            if (ultimoDigito == 8 || ultimoDigito == 9) {
                printf("%s nao pode circular sexta-feira\n", placa);
            } else {
                printf("%s pode circular sexta-feira\n", placa);
            }
        }
    }

    return 0;
}
