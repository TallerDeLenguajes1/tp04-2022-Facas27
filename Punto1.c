#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;


Nodo * CrearNodo(Nodo *, Tarea  );
Nodo * BuscarPorID(int ,Nodo * , Nodo *, int , int );
Nodo * BuscarPalabra(char [], Nodo *, Nodo* , int , int);



int main(){
    srand(time(NULL));
    int cantidadT;
    int j=0;
    int z=0;
    int id;
    char palabra[20];
    printf("Cuantas tarea desea ingresar?\n");
    scanf("%i",&cantidadT);
    Nodo * TareasAHacer;
    TareasAHacer = NULL;
    for (int i = 0; i < cantidadT; i++)
    {
        Tarea Tareas;
        
       Tareas.TareaID = i+1;
        Tareas.Descripcion = (char *)malloc(500);
        printf("Haga la descripcion a la tarea \n");
        fflush(stdin);
        gets(Tareas.Descripcion);
        fflush(stdin);
        Tareas.Duracion = rand()%91 + 10;
        TareasAHacer  = CrearNodo(TareasAHacer , Tareas);

    }
     Nodo *Tareaslistas, *TareasNlistas;
     Tareaslistas = NULL;
     TareasNlistas = NULL;
   
    
    printf("Lista de Tareas \n");
    for (int i = 0; i < cantidadT; i++)
    {
        printf("El id de la tarea es : %d \n", TareasAHacer->T.TareaID);
        fflush(stdin);
        printf("La descripcion de la tarea es: \n");
        fflush(stdin);
        puts(TareasAHacer->T.Descripcion);
        fflush(stdin);
        printf("La duracion es de %d \n", TareasAHacer->T.Duracion);
        char opc;
        
        printf("La tarea esta completada? Si esta completada ingrese: Y(si) o N(No)\n");
        scanf("%c",&opc);
        if (opc == 'Y')
        {
            Tareaslistas  = CrearNodo(Tareaslistas , TareasAHacer->T);
            
            j++;
        }else
        {
            TareasNlistas = CrearNodo(TareasNlistas , TareasAHacer->T);
            z++;
        }
        
        TareasAHacer = TareasAHacer->Siguiente;
     
        
        

    }
    printf("Ingrese el ID para buscar una tarea\n");
    scanf("%i",&id);
    if (BuscarPorID(id,TareasNlistas , Tareaslistas , z , j) == NULL)
    {
        printf("La tarea no se encontro o  no existe\n");
    }else
    {
        printf("La tareas es: \n");
        puts(BuscarPorID(id,TareasNlistas , Tareaslistas , z , j )->T.Descripcion);
    }

    printf("Ingrese la palabra a buscar en la descripcion\n");
    fflush(stdin);
    gets(palabra);
    fflush(stdin);
    if (BuscarPalabra(palabra , TareasNlistas , Tareaslistas, z , j) == NULL)
    {
        printf("La Tarea no se encontro o no existe\n");
     }else
     {
        printf("La tarea se encontro y es:\n");
        puts(BuscarPalabra(palabra , TareasNlistas , Tareaslistas, z , j)->T.Descripcion);
     }
    printf("Mostraremos cada una de las tareas realizadas \n");
    for (int i = 0; i < j; i++)
    {
        if (Tareaslistas == NULL)
        {
            printf("La lista esta vacia \n");
        }else
        {
            while (Tareaslistas != NULL)
            {
                printf("El id de la tarea es : %d \n", Tareaslistas->T.TareaID);
                printf("La descripcion de la tarea es: \n");
       
                puts(Tareaslistas->T.Descripcion);
       
                printf("La duracion es de %d \n", Tareaslistas->T.Duracion);
                Tareaslistas = Tareaslistas->Siguiente;
            }
            
        }
        
        
       
    }
    printf("Mostraremos cada una de las tareas NO realizadas \n");
    for (int i = 0; i < z; i++)
    {
        if (TareasNlistas == NULL)
        {
            printf("La lista esta vacia \n");
        }else
        {
            while (TareasNlistas != NULL)
            {
                printf("El id de la tarea es : %d \n", TareasNlistas->T.TareaID);
                printf("La descripcion de la tarea es: \n");
       
                puts(TareasNlistas->T.Descripcion);
       
                printf("La duracion es de %d \n", TareasNlistas->T.Duracion);

                TareasNlistas = TareasNlistas->Siguiente;
            }
            
        }
        
        
        
    }
    
    
    
    
    
    
    






    return 0;
}
Nodo *  BuscarPorID(int ID ,Nodo * TareasNlistas , Nodo * Tareaslistas , int z, int j ){
    for (int i = 0; i < z; i++)
    {
        if(TareasNlistas == NULL)
        {
            
        }else
        {
            if (TareasNlistas->T.TareaID == ID)
            {
                return TareasNlistas;
            }else
            {
                TareasNlistas = TareasNlistas->Siguiente;
            }
            
            

        }
        
    }
    for (int i = 0; i < j; i++)
    {
         if(Tareaslistas == NULL)
        {
            
        }else
        {
            if (Tareaslistas->T.TareaID == ID)
            {
                return Tareaslistas;
            }else
            {
                Tareaslistas = Tareaslistas->Siguiente;
            }
        }
            
        
        
    }
    return NULL;
}

Nodo* BuscarPalabra(char palabrea[],Nodo* TareasNlistas, Nodo * Tareaslistas , int z, int j){
        for (int i = 0; i < z; i++)
    {
            if (TareasNlistas == NULL)
            {
                /* code */
            }else
            {
                while (TareasNlistas != NULL)
                {
                        if (strstr(TareasNlistas->T.Descripcion,palabrea) != NULL)
                    {
                        return TareasNlistas;
                    }else
                    {
                        TareasNlistas = TareasNlistas->Siguiente;
                    }
                    
                }
                
            
                
            }
            
        
        }
        for (int i = 0; i < j; i++)
        {
            if (Tareaslistas == NULL)
            {
                /* code */
            }else
            {
                while (Tareaslistas != NULL)
                {
                        if (strstr(Tareaslistas->T.Descripcion,palabrea) != NULL)
                    {
                        return Tareaslistas;
                    }else
                    {
                        Tareaslistas = Tareaslistas->Siguiente;
                    }
                    
                }
            
            
        }
        }
      return NULL;
        

    }
    Nodo * CrearNodo(Nodo *cabeza, Tarea deber){
        Nodo* nuevoNodo;
        nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->T = deber;
        nuevoNodo->Siguiente = cabeza;
        cabeza  = nuevoNodo;
        return cabeza;
    }