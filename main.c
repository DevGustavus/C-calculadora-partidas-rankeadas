#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCAO CALCULO DE SALDO
int saldoRanqueada(int vitorias, int derrotas){
    return vitorias - derrotas;
}

//FUNCAO DE FILTRAGEM PARA CLASSES
char* filtrarClasses(int saldo){
    //CALCULO DA CLASSE DO HEROI
    if (saldo <= 10) {
        return "Ferro";
    }
    else if (saldo >= 11 && saldo <= 20) {
        return "Bronze";
    }
    else if (saldo >= 21 && saldo <= 50) {
        return "Prata";
    }
    else if (saldo >= 51 && saldo <= 80) {
        return "Ouro";
    }
    else if (saldo >= 81 && saldo <= 90) {
        return "Diamante";
    }
    else if (saldo >= 91 && saldo <= 100) {
        return "Lendario";
    }
    else if (saldo >= 101) {
        return "Imortal";
    }

    return "FAILURE";
}

int main(void){

    //CRIAR VARS
    char nome[35];
    char classe[35];
    int idade;
    int opc;
    int vitorias;
    int derrotas;
    int saldo;

    //INICIALIZAR VARS
    nome[0] = '\0';
    classe[0] = '\0';
    idade = 0;
    opc = 0;
    vitorias = 0;
    derrotas = 0;
    saldo = 0;

    do{
        //LIMPA TELA
        system("cls");

        //CHAMAR FUNÇÕES DE CALCULOS
        saldo = saldoRanqueada(vitorias, derrotas);
        strcpy(classe, filtrarClasses(saldo));

        //HUD
        printf("======= STATUS DO HEROI =======");
        printf("\nNome...........: %s", nome);
        printf("\nIdade.........: %d", idade);
        printf("\nVitorias...: %d", vitorias);
        printf("\nDerrotas...: %d", derrotas);
        printf("\nSaldo.........: %d", saldo);
        printf("\nClasse.......: %s", classe);

        printf("\n\nO Heroi tem de saldo de %d esta no nivel de %s", saldo, classe);

        printf("\n\n=============== MENU ===============");
        printf("\n1- Inserir nome do heroi..........");
        printf("\n2- Inserir idade do heroi.........");
        printf("\n3- Atribuir vitoria ao heroi......");
        printf("\n4- Atribuir vitoria ao heroi......");
        printf("\n0- Sair do programa...............");

        printf("\nEscolha uma opcao: ");
        fflush(stdin);
        scanf("%d", &opc);

        if(opc != 0){
            switch (opc){
                case 1:
                    do{
                        printf("\nQual o nome do seu heroi? ");
                        fflush(stdin);
                        gets(nome);

                        if (nome[0] == '\0') {
                            printf("\nPor favor, insira um nome valido!\n");
                        }
                    }while(nome[0] == '\0');
                break;

                case 2:
                    do {
                        printf("\nQual a idade do seu heroi? ");
                        fflush(stdin);
                        scanf("%d", &idade);
                        if (idade <= 0) {
                            printf("\nPor favor, insira uma idade valida!\n");
                        }
                    }while(idade <= 0);
                break;

                case 3:
                    vitorias++;
                    printf("\nVitoria atribuida!\n");
                    system("pause");
                break;

                case 4:
                    derrotas++;
                    printf("\nDerrota atribuida!\n");
                    system("pause");
                break;

                case 0:
                    opc = 0;
                break;
                
                default:
                    printf("\nInsira uma opcao valida!\n");
                    system("pause");
                break;
            }
        }
    }while(opc != 0);

    printf("\n\n\nFIM DO PROGRAMA...");
    return 0;
}