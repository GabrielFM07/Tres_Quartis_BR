#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int ORD(float *vetor, int tamanho)
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
	round(res);
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
	printf("A m�dia do conjunto de dados analisados (ignorando os outliers) �: %.2f\n",res);
	for(i=0;i<n;i++){
		somao+=(vet[i]*freq[i]);
	}
	reso=somao/somaf;
	printf("A m�dia do conjunto de dados analisados (contando com os outliers) �: %.2f\n",reso);
}*/

int main()
{
	float aiq,q1,q2,q3,tq,ol,or;
	int i,n;
	float *v;
	//float *f;
	float *v2;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Esse programa analisar� um conjunto de dados por meio dos Tr�s Quartis.\n");
	do{
		printf("Informe a quantidade de dados a ser analisada: ");
		scanf("%d",&n);
		if(n<0){
			printf("A quantidade informada � inv�lida, por favor digite um valor maior que 0.\n");
		}
	}while(n<0);
	
	v = (float*)malloc(sizeof(int)*n);
	//f = (float*)malloc(sizeof(int)*n);
	v2 = (float*)malloc(sizeof(int)*n);
	
	//printf("Por favor, informe o valor dos dados.\n");
	for(i=0;i<n;i++){
		printf("Informe o %d� dado: ",i+1);
		scanf("%f",&v[i]);
		//printf("Informe a frequ�ncia em que o %d� dado aparece: ",i+1);
		//scanf("%f",&f[i]);
	}
	
	tq=TRQR(n);
	v2= ORD(v,n);
	q1=Q1(v2,n);
	q2=Q2(v2,n);
	q3=Q3(v2,n);
	aiq=AIQ(q1,q3);
	ol=q1-1.5*aiq;
	or=q3+1.5*aiq;
	
	printf("\nOs quartis se encontram a uma dist�ncia de %.2f dados um do outro.\n",tq);
	printf("O 1� quartil �: %.2f\n",q1);
	printf("O 2� quartil �: %.2f\n",q2);
	printf("O 3� quartil �: %.2f\n",q3);
	printf("O valor da amplitude interquartil �: %2.f\n", aiq);
	OUTL(v,ol,n);
	printf("\n");
	OUTR(v,or,n);
	printf("\nOBS: Caso nenhum valor seja informado � porque n�o h� outliers.\n");
	//MED(v,f,ol,or,n);
	
	system("PAUSE");
	
	return 0;
}