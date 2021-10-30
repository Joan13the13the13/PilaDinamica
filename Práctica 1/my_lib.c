#include "my_lib.h"

/* Método que retornará la cantidad de valores 
no nulos de un string que nos pasen por parámetos */
size_t my_strlen(const char *str)
{
    size_t len = 0;
    int i = 0;

    while (str[i] != '\0')
    { // o while (str[i]')
        i++;
        len++;
    }
    return len;
}

/* Método para comparar si dos cadenas de caracteres 
son iguales, o diferentes */
int my_strcmp(const char *str1, const char *str2)
{
    //variable entera que retornaremos en caso de que tener cadenas distintas
    int tot = 0;
    //ídice
    int i = 0;
    /* Bucle con el qual llevaremos a cabo la comparación de los copdigos 
    asci de cada caracter */
    while (str1[i] || str2[i])
    {
        tot = ((int)str1[i] - (int)str2[i]);
        if (tot != 0)
        {
            return tot;
        }
        i++;
    }
    return 0;
}

/* Método con el cual copiaremos una cadena de caracteres 
en otra que nos pasarán por parámetro*/
char *my_strcpy(char *dest, const char *src)
{
    //índice
    int i = 0;
    /*bucle para el tratamiento de cada caracter de src, de 
    de forma que en cada iteracción se pone el caracter de src
    en la misma posición de dest*/
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    //añadimos el caracter nulo al final de la cadena
    dest[i] = '\0';

    return dest;
}

/* Método con el cual copiaremos n caracteres de una cadena  
en otra que nos pasarán por parámetro*/
char *my_strncpy(char *dest, const char *src, size_t n)
{
    //índice
    int i = 0;
    /*bucle mientras el índice sea menor al número de caracteres
    que se tienen que copiar, de forma que en cada iteracción 
    se pone el caracter de src en la misma posición de dest*/
    for (; i < n; i++)
    {
        dest[i] = src[i];
    }

    return dest;
}

/*
Método mediante el cual sobreescribimos la cadena de caracteres
src en la cadena dest, pasadas por parámetro, y lo devolvemos en dest
*/
char *my_strcat(char *dest, const char *src)
{
    //variable que contiene la longitud de la cadena dest
    int i = strlen(dest);
    /*variable que contendrá la posición del caracter de src que
    queremos copiar en la posición i de dest*/
    int n = 0;

    /*bucle for donde por cada iteracción copiamos el caracter de
    src correspondiente en la posición dest siguiente. Después incrementamos 
    el contador de i y de n para apuntar al siguiente caracter a escribir
    (n), y saber en que posició de src copiarla (n)
    */
    for (; n < strlen(src); i++, n++)
    {
        dest[i] = src[n];
    }

    //devolvemos la cadena dest
    dest[i] = '\0';
    return dest;
}

/*
Método que escanea una cadena de caracteres, y devuelve el 
puntero del primer caracter 'c' encontrado, o NULL si no encuentra
ninguna 'c'.
*/
char *my_strchr(const char *str, int c)
{
    //contador para saber la posición de la primera 'c'
    int i = 0;
    //puntero
    const char *ptr = str;

    /*bucle que incrementa el contador de caracteres por cada vez
    que lo completamos (por cada letra de la cadena), y mientras el
    caracter sea diferente a 'c' continuaremos en el bucle*/
    while ((int)str[i] != c)
    {
        i++;
        /*si i es mayor a la longitud de str, entonces significa que 
        la cadena no contiene 'c'y devolvemos NULL*/
        if (i > strlen(str))
        {
            return NULL;
        }
    }

    /*devolvemos el puntero del caracter que se encuentra en la
    posición i*/
    ptr = &(str[i]);
    return (char *)ptr;
}

/*
Método que crea una pila de tamaño size (pasado por parámetro).
params: entero con el tamaño de la pila(int size).
*/
struct my_stack *my_stack_init(int size){

    //reservamos espacio en la memoria para la pila
    struct my_stack *pila = malloc(sizeof(struct my_stack));
    //inicializamos la pila de tamaño size
    pila->size = size;
    //inicializamos el top de la pila en NULL
    pila->top = NULL;

