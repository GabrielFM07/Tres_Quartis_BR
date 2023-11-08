#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "3qt.h"

int menu(){
	int esc;
	
	printf(" ___________________________________________________________________\n");
	printf("|                                                                   |\n");
	printf("| 1-<Tr�s Quartis>               2-<M�dia Populacional ou Amostral> |\n");
	printf("|                                                                   |\n");
	printf("| 3-<M�dia Ponderada>                4-<Distribui��o de Frequ�ncia> |\n");
	printf("|                                                                   |\n");
	printf("| 5-<Vari�ncia e Desvio Padr�o>         6-<Intervalos de Confian�a> |\n");
	printf("|                                                                   |\n");
	printf("| 7-<Sair>                                                          |\n");
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
int menuIDC(){
	int esc;
	
	printf(" ________________________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("|             1-<Intervalo de confian�a com desvio padr�o conhecido>             |\n");
	printf("|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("|           2-<Intervalo de Confian�a com desvio padr�o desconhecido>            |\n");
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
	printf("Caso o conjunto seja populacional, os resultados s�o os seguintes:\n");
	printf("A m�dia populacional do conjunto de dados analisado �: %.2f\nA vari�ncia do conjunto de dados analisado �: %.2f\nO desvio padr�o do conjunto de dados analisado �: %.2f\n",med,var,sqrtf(var));
	printf("Caso o conjunto seja amostral, os resultados s�o os seguintes:\n");
	printf("A m�dia amostral do conjunto de dados analisado �: %.2f\nA vari�ncia do conjunto de dados analisado �: %.2f\nO desvio padr�o do conjunto de dados analisado �: %.2f\n",med,var2,sqrtf(var2));
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
}
void IDCC(int n){
	float x,e,zc,dp,c,soma=0,n1;
	float* vet;
	int i,n2,esc1,esc2;
	if(n==0)
		printf("Esse programa analisar� um conjunto de dados e retornar� a sua quantidade de membros.\n");
	if(n!=0){
		printf("Esse programa analisar� um conjunto de dados e retornar� o intervalo de confian�a do mesmo.\n");
		do{
			printf("Voc� j� sabe o valor da m�dia desse conjunto de dados(1-Sim / 2-N�o)? ");
			scanf("%d",&esc1);
			if(esc1<1 || esc1>2)
				printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
		}while(esc1<1 || esc1>2);
		if(esc1==2){
			printf(" ________________________________________________________________________________\n");
			printf("|\t\t\t\t\t\t\t\t\t\t |\n");
			printf("|                       1-<Digitar os valores do conjunto>                       |\n");
			printf("|\t\t\t\t\t\t\t\t\t\t |\n");
			printf("|                           2-<Buscar o erro amostral>                           |\n");
			printf("|________________________________________________________________________________|\n");
			printf("\nO que deseja? ");
			scanf("%d",&esc2);
			if(esc2==1){
				vet = (float*)malloc(sizeof(int)*n);
				for(i=0;i<n;i++){
					printf("Digite o %d� dado: ",i+1);
					scanf("%f",&vet[i]);
				}
			}
		}
	}
	
	printf("Qual o desvio padr�o populacional desse conjunto de dados? ");
	scanf("%f",&dp);
	
	do{
		printf("Qual o n�vel de confian�a para o intervalo desse conjunto de dados(ex: 80%%, 99%% etc - Digite sem a %%)? ");
		scanf("%f",&c);
		if(c<75.0 || c>99.9)
			printf("<Valor de 'c' inv�lido, favor digitar um valor entre 75%% e 99.9%%>\n");
	}while(c<75.0 || c>99.9);
	if(c==75)
		zc=1.15;
	if(c==80)
		zc=1.28;
	if(c==85)
		zc=1.44;
	if(c==90)
		zc=1.645;
	if(c==95)
		zc=1.96;
	if(c==97)
		zc=2.17;
	if(c==97.5)
		zc=2.242;
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
		printf("\nO conjunto de dados em quest�o possui %d dados.\n",n2);
	}
	else
		e=zc*dp/sqrtf(n);
	
	if(esc1==1){
		printf("Qual o valor da m�dia amostral desse conjunto de dados? ");
		scanf("%f",&x);
	}
	if(esc1==2){
		for(i=0;i<n;i++){
			soma+=vet[i];
		}
		x=soma/n;
	}
	
	if(n!=0 && esc2!=2){
		printf("\nSabendo que c � igual a '%.1f%%', z-cr�tico � igual a '%.3f' e o desvio padr�o � igual a: '%f', temos que:\n",c,zc,dp);
		printf("A margem de erro �: '%f' e o intervalo de confian�a �: |'%f' < u < '%f'|\n",e,x-e,x+e);
	}
	
	if(esc2==2)
		printf("\nO erro amostral �: '%f'\n",e);
}
void IDCD(int n){
	float tc,x,s,e,soma1=0,soma2=0,gl=(n-1);
	float* vet;
	int i,c,esc1,esc2;
	
	printf("Esse programa analisar� um conjunto de dados e retornar� o intervalo de confian�a e/ou o t-cr�tico do mesmo.\n");
	
	do{
		printf(" ________________________________________________________________________________\n");
		printf("|\t\t\t\t\t\t\t\t\t\t |\n");
		printf("|                 1-<Intervalo de Confian�a e/ou margem de erro>                 |\n");
		printf("|\t\t\t\t\t\t\t\t\t\t |\n");
		printf("|                        2-<Somente o valor do t-cr�tico>                        |\n");
		printf("|________________________________________________________________________________|\n");
		printf("\nO que est� buscando? ");
		scanf("%d",&esc1);
		if(esc1==1){
			do{
				printf("Qual o n�vel de confian�a para o intervalo desse conjunto de dados(ex: 90%%, 99%% etc - Digite sem a %%)? ");
				scanf("%d",&c);
				if(c<90 || c>99)
					printf("<Valor de 'c' inv�lido, favor digitar um valor que seja igual a 90%%, 95%%, 98%% ou 99%%>\n");
			}while(c<90 || c>99);
			if(c==90){
				if(gl==4)
					tc=2.132;
				if(gl==5)
					tc=2.015;
				if(gl==6)
					tc=1.943;
				if(gl==7)
					tc=1.895;
				if(gl==8)
					tc=1.860;
				if(gl==9)
					tc=1.833;
				if(gl==11)
					tc=1.796;
				if(gl==12)
					tc=1.782;
				if(gl==13)
					tc=1.771;
				if(gl==14)
					tc=1.761;
				if(gl==15)
					tc=1.753;
				if(gl==17)
					tc=1.740;
				if(gl==18)
					tc=1.734;
				if(gl==19)
					tc=1.729;
				if(gl==34)
					tc=1.691;
				if(gl==39)
					tc=1.685;
				if(gl>=43 && gl<=47)
					tc=1.679;
				if(gl>=48 && gl<=52)
					tc=1.676;
			}
			if(c==95){
				if(gl==4)
					tc=2.776;
				if(gl==5)
					tc=2.571;
				if(gl==6)
					tc=2.447;
				if(gl==7)
					tc=2.365;
				if(gl==8)
					tc=2.306;
				if(gl==9)
					tc=2.262;
				if(gl==11)
					tc=2.201;
				if(gl==12)
					tc=2.179;
				if(gl==13)
					tc=2.160;
				if(gl==14)
					tc=2.145;
				if(gl==15)
					tc=2.131;
				if(gl==17)
					tc=2.110;
				if(gl==18)
					tc=2.101;
				if(gl==19)
					tc=2.093;
				if(gl==34)
					tc=2.032;
				if(gl==39)
					tc=2.023;
				if(gl>=43 && gl<=47)
					tc=2.014;
				if(gl>=48 && gl<=52)
					tc=2.009;
			}
			if(c==98){
				if(gl==4)
					tc=3.747;
				if(gl==5)
					tc=3.365;
				if(gl==6)
					tc=3.143;
				if(gl==7)
					tc=2.998;
				if(gl==8)
					tc=2.896;
				if(gl==9)
					tc=2.821;
				if(gl==11)
					tc=2.718;
				if(gl==12)
					tc=2.681;
				if(gl==13)
					tc=2.650;
				if(gl==14)
					tc=2.624;
				if(gl==15)
					tc=2.602;
				if(gl==17)
					tc=2.567;
				if(gl==18)
					tc=2.552;
				if(gl==19)
					tc=2.539;
				if(gl==34)
					tc=2.441;
				if(gl==39)
					tc=2.426;
				if(gl>=43 && gl<=47)
					tc=2.412;
				if(gl>=48 && gl<=52)
					tc=2.403;
			}
			if(c==99){
				if(gl==4)
					tc=4.604;
				if(gl==5)
					tc=4.032;
				if(gl==6)
					tc=3.707;
				if(gl==7)
					tc=3.499;
				if(gl==8)
					tc=3.355;
				if(gl==9)
					tc=3.250;
				if(gl==11)
					tc=3.106;
				if(gl==12)
					tc=3.055;
				if(gl==13)
					tc=3.012;
				if(gl==14)
					tc=2.977;
				if(gl==15)
					tc=2.947;
				if(gl==17)
					tc=2.898;
				if(gl==18)
					tc=2.878;
				if(gl==19)
					tc=2.861;
				if(gl==34)
					tc=2.728;
				if(gl==39)
					tc=2.708;
				if(gl>=43 && gl<=47)
					tc=2.690;
				if(gl>=48 && gl<=52)
					tc=2.678;
			}
			
			printf("Qual o valor do desvio padr�o amostral(Caso n�o saiba, digite 0)? ");
			scanf("%f",&s);
			if(s==0){
				vet = (float*)malloc(sizeof(int)*n);
				for(i=0;i<n;i++){
					printf("Digite o %d� dado: ",i+1);
					scanf("%f",&vet[i]);
					soma1+=vet[i];
				}
				x=soma1/n;
				for(i=0;i<n;i++)
					soma2+=((vet[i]-x)*(vet[i]-x));
			}
			if(s<0 || s>0){
				do{
					printf("Voc� sabe o valor da m�dia amostral(1-Sim / 2-N�o)? ");
					scanf("%d",&esc2);
					if(esc2==1){
						printf("Digite o valor da m�dia: ");
						scanf("%f",&x);
					}
					if(esc2==2){
						
					}
					if(esc2<1 || esc2>2)
						printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
				}while(esc2<1 || esc2>2);
			}
			
			if(esc2==1 || s==0){
				if(s==0)
					s=sqrtf(soma2/gl);
				e=(tc*s)/sqrtf(n);
				printf("\nSabendo que c � igual a '%d%%', t-cr�tico � igual a '%.3f' e a m�dia amostral � igual a: '%f', temos que:\n",c,tc,x);
				printf("O desvio padr�o amostral � igual a: '%f'\nA margem de erro �: '%f' e o intervalo de confian�a �: |'%f' < u < '%f'|\n",s,e,x-e,x+e);
			}
			else{
				e=(tc*s)/sqrtf(n);
				printf("\nSabendo que c � igual a '%d%%', t-cr�tico � igual a '%.3f' e o desvio padr�o amostral � igual a: '%f', temos que:\n",c,tc,s);
				printf("O valor da margem de erro �: '%f'\n",e);
			}
		}
		if(esc1==2){
			do{
				printf("Qual o n�vel de confian�a para o intervalo desse conjunto de dados(ex: 90%%, 99%% etc - Digite sem a %%)? ");
				scanf("%d",&c);
				if(c<90 || c>99)
					printf("<Valor de 'c' inv�lido, favor digitar um valor que seja igual a 90%%, 95%%, 98%% ou 99%%>\n");
			}while(c<90 || c>99);
			if(c==90){
				if(gl==4)
					tc=2.132;
				if(gl==5)
					tc=2.015;
				if(gl==6)
					tc=1.943;
				if(gl==7)
					tc=1.895;
				if(gl==8)
					tc=1.860;
				if(gl==9)
					tc=1.833;
				if(gl==11)
					tc=1.796;
				if(gl==12)
					tc=1.782;
				if(gl==13)
					tc=1.771;
				if(gl==14)
					tc=1.761;
				if(gl==15)
					tc=1.753;
				if(gl==17)
					tc=1.740;
				if(gl==18)
					tc=1.734;
				if(gl==19)
					tc=1.729;
				if(gl==34)
					tc=1.691;
				if(gl==39)
					tc=1.685;
				if(gl>=43 && gl<=47)
					tc=1.679;
				if(gl>=48 && gl<=52)
					tc=1.676;
			}
			if(c==95){
				if(gl==4)
					tc=2.776;
				if(gl==5)
					tc=2.571;
				if(gl==6)
					tc=2.447;
				if(gl==7)
					tc=2.365;
				if(gl==8)
					tc=2.306;
				if(gl==9)
					tc=2.262;
				if(gl==11)
					tc=2.201;
				if(gl==12)
					tc=2.179;
				if(gl==13)
					tc=2.160;
				if(gl==14)
					tc=2.145;
				if(gl==15)
					tc=2.131;
				if(gl==17)
					tc=2.110;
				if(gl==18)
					tc=2.101;
				if(gl==19)
					tc=2.093;
				if(gl==34)
					tc=2.032;
				if(gl==39)
					tc=2.023;
				if(gl>=43 && gl<=47)
					tc=2.014;
				if(gl>=48 && gl<=52)
					tc=2.009;
			}
			if(c==98){
				if(gl==4)
					tc=3.747;
				if(gl==5)
					tc=3.365;
				if(gl==6)
					tc=3.143;
				if(gl==7)
					tc=2.998;
				if(gl==8)
					tc=2.896;
				if(gl==9)
					tc=2.821;
				if(gl==11)
					tc=2.718;
				if(gl==12)
					tc=2.681;
				if(gl==13)
					tc=2.650;
				if(gl==14)
					tc=2.624;
				if(gl==15)
					tc=2.602;
				if(gl==17)
					tc=2.567;
				if(gl==18)
					tc=2.552;
				if(gl==19)
					tc=2.539;
				if(gl==34)
					tc=2.441;
				if(gl==39)
					tc=2.426;
				if(gl>=43 && gl<=47)
					tc=2.412;
				if(gl>=48 && gl<=52)
					tc=2.403;
			}
			if(c==99){
				if(gl==4)
					tc=4.604;
				if(gl==5)
					tc=4.032;
				if(gl==6)
					tc=3.707;
				if(gl==7)
					tc=3.499;
				if(gl==8)
					tc=3.355;
				if(gl==9)
					tc=3.250;
				if(gl==11)
					tc=3.106;
				if(gl==12)
					tc=3.055;
				if(gl==13)
					tc=3.012;
				if(gl==14)
					tc=2.977;
				if(gl==15)
					tc=2.947;
				if(gl==17)
					tc=2.898;
				if(gl==18)
					tc=2.878;
				if(gl==19)
					tc=2.861;
				if(gl==34)
					tc=2.728;
				if(gl==39)
					tc=2.708;
				if(gl>=43 && gl<=47)
					tc=2.690;
				if(gl>=48 && gl<=52)
					tc=2.678;
			}
			
			printf("O valor do t-cr�tico �: '%.3f'\n",tc);
			}
		if(esc1<1 || esc1>2)
				printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
	}while(esc1<1 || esc1>2);
}