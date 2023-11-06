#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "3qt.h"

int menu(){
	int esc;
	
	printf(" ___________________________________________________________________\n");
	printf("|                                                                   |\n");
	printf("| 1-<Três Quartis>               2-<Média Populacional ou Amostral> |\n");
	printf("|                                                                   |\n");
	printf("| 3-<Média Ponderada>                4-<Distribuição de Frequência> |\n");
	printf("|                                                                   |\n");
	printf("| 5-<Variância e Desvio Padrão>         6-<Intervalos de Confiança> |\n");
	printf("|                                                                   |\n");
	printf("| 7-<Sair>                                                          |\n");
	printf("|___________________________________________________________________|\n");
	printf("\nDigite qual função do programa você deseja utilizar: ");
	scanf("%d",&esc);
	
	return esc;
}
int menuDF(){
	int esc;
	
	printf(" ________________________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("| 1-Amplitude de Classes, Ponto Médio e Frequências de um conjunto desorganizado |\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("|     2- Frequência Absoluta, Relativa e Acumulada de um conjunto organizado     |\n");
	printf("|________________________________________________________________________________|\n");
	printf("\nO que deseja calcular? ");
	scanf("%d",&esc);
	
	return esc;
}
int menuIDC(){
	int esc;
	
	printf(" ________________________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("|             1-<Intervalo de confiança com desvio padrão conhecido>             |\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("| 2-<Intervalo de Confiança com desvio padrão desconhecido (à ser implementado)> |\n");
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
	printf("Checando se os dados estão em ordem crescente...\n");
	if(cont>0){
		printf("Não estão, reordenando...\n");
		printf("Dados reordenados.\n");
	}
	else{
		printf("Estão, não foi necessário reordenar.\n");
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
		printf("São outliers à esquerda:\n");
		for(i=0;i<n;i++){
			if(vet[i]<ol){
				printf("<%.2f>",vet[i]);
			}
		}
	}
	else{
		printf("Não há outliers à esquerda.\n");
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
		printf("São outliers à direita:\n");
		for(i=0;i<n;i++){
			if(vet[i]>or){
				printf("<%.2f>",vet[i]);
			}
		}
	}
	else{
		printf("Não há outliers à direita.\n");
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
	printf("A média aritmética é: %.2f\n",res);
	printf("\nCaso o conjunto seja amostral:\n");
	printf("A média aritmética é: %.2f\n",res2);
	printf("\nEm todo caso, a mediana do conjunto de dados é: %.2f\n",mdn);
	if(val>1){
		printf("A moda do conjunto de dados é: %.2f\n",mde);
	}
	if(val<=1){
		printf("Não há moda nesse conjunto de dados.\n");
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
	printf("A média ponderada do conjunto de dados analisado é: %.2f\n",res);
}
void VDP(float *vet,int n){
	float med,var,var2,soma1,soma2;
	int i;
	soma1=0;
	soma2=0;
	for(i=0;i<n;i++){
		soma1+=vet[i];
	}
	med=soma1/n;
	for(i=0;i<n;i++){
		if(vet[i]>med){
			soma2+=(vet[i]-med)*(vet[i]-med);
		}
		if(vet[i]<med){
			soma2+=(med-vet[i])*(med-vet[i]);
		}
	}
	var=soma2/n;
	var2=soma2/(n-1);
	printf("Caso o conjunto seja populacional, os resultados são os seguintes:\n");
	printf("A média populacional do conjunto de dados analisado é: %.2f\nA variância do conjunto de dados analisado é: %.2f\nO desvio padrão do conjunto de dados analisado é: %.2f\n",med,var,sqrtf(var));
	printf("Caso o conjunto seja amostral, os resultados são os seguintes:\n");
	printf("A média amostral do conjunto de dados analisado é: %.2f\nA variância do conjunto de dados analisado é: %.2f\nO desvio padrão do conjunto de dados analisado é: %.2f\n",med,var2,sqrtf(var2));
}
void DF(float *vet,float *pes,int n){
	int i;
	float fi,fr,Fri;
	fi=0,Fri=0;
	for(i=0;i<n;i++){
		fi+=pes[i];
		printf("| O valor do %dº dado é: %.2f |",i+1,vet[i]);
		printf(" A freq. absoluta do %dº dado é: %.2f |\n",i+1,pes[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		fr=0;
		fr+=(pes[i]/fi)*100;
		printf("A freq. relativa do %dº dado é de %.2f%%\n",i+1,fr);
	}
	for(i=0;i<n;i++){
		Fri+=(pes[i]/fi)*100;
		printf("A freq. relativa acumulada do %dº dado é de %.2f%%\n",i+1,Fri);
	}
	printf("A freq. absoluta de todo o conjunto de dados analisado é: %.2f\n",fi);
}
float AC(float *vet,int n,int cla){
	float res,res2;
	printf("O limite inferior do conjunto de dados analisado é: %.2f\nO limite superior do conjunto de dados analisado é: %.2f\n",vet[0],vet[n-1]);
	res2=(vet[n-1]-vet[0])/cla;
	printf("A amplitude de classes do conjunto de dados analisado é: %.2f\n",res2);
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
		printf("O limite inferior da %dª classe é: %.1f",i+1,li[i]);
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		printf("\t|\tO limite superior da %dª classe é: %.1f\n",i+1,ls[i]);
		
		res[i]=(li[i]+ls[i])/2;
		printf("O ponto médio da %dª classe é: %.2f",i+1,res[i]);
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		printf("\t|\tA frequência dos valores contidos na %dª classe é: %d\n\n",i+1,freq[i]);
		freq1+=freq[i];
	}
	freq2=0;
	for(i=0;i<c;i++){
		printf("A frequência relativa da %dª classe é de %.2f%%\n",i+1,(freq[i]/freq1)*100.0);
	}
	for(i=0;i<c;i++){
		freq2+=(freq[i]/freq1)*100;
		printf("A frequência acumulada da %dª classe é de %.2f%%\n",i+1,freq2);
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
		printf("O limite inferior da %dª classe é: %.1f",i+1,li[i]);
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		printf("\t|\tO limite superior da %dª classe é: %.1f\n",i+1,ls[i]);
		
		res[i]=(li[i]+ls[i])/2;
		printf("O ponto médio da %dª classe é: %.2f",i+1,res[i]);
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		printf("\t|\tA frequência dos valores contidos na %dª classe é: %d\n\n",i+1,freq[i]);
		freq1+=freq[i];
	}
	freq2=0;
	for(i=0;i<c;i++){
		printf("A frequência relativa da %dª classe é de %.2f%%\n",i+1,(freq[i]/freq1)*100.0);
	}
	for(i=0;i<c;i++){
		freq2+=(freq[i]/freq1)*100;
		printf("A frequência acumulada da %dª classe é de %.2f%%\n",i+1,freq2);
	}
}
void IDCC(int n){
	float x,e,zc,dp,c,soma=0,n1;
	float* vet;
	int i,n2;
	if(n==0)
		printf("Esse programa analisará um conjunto de dados e retornará a sua quantidade de membros.\n");
	if(n!=0){
		printf("Esse programa analisará um conjunto de dados e retornará o intervalo de confiança do mesmo.\n");
		vet = (float*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++){
			printf("Digite o %dº dado: ",i+1);
				scanf("%f",&vet[i]);
		}
	}
	
	printf("Qual o desvio padrão populacional desse conjunto de dados? ");
	scanf("%f",&dp);
	
	do{
		printf("Qual o nível de confiança para o intervalo desse conjunto de dados(90%%, 95%% ou 99%% - Digite sem a %%)? ");
		scanf("%f",&c);
		if(c<80.0 || c>99.9)
			printf("<Valor de 'c' inválido, favor digitar um valor entre 80%% e 99.9%%>\n");
	}while(c<80.0 || c>99.9);
	if(c==80)
		zc=1.28;
	if(c==90)
		zc=1.645;
	if(c==95)
		zc=1.96;
	if(c==98)
		zc=2.33;
	if(c==99)
		zc=2.58;
	if(c==99.8)
		zc=3.08;
	if(c==99.9)
		zc=3.27;
	
	if(n==0){
		printf("Qual a margem de erro do conjunto de dados? ");
		scanf("%f",&e);
		n1=(zc*dp/e)*(zc*dp/e);
		n2=ceilf(n1);
		printf("O conjunto de dados em questão possui %d dados.\n",n2);
	}
	else
		e=zc*dp/sqrtf(n);
	
	for(i=0;i<n;i++){
		soma+=vet[i];
	}
	x=soma/n;
	
	if(n!=0)
		printf("O intervalo de confiança desse conjunto de dados se encontra entre '%f' e %f', com uma média de '%f'.\n",x-e,x+e,x);
	else
		printf("A estimativa pontual da média populacional é de '%f'.\n",x);
}
void IDCD(){//à ser implementada no futuro.
	printf("Função ainda em desenvolvimento.\n");
	system("PAUSE");
	system("CLS");
}