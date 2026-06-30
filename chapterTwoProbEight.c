#include <stdio.h>

int main(void){
  flaot loan, interextRate, monthlyPayment;
  float monthlyInterestRate;
  float balance;


  printf("Enter amount of loan: ");
  scanf("%f", &loan);

  prinf("Enter interest rate: ");
  scanf("%f", &interestRate);

  printf("Enter monthly payment");
  scanf("%f", &monthlyPayment);

  montlyInterestRate = (interestRate/100)/12;

  balance = loan;


  while(month <= 3){
    balance = balance * (1+monthlyInterestRate) - monthlyPayment;
    if(month ==1){
      printf("Balance remaining after first payment: $%.2f\n", balance);
}
    else if(month ==2){
      printf("Balance remaining after second payment: $%.2f\n", balance);
}
    else{
      printf("Balance remaining after third payment: $%.2f\n", balance);
}

    month++;
  }
  return 0;
}
