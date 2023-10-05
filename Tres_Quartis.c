#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu(){
	int esc;
	
	printf(" ___________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 1-<Três Quartis>\t\t 2-<Média Populacional ou Amostral> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 3-<Média Ponderada>\t\t     4-<Distribuição de Frequência> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n");
	printf("| 5-<Variância e Desvio Padrão>\t\t\t\t   6-<Sair> |\n");
	printf("|___________________________________________________________________|\n");
	printf("\nDigite qual função do programa você deseja utilizar: ");
	scanf("%d",&esc);
	
	return esc;
}
int tratamento_de_erro(){
	int n;
	do{
		printf("Digite a quantidade de dados a ser analisada: ");
		scanf("%d",&n);
		if(n<0){
			printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
		}
	}while(n<0);
	return n;
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
	printf("A média aritmética do conjunto de dados analisado é: %.2f\nA mediana do conjunto de dados é: %.2f\n",res,mdn);
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
	var2=soma2/n-1
	printf("Caso o conjunto seja populacional, os resultados são os seguintes:\n");
	printf("A média aritmética do conjunto de dados analisado é: %.2f\nA variância do conjunto de dados analisado é: %.2f\nO desvio padrão do conjunto de dados analisado é: %.2f\n\n",med,var,sqrtf(var));
	printf("Caso o conjunto seja amostral, os resultados são os seguintes:\n");
	printf("A média aritmética do conjunto de dados analisado é: %.2f\nA variância do conjunto de dados analisado é: %.2f\nO desvio padrão do conjunto de dados analisado é: %.2f\n",med,var2,sqrtf(var2));
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

void tabela(float *vet,float ac,int n,int c){
	int i,j,cont,*freq;
	float *li,*ls,*res,freq1,freq2;
	
	li = (float*)malloc(sizeof(float)*c);
	ls = (float*)malloc(sizeof(float)*c);
	res = (float*)malloc(sizeof(float)*c);
	freq = (int*)malloc(sizeof(int)*c);
	
	printf(" _______________________________________________________\n");
	printf("|                                                       |\n");
	printf("| Arredondando a amplitude de classe para baixo, temos: |\n");
	printf("|_______________________________________________________|\n\n");
	freq1=0;
	freq2=0;
	printf(" _________________________________________________________________________________________\n");
	printf("|    Classes     |  Frequências  |  Ponto médio  |  Freq. relativas  |  Freq. acumuladas  |\n");
	printf("|________________|_______________|_______________|___________________|____________________|\n");
	for(i=0;i<c;i++){
		cont=0;
		if(i==0){
			li[i]=vet[i];
		}
		else{
			li[i]=li[i-1]+ac;
		}
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		
		res[i]=(li[i]+ls[i])/2;
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		freq1+=freq[i];
		freq2+=(freq[i]/freq1)*100;
		printf("|   %.1f-%.1f \t |  \t%d\t | \t%.1f \t | \t%.2f\t     |       %.2f\t  |\n", li[i], ls[i], freq[i], res[i], (freq[i]/freq1)*100.0, freq2-1);
		printf("|________________|_______________|_______________|___________________|____________________|\n");
	}
	
	printf("\n ______________________________________________________\n");
	printf("|                                                      |\n");
	printf("| Arredondando a amplitude de classe para cima, temos: |\n");
	printf("|______________________________________________________|\n\n");
	freq1=0;
	ac+=1;
	freq2=0;
	printf(" _________________________________________________________________________________________\n");
	printf("|    Classes     |  Frequências  |  Ponto médio  |  Freq. relativas  |  Freq. acumuladas  |\n");
	printf("|________________|_______________|_______________|___________________|____________________|\n");
	for(i=0;i<c;i++){
		cont=0;
		if(i==0){
			li[i]=vet[i];
		}
		else{
			li[i]=li[i-1]+ac;
		}
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		
		res[i]=(li[i]+ls[i])/2;
		for(j=0;j<n;j++){
			if(vet[j]>=li[i] && vet[j]<=ls[i]){
				cont++;
			}
		}
		freq[i]=cont;
		freq1+=freq[i];
		freq2+=(freq[i]/freq1)*100;
		printf("|   %.1f-%.1f \t |  \t%d\t | \t%.1f \t | \t%.2f\t     |       %.2f\t  |\n", li[i], ls[i], freq[i], res[i], (freq[i]/freq1)*100.0, freq2-1);
		printf("|________________|_______________|_______________|___________________|____________________|\n");
	}
}

int main()
{
	float aiq,q1,q2,q3,tq,ol,or,ac;
	int i,n,c,esc,esc2,esc3,esc4,esc5;
	float *v,*v2;
	float *p,*p2;
	
	setlocale(LC_ALL,"Portuguese");
	do{
		system("CLS");
		esc=menu();
		if(esc==1){
			system("CLS");
			printf("\nEsse programa analisará um conjunto de dados por meio dos Três Quartis.\n");
			n= tratamento_de_erro();
			v = (float*)malloc(sizeof(float)*n);
			v2 = (float*)malloc(sizeof(float)*n);
			
			for(i=0;i<n;i++){
				printf("Digite o %dº dado: ",i+1);
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
			OUTR(v,or,n);
			system("PAUSE");
			continue;
		}
		if(esc==2){
			system("CLS");
			printf("\nEsse programa analisará um conjunto de dados e informará a média aritimética deles.\n");
			n= tratamento_de_erro(n);
			v = (float*)malloc(sizeof(float)*n);
			for(i=0;i<n;i++){
				printf("Digite o %dº dado: ",i+1);
				scanf("%f",&v[i]);
			}
			MEDA(v,n);
			system("PAUSE");
			continue;
		}
		if(esc==3){
			system("CLS");
			printf("Esse programa analisará um conjunto de dados e informará a média ponderada deles.\n");
			n= tratamento_de_erro();
			v = (float*)malloc(sizeof(float)*n);
			p = (float*)malloc(sizeof(float)*n);
			for(i=0;i<n;i++){
				printf("Digite o %dº dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Digite o peso do %dº dado: ",i+1);
				scanf("%f",&p[i]);
			}
			MEDP(v,p,n);
			system("PAUSE");
			continue;
		}
		if(esc==4){
			system("CLS");
			do{
				esc3=menuDF();
				if(esc3<1 || esc3>2){
					printf("<Valor inválido, por favor digite um valor entre 1 e 2>\n");
					continue;
				}
				else{
					system("CLS");
				}
			}while(esc3<1 || esc3>2);
			if(esc3==1){
				printf("Esse programa analisará um conjunto de dados e buscará a amplitude de classes do mesmo.\n");
				n= tratamento_de_erro();
				do{
					printf("Digite quantas classes deseja utilizar: ");
					scanf("%d",&c);
					if(c > n){
						printf("<Valor inválido, por favor digite um valor menor ou igual a %d>\n",n);
						continue;
					}
				}while(c > n);
				
				v = (float*)malloc(sizeof(float)*n);
				v2 = (float*)malloc(sizeof(float)*n);
				
				for(i=0;i<n;i++){
					printf("Digite o %dº dado: ",i+1);
					scanf("%f",&v[i]);
				}
				
				v2=ORD(v,n);
				printf("\n");
				ac=AC(v2,n,c);
				
				do{
					printf("Você deseja calcular o ponto médio, a frequência relativa e a frequência acumulada desses dados?\n(1-Sim  /  2-Não)\n");
					scanf("%d",&esc4);
					do{
						printf("Você deseja limpar a tela antes de receber os resultados?(Recomendado)\n(1-Sim  /  2-Não)\n");
						scanf("%d",&esc5);
						if(esc5==1){
							system("CLS");
						}
						if(esc5==2){
							continue;
						}
						if(esc5<1 || esc5>2){
							printf("<Valor inválido, por favor digite um valor entre 1 e 2>\n");
							continue;
						}
					}while(esc5<1 || esc5>2);
					if(esc4==1){
						//PM(v2,ac,n,c);
						tabela(v2,ac,n,c);
					}
					if(esc4==2){
						break;
					}
					if(esc4<1 || esc4>2){
						printf("Valor inválido, por favor digite um valor entre 1 e 2.\n");
						continue;
					}
				}while(esc4<1 || esc4>2);
				
			}
			if(esc3==2){
				printf("Esse programa analisará um conjunto de dados e realizará uma distribuição de frequência no mesmo.\n");
				do{
					printf("Digite a quantidade de classes que serão analisadas: ");
					scanf("%d",&n);
					if(n<0){
						printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
					}
				}while(n<0);
				
				v = (float*)malloc(sizeof(float)*n);
				p = (float*)malloc(sizeof(float)*n);
				
				for(i=0;i<n;i++){
					printf("Digite o %dº dado: ",i+1);
					scanf("%f",&v[i]);
					printf("Digite a frequência em que o %dº dado aparece: ",i+1);
					scanf("%f",&p[i]);
				}
				
				v2 = (float*)malloc(sizeof(float)*n);
				p2 = (float*)malloc(sizeof(float)*n);
				v2=ORD(v,n);
				p2=ORDP(v,p,n);
				
				do{
					printf("Você deseja limpar a tela antes de receber os resultados?(Recomendado)\n(1-Sim  /  2-Não)\n");
					scanf("%d",&esc2);
					if(esc2==1){
						system("CLS");
					}
					if(esc2==2){
						continue;
					}
					if(esc2<1 || esc2>2){
						printf("<Valor inválido, por favor digite um valor entre 1 e 2>\n");
						continue;
					}
				}while(esc2<1 || esc2>2);
				
				DF(v2,p2,n);
			}
			system("PAUSE");
			continue;
		}
		if(esc==5){
			system("CLS");
			printf("Esse programa analisará um conjunto de dados e informará a média, variância e desvio padrão deles.\n");
			n= tratamento_de_erro();
			
			v = (float*)malloc(sizeof(float)*n);
			
			for(i=0;i<n;i++){
				printf("Digite o %dº dado: ",i+1);
				scanf("%f",&v[i]);
			}
			VDP(v,n);
			system("PAUSE");
			continue;
		}
		if(esc==6){
			printf("\t\t\t\tSaindo...\n");
		}
		if(esc<1 || esc>6){
			printf("<Valor inválido, por favor digite um valor entre 1 e 6>\n");
			system("PAUSE");
			continue;
		}
	}while(esc!=6);
	
	system("PAUSE");
	
	return 0;
}