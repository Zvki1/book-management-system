#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef struct chapitre
{
    int id;
    char titrechap[30];
    int nbpages;
    char contenu[500];
    char titrechapsuiv[50];
} chap; //declaration de lenregistrement chapitre


typedef struct liste*  pliste; //declaration type de pointeur vers le maillon de la liste (chapitre)

typedef struct liste
{
    chap info;
    pliste suiv;
} cellule; // declaration de maillon (chapitre)



bool check(pliste tete,int pos)
{
    int i=0;
    while(tete != NULL)
    {
        i++;
        tete=tete->suiv;
    }
    if(pos>=1 && pos<= i+1) return true;

    else  return false;

}
bool checksup(pliste tete,int pos)
{
    int i=0;
    while(tete != NULL)
    {
        i++;
        tete=tete->suiv;
    }
    if(pos>=1 && pos<i+1) return true;

    else  return false;

}


void inser(pliste *t,int pos) // fonction ajouter un chapitre
{
    char tempchar;
    char inter[300];
    pliste temp=*t;
    pliste nouv=NULL;
    int i=1;
    int j=0;
debut :
    if (check(*t,pos)==true)
    {
        // if tete !=NULL
        nouv=malloc(sizeof(cellule));
        (nouv->info).id=pos;
        printf("----------------------------Important: il faut remplacer l'espace ' ' par '_' pendant la saisie ---------------------- \n");
        printf("entrez le titre : ");
        scanf("%s",(nouv->info).titrechap);
        printf("entrez le nombres de pages : ");
        scanf("%d",&((nouv)->info).nbpages);
        printf("entrez le contenu : ");
        scanf("%s",(nouv->info).contenu);

        if(pos==1 || *t==NULL)
        {
            if(*t==NULL) strcpy((nouv->info).titrechapsuiv,(nouv->info).titrechap);

            else  strcpy((nouv->info).titrechapsuiv,((*t)->info).titrechap);


            nouv->suiv=*t;

            *t=nouv;

        }
        else
        {
            while(temp!=NULL&&i!=pos-1)
            {
                temp=temp->suiv;
                i++;
            }
            nouv->suiv=temp->suiv;
            temp->suiv=nouv;
            strcpy((temp->info).titrechapsuiv,(nouv->info).titrechap);
            if(nouv->suiv==NULL)  strcpy((nouv->info).titrechapsuiv,((*t)->info).titrechap);
            else strcpy((nouv->info).titrechapsuiv,((nouv->suiv)->info).titrechap);
        }
    }

    else // ecrire les info
    {
        printf("position non valide,entrez une nouvelle position : ");
        scanf("%d",&pos);
        goto debut;
    }
    temp=nouv->suiv;
    // (nouv->info).id=pos;
    while(temp != NULL)
    {
        (temp->info).id++ ;
        temp=temp->suiv;
    }
}



void aff(pliste tete)
{
if(tete==NULL) printf("la liste vide \n \n");

    else
    {

    pliste temp2;

    temp2=tete;
    while(temp2!=NULL)
    {
        printf("id = %d \n",(temp2->info).id);
        printf("le titre: ");
        puts((temp2->info).titrechap);
        printf("nbpages = %d \n",(temp2->info).nbpages);
        printf("le contenu: ");
        puts((temp2->info).contenu);
        printf("le titre du chapsuiv: ");
        puts((temp2->info).titrechapsuiv);

        temp2=temp2->suiv;
        printf("\n\n\n");
    }
    }
}


void modifcontent(pliste t,int idch){
    char ch[500];
    if(t==NULL){
        printf("erreur le livre est vide \n");
    }else{

    printf("entrez le nouveau contenu \n");
    scanf("%s",ch);

    while( (t!=NULL) && ((t->info).id !=idch)  ){
        t=t->suiv;
    }if(t==NULL){
    printf("position incorrect \n");
    }else strcpy((t->info).contenu,ch);
    //(p->info).contenu=ch;
    }
    }

 int nbpages(pliste t)
            {

                if(t==NULL)
                {
                    return 0;
                }
                else
                {
                    return (t->info).nbpages + nbpages(t->suiv);
                }
            }