    //devolvemos la pila creada
    return pila;
}

/*
-Método que inserta un nuevo nodo en la pila.
params: puntero a la pila (struct my_stack *stack),puntero a los dados (void *data).
*/
int my_stack_push(struct my_stack *stack, void *data){

    //condicional para saber si la pila está vacía
    if ((stack != NULL) && (stack->size > 0)){
        //reservamos espacio
        struct my_stack_node *nodo = malloc(sizeof(nodo));
        //cambiamos atributos del nuevo nodo
        nodo->data=data;
        nodo->next=stack->top;
        //el top de la pila será el nuevo nodo
        stack->top=nodo;

        return 0;//EXIT_SUCCESS
    }
    return -1; //EXIT_FAILURE
}

/*

*/
void *my_stack_pop (struct my_stack *stack){

    if(stack->top!=NULL){
        struct my_stack_node *nodoSUP =stack->top;
        stack->top=nodoSUP->next;
        void *datos=nodoSUP->data;
        free(nodoSUP);

        return datos;
    }
    return NULL;
}

/*
Método que devuelve el número de nodos que hay en la pila.
*/
int my_stack_len(struct my_stack *stack){

    //contador
    int n = 0;
    struct my_stack_node *nodo = stack->top;

    //bucle while que recorre la pila nodo por nodo
    while (nodo->next != NULL){
        //apuntamos al siguiente nodo
        nodo = nodo->next;
        //aumentamos el contador
        n++;
    }
    //devolvemos el número de nodos
    return n;
}

/*
Este método libera el espacio que se había reservado en la 
memoria para la pila
*/
int my_stack_purge(struct my_stack *stack){
    //numero de bytes acumulados
    int n = sizeof(struct my_stack);
    struct my_stack_node *nodo = stack->top;
    
    //bucle que recorre la pila nodo a nodo
    while (nodo->next != NULL){
        //sumamos los bytes que ocupan los nodos
        n += sizeof(nodo);
        n += sizeof(nodo->data);
        //liberamos el espacio que ocupa cada nodo
        free(nodo);
        //apuntamoss al siguiente nodo 
        nodo = nodo->next;
    }

    //liberamos el espacio que ocupa la pila
    free(stack);
    //devolvemos el número de bytes necesarios
    return n;
}

int my_stack_write (struct my_stack *stack, char *filename){
    //inicializamos el contador de bytes a -1 por si la apertura del fichero no funcionase correctamente, devolver dicho numero
    int bytes = -1;

    //Creamos una copia de la pila actual que nos han pasado por parámetro
    struct my_stack *aux = my_stack_init(stack->size);

    //declaramos un nodo y lo inicializamos al nodo top
    struct my_stack_node *nodo = stack->top;

    //abrimos el fichero, que nos retorna un numero que nos indica si la apertura ha ido bien o no 
    int fichero = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    //Realizamos un control de errores para saber si la apertura se ha realizado correctamente

    //si el entero retornado de la función open és un 0, significa que la operación no se ha realizado correctamente
    if(fichero < 0){ //podriem posar (fichero = -1)???
        return bytes;
    }

    //ecribimos la estructura pila dentro del fichero mediante la función write(fichero, dirección del dato a escribir, tamaño del dato a escribir)
    bytes = write(fichero, &stack->size, sizeof(stack->size));

    //ahora realizaremos un bucle para escribir nodo a nodo dentro del fichero
    while(nodo != NULL){
        //escribimos el nodo dentro del fichero y aumentamos el numero de bytes escritos
        bytes += write(fichero, &nodo, sizeof(nodo));
        nodo = nodo->next;
    }

    //Cerramos el fichero y realizamos un contro de errores para saber si se han producido errores
    int cierre = close(fichero);
    if(cierre == -1){
        return -1;
    }

    //Control de errores a consecuencia de las escrituras
    if(bytes == -1){
        return bytes;
    }else{
        return bytes / stack->size; //no entenc perquè fa això
    }
}

struct my_stack *my_stack_read (char *filename){
    
}
