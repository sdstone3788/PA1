public class Homework1{
   public static void NewNum(int a, int b){
      int c=2;
     // int c=6;
      int[] array = new int[10];
      System.out.println(a);
      System.out.println(" base 10 is ");
      int counter=9;
      while (a>b){
         array[counter]= a%c;
         a=a/c;
         c=c+1;
         counter--;
      }
      for (int x=0; x<10; x++){
         System.out.println(array[x]+" ");
      }
      System.out.println(" in the new numbering system.");
   }
   public static void main(String[] args){
      int a =150;
      int b=0;
      int c=6;
      Homework1.NewNum(a, b);
      }
}


