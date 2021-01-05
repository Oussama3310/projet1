#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
/*Déclaration des types*/
typedef struct {
	int num_machine;
	char descriptif[50], local[50];
}machine;
typedef struct{
	int j,m,a;
}date;
typedef struct {
	int num;
	char nom[10],prenom[10], adresse[50],email[10],tel[10];
	date DateEmploi;
	/*char dateemploi */
}technicien;
typedef struct {
	int num_machine, num_incident,num_technicien;
	char description[50];
	date DateResolution;
	/* char dateresolution*/
}incident;

main()
{printf("\n \n ----- DEBUT DU PROGRAMME ----- \n\n ");
machine M[20];
technicien T[10];
incident I[10];
int i,j,NM,NT,NI,m,R_num,existe,choix,ch,ch1,L;
 /*NM = 2; 
NT = 2;
NI = 2;
machine M[] = {{1,"carre","agdal"},{2,"ovale","sale"}};
technicien T[] = {{7,"tahiri","amal","rue 5","ta@kk.cl","0987654321","3/5/2001"},{9,"elfadil","nada","rue 7","na@lk.m","1234567890","12/6/2012"}};
incident I[] = {{4,1,7,"danger1","15/6/2008"},{5,2,9,"danger2","23/3/2010"}};
*/
do{
	printf(" -> Le nombre de machines : ");
	scanf("%d",&NM);
}
while (NM<=0 || NM > 20);
//Remplissage du tableau de machines
for ( i=0; i<NM; i++){
	printf("\n -> Machine %d : ",i+1);
	printf("\n\t - Numero de machine : ");
	scanf("%d",&M[i].num_machine);
	fflush(stdin);
	printf("\t - Le descriptif : ");
	gets(M[i].descriptif);
	printf("\t - Le local : ");
	gets(M[i].local);
}

do{
	printf("\n -> Le nombre de techniciens : ");
	scanf("%d",&NT);
}while (NT<=0 || NT > 10);
//Remplissage du tableau de techniciens
for ( i=0 ; i<NT ; i++){
	printf("\n -> Technicien %d : ",i+1);
	printf("\n \t - Numero de technicien : ");
	scanf("%d",&T[i].num);
	fflush(stdin);
	do {
	printf("\t - Numero de telephone : ");
	gets(T[i].tel);
	m=strlen(T[i].tel);
	if (m!=10)
	printf("Le numero est incorrect !!! \n");
	}
	while(m!=10);
	printf(" \t - Nom : ");
	gets(T[i].nom);
	printf(" \t - Prenom : ");
	gets(T[i].prenom);
	printf(" \t - Adresse : ");
	gets(T[i].adresse);
	printf("\t - Email : ");
	gets(T[i].email);
	do{
		printf("\t - Date d'emploi (jour/mois/annee) : ");
		L = scanf("%d/%d/%d",&T[i].DateEmploi.j,&T[i].DateEmploi.m,&T[i].DateEmploi.a);
		if (L!=3)
		printf("--> LA DATE D'EMPLOI EST INVALIDE !!! \n ");
	}while (L!=3);
	
}
do{
	printf("\n -> Le nombre d'incidents : ");
	scanf("%d",&NI);
}
while (NI<=0 || NI > 10);
//Remplissage du tableau d'incidents
for ( i=0; i<NI; i++){
	printf("\n -> L'incident %d : ",i+1);
	printf("\n \t - Le numero d'incident : ");
	scanf("%d",&I[i].num_incident);
	existe = 0;
	do{
		printf("\t - Le numero de machine : ");
		scanf("%d",&I[i].num_machine);
		for (j=0; j<NI; j++){
			if (I[i].num_machine == M[j].num_machine)
			existe = 1;
		}
		if (existe == 0)
		printf("\t --> LE NUMERO DE MACHINE DE L'INCIDENT N'EXISTE PAS !!! \n");
	}while (existe == 0);
	existe = 0;
	do{
		printf("\t - Le numero de technicien : ");
		scanf("%d",&I[i].num_technicien);
		for (j=0;j<NT;j++){
			if (I[i].num_technicien == T[j].num)
			existe = 1;
		}
		if (existe == 0)
		printf("\t --> LE NUMERO DU TECHNICIEN DE L'INCIDENT N'EXISTE PAS !!! \n");
	}while (existe == 0);
	fflush(stdin);
	printf("\t - Description : ");
	gets(I[i].description);
	do{
		printf("\t - Date de resolution (jour/mois/annee) : ");
		L = scanf("%d/%d/%d",&I[i].DateResolution.j,&I[i].DateResolution.m,&I[i].DateResolution.a);
		if (L!=3)
		printf("\t --> LA DATE DE RESOLUTION EST INVALIDE !!! \n ");
	}while (L!=3);
	
}    
fflush(stdin);
do{ printf("\n \t ~~~~~~~~ MENU~~~~~~~~ ");
 printf(" \n (1) --> Ajouter une machine  ");
 printf("\n (2) --> Ajouter un technicien ");
 printf("\n (3) --> Ajouter un incident  ");
 printf("\n (4) --> Modifier une machine ");
 printf("\n (5) --> Modifier un technicien ");
 printf("\n (6) --> Modifier un incident  ");
 printf("\n (7) --> Supprimer une machine ");
 printf("\n (8) -->  Supprimer un technicien ");
 printf("\n (9) -->  Supprimer un incident  ");
 printf("\n (10) --> Afficher une machine ");
 printf("\n (11) --> Afficher un technicien ");
 printf("\n (12) --> Afficher un incident  ");
 printf("\n (13) --> Quitter le programme ");

do {  
		printf("\n\n \t --> Entrer votre choix : ");
      	scanf("%d",&choix);
      	if(choix<1|| choix>13)
      	printf(" LE CHOIX EST INVALIDE !!!! ");
		}while(choix<1 || choix>13);
switch (choix)
{
case 1 : 
	printf("\n \n \t -->  Ajout d'une Machine ");
	do{ printf("\n\t - Entrer le numero de la machine : ");
    	scanf("%d",&M[NM].num_machine);
    for(i=0,existe=0;i<NM;i++)
    	{ if(M[NM].num_machine==M[i].num_machine)
    	existe=1;
			}
	if(existe==1)
	printf("\t --> LE NUMERO DE MACHINE EXISTE DEJA !! ");
	} while(existe==1);	
	fflush(stdin);
	printf("\n --> Machine %d : ",M[NM].num_machine);
	printf(" \n\t - Descriptif : ");
	gets(M[NM].descriptif); 
	printf("\t - Local : ");
	gets(M[NM].local);
	printf("\n -> MACHINE AJOUTEE !!!");
	NM=NM+1;
break;
	
case 2 : 
    printf("--> \n \n Ajout d'un technicien ");
	do{ printf("\n \t - Entrer le numero du technicien  : ");
    	scanf("%d",&T[NT].num);
    for(i=0,existe=0;i<NT;i++)
    	{ if(T[NT].num==T[i].num)
    	existe=1;
			}
	if(existe==1)
	printf("\t --> LE NUMERO DU TECHNICIEN EXISTE DEJA !! ");
	} while(existe==1);	
	fflush(stdin);
	printf("\n --> Technicien  %d : ",T[NT].num);
    printf("\n\t - Nom : ");
    gets(T[NT].nom);
    printf("\t - Prenom : ");
    gets (T[NT].prenom);
    printf(" \t - Adresse : ");
    gets(T[NT].adresse);
    printf(" \t - Email : ");
    gets(T[NT].email);
    do {
	printf("\t - Numero de telephone : ");
	gets(T[NT].tel);
	m=strlen(T[NT].tel);
	if (m!=10)
	printf("--> LE NUMERO DE TELEPHONE DU NOUVEAU TECHNICIEN EST INCORRECT !!! \n");
	}
	while(m!=10);
	do{
		printf("\t - Date d'emploi (jour/mois/annee) : ");
		L = scanf("%d/%d/%d",&T[NT].DateEmploi.j,&T[NT].DateEmploi.m,&T[NT].DateEmploi.a);
		if (L!=3)
		printf("--> LA DATE D'EMPLOI DU NOUVEAU TECHNICIEN EST INVALIDE !!! \n ");
	}while (L!=3);
	
	NT=NT+1;
break;
case 3:
	printf("\n \t --> Ajout d'un incident ");
	do{ printf("\n \t - Entrer le numero d'incident : ");
    	scanf("%d",&I[NI].num_incident);
    for(i=0,existe=0;i<NI;i++)
    	{ if(I[NI].num_incident==I[i].num_incident)
    	existe=1;
			}
	if(existe==1)
	printf("\t --> LE NUMERO D'INCIDENT  EXISTE DEJA !!! \n ");
	} while(existe==1);	
	do{ printf("\t - Entrer le numero de machine  : ");
    	scanf("%d",&I[NI].num_machine);
    for(i=0,existe=0;i<NM;i++)
    	{ if(I[NI].num_machine==M[i].num_machine)
    	existe=1;
			}
	if(existe==0)
	printf("\t --> LE NUMERO DE MACHINE  N'EXISTE PAS !!! \n ");
	} while(existe==0);	
	do{ printf("\t -  Entrer le numero de Technicien  : ");
    	scanf("%d",&I[NI].num_technicien);
    for(i=0,existe=0;i<NT;i++)
    	{ if(I[NI].num_technicien==T[i].num)
    	existe=1;
			}
	if(existe==0)
	printf("\t --> LE NUMERO DU TECHNICIEN  N'EXISTE PAS !! ");
	} while(existe==0);	
	fflush(stdin);
	printf("\t - Description : ");
	gets(I[NI].description);
	do{
		printf("\t - Date de resolution (jour/ mois/ annee): ");
		L = scanf("%d/%d/%d",&I[NI].DateResolution.j,&I[NI].DateResolution.m,&I[NI].DateResolution.a);
		if (L!=3)
		printf("--> LA DATE DE RESOLUTION DE L'INCIDENT EST INVALIDE !!! \n ");
	}while (L!=3);
	
	NI=NI+1;
	break;
case 4 : 
	printf("\n \t --> Modification d'une machine <-- ");
	do{
		printf("\n \t (1) -> Modifier le numero de machine : ");
		printf("\n \t (2) -> Modifier le descriptif :");
		printf("\n \t (3) -> Modifier le local : ");
		printf("\n \t (4) -> Quitter le choix : ");
		do{
			printf("\n\t --> Entrer votre choix : ");
			scanf("%d",&ch);
			if (ch<1 || ch>4)
			printf("\n--> LE CHOIX EST INVALIDE !!! ");
		}while (ch<1 || ch>4);
		switch (ch) 
			{case 1 :
				printf("\n \n --> Modification du numero de machine : ");
				existe = 1;
				do{
				printf("\n Le numero de machine recherche : ");
				scanf("%d",&R_num);
				for (i=0;i<NM;i++){
				if (M[i].num_machine == R_num){
				existe = 0;
				printf("\n \t -> Nouveau Numero : ");
				scanf("%d",&M[i].num_machine);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO DE MACHINE EST INTROUVABLE !!! ");
				}while (existe == 1);
				break;
			case 2 :
				printf("\n \t --> Modification du descriptif <-- ");
				
				do{
					printf("\n\t - Entrer le numero de machine concernee : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0,existe = 0; i<NM; i++){
						if (M[i].num_machine == R_num){
						existe = 1;
						printf("\t - Entrer le nouveau descriptif : ");
						gets(M[i].descriptif);
					}
					
				}
				if (existe == 0)
				printf("LE NUMERO DE MACHINE EST INTROUVABLE !!! \n");
				}while (existe == 0);
				break;
			case 3 : 
			printf("\n \t --> Modification du local <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de machine : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NM; i++){
						if (M[i].num_machine == R_num){
						existe = 1;
						printf("\t- Entrer le nouveau local : ");
						gets(M[i].local);
					}
				}
				if (existe == 0)
				printf("LE NUMERO DE MACHINE EST INTROUVABLE !!! \n ");
				}while (existe == 0);
				break;
				
			}
				
	}while (ch != 4);
break;
case 5 :
	printf("\n \t --> Modification des techniciens <-- ");
	do{
		printf("\n \t (0) -> Modifier le numero du technicien ");
		printf("\n \t (1) -> Modifier Le nom : ");
		printf("\n \t (2) -> Modifier le prenom ");
		printf("\n \t (3) -> Modifier l'email ");
		printf("\n \t (4) -> Modifier l'adresse ");
		printf("\n \t (5) -> Modifier le numero de telephone ");
		printf("\n \t (6) -> Modidier la date d'emploi du technicien ");
		printf("\n \t (7) -> Quitter le choix ");
		do{
			printf("\n --> Entrer votre choix : ");
			scanf("%d",&ch);
			if (ch<0 || ch >7)
			printf("\n \t --> LE CHOIX EST INVALIDE !!!");
		}while(ch<0 || ch > 7);
		switch (ch) 
			{case 0 :
				printf("\n \n --> Modification du numero de technicien <-- ");
				existe = 1;
				do{
				printf("\n \t - Entrer le numero de technicien : ");
				scanf("%d",&R_num);
				for (i=0;i<NT;i++){
				if (T[i].num == R_num){
				existe = 0;
				printf("\t - Nouveau Numero du technicien : ");
				scanf("%d",&T[i].num);
				}
				}
				if (existe == 1)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! \n ");
				
				}while (existe == 1);
				break;
			case 1 :
				printf("\n \t --> Modification du Nom <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de technicien : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						printf("\t - Entrer le nouveau Nom : ");
						gets(T[i].nom);
					}
					
				}
				if (existe == 0)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! \n");
				}while (existe == 0);
				break;
			case 2 :
				printf("\n \t --> Modification du prenom <-- ");
				
				do{
					printf("\n\t - Entrer le numero du technicien concernee : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0,existe = 0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						printf("\t - Entrer le nouveau prenom : ");
						gets(T[i].prenom);
					}
				}
				if (existe == 0)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! \n");
				}while (existe == 0);
				break;
			case 3 : 
			printf("\n \t --> Modification de l'email <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de technicien : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						printf("\t - Entrer le nouveau email : ");
						gets(T[i].email);
					}
				}
				if (existe == 0)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! \n ");
				}while (existe == 0);
				break;
			case 4 :
				printf("\n \t --> Modification de l'adresse <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de technicien : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						printf("\t - Entrer la nouvelle adresse : ");
						gets(T[i].adresse);
					}
				}
				if (existe == 0)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! \n ");
				}while (existe == 0);
				break;
			case 5 :
				printf("\n \t --> Modification du numero de telephone <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de technicien : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						do{
							printf("\t - Entrer le nouveau numero de telephone : ");
							gets(T[i].tel);
							m = strlen(T[i].tel);
							if (m!= 10)
							printf("LE NUMERO DE TELEPHONE EST INCORRECT !!!\n");
						} while (m!=10);
						
					}
				}
				if (existe == 0)
				printf("LE NUMERO DE TECHNICIEN EST INTROUVABLE !!!\n ");
				}while (existe == 0);
				break;
			case 6 : 
			printf("\n \t --> Modification la date d'emploi du technicien <-- ");
				existe = 0;
				do{
					printf("\n\t - Entrer le numero de technicien : ");
					scanf("%d",&R_num);
					fflush(stdin);
					for (i=0; i<NT; i++){
						if (T[i].num == R_num){
						existe = 1;
						do{
							printf("\t - Entrer la nouvelle date d'emploi (jour/mois/annee) : ");
							L = scanf("%d/%d/%d",&T[i].DateEmploi.j,&T[i].DateEmploi.m,&T[i].DateEmploi.a);
							if (L!=3)
							printf("--> LA DATE D'EMPLOI DU TECHNICIEN EST INVALIDE !!! \n ");
						}while (L!=3);
							
					}
				}
				if (existe == 0)
				printf("\n LE NUMERO DE TECHNICIEN EST INTROUVABLE !!! ");
				}while (existe == 0);
				break;
			
			
			}
	}while (ch!= 7);
