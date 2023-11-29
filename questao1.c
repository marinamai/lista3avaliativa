#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para converter algarismos romanos em valores decimais
int romanToDecimal(char *roman) {
    int values[7] = {1, 5, 10, 50, 100, 500, 1000};
    char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int total = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        char current = toupper(roman[i]);
        int value = 0;

        for (int j = 0; j < 7; j++) {
            if (symbols[j] == current) {
                value = values[j];
                break;
            }
        }

        if (i > 0) {
            char prev = toupper(roman[i - 1]);
            int prevValue = 0;

            for (int j = 0; j < 7; j++) {
                if (symbols[j] == prev) {
                    prevValue = values[j];
                    break;
                }
            }

            if (prevValue < value) {
                total += value - prevValue;
                i--;
            } else {
                total += value;
            }
        } else {
            total += value;
        }
    }

    return total;
}

// Função para converter um número decimal para sua representação em uma base específica
void convertBase(int decimal, int base) {
    char result[50];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % base;
        char digit;

        if (remainder < 10) {
            digit = remainder + '0';
        } else {
            digit = remainder + 55; // Para hexadecimais (A-F)
        }

        result[index++] = digit;
        decimal /= base;
    }

    // Armazenando a representação em uma string reversa
    char output[50];
    int outputIndex = 0;
    for (int i = index - 1; i >= 0; i--) {
        output[outputIndex++] = result[i];
    }
    output[outputIndex] = '\0';

    // Encontrando o índice do primeiro caractere diferente de '0'
    int nonZeroIndex = 0;
    while (output[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }

    // Imprimindo a saída ignorando os zeros à esquerda e convertendo a vogal para minúscula
    printf("na base %d: ", base);
    for (int i = nonZeroIndex; i < outputIndex; i++) {
        if (output[i] >= 'A' && output[i] <= 'F') {
            printf("%c", output[i] + 32); // Convertendo para minúscula
        } else {
            printf("%c", output[i]);
        }
    }
    printf("\n");
}

int main() {
    char romanNum[13]; // Definição do número romano como entrada
    scanf("%s", romanNum);

    // Verificando se todos os caracteres são maiúsculos
    for (int i = 0; i < strlen(romanNum); i++) {
        if (!isupper(romanNum[i])) {
            printf("A entrada deve conter apenas letras maiusculas.\n");
            return 1;
        }
    }

    int decimal = romanToDecimal(romanNum);

    printf("%s ", romanNum);
    convertBase(decimal, 2);
    printf("%s ", romanNum);
    printf("na base 10: %d\n", decimal);
    printf("%s ", romanNum);
    convertBase(decimal, 16);

    return 0;
}

