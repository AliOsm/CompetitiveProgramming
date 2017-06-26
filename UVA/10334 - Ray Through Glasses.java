import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    BigInteger fib[] = new BigInteger[1005];
    fib[0] = BigInteger.ZERO;
    fib[1] = new BigInteger("1");
    for(int i = 2; i < 1005; ++i)
      fib[i] = fib[i - 1].add(fib[i - 2]);
    
    int n;
    while (sc.hasNextInt()) {
      n = sc.nextInt();
      System.out.println(fib[n + 2]);
    }
  }
}

