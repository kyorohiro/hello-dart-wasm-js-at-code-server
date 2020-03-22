#include<stdio.h>
#include<emscripten.h>
#include<malloc.h> 
void hello() {
  printf("hello\n");
}

int sum(int a, int b){
  return a+b;
}

double sum_double(double a, double b){
  return a+b;
}

char* create_buffer(int size) {
    char* ret = malloc(sizeof(char)*size);
    return ret;
}

void destroy_buffer(uint8_t* p) {
  free(p);
}


int main() {
  printf("main\n");
  return 0;
}