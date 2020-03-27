#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20
#define DATA_VALIDA 1
#define DATA_INVALIDA 2
#define ANOBISSEXTO 5
#define NUMERO_INVALIDO 6

int validar_data(char data[]);
int valida_numeros(int iDia, int iMes, int iAno);
int verifica_ano_bisexto(int iAno);
int verifica_numero(char CARACTER);
void opcao_validacao_data();
int ConverteDia(char DATA[], int iCont[]);
int ConverteMes(char DATA[], int iCont[]);
int ConverteAno(char DATA[], int iCont[]);
void CalculaDiferencaEntreDatas(int diaI, int mesI, int anoI, int diaF, int mesF, int anoF);
int ContaDiasDaData( int Dia, int Mes, int Ano);
int ContaDiasDaData( int Dia, int Mes, int Ano);
int ContaAnoBissexto(int anoI, int anoF);

int main(){
    
    //opcao_validacao_data();
    
    char data_inicial[TAM];
    char data_final[TAM];
    int diaInicial;
    int mesInicial;
    int anoInicial;
    int diaFinal;
    int mesFinal;
    int anoFinal;
    int iCont[1];
    
    strcpy(data_inicial, "29/02/2016");
    diaInicial= ConverteDia(data_inicial, iCont);
    mesInicial= ConverteMes(data_inicial, iCont);
    anoInicial= ConverteAno(data_inicial, iCont);
    
    strcpy(data_final, "28/02/2017");
    diaFinal= ConverteDia(data_final, iCont);
    mesFinal= ConverteMes(data_final, iCont);
    anoFinal= ConverteAno(data_final, iCont);
    
    CalculaDiferencaEntreDatas(diaInicial, mesInicial, anoInicial, diaFinal, mesFinal, anoFinal);
    
    return 0;
}


void opcao_validacao_data()
{
    char data[TAM];
    int validacao;
    
    strcpy(data, "29/02/2012");
    
    validacao = validar_data(data);
    
    if(validacao == 1)
        printf("#DATA VALIDA#\n");
    else if(validacao == 2)
        printf("#DATA INVALIDA#\n");
}

int validar_data(char data[])
{
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
            return DATA_INVALIDA;
    }
    sDia[iCont] = '\0';
    
    for (jCont = 0; sDia[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sDia[jCont]);
        if(verificacao == NUMERO_INVALIDO)
            return DATA_INVALIDA;
    }
    
    if (strlen(sDia) == 0)
        return DATA_INVALIDA;
 
    iDia = atoi(sDia); 
 
    // CONVERTE MES*****************************************************************************
    for (iCont = iCont+1, jCont=0; data[iCont] != '/'; iCont++, jCont++){
        sMes[jCont] = data[iCont];
        if(jCont>=3)
            return DATA_INVALIDA;
    }
    sMes[jCont] = '\0';
    
    for (jCont = 0; sMes[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sMes[jCont]);
            if(verificacao == NUMERO_INVALIDO)
                return DATA_INVALIDA;
    }
    
    if (strlen(sMes) == 0)
        return DATA_INVALIDA;
    
    iMes = atoi(sMes); 
  
    // CONVERTE ANO****************************************************************************
    
    for (iCont = iCont+1, jCont=0; data[iCont] != '\0' ; iCont++, jCont++){
        sAno[jCont] = data[iCont];
    }
    sAno[jCont] = '\0';
    
    for (jCont = 0; sAno[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sAno[jCont]);
            if(verificacao == NUMERO_INVALIDO)
                return DATA_INVALIDA;
        }
        
    if (strlen(sAno) == 0)
        return DATA_INVALIDA;
    
    iAno = atoi(sAno); 
 
    // *****************************************************************************************
    retorno= valida_numeros(iDia, iMes, iAno);
    
    return retorno;
}

int valida_numeros(int iDia, int iMes, int iAno)
{
    int bissexto;
    
    bissexto= verifica_ano_bisexto(iAno);
    
    if (iDia < 1 || iDia > 31)
        return DATA_INVALIDA;
    
    else if (iDia >= 31 && (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11 ))
        return DATA_INVALIDA;
    
    else if (iMes < 1 || iMes > 12)
        return DATA_INVALIDA;
    
    else if(iDia> 29 && iMes== 2 && bissexto== 5)
        return DATA_INVALIDA;
    
    else if(iDia> 28 && iMes== 2 && bissexto== 0)
        return DATA_INVALIDA;
    
    else if (iAno <= 0)
        return DATA_INVALIDA;
    
  return DATA_VALIDA;  
}

