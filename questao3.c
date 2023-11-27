#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	char strDia[25];
	char strPlaca[10];
	int num;
	
	// pega os digitos da placa
	printf("Digite a placa: ");
	fgets(strPlaca, sizeof(strPlaca), stdin);
	// strcspn retira o caractere \n caso tenha algum presente
	strPlaca[strcspn(strPlaca, "\n")] = '\0';
	
	// pega os digitos do dia da semana
	printf("Digite o dia da semana: ");
	scanf("%s", strDia);
	
	if (strlen(strPlaca) >	0){
		//seleciona o ultimo caractere
		char ultimoChar = strPlaca[strlen(strPlaca) - 1];
		// atoi faz com que esse ultimoChar seja visto como um INT 
		num = atoi(&ultimoChar);
	}
	
	// strcmp compara se duas strings sao lexograficamente iguais, se forem, retorna 0
	// repete para cada dia da semana, para verificar qual foi o escolhido
	if (strcmp(strDia, "SEGUNDA-FEIRA") == 0) {
		// comparacoes para ver se esta de acordo, repetindo para cada if
        if (num == 0 || num == 1) {
            printf("Nao pode circular!");
        } else {
            printf("Pode circular!");
        }
    } else if (strcmp(strDia, "TERCA-FEIRA") == 0) {
		if (num == 2 || num == 3) {
            printf("Nao pode circular!");
        } else {
            printf("Pode circular!");
        }
    } else if (strcmp(strDia, "QUARTA-FEIRA") == 0) {
		if (num == 4 || num == 5) {
            printf("Nao pode circular!");
        } else {
            printf("Pode circular!");
        }
    } else if (strcmp(strDia, "QUINTA-FEIRA") == 0) {
		if (num == 6 || num == 7) {
            printf("Nao pode circular!");
        } else {
            printf("Pode circular!");
        }
    } else if (strcmp(strDia, "SEXTA-FEIRA") == 0) {
        if (num == 8|| num == 9) {
            printf("Nao pode circular!");
        } else {
            printf("Pode circular!");
        }
    } else if (strcmp(strDia, "SABADO") == 0 || strcmp(strDia, "DOMINGO") == 0) {
        printf("Pode circular! Sem proibicoes");
    // Caso de erro de digitacoes
    } else {
        printf("Dia da semana invalido!");
    }
	
	return 0;
	
}

