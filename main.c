#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void exibir_menu(void) {
    printf("================================\n");
    printf("    Calculadora Simples\n");
    printf("================================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
}

/* Lê uma opção inteira entre 1 e 5; repete até ser válida. */
int ler_opcao(void) {
    char buf[TAM];
    char *fim;
    long v;

    while (1) {
        exibir_menu();
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            return 5; /* fim da entrada: sair */
        }
        v = strtol(buf, &fim, 10);
        while (*fim == ' ' || *fim == '\t') fim++;
        if (fim != buf && (*fim == '\n' || *fim == '\0') && v >= 1 && v <= 5) {
            return (int)v;
        }
        printf("Opção inválida. Por favor, digite um número inteiro entre 1 e 5.\n\n");
    }
}

/* Lê um número (inteiro ou decimal); repete até ser válido. */
double ler_numero(const char *mensagem) {
    char buf[TAM];
    char *fim;
    double v;

    while (1) {
        printf("%s", mensagem);
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            exit(0);
        }
        v = strtod(buf, &fim);
        while (*fim == ' ' || *fim == '\t') fim++;
        if (fim != buf && (*fim == '\n' || *fim == '\0')) {
            return v;
        }
        printf("Entrada inválida. Digite um número válido.\n");
    }
}

/* Pergunta s/n; repete até resposta válida. Retorna 1 para 's', 0 para 'n'. */
int deseja_continuar(void) {
    char buf[TAM];
    char c;

    while (1) {
        printf("Deseja realizar outra operação? (s/n): ");
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            return 0;
        }
        if (sscanf(buf, " %c", &c) == 1) {
            char resto = '\0';
            /* garante que só há um caractere na resposta */
            char *p = strchr(buf, c) + 1;
            while (*p == ' ' || *p == '\t') p++;
            resto = *p;
            if (resto == '\n' || resto == '\0') {
                c = (char)tolower((unsigned char)c);
                if (c == 's') return 1;
                if (c == 'n') return 0;
            }
        }
        printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
    }
}

int main(void) {
    int opcao;
    double a, b, resultado;
    char operador;

    do {
        opcao = ler_opcao();

        if (opcao == 5) {
            break;
        }

        a = ler_numero("Digite o primeiro número: ");
        b = ler_numero("Digite o segundo número: ");

        switch (opcao) {
            case 1: operador = '+'; resultado = a + b; break;
            case 2: operador = '-'; resultado = a - b; break;
            case 3: operador = '*'; resultado = a * b; break;
            default: operador = '/'; resultado = 0; break;
        }

        if (opcao == 4 && b == 0) {
            printf("Erro: Divisão por zero não é permitida.\n");
        } else {
            if (opcao == 4) {
                resultado = a / b;
            }
            printf("Resultado: %g %c %g = %g\n", a, operador, b, resultado);
        }

        printf("\n");
    } while (deseja_continuar());

    printf("Obrigado por usar a calculadora! Até a próxima.\n");
    return 0;
}
