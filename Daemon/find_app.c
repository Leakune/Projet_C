/*
** Programme pour chercher la version d'une application que détient un utilisateur dans son système
** Ludovic & Gabriel
** 24/12/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find_app.h"

void find_app(char *path_app)
{
    long size;  //taille de l'application
    char *array;
    char *product_version = "ProductVersion";
    char found = 0;
    char found2;
    int i;
    char version_app [20];

    FILE *pf = fopen(path_app, "rb");
    if(pf == NULL)
        printf("\nError: file not found\n");
    else{
    printf("\nFile found!\n %s\n", path_app);
    fseek(pf, 0, SEEK_END);
    size = ftell(pf);
    array = malloc(sizeof(char) * size);
    fseek(pf, 0, SEEK_SET);
    fread(array, sizeof(char), size, pf);
    fclose(pf);

    for(i = 0; i < size - 2 * strlen(product_version); i++) {
        found2 = 1;
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
    i = i + 2 * strlen(product_version);
    int k = 0;
    while(array[i] == '\0' || array[i] == '.' || array[i] == '0' || array[i] == '1' || array[i] == '2'
          || array[i] == '3' || array[i] == '4' || array[i] == '5' || array[i] == '6' || array[i] == '7'
          || array[i] == '8' || array[i] == '9'){
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
          }
    k = 0;
    while(version_app[k] == '.' || (version_app[k] >= '0' && version_app[k] <= '9')){
        k++;
    }
    version_app[k] = '\0';
    printf("The version: %s", version_app);
    free(array);
    }
}
