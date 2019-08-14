#include <stdio.h>

void analise_lexica(char codigo[50], char tokens[7][20], char estruturas[5][1]){
    int i,j, k;

    //remover estruturas do codigo
    for(i=0; i<5; i++){
        for(j=0; j<50; j++){
            char estrutura  = estruturas[i][0];
            char simbolo = codigo[j];

            if(estrutura == simbolo){
                codigo[j] = ' ';
            }

        }
    }

    //quebrar o codigo em partes por espaços
    char temp[50][50];
    j = 0;
    k = 0;
    for(i=0; i<50; i++){
        if(codigo[i] != ' '){
            temp[j][k] = codigo[i];
            k++;
        }else{
            j++;
            k=0;
        }
    }

    //quantidade de partes
    int N = j;

    //verificar se estão na lista de tokens permitidos
    int sentinela;
    for(i=0; i<N; i++){
        for(j=0; j<7; j++){
            sentinela = 0;
            for(k=0; k<20; k++){
                if(temp[i][k]==tokens[j][k]){
                    sentinela = 1;
                }
            }
        }

        if(sentinela == 0){
            printf("ERRO: Token nao permitido!");
            break;
        }
    }

    printf("Codigo Analisado com sucesso!");
}

int main(){
    char codigo[50] = {"int main(){ a=1; b=2; return 0; }"};
    char tokens[7][20] = {{"int"}, {"main"}, {"return"}, {"if"}, {"for"}, {"a"}, {"b"}};
    char estruturas[5][1] = {";", "(", ")", "{", "}"};

    analise_lexica(codigo, tokens, estruturas);

    return 0;
}