break;
case 6 : 
printf("\n \t --> Modification de l'incident  <-- ");
	do{
		printf("\n \t (0) -> Modifier le numero de machine de l'incident  ");
		printf("\n \t (1) -> Modifier Le numero du technicien de l'incident  ");
		printf("\n \t (2) -> Modifier la description de l'incident  ");
		printf("\n \t (3) -> Modifier la date de resolution de l'incident ");
		printf("\n \t (4) -> Modifier le numero d'incident ");
		printf("\n \t (5) -> Quitter le choix ");
		do{
			printf("\n --> Entrer votre choix : ");
			scanf("%d",&ch);
			if (ch<0 || ch >5)
			printf("\n \t --> LE CHOIX EST INVALIDE !!!");
		}while(ch<0 || ch > 5);
		switch (ch)
		{  case 0 :
				printf("\n \n --> Modification du numero de machine de l'incidnt : ");
				existe = 1;
				do{
				printf("\nLe numero de machine recherche : ");
				scanf("%d",&R_num);
				for (i=0;i<NI;i++){
				if (I[i].num_machine == R_num){
				existe = 0;
				printf("\nNouveau Numero de machine  : ");
				scanf("%d",&I[i].num_machine);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO DE MACHINE EST INTROUVABLE !!! ");
				
				}while (existe == 1);
				break;
			case 1 :
				printf("\n \n --> Modification du numero de technicien : ");
				existe = 1;
				do{
				printf("\nLe numero de technicien recherche : ");
				scanf("%d",&R_num);
				for (i=0;i<NI;i++){
				if (I[i].num_technicien == R_num){
				existe = 0;
				printf("\nNouveau Numero de technicien  : ");
				scanf("%d",&I[i].num_technicien);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO DE TECHNICIEN EST INTROUVABLE !!! ");
				
				}while (existe == 1);
				break;
			case 2 :
				printf("\n \n --> Modification de la description  : ");
				existe = 1;
				do{
				printf("\nLe numero de l'incident concerne : ");
				scanf("%d",&R_num);
				fflush(stdin);
				for (i=0;i<NI;i++){
				if (I[i].num_incident == R_num){
				existe = 0;
				printf("\n Nouveau Description   : ");
				gets(I[i].description);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO DE L'INCIDENT EST INTROUVABLE !!! ");
				
				}while (existe == 1);
				break;	
			case 3 :
			printf("\n \n --> Modification de la date de resolution   : ");
				existe = 1;
				do{
				printf("\nLe numero de l'incident  recherche : ");
				scanf("%d",&R_num);
				fflush(stdin);
				for (i=0;i<NI;i++){
				if (I[i].num_incident == R_num){
				existe = 0;
				do{
					printf("\n la nouvelle date de resolution (jour/mois/annee)   : ");
					L = scanf("%d/%d/%d",&I[i].DateResolution.j,&I[i].DateResolution.m,&I[i].DateResolution.a);
					if (L!=3)
					printf("--> LA DATE DE RESOLUTION DE L'INCIDENT EST INVALIDE !!! \n ");
				}while (L!=3);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO DE L'INCIDENT EST INTROUVABLE !!! ");
				
				}while (existe == 1);
				break;	
			case 4 :
				
				printf("\n \n --> Modification du numero d'incident : ");
				existe = 1;
				do{
				printf("\nLe numero d'incident recherche : ");
				scanf("%d",&R_num);
				for (i=0;i<NI;i++){
				if (I[i].num_incident == R_num){
				existe = 0;
				printf("\nNouveau Numero d'incident  : ");
				scanf("%d",&I[i].num_incident);
				}
				}
				if (existe == 1)
				printf("\nLE NUMERO D'INCIDENT EST INTROUVABLE !!! ");
				
				}while (existe == 1);
				break;		
		
	}
		
	}while(ch!=5);
break;
case 7 :
	printf("\n\n --> Suppression d'une machine <--");
	existe = 0;
	do{
		printf("\nEntrer le numero de machine : ");
		scanf("%d",&R_num);
		for (i=0; i<NM && existe == 0; i++){
			if (M[i].num_machine == R_num){
				existe = 1;
				for (j=i; j<NM-1; j++){
					M[j] = M[j+1];
				}
			}
		}
		if (existe == 1){
			printf("\t --> La machine a ete suppprime avec succes !!! \n");
			NM = NM - 1;
		}
		
	}while (existe == 0);
break;
case 8 :
	printf("\n\n --> Suppression d'un technicien <--");
	existe = 0;
	do{
		printf("\nEntrer le numero du technicien : ");
		scanf("%d",&R_num);
		for (i=0; i<NT && existe == 0; i++){
			if (T[i].num == R_num){
				existe = 1;
				for (j=i; j<NT-1; j++){
					T[j] = T[j+1];
				}
			}
		}
		if (existe == 1){
			printf("\t --> Le technicien a ete suppprime avec succes  !!! \n");
			NT = NT - 1;
		}
		
	}while (existe == 0);
break;
case 9 :
printf("\n\n --> Suppression d'un incident <--");
	existe = 0;
	do{
		printf("\nEntrer le numero de l'incident : ");
		scanf("%d",&R_num);
		for (i=0; i<NI && existe == 0; i++){
			if (I[i].num_incident == R_num){
				existe = 1;
				for (j=i; j<NI-1; j++){
					I[j] = I[j+1];
				}
			}
		}
		if (existe == 1){
			printf("\t --> L'incident a ete suppprime avec succes !!! \n");
			NI = NI - 1;
		}
		
	}while (existe == 0);
break;
case 10:
	printf("\n\n --> Affichage d'une machine <-- ");
	existe = 0;
	do{
		printf("\nEntrer le numero de machine : ");
		scanf("%d",&R_num);
		for (i=0; i<NM; i++){
			if (M[i].num_machine == R_num){
				existe = 1;
				printf("\t - Numero de machine : %d ",M[i].num_machine);
				printf("\t - Descriptif : %s ",M[i].descriptif);
				printf("\t - Local : %s ",M[i].local);
			}
			
		}
		if (existe == 0)
		printf("\t --> LE NUMERO DE MACHINE N'EXISTE PAS !!! \n");
	}while (existe == 0);
break;
case 11 :
	printf("\n\n --> Affichage d'un technicien <-- ");
	existe = 0;
	do{
		printf("\nEntrer le numero de technicien : ");
		scanf("%d",&R_num);
		for (i=0; i<NT; i++){
			if (T[i].num == R_num){
				existe = 1;
				printf("\t - Numero du technicien : %d ",T[i].num);
				printf("\t - Nom : %s ",T[i].nom);
				printf("\t - Prenom : %s ",T[i].prenom);
				printf("\t - Adresse : %s ",T[i].adresse);
				printf("\t - Email : %s ",T[i].email);
				printf("\t - Numero de telephone : %s ",T[i].tel);
				printf("\t - Date d'emploi : %d/%d/%d ",T[i].DateEmploi.j,T[i].DateEmploi.m,T[i].DateEmploi.a);
			}
			
		}
		if (existe == 0)
		printf("\t --> LE NUMERO DU TECHNICIEN N'EXISTE PAS !!! \n");
	}while (existe == 0);
break;
case 12 : 
	printf("\n\n --> Affichage de l'incident <-- ");
	existe = 0;
	do{
		printf("\nEntrer le numero de l'incident : ");
		scanf("%d",&R_num);
		for (i=0; i<NI; i++){
			if (I[i].num_incident == R_num){
				existe = 1;
				printf("\n \t - Numero de l'incident : %d ",I[i].num_incident);
				printf("\n\t - Numero du technicien de l'incident : %d ",I[i].num_technicien);
				printf("\n\t - Numero de la machine de l'incident : %d ",I[i].num_machine);
				printf("\n\t - Description : %s ",I[i].description);
				printf("\n\t - Date de resolution de l'incident : %d/%d/%d ",I[i].DateResolution.j,I[i].DateResolution.m,I[i].DateResolution.a);
			}		
		}
		if (existe == 0)
		printf("\t --> LE NUMERO DE L'INCIDENT N'EXISTE PAS !!! \n");
	}while (existe == 0);
break;
	
}
}while(choix != 13);
printf("\n\n --------FIN DU PROGRAMME ---------");
}
