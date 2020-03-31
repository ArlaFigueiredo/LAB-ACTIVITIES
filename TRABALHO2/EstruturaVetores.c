#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "EstruturaVetores.h"

void dobrar(int *x){

    *x = *x * 2;
}

int criarEstruturaAuxiliar(int tamanho, int posicao){

  int retorno = Validacoes(posicao, tamanho, 1);

  retorno == SUCESSO ? (retorno = Create(posicao, tamanho)) : (retorno = retorno);
  
  return retorno;
}


int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = Validacoes(posicao, 0, 2);
    retorno == SUCESSO ? (retorno = Insert(posicao, valor)) : (retorno = retorno);
    
    return retorno;
}


int excluirNumeroDoFinaldaEstrutura(int posicao){
  
  int retorno = Validacoes(posicao, 0, 3);
  retorno == SUCESSO ? (retorno = Delete(posicao)) : (retorno = retorno);

  return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

  int retorno = Validacoes(posicao, 0, 3);
  retorno == SUCESSO ? (retorno = DeleteInPosition(posicao, valor)) : (retorno = retorno);

  return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

  int retorno = Validacoes(posicao, 0, 4);
  retorno == SUCESSO ? (retorno = InsertVetor(posicao, vetorAux)) : (retorno = retorno);
  
  return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

  int retorno = Validacoes(posicao, 0, 4);
  retorno == SUCESSO ? (retorno = InsertVetorOrdenado(posicao, vetorAux)) : (retorno = retorno);
  
  return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

  int retorno = 0;
  int contadorVazio = 0;
  int jCont= 0;

  for(int kCont = 0; kCont < TAM; kCont++){
    if (ExisteEstruturaAuxiliar(kCont+1) && vetorPrincipal[kCont].QuantidadeElementos != 0){
      for(int iCont = 0; iCont < vetorPrincipal[kCont].QuantidadeElementos; iCont++ ){
        vetorAux[jCont] = vetorPrincipal[kCont].PonteiroEstruturaSecundaria[iCont];
        jCont++;
      }
    }
    else{
      contadorVazio++;
    }
  }
  contadorVazio != 10 ? (retorno = SUCESSO) : (retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    
  return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

  int retorno = 0;
  int contadorVazio = 0;
  int jCont= 0;

  for(int k = 0; k < TAM; k++){
    if (existeEstruturaAuxiliar(k+1) && vetorPrincipal[k].QuantidadeElementos != 0){
      for(int i = 0; i < vetorPrincipal[k].QuantidadeElementos; i++ ){
        vetorAux[jCont] = vetorPrincipal[k].PonteiroEstruturaSecundaria[i];
        jCont++;
      }
    }
    else{
      contadorVazio++;
    }
  }
    contadorVazio != 10 ? (retorno = SUCESSO) : (retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    
    if(retorno == SUCESSO){Ordenar(vetorAux, jCont)}; 

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

int ValidacaoPosicao(int posicao){
    
  int retorno;
  (posicao < 1 || posicao > 10) ? (retorno = 0) : (retorno = 1);
    
  return retorno;
}

int ExisteEstruturaAuxiliar(int posicao){
    
  int retorno = 0;
  (vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria != NULL) ? (retorno = 1) : (retorno = 0);

  return retorno;
}

int ValidacaoCheio(int posicao){
    
  int retorno = 0;
  (vetorPrincipal[posicao - 1].QuantidadeElementos == vetorPrincipal[posicao - 1].MaxElementos) ? (retorno = 1) : (retorno = 0);

  return retorno;
}

int ValidacaoVazio(int posicao){
    
  int retorno = 0;
  (vetorPrincipal[posicao - 1].QuantidadeElementos == 0) ? (retorno = 1) : (retorno = 0);

  return retorno;
}

int ValidacaoTamanho(int tamanho){
  
  int retorno;
  (tamanho < 1) ? (retorno = 0) : (retorno = 1);
  
  return retorno;

}

int localizar_Numero(int valor, int posicao){

  for(int i = 0; i < vetorPrincipal[posicao - 1].QuantidadeElementos; i++ ){
    if(valor == vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i])
      return i;
  }
  return -1;
}

void Ordenar(int vetorAux[], int tamanho){
  int i,j,aux;
  for(i = 0; i < tamanho; i++){
    for(j = i+1; j < tamanho; j++){
      if(vetorAux[i] > vetorAux[j]){
        aux = vetorAux[i];
        vetorAux[i] = vetorAux[j];
        vetorAux[j] = aux;
      }
    }
  }
}

// ####################################################################################################

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

//#################################################################
//                          METODOS PRIVADOS
//#################################################################

int Validacoes(int parametroUm, int parametroDois, int operacao){
  
  switch(operacao){
    case 1:{     // CRIACAO
      if(!ValidacaoPosicao(parametroUm)){
        return POSICAO_INVALIDA;
      }
      else if(ExisteEstruturaAuxiliar(parametroUm)){
        return JA_TEM_ESTRUTURA_AUXILIAR;
      }
      else if(!ValidacaoTamanho(parametroDois)){
        return TAMANHO_INVALIDO;
      }
      else
        return SUCESSO;
    }
    case 2:{     //INSERCAO
      if(!ValidacaoPosicao(parametroUm)){
        return POSICAO_INVALIDA;
      }
      else if(!ExisteEstruturaAuxiliar(parametroUm)){
        return SEM_ESTRUTURA_AUXILIAR;
      }
      else if(ValidacaoCheio(parametroUm)){
        return SEM_ESPACO;
      }
      else
        return SUCESSO;
    }
    case 3:{     //EXCLUSAO
      if(!ValidacaoPosicao(parametroUm)){
        return POSICAO_INVALIDA;
      }
      else if(!ExisteEstruturaAuxiliar(parametroUm)){
        return SEM_ESTRUTURA_AUXILIAR;
      }
      else if(ValidacaoVazio(parametroUm)){
        return ESTRUTURA_AUXILIAR_VAZIA;
      }
      else
        return SUCESSO;
    }
     case 4:{     //LISTAGEM
      if(!ValidacaoPosicao(parametroUm)){
        return POSICAO_INVALIDA;
      }
      else if(!ExisteEstruturaAuxiliar(parametroUm)){
        return SEM_ESTRUTURA_AUXILIAR;
      }
      else
        return SUCESSO;
    }
  }
  
  return 0;
}

int Create(int posicao, int tamanho){

  int retorno = 0;

  vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria = (int *)malloc (tamanho * sizeof (int));
  if(vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria == NULL){
    retorno = SEM_ESPACO_DE_MEMORIA;
  }
  else{
    vetorPrincipal[posicao - 1].MaxElementos = tamanho;
    retorno = SUCESSO;
  }
  return retorno;
}

int Insert(int posicao, int valor){
   
  vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[vetorPrincipal[posicao - 1].QuantidadeElementos] = valor;
  vetorPrincipal[posicao - 1].QuantidadeElementos ++;
      
  return SUCESSO;
}

int Delete(posicao){

   vetorPrincipal[posicao - 1].QuantidadeElementos--;

   return SUCESSO;
}

int DeleteInPosition(int posicao, int valor){

  int posicaoNumero = localizar_Numero(int valor, int posicao);

  if(posicaoNumero == -1)
    return NUMERO_INEXISTENTE;
  
  for(int i = localizar_Numero(int valor, int posicao); i < vetorPrincipal[posicao - 1].QuantidadeElementos; i++){
    vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i]= vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i+1];
  }
  vetorPrincipal[posicao - 1].QuantidadeElementos--;
  
  return SUCESSO;
}

int InsertVetor(int posicao, int vetorAux[]){

  for(int i = 0; i < vetorPrincipal[posicao - 1].QuantidadeElementos; i++ )
    vetorAux[i] = vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i];
    
    return SUCESSO;
}

int InsertVetorOrdenado(int posicao, int vetorAux[]){

  for(int i = 0; i < vetorPrincipal[posicao - 1].QuantidadeElementos; i++ ){
    vetorAux[i] = vetorPrincipal[posicao - 1].PonteiroEstruturaSecundaria[i];
  }
  Ordenar(vetorAux, vetorPrincipal[posicao - 1].QuantidadeElementos); 

  return SUCESSO;
}
