import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	
	public static void main(String [] agrs){
		Scanner sc = new Scanner(System.in);
		BigInteger factorial;
		int n;
		
		while(sc.hasNext()){
			n = sc.nextInt();
			factorial = BigInteger.ONE;
			for(int i = 1; i <= n; i++){
				factorial = factorial.multiply(new BigInteger(Integer.toString(i)));
			}
			System.out.println(n+"!");
			System.out.println(factorial.toString());
		}
		sc.close();
	}
}