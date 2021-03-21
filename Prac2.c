//Programado por el equipo DreamPower
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void printFileProperties(struct stat stats);

int main(int argc, char* argv[]) {
    struct stat stats;
    struct dirent *de;
    //Paso 1
    /*for(int i = 0;i < argc;i++)
        printf("arg %d : %s\n",i,argv[i]);
        */
    int check;
    if(argc == 3)
    {
	DIR* dir = opendir(argv[1]);
	DIR* dirPDirectory = opendir(".");
	char aux[50];
	if (dir) //Se ejecuta solo si el directorio ya existe
	{
	    printf("\nYa existe el Directorio\nIngresa otro nombre: ");
	    scanf("%s", &aux);
	    argv[1] = aux;
	}
    check = mkdir(argv[1], 0777);
    
    // check if it is actually created
    // mkdir returns 0 if its completion is successful
    if(!check)
    {
    	printf("Directory created\n");
    	dirPDirectory = opendir(".");
    	dir = opendir(argv[1]);
    	if(dir)
    	{
	    char instruccion[100];
	    sprintf(instruccion, "echo 'Blengio Landin Guillermo' >> ./%s/%s", argv[1], argv[2]);
	    system(instruccion);
	    sprintf(instruccion, "echo 'Gomez de Segura Gonzalez AAr0n' >> ./%s/%s", argv[1], argv[2]);
	    system(instruccion);
	    sprintf(instruccion, "echo 'Guerrero Avila Carlos' >> ./%s/%s", argv[1], argv[2]);
	    system(instruccion);
	    sprintf(instruccion, "echo 'Gutierrez Martinez Braulio Rodrigo' >> ./%s/%s", argv[1], argv[2]);
	    system(instruccion);
	    char ruta_origen[100];
	    strcat(ruta_origen, "./");
	    strcat(ruta_origen, argv[1]);
	    strcat(ruta_origen, "/");
	    strcat(ruta_origen, argv[2]);
	    if(!link(ruta_origen,"./LinkFisico"))
	        printf("Link Fisico Creado\n");
	    else
	        printf("Link Fisico no creado\n");
            if(!symlink(ruta_origen,"./LinkSimbolico"))
	        printf("Link Simbolico Creado\n");
	    else
	        printf("Link Simbolico no creado\n");
	    if (stat(ruta_origen, &stats) == 0)
	    {
	    	printf("Lista de los atributos del archivo creado:\n");
	    	printf("------------------------------------\n"); 
		printFileProperties(stats);
		printf("------------------------------------\n"); 
	    }
	    printf("Lista de atributos de todas las entradas del directorio actual\n");
	    while ((de = readdir(dirPDirectory)) != NULL)
	    {
	    	printf("--------------\n");
	    	printf("Nombre: %s\n", de->d_name);
	    	printf("Inode: %ld\n", de->d_ino);
	    }
    	}
    	else
    	    printf("Directorio no abierto");
    }
    // mkdir returns -1 otherwise
    else
    	{
    	    printf("Directory not created\n");
    	}	
    }
    else
    	printf("Numero de argumentos incorrecto");
    
    return 0;
    
}

void printFileProperties(struct stat stats)
{
    printf("\nFile size: %ld bytes", stats.st_size);
    printf("\nInode: %ld", stats.st_ino);
    printf("\nNumero de enlaces %lu\n", stats.st_nlink);
}