void create_insert (pliste *T)
{
    pliste P,Q,C;
    int n,i,nc;
    if (*T==NULL) //Creation FIFO si la liste est vide
    {
        printf("Donner le nombre de chapitres");
        scanf("%d",&n);
        *T = malloc(sizeof(cellule)); //la tete
        printf("entrez le titre");
        scanf("%s",((*T)->info).titrechap);
        printf("entrez le nombres de pages");
        scanf("%d",&((*T)->info).nbpages);
        printf("entrez le contenu ");
        scanf("%s",((*T)->info).contenu);

        //scanf("%s",((*T)->info).titrechapsuiv);
        ((*T)->info).id=1;
        Q = *T;
        for(i=1; i<n; i++) //boucle de creation
        {
            P = malloc(sizeof(cellule));
            scanf("%s",(P->info).titrechap);
            scanf("%d",&(P->info).nbpages);
            scanf("%s",(P->info).contenu);
            scanf("%s",(P->info).titrechapsuiv);
            (P->info).id=i+2;
            Q->suiv=P;
            Q=P;
        }
        Q->suiv=NULL; //fin de la liste
    }
    else //insertion
    {
        printf("Donner le numero du chapitre : ");
        scanf("%d",&nc);
        P = malloc(sizeof(cellule)); //Créer l'element
        printf("Le numero du chapitre : ");
        scanf("%d",&(P->info).id);
        printf("Le titre du chapitre : ");
        scanf("%s",(P->info).titrechap);
        printf("Le Nombre des pages du chapitre : ");
        scanf("%d",&(P->info).nbpages);
        printf("Contenu du chapitre : ");
        scanf("%s",(P->info).contenu);
        printf("Titre du chapitre suivant : ");
        scanf("%s",(P->info).titrechapsuiv);
        if (nc==1) //insertion au debut
        {
            P->suiv=*T;
            *T=P;
        }
        else
        {
            Q=*T;
            C=(*T)->suiv;
            while(C!=NULL && ((P->info).id)>(C->info).id) //chercher la position
            {
                Q=C;
                C=C->suiv;
            }
            P->suiv=Q->suiv;  //insertion au milieu ou à la fin
            Q->suiv=P;
        }
    }
}

void maxchapitre(pliste t){
    if(t==NULL){
        printf("La liste est vide \n");
    }else{
    pliste temp=t;
   int max=(t->info).nbpages;
   while(temp != NULL){

    if((temp->info).nbpages > max){
            max=(temp->info).nbpages;
    }
    temp=temp->suiv;
   } // on a trouver le maximum  des nbpages

    temp=t;
    while( (temp != NULL) && ((temp->info).nbpages != max) ) {
        temp=temp->suiv;
    } // ona trouver le plus grand chap

    printf("les informations du plus grand chapitre: \n");

    printf("id = %d \n",(temp->info).id);
        printf("le titre: ");
        puts((temp->info).titrechap);
        printf("le nombre de pages: ");
        printf("nbpages = %d \n",(temp->info).nbpages);
        printf("le contenu: ");
        puts((temp->info).contenu);
        printf("le titre du chapitre suivant: ");
        puts((temp->info).titrechapsuiv);

        }

}


void f_m(pliste t,chap *mini){

    if(t!=NULL)
    {
        if(((t->info).nbpages)< (*mini).nbpages) *mini=t->info;
    f_m(t->suiv,mini);
    }


}

void minchap(pliste t){

     if(t==NULL) printf("liste est vide\n");
     else{
        chap mini=t->info;
        f_m(t->suiv,&mini);
        printf("les informations du plus petit chapitre: \n");

    printf("id = %d \n",mini.id);
        printf("le titre: ");
        puts(mini.titrechap);
        printf("le nombre de pages: ");
        printf("nbpages = %d \n",mini.nbpages);
        printf("le contenu: ");
        puts(mini.contenu);
        printf("le titre du chapitre suivant: ");
        puts(mini.titrechapsuiv);
     }
 }

void supprimer(pliste *t,int pos){

    if(*t==NULL){
        printf("le livre est vide \n");
    }else{
    // printf("je suis la \n");
    debut2 :
    if (checksup(*t,pos)==true)
    {
        if(*t==NULL)
        {

            printf("la liste est vide \n");
        }
        else if(pos==1)
        {
            pliste p;
            p=(*t)->suiv;
            free(*t);
            *t=p;
            while(p!= NULL)
            {

                (p->info).id=(p->info).id-1;
                p=p->suiv;
            }
            p=*t;
            if(p!=NULL)
            {
                while(p->suiv!=NULL)
                {
                    p=p->suiv;
                }
                strcpy((p->info).titrechapsuiv,((*t)->info).titrechap);
            }
            printf("chapitre supprime \n");

        }
        else if(pos>1)
        {
            int i;
            pliste p,q;
            q=*t;
            p=(*t)->suiv;

            for(i=1; i<(pos-1); i++)
            {
                q=q->suiv;
                p=p->suiv;
            }
            q->suiv=p->suiv;

            if(p->suiv==NULL)
            {
                strcpy((q->info).titrechapsuiv,((*t)->info).titrechap);
            }
            else
            {

                strcpy((q->info).titrechapsuiv,((p->suiv)->info).titrechap);
            }

            q=q->suiv;
            while(q!=NULL)
            {
                (q->info).id=(q->info).id -1;
                q=q->suiv;
            }
            free(p);
            printf("chapitre supprime \n");
        }

    }
    else
    {
        printf("Ce chapitre n'existe pas, entrez une nouvelle position: ");
        scanf("%d",&pos);
        goto debut2 ;
    }
    }
}


