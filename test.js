function factorial(int a) {
  if(a == 0) return 1;
  return a * factorial(a - 1);
}


int main(){
  int a = 7;
  console.log(factorial(a));
  return 0;
}
