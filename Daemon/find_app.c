/*
** Programme pour chercher la version d'une application que détient un utilisateur dans son système
** Ludovic & Gabriel
** 24/12/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find_app.h"

#define MAX_VERSION 20

char * find_version_app(char *path_app)
{
    long size;  //taille de l'application
    char *array; //tableau qui contiendra tous les octets du fichier .exe
    char *product_version = "ProductVersion"; //dans le ficher .exe donné, sa version est donnée juste après cette chaine de caractères
    char found = 0;
    int i;
    char * version_app;   //on stocke la version dans ce tableau

    FILE *pf = fopen(path_app, "rb");
    if(pf == NULL) {
        printf("\nError: file not found\n");
        return NULL;
    }
    fseek(pf, 0, SEEK_END);
    size = ftell(pf);
    array = malloc(sizeof(char) * size);
    fseek(pf, 0, SEEK_SET);
    fread(array, sizeof(char), size, pf);
    fclose(pf);

    /* RECHERCHE DE PRODUCTVERSION*/
    for(i = 0; i < size - 2 * strlen(product_version); i++) {
        char found2 = 1;
        for(int j = 0; j < strlen(product_version); j++){
            if (array[i+2*j] != product_version[j] || array[i+2*j+1] != 0) {
                found2 = 0;
                break;
            }
        }
        if (found2) {
                found = 1;
                break;
            }
    }
    if(!found) { //si on n'a pas trouvé "ProductVersion", c'est que la version est introuvable
        printf("\nError: version not found\n");
        free(array);
        return NULL;
    }

    version_app = malloc((sizeof(char)) * (MAX_VERSION + 1));
    i = i + 2 * strlen(product_version);
    int k = 0;

    /*RECUPERATION DE LA VERSION SITUEE APRES PRODUCTVERSION*/
    while(array[i] == '\0' || array[i] == '.' || (array[i] >= '0' && array[i] <= '9')){
            if (array[i] == '\0')
                i++;
            else if (array[i] == '.'){
                version_app[k] = array[i];
                i++;
                k++;
            }
            else{
                version_app[k] = array[i];
                i++;
                k++;
            }
            if (k > MAX_VERSION) {
                printf("\nError: version too long\n");
                free(array);
                free(version_app);
                return NULL;
            }
          }
    k = 0;
    while(version_app[k] == '.' || (version_app[k] >= '0' && version_app[k] <= '9')){
        k++;
    }
    version_app[k] = '\0';
    free(array);
    return version_app;
}
char *find_exe_app(char *path_app)
{
    char *is_exec;
    /*VERIFICATION SI FICHIER EST BIEN UN EXECUTABLE*/
    if((is_exec = strstr(path_app, ".exe")) == NULL){
        printf("\nError: file is not an executable one");
        return "not_exec";
    }
    char *inter;
    int count = 0; //compteur pour la taille du nom de fichier de l'executable

    /*ON COMPTE LE NOMBRE D'OCTETS DU NOM DE L'EXECUTABLE*/
    for(int i = 0; i < strlen(path_app); i++){
        count++;
        if(path_app[i] == '\\') count = 0;
        if(path_app[i] == '.'){
            count = count + 3; //on prend en compte les 3 lettres dans ".exe"
            break;
        }
    }

    /*RECUPERATION DU NOM DU FICHIER*/
    char *name_exe = malloc(sizeof(char) * (count +1)); //+1 car il faut compter le 0 de fin de chaine
    for(int i = 0; i < strlen(path_app); i++){
        if(path_app[i] == '\\') inter = &path_app[i+1];
        if(path_app[i] == '.'){
            strcpy(name_exe, inter);
            break;
        }
    }
    return name_exe;
}