void affichechappg (pliste T)
{
    if(T==NULL){
        printf("La livre est vide \n");
    }else{
    int n,i,j;
    pliste P=T;
    printf("Donner le nombre de chapitres : ");
        scanf("%d",&n);
        chap tab[n];
        chap tmp;
        i=0;
        while ( P != NULL ) // stocker les chapitres dans un tableau d'enregistrements
        {
            tab[i] = P->info;
            P = P->suiv;
            i = i+1;
        }
        for (i=0;i<n;i++) //trier le tableau
        {
            for(j=i+1;j<n;j++)
            {
                if (tab[i].nbpages>tab[j].nbpages)
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }
            }
        }
        for (i=0;i<n;i++) //affichage des titres des chapitres selon nombre de pages en ordre croissant
        {
        printf("%d - le titre %s \n",i+1, tab[i].titrechap );
        printf("nbpages = %d \n",tab[i].nbpages);
        printf("le contenu: ");
        puts(tab[i].contenu);
        printf("titre du chapitre suivant");
        puts(tab[i].titrechapsuiv);
        printf("\n");

        }
    }
}


int main()
{

    int possup;
    int position;
 pliste tete=NULL;
  int n,pos;

   while(n!=10){
          //  printf("olaaaa");

          printf("\n");
    printf("------------------------menu-------------\n");
       // printf("\n");
        printf("1- Ajouter un chapitre \n");
        printf("2-afficher les chapitres selon id (ordre croissant) \n");
         printf("3-afficher le nombre de pages \n");
         printf("4-modifier le contenu d'un chapitre  \n");
         printf("5-afficher les informations du plus grand chapitre  \n");
         printf("6-les informations du plus petit chapitre  \n");
         printf("7-supprimer un chapitre  \n");
        printf("8-affiche selon nombre de pages (ordre croissant) \n");
        printf("9-clear screen \n");



         printf("10-exit \n");


        printf("\n");
        printf(" veuilez choisire une fonction : ");
        scanf("%d",&n);

         switch (n) //debut du case
            {
            case 1:
                printf("entre la position du chapitre : ");
                scanf("%d",&pos);
                inser(&tete,pos);
                break;

             case 2:
            aff(tete);
                break;

            case 3:
                    printf("le nombre de pages est: %d \n",nbpages(tete));
//                printf(" Si vous voulez Supprimer le premier chapitre appuyez sur '1' \n");
//                printf(" Si vous voulez Supprimer le dernier chapitre appuyez sur '2' \n");
//                printf(" Si vous voulez Supprimer le  n-eme chapitre appuyez sur '3' \n");
//                scanf("%d",&n);
//                if (n==3)
//                {
//                    printf("Entrez le numero du chapitre a supprimer \n");
//                    scanf("%d",&num_chap);
//
//                }
              break;
//
            case 4:

                printf("entrez la position du chapitres a modifier ");
                scanf("%d",&position);
                modifcontent(tete,position);
//                printf("Entrez l'ID du chapitre a modifier \n");
//                scanf("%d",&id);
//
              break;
//
//            case 5:
//                //affichage du nb de pages de livre
//                break;
//


            case 5:
                maxchapitre(tete);

                 break;
            case 6:

                minchap(tete);
                break;
            case 7:

                printf("entrez la position du chapitre a suprimer:  ");
                scanf("%d",&possup);

                supprimer(&tete,possup);

                break;

                     case 8:
            affichechappg (tete);
            break;

         case 9:
              system("cls");

//                printf("si vous voulez afficher les informations du plus grand chapitre appuez sur '1' \n");
//                printf("si vous voulez afficher les informations du plus petit chapitre appuez sur '2' \n");
//                scanf("%d",&n);
//
               break;

         case 10:
            exit(0);
            break;

                /*...
                default:
                statement; */
            }  // fin du switch
                    printf("10-Sortir          1-Afficher le menu: \n");
                    scanf("%d",&n);


        }//fin du while









    return 0;
}
