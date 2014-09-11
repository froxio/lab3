#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

static int getSize(primitiveType type);

/*
* Constructs an arraylist and initializes its values.
*
* Parameters:
*
* type      type of primative (char, short, or int) that the arraylist will be
*
* Returns a pointer to the created arraylist.
*/
arrayList * initialize(primitiveType type)
{
   arrayList * a = malloc(sizeof(arrayList));
   a -> array = malloc(getSize(type) * 4);
   a -> elementSize = getSize(type);
   a -> numElements = 0;
   a -> arraySize = 4;
   a -> type = type;
   return a;
}


/*
* Gets the size of a specified type.
*
* Parameters:
*
* type      type of primative (char, short, or int)
*
* Returns the size of the primative.
*/
static int getSize(primitiveType type)
{
   if (type == charType)
   {
      return sizeof(char);  
   }
   if (type == intType)
   {
      return sizeof(int);  
   }
   else
   {
      return sizeof(short);
   }
}

/*
* Adds an element to the end of a passed arraylist. An arraylist's capacity will expand as needed.
*
* Parameters:
*
* arylstP      pointer to the source arraylist that receives a new element
* element      element to be added to source arraylist
*/

void addElement(arrayList * arylstP, void * element)
{
   if (arylstP -> numElements == arylstP -> arraySize)
   {
      arrayList * aNew = malloc(sizeof(arrayList));
      aNew -> array = malloc(getSize(arylstP -> type) * (arylstP -> arraySize) * 2);
      aNew -> elementSize = getSize(arylstP -> elementSize);
      aNew -> numElements = arylstP -> numElements;
      aNew -> arraySize = (arylstP -> arraySize) * 2;
      aNew -> type = (arylstP -> type);
      if (arylstP -> type == intType)
      {         
         int i;
         for (i = 0; i < arylstP -> numElements; i++)
         {
            ((int *) (aNew -> array))[i] = ((int *) (arylstP -> array))[i];
         }      
      }
      else if (arylstP -> type == shortType)
      {        
         short i;
         for (i = 0; i < arylstP -> numElements; i++)
         {
            ((short *) (aNew -> array))[i] = ((short *) (arylstP -> array))[i];
         }  
      }   
      else if (arylstP -> type == charType)
      {    
         int i;     
         for (i = 0; i < arylstP -> numElements; i++)
         {
            ((char *) (aNew -> array))[i] = ((char *) (arylstP -> array))[i];
         }
      }
      * arylstP = * aNew;
   }
   if (arylstP -> type == intType)
   {
      ((int *) (arylstP -> array))[arylstP -> numElements] = *((int *) element);      
   }
   else if (arylstP -> type == shortType)
   {
      ((short *) (arylstP -> array))[arylstP -> numElements] = *((short *) element);     
   }   
   else if (arylstP -> type == charType)
   {
      ((char *) (arylstP -> array))[arylstP -> numElements] = *((char *) element);
   }
   (arylstP -> numElements)++;
}

/*
* Removes an element from the specified arraylist at a specified index. Elements to the right of the
* index are shifted by one. 
*
* Parameters:
*
* arylstP      pointer to the source arraylist that will have an element removed
* index        index within the source arraylist at which an element will be removed
*/

void removeElement(arrayList * arylstP, int index)
{
   int i;
   if (arylstP -> type == intType)
   {         
      for (i = index; i < arylstP -> numElements - 1; i++)
      {
         ((int *) (arylstP -> array))[i] = ((int *) (arylstP -> array))[i + 1];
      }      
   }
   else if (arylstP -> type == shortType)
   {        
      for (i = index; i < arylstP -> numElements - 2; i++)
      {
         ((short *) (arylstP -> array))[i] = ((short *) (arylstP -> array))[i + 1];
      }    
   }   
   else if (arylstP -> type == charType)
   {         
      for (i = index; i < arylstP -> numElements - 2; i++)
      {
         ((char *) (arylstP -> array))[i] = ((char *) (arylstP -> array))[i + 1];
      }   
   }
   (arylstP -> numElements)--;
}
      
/*
* Prints useful arraylist info including size, number of elements, and contents.
*
* Parameters:
*
* arylstP      pointer of the the arraylist to be printed
*/

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         printf("%02x ", ((char *) (arylstP -> array))[i] & 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", ((short *) (arylstP -> array))[i] & 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", ((int *) (arylstP -> array))[i] & 0xffffffff);
   }
   printf("\n");
}

