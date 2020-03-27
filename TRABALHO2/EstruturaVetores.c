#include <stdio.h>
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

//EstruturaPrincipal vetorPrincipal[TAM];

void dobrar(int *x){

    *x = *x * 2;


}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){

  int retorno = 0;

  if(posicao <= 0 || posicao >= 11){
    retorno = POSICAO_INVALIDA;
  }else if(vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria != NULL){
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  }else if(tamanho < 1){
    retorno = TAMANHO_INVALIDO;
  }else{
     vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria = (int *)malloc (tamanho * sizeof (int));

     if(vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria == NULL){
       retorno = SEM_ESPACO_DE_MEMORIA;
     }else{
       vetorPrincipal[posicao - 1].MaxElementos = tamanho;
       retorno = SUCESSO;
     }
  }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int ExisteEstruturaAuxiliar = existeEstruturaAuxiliar(posicao);
    int temEspaco = 0;
    int posicaoValida = ehPosicaoValida(posicao);

    if (!posicaoValida)
        retorno = POSICAO_INVALIDA;
    else{
        if (ExisteEstruturaAuxiliar){
          if(vetorPrincipal[posicao - 1].QuantidadeElementos < vetorPrincipal[posicao - 1].MaxElementos ){
            temEspaco = 1;
          }
          if (temEspaco){
              vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[vetorPrincipal[posicao - 1].QuantidadeElementos] = valor;
              vetorPrincipal[posicao - 1].QuantidadeElementos ++;
              retorno = SUCESSO;
          }else{
              retorno = SEM_ESPACO;
          }
        }else{
          retorno = SEM_ESTRUTURA_AUXILIAR; // CHAMAR A FUNCAO DE CRIAR A ESTRUTURA AUXILIAR E DPS INSERIR
        }
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
  int retorno = 0;
  int ExisteEstruturaAuxiliar = existeEstruturaAuxiliar(posicao);
  int posicaoValida = ehPosicaoValida(posicao);

  if (!posicaoValida)
    retorno = POSICAO_INVALIDA;
  else{
        if (ExisteEstruturaAuxiliar){
          if(vetorPrincipal[posicao - 1].QuantidadeElementos == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
          }
          else{
            vetorPrincipal[posicao - 1].QuantidadeElementos--;
            retorno = SUCESSO;
          }
        }
        else{
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }
  }

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

  int retorno = 0;
  int posicaoNumero = localizar_Numero(valor, posicao);
  int ExisteEstruturaAuxiliar = existeEstruturaAuxiliar(posicao);
  int posicaoValida = ehPosicaoValida(posicao);


  if (!posicaoValida)
    retorno = POSICAO_INVALIDA;
  else{
        if (ExisteEstruturaAuxiliar){
          if(vetorPrincipal[posicao - 1].QuantidadeElementos == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
          }
          else{
            if(posicaoNumero == -1){
              retorno = NUMERO_INEXISTENTE;
            }
            else{
              for (int i = 0; i < vetorPrincipal[posicao - 1].QuantidadeElementos; i++){
                  vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i]= vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i+1];
              }
              vetorPrincipal[posicao - 1].QuantidadeElementos--;
              retorno = SUCESSO;
            }
          }
        }
        else{
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }

        return retorno;
  }

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;


    return retorno;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;


    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;


    return retorno;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
/*
No* montarListaEncadeadaComCabecote(){

  No* inicio = (No*) malloc(sizeof(No));
	inicio->prox = NULL;

  int QuantidadeElementosTotais;
  int vetorAux[];

  getDadosDeTodasEstruturasAuxiliares(vetorAux);

  for (int i = 0; i < QuantidadeElementosTotais; i++)
		inserirNoFinal(&inicio, vetorAux[i]);

  if (QuantidadeElementosTotais == 0)
    return NULL;

}
*/

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
/*
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
  celula* tmp = inicio->prox;
  int i = 0;

	while(tmp != NULL){
		vetor[i] tmp->conteudo);
		tmp = tmp->prox;
    i++;
	}

}
*/
/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No* inicio){


}



// ####################################################################################################
//   FUNÇÕES AUXILIARES

int ehPosicaoValida(int posicao){
    int retorno = 1;
    if (posicao < 1 || posicao > 10){
        retorno = 0;
    }

    return retorno;
}

int existeEstruturaAuxiliar(int posicao){
    int retorno = 0;
    if (vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria != NULL){
        retorno = 1;
    }

    return retorno;
}

int localizar_Numero(int valor, int posicao){

  for(int i = 0; i > vetorPrincipal[posicao - 1].QuantidadeElementos; i++ ){
    if(valor == vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i])
      return i;
  }
  return -1;
}

int inserirNoFinal(No **inicio, int val){
    No *novo;
    No *atual;

    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }
    novo->conteudo = val;
    novo->prox = NULL;

    if(*inicio == NULL)
        *inicio = novo;
    else{
        atual = *inicio;

        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
    }
		return 1;
}

void liberarLista(No* inicio){

	No* atual = inicio;
	No* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/

void inicializar(){

  for(int i = 0; i < TAM; i++) {
      vetorPrincipal[i].PonteiroEstruturaSecundaria = NULL;
      vetorPrincipal[i].QuantidadeElementos = 0;
       vetorPrincipal[i].MaxElementos = 0;
  }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar(){


}
