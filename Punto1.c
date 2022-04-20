#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;


Tarea* BuscarTarea(char [], struct Tarea**, struct Tarea** , int , int);



int main(){
    srand(time(NULL));
    Tarea **Tareas, **TareasListas, **TareasNListas ;
    int cantidadT;
    int j=0;
    int z=0;
    char palabra[10];
    printf("Cuantas tarea desea ingresar?\n");
    scanf("%i",&cantidadT);
    Tareas = (Tarea **)malloc(cantidadT * sizeof(Tarea *));
    for (int i = 0; i < cantidadT; i++)
    {
        Tareas[i]  = (Tarea *)malloc(sizeof(Tarea)); 
        Tareas[i]->TareaID = i+1;
        Tareas[i]->Descripcion = (char *)malloc(500);
        printf("Haga la descripcion a la tarea \n");
        fflush(stdin);
        gets(Tareas[i]->Descripcion);
        fflush(stdin);
        Tareas[i]->Duracion = rand()%91 + 10;
    }
    TareasListas = (Tarea **)malloc(cantidadT * sizeof(Tarea *));
    TareasNListas = (Tarea **)malloc(cantidadT * sizeof(Tarea *));

    for (int i = 0; i < cantidadT; i++)
    {
        
        TareasListas[i] = NULL;
    }
    for (int i = 0; i < cantidadT; i++)
    {
        
        TareasNListas[i] = NULL;
    }
    printf("Lista de Tareas \n");
    for (int i = 0; i < cantidadT; i++)
    {
        printf("El id de la tarea es : %d \n", Tareas[i]->TareaID);
        fflush(stdin);
        printf("La descripcion de la tarea es: \n");
        fflush(stdin);
        puts(Tareas[i]->Descripcion);
        fflush(stdin);
        printf("La duracion es de %d \n", Tareas[i]->Duracion);
        char opc;
        
        printf("La tarea esta completada? Si esta completada ingrese: Y(si) o N(No)\n");
        scanf("%c",&opc);
        if (opc == 'Y')
        {
            TareasListas[j] = Tareas[i];
            Tareas[i] = NULL;
            j++;
        }else
        {
            TareasNListas[z] = Tareas[i];
            Tareas[i] = NULL;
            z++;
        }
        
        

    }
    printf("Mostraremos cada una de las tareas realizadas \n");
    for (int i = 0; i < j; i++)
    {
        if (TareasListas[i] == NULL)
        {
            /* code */
        }else
        {
            printf("El id de la tarea es : %d \n", TareasListas[i]->TareaID);
            printf("La descripcion de la tarea es: \n");
       
            puts(TareasListas[i]->Descripcion);
       
            printf("La duracion es de %d \n", TareasListas[i]->Duracion);
        }
        
        
       
    }
    printf("Mostraremos cada una de las tareas NO realizadas \n");
    for (int i = 0; i < z; i++)
    {
        if (TareasNListas[i] == NULL)
        {
            /* code */
        }else
        {
            printf("El id de la tarea es : %d \n", TareasNListas[i]->TareaID);
            printf("La descripcion de la tarea es: \n");
            
            puts(TareasNListas[i]->Descripcion);
        
            printf("La duracion es de %d \n", TareasNListas[i]->Duracion);
        }
        
        
        
    }
    
    
    
    
    




    
    
    
    
    
    printf("Ingrese la palabra a buscar en la descripcion\n");
    fflush(stdin);
    gets(palabra);
    if (BuscarTarea(palabra , TareasNListas , TareasListas, z , j) == NULL)
    {
        printf("La Tarea no se encontro o no existe\n");
    }else
    {
        printf("La tarea se encontro y es:\n");
        puts(BuscarTarea(palabra , TareasNListas , TareasListas, z , j)->Descripcion);
    }
    
    


    return 0;
}
Tarea* BuscarTarea(char palabrea[], struct Tarea** TareasNListas, struct Tarea**TareasListas , int z, int j){
    for (int i = 0; i < z; i++)
    {
        if (TareasNListas[i] == NULL)
        {
            /* code */
        }else
        {
            if (strstr(TareasNListas[i]->Descripcion,palabrea) != NULL)
            {
                return TareasNListas[i];
            }
            
        }
        
        
    }
     for (int i = 0; i < j; i++)
    {
        if (TareasListas[i] == NULL)
        {
            /* code */
        }else
        {
            if (strstr(TareasListas[i]->Descripcion,palabrea) != NULL)
            {
                return TareasListas[i];
            }
            
        }
        
        
    }
    return NULL;
    

}