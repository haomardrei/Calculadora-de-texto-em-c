# Calculadora Baseada em Texto em C

Calculadora que funciona inteiramente no terminal. O programa exibe um menu de opções, pede dois números, realiza a operação escolhida e mostra o resultado na hora.

## Funcionalidades

- Adição, subtração, multiplicação e divisão
- Aceita números inteiros e decimais
- Validação da opção do menu (inteiro entre 1 e 5, entradas não numéricas são rejeitadas)
- Tratamento de divisão por zero
- Pergunta se o usuário deseja realizar outra operação (`s`/`n`, maiúsculo ou minúsculo)
- Repete a pergunta até receber uma resposta válida

## Estrutura do projeto

```
.
├── main.c      # código-fonte principal
└── README.md
```

## Como compilar e executar

Requisito: um compilador C (por exemplo, `gcc`).

```bash
gcc main.c -o calculadora
./calculadora
```

No Windows (MinGW):

```bash
gcc main.c -o calculadora.exe
calculadora.exe
```

## Exemplo de uso

```
================================
    Calculadora Simples
================================
Selecione uma operação:
1. Adição
2. Subtração
3. Multiplicação
4. Divisão
5. Sair
Opção: 1
Digite o primeiro número: 5
Digite o segundo número: 3
Resultado: 5 + 3 = 8

Deseja realizar outra operação? (s/n): n
Obrigado por usar a calculadora! Até a próxima.
```

### Divisão por zero

```
Opção: 4
Digite o primeiro número: 10
Digite o segundo número: 0
Erro: Divisão por zero não é permitida.

Deseja realizar outra operação? (s/n):
```

### Entradas inválidas

```
Opção: abc
Opção inválida. Por favor, digite um número inteiro entre 1 e 5.

Deseja realizar outra operação? (s/n): talvez
Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.
```

## Como funciona

| Função | Responsabilidade |
|---|---|
| `exibir_menu()` | Imprime o menu inicial |
| `ler_opcao()` | Lê e valida a opção (1 a 5) |
| `ler_numero()` | Lê um número inteiro ou decimal, repetindo em caso de erro |
| `deseja_continuar()` | Lê `s`/`n` e repete até a resposta ser válida |
| `main()` | Loop principal: menu, cálculo, resultado e nova pergunta |

A leitura é feita com `fgets` seguido de `strtol`/`strtod`, o que evita problemas de buffer e permite detectar entradas não numéricas.
