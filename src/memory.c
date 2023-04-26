#include"memory.h"
#include<stdlib.h> // malloc free
#include<string.h> // memset
void* memory_alloc(size_t size){
    void* ret=NULL;
    while(1){
        ret=malloc(size);
        if(ret!=NULL){
            memset(ret,0,size);
            return ret;
        }
        free(ret);
        ret=NULL;
    }
}
void  memory_free(void* ptr) {
    if (ptr!=NULL) {
        free(ptr);
        ptr=NULL;
    }
}
