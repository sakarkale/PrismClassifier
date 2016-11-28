#include "Instance.h"

Instance_t *InstanceConstruct(Attribute_t *attribute, Classification_t *classification)
{
    Instance_t *newInstance = (Instance_t *)malloc(sizeof(Instance_t));
    if(newInstance == NULL)
    {
        printf("Not enough memory");
        exit(0);
    }
    newInstance->attribute = attribute;
    newInstance->classification = classification;
    newInstance->next = NULL;
    return newInstance;
}

Instance_t *addInstance(Instance_t **startInstance, Instance_t *lastInstance, Attribute_t *attribute, Classification_t *classification)
{
    if(*startInstance == NULL)
    {
        *startInstance = InstanceConstruct(attribute, classification);
        return *startInstance;
    }
    lastInstance->next = InstanceConstruct(attribute, classification);
    return lastInstance->next;
}

void printInstance(Instance_t *startInstance)
{
    Instance_t *currentInstance = startInstance;
    while(currentInstance != NULL)
    {
        printAttribute(currentInstance->attribute);
        printf("%s\n", currentInstance->classification->classificationName);
        printf("%d\n", currentInstance->classification->classificationIndex);
        currentInstance = currentInstance->next;
    }
    printf("\n");
}


