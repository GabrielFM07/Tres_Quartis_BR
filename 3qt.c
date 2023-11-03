#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "3qt.h"

int menu(){
	int esc;
	
	printf(" ___________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 1-<Tr�s Quartis>\t\t 2-<M�dia Populacional ou Amostral> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 3-<M�dia Ponderada>\t\t     4-<Distribui��o de Frequ�ncia> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 5-<Vari�ncia e Desvio Padr�o>\t\t\t\t   6-<Sair> |\n");
	printf("|___________________________________________________________________|\n");
	printf("\nDigite qual fun��o do programa voc� deseja utilizar: ");
	scanf("%d",&esc);
	
	return esc;
}
int menuDF(){
	int esc;
	
	printf(" ________________________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("| 1-Amplitude de Classes, Ponto M�dio e Frequ�ncias de um conjunto desorganizado |\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("|     2- Frequ�ncia Absoluta, Relativa e Acumulada de um conjunto organizado     |\n");
	printf("|________________________________________________________________________________|\n");
	printf("\nO que deseja calcular? ");
	scanf("%d",&esc);
	
	return esc;
}
float* ORDP(float *vetor,float *peso,int n){
	int i,j;
    float temp;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(vetor[i]>vetor[j]){
                temp = peso[i];
                peso[i] = peso[j];
                peso[j] = temp;
             }
        }
	}
	return peso;
}
float* ORD(float *vetor, int tamanho){
    int i,j,cont;
    float temp;
    cont=0;
    for(i=0;i<tamanho;i++){
        for(j=i;j<tamanho;j++){
            if (vetor[i] > vetor[j]){
            	temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                cont++;
             }
        }
	}
	printf("Checando se os dados est�o em ordem crescente...\n");
	if(cont>0){
		printf("N�o est�o, reordenando...\n");
		printf("Dados reordenados.\n");
	}
	else{
		printf("Est�o, n�o foi necess�rio reordenar.\n");
	}
	return vetor;
}
void OUTL(float *vet,float ol,int n){
	int i,cont;
	cont=0;
	for(i=0;i<n;i++){
		if(vet[i]<ol){
			cont++;
		}
	}
	if(cont>0){
		printf("S�o outliers � esquerda:\n");
		for(i=0;i<n;i++){
			if(vet[i]<ol){
				printf("<%.2f>",vet[i]);
			}
		}
	}
	else{
		printf("N�o h� outliers � esquerda.\n");
	}
}
void OUTR(float *vet,float or,int n){
	int i,cont;
	cont=0;
	for(i=0;i<n;i++){
		if(vet[i]>or){
			cont++;
		}
	}
	if(cont>0){
		printf("S�o outliers � direita:\n");
		for(i=0;i<n;i++){
			if(vet[i]>or){
				printf("<%.2f>",vet[i]);
			}
		}
	}
	else{
		printf("N�o h� outliers � direita.\n");
	}
}
float TRQR(int n){
	float res;
	res=n/4.0;
	return round(res);
}
float Q1(float *vet,int n){
	float res;
	res=vet[n/4];
	return res;
}
float Q2(float *vet,int n){
	float res;
	if(n%2==0){
		res=(vet[n/2]+vet[n/2-1])/2;
	}
	else{
		res=vet[n/2];
	}
	return res;
}
float Q3(float *vet,int n){
	float res;
	res=vet[(3*n)/4];
	return res;
}
float AIQ(float q1,float q3){
	float res;
	res=q3-q1;
	return res;
}
void MEDA(float *vet,int n){
	float res,res2,soma,mdn,mde;
	int i,j,cont,val;
	val=0;
	soma=0;
	for(i=0;i<n;i++){
		soma+=vet[i];
		cont=0;
		for(j=0;j<n;j++){
			if(vet[j]==vet[i]){
				++cont;
			}
		}
		if(cont>val){
			val=cont;
			mde=vet[i];
		}
	}
	res=soma/n;
	res2=soma/(n-1);
	if(n%2==0){
		mdn=(vet[n/2]+vet[n/2-1])/2;
	}
	else{
		mdn=vet[n/2];
	}
	printf("\nCaso o conjunto seja populacional:\n");
	printf("A m�dia aritm�tica �: %.2f\n",res);
	printf("\nCaso o conjunto seja amostral:\n");
	printf("A m�dia aritm�tica �: %.2f\n",res2);
	printf("\nEm todo caso, a mediana do conjunto de dados �: %.2f\n",mdn);
	if(val>1){
		printf("A moda do conjunto de dados �: %.2f\n",mde);
	}
	if(val<=1){
		printf("N�o h� moda nesse conjunto de dados.\n");
	}
}
void MEDP(float *vet,float *pes,int n){
	float res,soma,somap;
	int i;
	soma=0;
	somap=0;
	for(i=0;i<n;i++){
		soma+=(vet[i]*pes[i]);
		somap+=pes[i];
	}
	res=soma/somap;
	printf("A m�dia ponderada do conjunto de dados analisado �: %.2f\n",res);
}
void VDP(float *vet,int n){
	float med1,med2,var,var2,soma1,soma2,soma3;
	int i;
	soma1=0;
	soma2=0;
	soma3=0;
	for(i=0;i<n;i++){
		soma1+=vet[i];
	}
	med1=soma1/n;
	med2=soma1/(n-1);
	for(i=0;i<n;i++){
		if(vet[i]>med1){
			soma2+=(vet[i]-med1)*(vet[i]-med1);
		}
		if(vet[i]>med2){
			soma3+=(vet[i]-med2)*(vet[i]-med2);
		}
		if(vet[i]<med1){
			soma2+=(med1-vet[i])*(med1-vet[i]);
		}
		if(vet[i]<med2){
			soma3+=(med2-vet[i])*(med2-vet[i]);
		}
	}
	var=soma2/n;
	var2=soma3/n;
	printf("Caso o conjunto seja populacional, os resultados s�o os seguintes:\n");
	printf("A m�dia aritm�tica do conjunto de dados analisado �: %.2f\nA vari�ncia do conjunto de dados analisado �: %.2f\nO desvio padr�o do conjunto de dados analisado �: %.2f\n",med1,var,sqrtf(var));
	printf("Caso o conjunto seja amostral, os resultados s�o os seguintes:\n");
	printf("A m�dia aritm�tica do conjunto de dados analisado �: %.2f\nA vari�ncia do conjunto de dados analisado �: %.2f\nO desvio padr�o do conjunto de dados analisado �: %.2f\n",med2,var2,sqrtf(var2));
}
void DF(float *vet,float *pes,int n){
	int i;
	float fi,fr,Fri;
	fi=0,Fri=0;
	for(i=0;i<n;i++){
		fi+=pes[i];
		printf("| O valor do %d� dado �: %.2f |",i+1,vet[i]);
		printf(" A freq. absoluta do %d� dado �: %.2f |\n",i+1,pes[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		fr=0;
		fr+=(pes[i]/fi)*100;
		printf("A freq. relativa do %d� dado � de %.2f%%\n",i+1,fr);
	}
	for(i=0;i<n;i++){
		Fri+=(pes[i]/fi)*100;
		printf("A freq. relativa acumulada do %d� dado � de %.2f%%\n",i+1,Fri);
	}
	printf("A freq. absoluta de todo o conjunto de dados analisado �: %.2f\n",fi);
}
float AC(float *vet,int n,int cla){
	float res,res2;
	printf("O limite inferior do conjunto de dados analisado �: %.2f\nO limite superior do conjunto de dados analisado �: %.2f\n",vet[0],vet[n-1]);
	res2=(vet[n-1]-vet[0])/cla;
	printf("A amplitude de classes do conjunto de dados analisado �: %.2f\n",res2);
	res=floor(res2);
	
	return res;
}
void PM(float *vet,float ac,int n,int c){
	int i,j,cont,*freq;
	float *li,*ls,*res,freq1,freq2;
	
	li = (float*)malloc(sizeof(int)*c);
	ls = (float*)malloc(sizeof(int)*c);
	res = (float*)malloc(sizeof(int)*c);
	freq = (int*)malloc(sizeof(int)*c);
	
	printf(" _______________________________________________________\n");
	printf("|                                                       |\n");
	printf("| Arredondando a amplitude de classe para baixo, temos: |\n");
	printf("|_______________________________________________________|\n\n");
	freq1=0;
	for(i=0;i<c;i++){
		cont=0;
		if(i==0){
			li[i]=vet[i];
		}
		else{
			li[i]=li[i-1]+ac;
		}
		printf("O limite inferior da %d� classe �: %.1f",i+1,li[i]);
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		printf("\t|\tO limite superior da %d� classe �: %.1f\n",i+1,ls[i]);
		
		res[i]=(li[i]+ls[i])/2;
		printf("O ponto m�dio da %d� classe �: %.2f",i+1,res[i]);
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		printf("\t|\tA frequ�ncia dos valores contidos na %d� classe �: %d\n\n",i+1,freq[i]);
		freq1+=freq[i];
	}
	freq2=0;
	for(i=0;i<c;i++){
		printf("A frequ�ncia relativa da %d� classe � de %.2f%%\n",i+1,(freq[i]/freq1)*100.0);
	}
	for(i=0;i<c;i++){
		freq2+=(freq[i]/freq1)*100;
		printf("A frequ�ncia acumulada da %d� classe � de %.2f%%\n",i+1,freq2);
	}
	
	printf("\n ______________________________________________________\n");
	printf("|                                                      |\n");
	printf("| Arredondando a amplitude de classe para cima, temos: |\n");
	printf("|______________________________________________________|\n\n");
	freq1=0;
	ac+=1;
	for(i=0;i<c;i++){
		cont=0;
		if(i==0){
			li[i]=vet[i];
		}
		else{
			li[i]=li[i-1]+ac;
		}
		printf("O limite inferior da %d� classe �: %.1f",i+1,li[i]);
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		printf("\t|\tO limite superior da %d� classe �: %.1f\n",i+1,ls[i]);
		
		res[i]=(li[i]+ls[i])/2;
		printf("O ponto m�dio da %d� classe �: %.2f",i+1,res[i]);
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		printf("\t|\tA frequ�ncia dos valores contidos na %d� classe �: %d\n\n",i+1,freq[i]);
		freq1+=freq[i];
	}
	freq2=0;
	for(i=0;i<c;i++){
		printf("A frequ�ncia relativa da %d� classe � de %.2f%%\n",i+1,(freq[i]/freq1)*100.0);
	}
	for(i=0;i<c;i++){
		freq2+=(freq[i]/freq1)*100;
		printf("A frequ�ncia acumulada da %d� classe � de %.2f%%\n",i+1,freq2);
	}
};