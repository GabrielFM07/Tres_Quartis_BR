#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu(){
	int esc;
	
	printf("\tDigite qual fun��o do programa voc� deseja utilizar:\n ___________________________________________________________________\n|\t\t\t\t\t\t\t\t    |\n");
	printf("| 1-<Tr�s Quartis>\t\t 2-<M�dia Populacional ou Amostral> |\n|\t\t\t\t\t\t\t\t    |\n| 3-<M�dia Ponderada>\t\t     4-<Distribui��o de Frequ�ncia> |\n");
	printf("|\t\t\t\t\t\t\t\t    |\n| 5-<Vari�ncia e Desvio Padr�o>\t\t\t\t   6-<Sair> |\n|___________________________________________________________________|\n");
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
	printf("A m�dia aritm�tica do conjunto de dados analisado �: %.2f\nA mediana do conjunto de dados �: %.2f\n",res,mdn);
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
	printf("A m�dia aritm�tica do conjunto de dados analisado �: %.2f\nA vari�ncia do conjunto de dados analisado �: %.2f\nO desvio padr�o do conjunto de dados analisado �: %.2f\n",med,var,sqrtf(var));
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
	int esc;
	float res;
	printf("O limite inferior do conjunto de dados analisado �: %.2f\nO limite superior do conjunto de dados analisado �: %.2f\n",vet[0],vet[n-1]);
	res=(vet[n-1]-vet[0])/cla;
	printf("A amplitude de classes do conjunto de dados analisado �: %.2f\n",res);
	do{
		printf("Voc� deseja arredondar esse valor?\n(1-Para cima  /  2-Para baixo)\n");
		scanf("%d",&esc);
		if(esc==1){
			return ceil(res);
		}
		if(esc==2){
			return floor(res);
		}
		else{
			printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
			continue;
		}
	}while(esc<1 || esc>2);
}
void PM(float *vet,float ac,int n,int c){
	int i,j,cont,*freq;
	float *li,*ls,*res,freq1,freq2;
	
	li = (float*)malloc(sizeof(int)*c);
	ls = (float*)malloc(sizeof(int)*c);
	res = (float*)malloc(sizeof(int)*c);
	freq = (int*)malloc(sizeof(int)*c);
	
	freq1=0;
	for(i=0;i<c;i++){
		cont=0;
		if(i==0){
			li[i]=vet[i];
		}
		else{
			li[i]=li[i-1]+ac;
		}
		printf("O limite inferior da %d� classe �: %.2f",i+1,li[i]);
		if(i==0){
			ls[i]=li[i]+ac-1;
		}
		else{
			ls[i]=ls[i-1]+ac;
		}
		printf("\t|\tO limite superior da %d� classe �: %.2f\n",i+1,ls[i]);
		
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
			printf("\nEsse programa analisar� um conjunto de dados por meio dos Tr�s Quartis.\n");
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Digite o %d� dado: ",i+1);
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
			OUTR(v,or,n);
			system("PAUSE");
			continue;
		}
		if(esc==2){
			system("CLS");
			printf("\nEsse programa analisar� um conjunto de dados e informar� a m�dia aritim�tica deles.\n");
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Digite o %d� dado: ",i+1);
				scanf("%f",&v[i]);
			}
			MEDA(v,n);
			system("PAUSE");
			continue;
		}
		if(esc==3){
			system("CLS");
			printf("Esse programa analisar� um conjunto de dados e informar� a m�dia ponderada deles.\n");
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
	
			v = (float*)malloc(sizeof(int)*n);
			p = (float*)malloc(sizeof(int)*n);
	
			for(i=0;i<n;i++){
				printf("Digite o %d� dado: ",i+1);
				scanf("%f",&v[i]);
				printf("Digite o peso do %d� dado: ",i+1);
				scanf("%f",&p[i]);
			}
			MEDP(v,p,n);
			system("PAUSE");
			continue;
		}
		if(esc==4){
			system("CLS");
			do{
				printf("O que deseja calcular?\n(1-Amplitude de Classes  /  2-Frequ�ncia Absoluta, Relativa e Acumulada)\n");
				scanf("%d",&esc3);
				if(esc3<1 || esc3>2){
					printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
					continue;
				}
				else{
					system("CLS");
				}
			}while(esc3<1 || esc3>2);
			if(esc3==1){
				printf("Esse programa analisar� um conjunto de dados e buscar� a amplitude de classes do mesmo.\n");
				printf("Digite a quantidade de dados que ser�o analisados: ");
				scanf("%d",&n);
				do{
					printf("Digite quantas classes deseja utilizar: ");
					scanf("%d",&c);
					if(c > n){
						printf("<Valor inv�lido, por favor digite um valor menor ou igual a %d>\n",n);
						continue;
					}
				}while(c > n);
				
				if(n<0){
					printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
				}
				
				v = (float*)malloc(sizeof(int)*n);
				v2 = (float*)malloc(sizeof(int)*n);
				
				for(i=0;i<n;i++){
					printf("Digite o %d� dado: ",i+1);
					scanf("%f",&v[i]);
				}
				
				v2=ORD(v,n);
				printf("\n");
				ac=AC(v2,n,c);
				
				do{
					printf("Voc� deseja calcular o ponto m�dio, a frequ�ncia relativa e a frequ�ncia acumulada desses dados?\n(1-Sim  /  2-N�o)\n");
					scanf("%d",&esc4);
					do{
						printf("Voc� deseja limpar a tela antes de receber os resultados?(Recomendado)\n(1-Sim  /  2-N�o)\n");
						scanf("%d",&esc5);
						if(esc5==1){
							system("CLS");
						}
						if(esc5==2){
							continue;
						}
						else{
							printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
							continue;
						}
					}while(esc5<1 || esc5>2);
					if(esc4==1){
						PM(v2,ac,n,c);
					}
					if(esc4==2){
						break;
					}
					if(esc4<1 || esc4>2){
						printf("Valor inv�lido, por favor digite um valor entre 1 e 2.\n");
						continue;
					}
				}while(esc4<1 || esc4>2);
				
			}
			if(esc3==2){
				printf("Esse programa analisar� um conjunto de dados e realizar� uma distribui��o de frequ�ncia no mesmo.\n");
				do{
					printf("Digite a quantidade de classes que ser�o analisadas: ");
					scanf("%d",&n);
					if(n<0){
						printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
					}
				}while(n<0);
				
				v = (float*)malloc(sizeof(int)*n);
				p = (float*)malloc(sizeof(int)*n);
				
				for(i=0;i<n;i++){
					printf("Digite o %d� dado: ",i+1);
					scanf("%f",&v[i]);
					printf("Digite a frequ�ncia em que o %d� dado aparece: ",i+1);
					scanf("%f",&p[i]);
				}
				
				v2 = (float*)malloc(sizeof(int)*n);
				p2 = (float*)malloc(sizeof(int)*n);
				v2=ORD(v,n);
				p2=ORDP(v,p,n);
				
				do{
					printf("Voc� deseja limpar a tela antes de receber os resultados?(Recomendado)\n(1-Sim  /  2-N�o)\n");
					scanf("%d",&esc2);
					if(esc2==1){
						system("CLS");
					}
					if(esc2==2){
						continue;
					}
					if(esc2<1 || esc2>2){
						printf("<Valor inv�lido, por favor digite um valor entre 1 e 2>\n");
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
			printf("Esse programa analisar� um conjunto de dados e informar� a m�dia, vari�ncia e desvio padr�o deles.\n");
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada � inv�lida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++){
				printf("Digite o %d� dado: ",i+1);
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
			printf("<Valor inv�lido, por favor digite um valor entre 1 e 6>\n");
			system("PAUSE");
			continue;
		}
	}while(esc!=6);
	
	system("PAUSE");
	
	return 0;
}