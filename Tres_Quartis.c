#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "3qt.h"

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
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			v2 = (float*)malloc(sizeof(int)*n);
			
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
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			
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
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
	
			v = (float*)malloc(sizeof(int)*n);
			p = (float*)malloc(sizeof(int)*n);
	
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
				printf("Digite a quantidade de dados que serão analisados: ");
				scanf("%d",&n);
				do{
					printf("Digite quantas classes deseja utilizar: ");
					scanf("%d",&c);
					if(c > n){
						printf("<Valor inválido, por favor digite um valor menor ou igual a %d>\n",n);
						continue;
					}
				}while(c > n);
				
				if(n<0){
					printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
				}
				
				v = (float*)malloc(sizeof(int)*n);
				v2 = (float*)malloc(sizeof(int)*n);
				
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
						PM(v2,ac,n,c);
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
				
				v = (float*)malloc(sizeof(int)*n);
				p = (float*)malloc(sizeof(int)*n);
				
				for(i=0;i<n;i++){
					printf("Digite o %dº dado: ",i+1);
					scanf("%f",&v[i]);
					printf("Digite a frequência em que o %dº dado aparece: ",i+1);
					scanf("%f",&p[i]);
				}
				
				v2 = (float*)malloc(sizeof(int)*n);
				p2 = (float*)malloc(sizeof(int)*n);
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
			do{
				printf("Digite a quantidade de dados a ser analisada: ");
				scanf("%d",&n);
				if(n<0){
					printf("A quantidade digitada é inválida, por favor digite um valor maior que 0.\n");
				}
			}while(n<0);
			
			v = (float*)malloc(sizeof(int)*n);
			
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