#include <stdio.h>
#include <math.h>

int main() {
    int tempo_meses;
    double aporte_mensal, taxa_juros;
    double montante = 0; // Inicializando a variável montante

    scanf("%d", &tempo_meses);
    scanf("%lf", &aporte_mensal);
    scanf("%lf", &taxa_juros);

    for (int i = 1; i <= tempo_meses; ++i) {
        //Calculo do montante para o mes atual
        montante += aporte_mensal;
        montante *= (1 + taxa_juros);
        //Exibicao do resultado
        printf("Montante ao fim do mes %d: R$ %.2f\n", i, montante);
    }

    return 0;
}