int verifica_ano_bisexto(int iAno)
{
    if(((iAno%4)==0) && ((iAno%100)!=0) && ((iAno%400)!=0))
        return ANOBISSEXTO;
    return 0;
}

int verifica_numero(char CARACTER)
{
    if  (  CARACTER <'0' && CARACTER >'9' )
        return NUMERO_INVALIDO;
    
    return 0;
}

void CalculaDiferencaEntreDatas(int diaI, int mesI, int anoI, int diaF, int mesF, int anoF)
{
    int DiasDataInicial=0;
    int DiasDataFinal=0;
    int Diferenca=0;
    int quantidade_bi;
    int anos, meses, dias;
   
    DiasDataInicial= ContaDiasDaData(diaI, mesI, anoI);
    DiasDataFinal= ContaDiasDaData(diaF, mesF, anoF);
    quantidade_bi= ContaAnoBissexto(anoI, anoF);
    int bisextoinicial= verifica_ano_bisexto(anoI);
    int bisextofinal = verifica_ano_bisexto(anoF);
    
    Diferenca= (DiasDataFinal - DiasDataInicial) ;//+ quantidade_bi;
    
    printf("ANOS: %d\n", anos= (Diferenca/365));
    if((mesI != 4 && mesI != 6 && mesI != 9 && mesI != 11 && mesF != 2) && ((Diferenca%365)/30) == 1) {
        printf("MESES: %d\n", meses=0);
        printf("DIAS: %d\n", dias=(Diferenca%365));
    }
    else if(bisextofinal== ANOBISSEXTO){
        printf("MESES: %d\n", meses =(Diferenca%365)/30);
        printf("DIAS: %d\n", dias=(Diferenca%365)%30-1);
    }
    else{
        printf("MESES: %d\n", meses =(Diferenca%365)/30);
        printf("DIAS: %d\n", dias=(Diferenca%365)%30);
    }
    
}

int ContaDiasDaData( int Dia, int Mes, int Ano)
{
    
    int desc;
    int totalMes;
    int verificaAno;
    int ContMes;
    int DiasData=0;
    
    verificaAno= verifica_ano_bisexto(Ano);
    
    DiasData=  Ano*365;
    
    if (verificaAno == ANOBISSEXTO && Mes>2){
        desc=1;
    }
    if (verificaAno == 0 && Mes>2){
        desc=2;
    }
    else {
        desc=0;
    }
    
    ContMes=1;
    totalMes=0;
    while (ContMes < Mes){
        if ( (ContMes%2==0 && ContMes < 8) || (ContMes%2!=0 && ContMes >= 8) )
            totalMes+= 30;
        if ( (ContMes%2!=0 && ContMes<8) || (ContMes%2==0 && ContMes>=8) )
            totalMes+= 31;
        ContMes++;
    }
    
    
	DiasData += totalMes + Dia - desc;
    
    return DiasData;
}

int ContaAnoBissexto(int anoI, int anoF)
{
    int i;
    int verificador;
    int Cont;
    
    Cont=0;
    for(i=anoI; i < anoF; i++){
        verificador= verifica_ano_bisexto(i);
        if(verificador == ANOBISSEXTO)
            Cont++;
    }
    return Cont;
} 

int ConverteDia(char DATA[], int iCont[])
{
    char sDia[3];
    int iDia;
    
    for (iCont[0] = 0; DATA[iCont[0]] != '/'; iCont[0]++){
        sDia[iCont[0]] = DATA[iCont[0]];
    }
    sDia[iCont[0]] = '\0';
 
    iDia = atoi(sDia); 
    
    return iDia;
}

int ConverteMes(char DATA[], int iCont[])
{
    char sMes[3];
    int iMes;
    int jCont;
    
    for (iCont[0] = iCont[0]+1, jCont=0; DATA[iCont[0]] != '/'; iCont[0]++, jCont++){
        sMes[jCont] = DATA[iCont[0]];
    }
    sMes[jCont] = '\0';
    
    iMes = atoi(sMes); 
}

int ConverteAno(char DATA[], int iCont[])
{
    char sAno[5];
    int iAno;
    int jCont;
    
    for (iCont[0] = iCont[0]+1, jCont=0; DATA[iCont[0]] != '\0' ; iCont[0]++, jCont++){
        sAno[jCont] = DATA[iCont[0]];
    }
    sAno[jCont] = '\0';
    
    iAno = atoi(sAno); 
}
