#include<stdio.h>
#include<math.h>

int main(){
	
	int mes;
	float montante;
	float taxa;
	
	printf("Digite os meses: ");
	scanf("%d", &mes);
	
	printf("Digite o montante: ");
	scanf("%f", &montante);
	
	printf("Digite a taxa: ");
	scanf("%f", &taxa);
	
	for (int i = 1; i <= mes; ++i) {
        // Calculo do montante para o mes atual
        float resultado = montante * pow(1 + taxa, i);

        // Exibicao do resultado
        printf("Montante ao fim do mes %d: %.2f\n", i, resultado);
    }
    
    return 0;
	
}
