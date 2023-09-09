#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu(){
	int esc;
	
	printf("\tInforme qual fun��o do programa voc� deseja utilizar:\n ___________________________________________________________________\n|\t\t\t\t\t\t\t\t    |\n");
	printf("|1-<Tr�s Quartis>\t2-<M�dia Aritim�tica>\t 3-<M�dia Ponderada>|\n|\t\t\t\t\t\t\t\t    |\n|4-<Distribui��o de Frequ�ncia>\t       5-<Vari�ncia e Desvio Padr�o>|\n");
	printf("|___________________________________________________________________|\n");
	scanf("%d",&esc);
	
	return esc;
}
/*void ORDP(float* vetor,float *peso,int tamanho){
	int i, j;
    float temp,temp2;
    for ( i = 0; i < tamanho; i++)
    {
        for ( j = i; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                temp2 = peso[i];
                peso[i] = peso[j];
                peso[j] = temp2;
             }
        }
	}
}� ser usado no futuro. (escrever fun��o assim: 'ORDP(&v,&p,n)'*/
float* ORD(float *vetor, int tamanho){
    int i, j;
    float temp;
    for ( i = 0; i < tamanho; i++)
    {
        for ( j = i; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
             }
        }
	}
	return vetor;
}
void OUTL(float *vet,float ol,int n){
	int i;
	printf("S�o outliers � esquerda:\n");
	for(i=0;i<n;i++){
		if(vet[i]<ol){
			printf("<%.2f>",vet[i]);
		}
	}
}
void OUTR(float *vet,float or,int n){
	int i;
	printf("S�o outliers � direita:\n");
	for(i=0;i<n;i++){
		if(vet[i]>or){
			printf("<%.2f>",vet[i]);
		}
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
		res=(vet[((3*n)/4)-(n/4)-1]+vet[((3*n)/4)-(n/4)])/2;
	}
	if(n%2!=0 && n!=5){
		res=vet[((3*n)/4)-(n/4)-1];
	}
	if(n%2!=0 && n==5){
		res=vet[((3*n)/4)-(n/4)];
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
	float res,soma;
	int i;
	soma=0;
	for(i=0;i<n;i++){
		soma+=vet[i];
	}
	res=soma/n;
	printf("A m�dia aritm�tica do conjunto de dados analisado �: %.2f\n",res);
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

int main()
{
	float aiq,q1,q2,q3,tq,ol,or;
	int i,n,esc;
	float *v,*v2;
	float *p;
	//float *p2;
	
	setlocale(LC_ALL,"Portuguese");
	do{
		esc=menu();
		if(esc==1){
			system("CLS");
			printf("\nEsse programa analisar� um conjunto de dados por meio dos Tr�s Quartis.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Informe o %d� dado: ",i+1);
				scanf("%f",&v[i]);
			}
			tq=TRQR(n);
			v2=ORD(v,n);
			q1=Q1(v2,n);
			q2=Q2(v2,n);
			q3=Q3(v2,n);
			aiq=AIQ(q1,q3);
			ol=q1-1.5*aiq;
			or=q3+1.5*aiq;
			printf("\nResolu��o:\nOs quartis se encontram a uma dist�ncia aproximada de %.0f dados um do outro.\n",tq);
			printf("O 1� quartil �: %.2f\n",q1);
			printf("O 2� quartil �: %.2f\n",q2);
			printf("O 3� quartil �: %.2f\n",q3);
			printf("O valor da amplitude interquartil �: %2.f\n", aiq);
			OUTL(v,ol,n);
			printf("\n");
			OUTR(v,or,n);
			printf("\nOBS: Caso nenhum valor seja informado � porque n�o h� outliers.\n");
		}
		if(esc==2){
			system("CLS");
			printf("\nEsse programa analisar� um conjunto de dados e informar� a m�dia aritim�tica deles.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Informe o %d� dado: ",i+1);
				scanf("%f",&v[i]);
			}
			v2=ORD(v,n);
			MEDA(v2,n);
		}
		if(esc==3){
			system("CLS");
			printf("Esse programa analisar� um conjunto de dados e informar� a m�dia ponderada deles.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
	
			v = (float*)malloc(sizeof(int)*n);
			p = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
	
			printf("Por favor, informe o valor dos dados.\n");
			for(i=0;i<n;i++){
				printf("Informe o %d� dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Informe o peso do %d� dado: ",i+1);
				scanf("%f",&p[i]);
			}
			MEDP(v,p,n);
		}
		if(esc==4){
			printf("\tEssa fun��o ser� implementada em vers�es futuras.\n");
		}
		if(esc==5){
			printf("\t3Essa fun��o ser� implementada em vers�es futuras.\n");
		}
	}while(esc<1 || esc>5);
	
	system("PAUSE");
	
	return 0;
}