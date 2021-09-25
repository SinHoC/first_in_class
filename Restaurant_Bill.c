#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
  
   srand(time(NULL));
   int meal = rand()%4 + 1;
   double taxPercentage, tipPercentage;
   double mealCost, tax, tip, total;
   printf("Enter tax as percentage: ");
   scanf("%lf",&taxPercentage);
   printf("Enter tip as percentage: ");
   scanf("%lf",&tipPercentage);
  
   printf("\n");
   if(meal==1){
       printf("Meal Ordered Salad @ $9.95\n");
       mealCost = 9.95;
   }
   else if(meal==2){
       printf("Meal Ordered Soup @ $4.55\n");
       mealCost = 4.55;
   }
   else if(meal==3){
       printf("Meal Ordered Sandwich @ $13.25\n");
       mealCost = 13.25;
   }
   else{
       printf("Meal Ordered Pizza @ $22.35\n");
       mealCost = 22.35;
   }
   tax = mealCost*taxPercentage/100;
   tip = mealCost*tipPercentage/100;
  
  
   printf("\n");
   total = mealCost + tax + tip;
  
  
   printf("Total Tax (%.1lf%%) = $ %12.2lf\n",taxPercentage,tax);
   printf("Tip Amount(%.1lf%%) = $ %12.2lf\n",tipPercentage,tip);
   printf("====================================\n");
   printf("Total Cost = $ %12.2lf\n",total);
   printf("====================================\n");
  
   return 0;
}