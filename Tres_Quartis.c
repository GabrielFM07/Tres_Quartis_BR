#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu(){
	int esc;
	
	printf("\tInforme qual função do programa você deseja utilizar:\n ___________________________________________________________________\n|\t\t\t\t\t\t\t\t    |\n");
	printf("| 1-<Três Quartis>\t\t 2-<Média Populacional ou Amostral> |\n|\t\t\t\t\t\t\t\t    |\n| 3-<Média Ponderada>\t\t     4-<Distribuição de Frequência> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n| 5-<Variância e Desvio Padrão>\t\t\t\t   6-<Sair> |\n|___________________________________________________________________|\n");
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
	printf("Reordenando os dados em ordem crescente...\nDados reordenados.\n");
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
	float res,soma,mdn,mde;
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
	if(n%2==0){
		mdn=(vet[n/2]+vet[n/2-1])/2;
	}
	else{
		mdn=vet[n/2];
	}
	printf("A média aritmética do conjunto de dados analisado é: %.2f\nA mediana do conjunto de dados é: %.2f\nA moda do conjunto de dados é: %.2f\n",res,mdn,mde);
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
	float med,var,soma1,soma2;
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
	printf("A média aritmética do conjunto de dados analisado é: %.2f\nA variância do conjunto de dados analisado é: %.2f\nO desvio padrão do conjunto de dados analisado é: %.2f\n",med,var,sqrtf(var));
}
void DF(float *vet,float *pes,int n){
	int i;
	float fi,fr,Fri;
	fi=0,Fri=0;
	for(i=0;i<n;i++){
		fi+=pes[i];
		printf("| O valor do %dº dado é: %.2f |",i+1,vet[i]);
		printf(" A freq. absoluta do %dº dado é: %.2f |",i+1,pes[i]);
		if((i+1)!=n){
			printf("\n");
		}
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

int main()
{
	float aiq,q1,q2,q3,tq,ol,or;
	int i,n,esc,esc2,esc3;
	float *v,*v2;
	float *p;
	float *p2;
	
	setlocale(LC_ALL,"Portuguese");
	do{
		system("CLS");
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
			system("PAUSE");
			continue;
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
			
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
			}
			MEDA(v,n);
			system("PAUSE");
			continue;
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
	
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Informe o peso do %dº dado: ",i+1);
				scanf("%f",&p[i]);
			}
			MEDP(v,p,n);
			system("PAUSE");
			continue;
		}
		if(esc==4){
			system("CLS");
			printf("Esse programa analisará um conjunto de dados e realizará uma distribuição de frequência no mesmo.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
	
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			p = (float*)malloc(sizeof(int)*n);
			p2 = (float*)malloc(sizeof(int)*n);
	
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Informe a frequência em que o %dº dado aparece: ",i+1);
				scanf("%f",&p[i]);
			}
			do{
				printf("Você deseja reordenar os dados informados em ordem crescente?(Opcional)\n(1-Sim  /  2-Não)\n");
				scanf("%d",&esc3);
				if(esc3==1){
					v2=ORD(v,n);
					p2=ORDP(v,p,n);
				}
				if(esc3==2){
					break;
				}
			}while(esc3<1 || esc3>2);
			do{
				printf("Você deseja limpar a tela antes de receber os resultados?(Recomendado)\n(1-Sim  /  2-Não)\n");
				scanf("%d",&esc2);
				if(esc2==1){
					system("CLS");
				}
				if(esc2==1){
					continue;
				}
				else{
					printf("Valor inválido, por favor digite um valor entre 1 e 2.\n");
					continue;
				}
			}while(esc2 !=1 && esc2 !=2);
			if(esc3==1){
				DF(v2,p2,n);
			}
			if(esc3==2){
				DF(v,p,n);
			}
			
			system("PAUSE");
			continue;
		}
		if(esc==5){
			system("CLS");
			printf("Esse programa analisará um conjunto de dados e informará a média, variância e desvio padrão deles.\n");
			do{
				printf("Informe a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade informada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Informe o %dº dado: ",i+1);
				scanf("%f",&v[i]);
			}
			VDP(v,n);
			system("PAUSE");
			continue;
		}
		if(esc==6){
			printf("\t\t\t\tSaindo...\n");
			exit(0);
		}
		if(esc<1 || esc>6){
			printf("Valor inválido, por favor digite um valor entre 1 e 6.\n");
			system("PAUSE");
			continue;
		}
	}while(esc!=6);
	
	system("PAUSE");
	
	return 0;
}