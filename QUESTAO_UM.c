#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# define TAM 20
#define ERRO_DIA 1
#define ERRO_MES 2
#define ERRO_FEVEREIRO 3
#define ERRO_ANO 4
#define ANOBISSEXTO 5
#define NUMERO_INVALIDO 6

int validar_data(char data[]);
int valida_numeros(int iDia, int iMes, int iAno);
int verifica_ano_bisexto(int iAno);
int verifica_numero(char CARACTER);
void menu();
void opcao_validacao_data();

int main(){
    
    int opcao;
    
    do{
        
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
            opcao_validacao_data();
            }break;
            default:{
                printf("## OPCAO INVALIDA ##\n");
            }
        }
    }while(opcao != 0);
    
    return 0;
}

void menu(){
    
    printf("  ************************************************************\n");
    printf("  *                                                          *\n");
    printf("  *                                                          *\n");
    printf("  *                ######  M E N U ######                    *\n");
    printf("  *                                                          *\n");
    printf("  *                                                          *\n");
    printf("  *  # (1)............................ VALIDAR UMA DATA      *\n");
    printf("  *  # (2)............................ VERIFICAR IDADE       *\n");
    printf("  *  # (0)............................ SAIR                  *\n");
    printf("  *                                                          *\n");
    printf("  *                                                          *\n");
    printf("  ************************************************************\n\n");
    
}

void opcao_validacao_data(){
    
    char data[TAM];
    int validacao;
    
    strcpy(data, "31/06/2018");
    
    validacao = validar_data(data);
    
    if(validacao == 1)
        printf("# DIA INVALIDO #\n");
    else if(validacao == 2)
        printf("# MES INVALIDO #\n");
    else if(validacao == 3)
        printf("O MES DE FEVEREIRO TEM ALGO DE ERRADO\n");
    else if(validacao == 4)
        printf("# ANO INVALIDO #\n");
    else
        printf("# DATA VALIDA #\n");
}



int validar_data(char data[]){
    

    int iDia;
    int iMes;
    int iAno;
    int retorno;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int iCont;
    int jCont;
    int verificacao;
    
    //CONVERTE DIA******************************************************************************
    for (iCont = 0; data[iCont] != '/'; iCont++){
        sDia[iCont] = data[iCont];
        if(iCont>=3)
            return ERRO_DIA;
    }
    sDia[iCont] = '\0';
    
    
    for (jCont = 0; sDia[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sDia[jCont]);
        if(verificacao == NUMERO_INVALIDO)
            return ERRO_DIA;
    }
    
    if (strlen(sDia) == 0)
        return ERRO_DIA;
    
    printf("%s\n", sDia);
    iDia = atoi(sDia); 
    printf("%d\n", iDia);
    
    // CONVERTE MES*****************************************************************************
    for (iCont = iCont+1, jCont=0; data[iCont] != '/'; iCont++, jCont++){
        sMes[jCont] = data[iCont];
        if(jCont>=3)
            return ERRO_MES;
    }
    sMes[jCont] = '\0';
    
    for (jCont = 0; sMes[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sMes[jCont]);
            if(verificacao == NUMERO_INVALIDO)
                return ERRO_MES;
    }
    
    if (strlen(sMes) == 0)
        return ERRO_MES;
    printf("%s\n", sMes);
    iMes = atoi(sMes); 
    printf("%d\n", iMes);
    
    // CONVERTE ANO****************************************************************************
    
    for (iCont = iCont+1, jCont=0; data[iCont] != '\0' ; iCont++, jCont++){
        sAno[jCont] = data[iCont];
    }
    sAno[jCont] = '\0';
    
    for (jCont = 0; sAno[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sAno[jCont]);
            if(verificacao == NUMERO_INVALIDO)
                return ERRO_ANO;
        }
        
    if (strlen(sAno) == 0)
        return ERRO_ANO;
    printf("%s\n", sAno);
    iAno = atoi(sAno); 
    printf("%d\n", iAno);
    
    // *****************************************************************************************
    
    retorno= valida_numeros(iDia, iMes, iAno);
    
    return retorno;
}

int valida_numeros(int iDia, int iMes, int iAno){
    
    int bissexto;
    
    bissexto= verifica_ano_bisexto(iAno);
    
    if (iDia < 1 || iDia > 31)
        return ERRO_DIA;
    
    if (iDia > 30 && (iMes == 4 && iMes ==6 && iMes ==9 && iMes ==11 ));
        return ERRO_DIA;
    
    if (iMes < 1 || iMes > 12)
        return ERRO_MES;
    
    if(iDia> 29 && iMes== 2 && bissexto== 5)
        return ERRO_FEVEREIRO;
    
    if(iDia> 28 && iMes== 2 && bissexto== 0)
        return ERRO_FEVEREIRO;
    
   if (iAno <= 0)
        return ERRO_ANO;
    
  return 0;  
}

int verifica_ano_bisexto(int iAno){
    
    if(((iAno%4)==0) && ((iAno%100)!=0) && ((iAno%400)!=0))
        return ANOBISSEXTO;
    return 0;
}

int verifica_numero(char CARACTER){
    
    if  (  CARACTER <'0' && CARACTER >'9' )
        return NUMERO_INVALIDO;
    
    return 0;
    
}
 
