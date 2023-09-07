#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int ordenar(float *vetor, int tamanho)
{
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
	return res;
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
/*void MED(float *vet,float *freq,float outl,float outr,int n){
	float res,reso,soma,somao,somaf;
	int i;
	soma=0;
	somao=0;
	somaf=0;
	for(i=0;i<n;i++){
		somaf+=freq[i];
	}
	for(i=0;i<n;i++){
		if(vet[i]>outl && vet[i]<outr){
		soma+=(vet[i]*freq[i]);
		}
	}
	res=soma/somaf;
	printf("A média do conjunto de dados analisados (ignorando os outliers) é: %.2f\n",res);
	for(i=0;i<n;i++){
		somao+=(vet[i]*freq[i]);
	}
	reso=somao/somaf;
	printf("A média do conjunto de dados analisados (contando com os outliers) é: %.2f\n",reso);
}*/

int main()
{
	float aiq,q1,q2,q3,tq,ol,or;
	int i,n;
	float *v;
	//float *f;
	float *v2;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Esse programa analisará um conjunto de dados por meio dos Três Quartis e informará a média de uma distribuição de frequência.\n");
	do{
		printf("Informe a quantidade de dados a ser analisada: ");
		scanf("%d",&n);
		if(n<0){
			printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
		}
	}while(n<0);
	
	v = (float*)malloc(sizeof(int)*n);
	//f = (float*)malloc(sizeof(int)*n);
	v2 = (float*)malloc(sizeof(int)*n);
	
	printf("Por favor, informe o valor dos dados EM ORDEM CRESCENTE, caso contrário os cálculos serão imprecisos.\n");
	for(i=0;i<n;i++){
		printf("Informe o %dº dado: ",i+1);
		scanf("%f",&v[i]);
		//printf("Informe a frequência em que o %dº dado aparece: ",i+1);
		//scanf("%f",&f[i]);
	}
	v2= ordenar(v, n);
	tq=TRQR(n);
	q1=Q1(v2,n);
	q2=Q2(v2,n);
	q3=Q3(v2,n);
	aiq=AIQ(q1,q3);
	ol=q1-1.5*aiq;
	or=q3+1.5*aiq;
	
	printf("\nOs quartis se encontram a uma distância de %.2f um do outro.\n",tq);	
	printf("O 1º quartil é: %.2f\n",q1);
	printf("O 2º quartil é: %.2f\n",q2);
	printf("O 3º quartil é: %.2f\n",q3);
	printf("O valor da amplitude interquartil é: %2.f", aiq);
	OUTL(v,ol,n);
	printf("\n");
	OUTR(v,or,n);
	printf("\nOBS: Caso nenhum valor seja informado é porque não há outliers.\n");
	//MED(v,f,ol,or,n);
	
	system("PAUSE");
	
	return 0;
}
