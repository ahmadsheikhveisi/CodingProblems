#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long unsigned ull;
typedef unsigned int uint;

#define MAX_SIZE 100

#define MAX(_a,_b) ((_a)>(_b)?(_a):(_b))
#define MIN(_a,_b) ((_a)>(_b)?(_b):(_a))

typedef struct large_num_str {
  uint num[MAX_SIZE];
  uint size;
}large_num_t;

/* fill the large number type variable with zeros
* large_num the large number to be reset
*/
void reset_large_num(large_num_t* large_num){
  memset(large_num,0,sizeof(large_num_t));
  large_num->size = 1;
}
/* convert a long long to a large num type
* x the number to be converted to array
* p_large_num the array to be filled
* return -1 if overflow; 0 if ok
*/
int convert2arr(ull x, large_num_t* p_large_num){
  uint* x_arr = p_large_num->num;
  uint arr_cnt = 0;
  uint bit_size = sizeof(x_arr[0]) * 8;
  uint filter = (uint)(-1);
  
  do{
    x_arr[arr_cnt] = (uint)(x & (ull)filter);
    arr_cnt++;
    x = x >> bit_size;    
    if (arr_cnt >= MAX_SIZE){
      return -1;
    }
  }while(x);
  p_large_num->size = arr_cnt;
  return 0;
}
/* convert an array to ull
* x the output number
* p_large_num the array to be converted to number
* return 0 if no error, -1 if overflow
*/
int convert2ull(ull* x, const large_num_t* p_large_num){
  const uint* x_arr = p_large_num->num;
  uint arr_size = p_large_num->size;
  int res = 0;
  uint bit_size = sizeof(x_arr[0]) * 8;
  *x = 0;
  if (arr_size > sizeof(*x)/sizeof(x_arr[0])){
    res = -1;
  }
  else{
    for (uint cnt = arr_size; cnt >= 1; --cnt){
      *x = *x << bit_size;
      *x |= x_arr[cnt - 1];
    }
  }  
  return res;
}

void print_large_num(const large_num_t* p_num){
  uint arr_size = p_num->size;
  printf("size: %d 0x",arr_size);
  while(arr_size >= 1){
    printf("%08x",p_num->num[arr_size - 1]);
    arr_size--;
  }
  printf("\n");
}

large_num_t* digit_mul(const large_num_t* multiplicand, const large_num_t* multiplier ){
  ull carry = 0;
  uint bit_size = sizeof(multiplicand->num[0]) * 8;
  uint filter = (uint)(-1);
  
  large_num_t* result = malloc(sizeof(large_num_t));
  reset_large_num(result);

  for (uint cnt1 = 0; cnt1 < multiplier->size; ++cnt1){
    uint cnt2 = 0;
    for (; cnt2 < multiplicand->size; ++cnt2){
      ull res = (ull)multiplicand->num[cnt2] * (ull)multiplier->num[cnt1] + carry + result->num[cnt1 + cnt2];
      result->num[cnt1 + cnt2] = (uint)(res & (ull)filter);
      carry = res >> bit_size;
    }
    while (carry){
      result->num[cnt2+cnt1] += (uint)(carry & (ull)filter);
      carry = carry >> bit_size;
      cnt2++;
    }
  }
  uint arr_size = multiplier->size + multiplicand->size;
    
  while (carry){
    result->num[arr_size - 1] += (uint)(carry & (ull)filter);
    carry = carry >> bit_size;
    arr_size++;
  }
  
  while ((result->num[arr_size - 1] == 0) && (arr_size > 1)){
    arr_size--;
  }
  
  result->size = arr_size;
    
  return result;
}

large_num_t* digit_div(const large_num_t* dividend, const large_num_t* divisor){ 
  large_num_t* result = malloc(sizeof(large_num_t));
  reset_large_num(result);
  
  (void)dividend;
  (void)divisor;
  
  return result;

}


large_num_t* fact_large_num(ull x, ull limit){ 
  
  if(x > limit){    
    large_num_t arr_num;
    reset_large_num(&arr_num);
    convert2arr(x,&arr_num);
    
    large_num_t* fact_res = fact_large_num(x-1, limit);
    
    large_num_t* mul_res = digit_mul(fact_res,&arr_num);
    
    free(fact_res);
    
    return mul_res;   
    
  }
  else{
    large_num_t* fact_x = malloc(sizeof(large_num_t));
    reset_large_num(fact_x);
    convert2arr(1,fact_x);
    return fact_x;
  }
}

ull fact(ull x){
  if (x <= 1){
    return 1;
  }
  return x * fact(x - 1);
}

ull fact_limited(ull x, ull limit){
  if (x <= limit){
    return 1;
  }
  return x * fact_limited(x - 1, limit);
}

ull choose(ull n, ull k) {

    //  <----  hajime!
  if (k > n)
    {
    return 0;
  }
  
  /*ull test_num = 0xFFFFFFFFFFFFFFFF;
  large_num_t arr_num;
  reset_large_num(&arr_num);
  printf("%i\n", convert2arr(test_num,&arr_num));
  print_large_num(&arr_num);
  
  ull test_num2 = 0xFFFFFFFFFFFFFFFF;
  large_num_t arr_num2;
  reset_large_num(&arr_num2);
  printf("%i\n", convert2arr(test_num2,&arr_num2));
  print_large_num(&arr_num2);
  
  large_num_t *res_num = digit_mul(&arr_num,&arr_num2);
  print_large_num(res_num);  
  free(res_num);*/
  
  /*large_num_t* fact_res = fact_large_num(20);
  print_large_num(fact_res);
  free(fact_res);*/
  
  //printf("-----------\n");
  
  //fact_limited(n,k)/fact(n - k);
  
  /*ull num_1 = 1;
  ull num_2 = 1;
  
  large_num_t* fact_n_limit_k = fact_large_num(n, k);
  large_num_t* fact_n_k = fact_large_num(n-k, 0);
  
  convert2ull(&num_1,fact_n_limit_k);
  convert2ull(&num_2,fact_n_k);
  
  free(fact_n_limit_k);
  free(fact_n_k);
  
  ull result = 0;
  if (num_2 != 0){
    result = (num_1/num_2);
  }*/
  //printf("result %llu %llu %llu\n",n,k,result);
  
  //printf("-----------\n");
    
  return fact_limited(n,MAX(n-k,k))/fact_limited(MIN(n - k,k),1);//result; //
}
