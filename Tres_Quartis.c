#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu(){
	int esc;
	
	printf("\tInforme qual função do programa você deseja utilizar:\n ___________________________________________________________________\n|\t\t\t\t\t\t\t\t    |\n");
	printf("|1-<Três Quartis>\t2-<Média Aritimética>\t 3-<Média Ponderada>|\n|\t\t\t\t\t\t\t\t    |\n|4-<Distribuição de Frequência>\t       5-<Variância e Desvio Padrão>|\n");
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
}À ser usado no futuro. (escrever função assim: 'ORDP(&v,&p,n)'*/
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
	printf("São outliers à esquerda:\n");
	for(i=0;i<n;i++){
		if(vet[i]<ol){
			printf("<%.2f>",vet[i]);
		}
	}
}
void OUTR(float *vet,float or,int n){
	int i;
	printf("São outliers à direita:\n");
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
	printf("A média aritmética do conjunto de dados analisado é: %.2f\n",res);
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
			printf("\nEsse programa analisará um conjunto de dados por meio dos Três Quartis.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
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
			printf("\nResolução:\nOs quartis se encontram a uma distância aproximada de %.0f dados um do outro.\n",tq);
			printf("O 1º quartil é: %.2f\n",q1);
			printf("O 2º quartil é: %.2f\n",q2);
			printf("O 3º quartil é: %.2f\n",q3);
			printf("O valor da amplitude interquartil é: %2.f\n", aiq);
			OUTL(v,ol,n);
			printf("\n");
			OUTR(v,or,n);
			printf("\nOBS: Caso nenhum valor seja informado é porque não há outliers.\n");
		}
		if(esc==2){
			system("CLS");
			printf("\nEsse programa analisará um conjunto de dados e informará a média aritimética deles.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
			}
			v2=ORD(v,n);
			MEDA(v2,n);
		}
		if(esc==3){
			system("CLS");
			printf("Esse programa analisará um conjunto de dados e informará a média ponderada deles.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
	
			v = (float*)malloc(sizeof(int)*n);
			p = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
	
			printf("Por favor, informe o valor dos dados.\n");
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Informe o peso do %dº dado: ",i+1);
				scanf("%f",&p[i]);
			}
			MEDP(v,p,n);
		}
		if(esc==4){
			printf("\tEssa função será implementada em versões futuras.\n");
		}
		if(esc==5){
			printf("\t3Essa função será implementada em versões futuras.\n");
		}
	}while(esc<1 || esc>5);
	
	system("PAUSE");
	
	return 0;
}