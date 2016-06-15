import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String [] agrs){
		Scanner sc = new Scanner(System.in);
		int n, len, count;
		String [] FactorialNum = new String[1000];
		BigInteger bg = new BigInteger("1");
		for(int i = 0; i < 1000; i++){
			FactorialNum[i] = bg.toString();
			bg = bg.multiply(new BigInteger(Integer.toString(i + 2)));
		}
		while(sc.hasNextInt()){
			n = sc.nextInt();
			count = 0;
			len = FactorialNum[n-1].length();
			for(int i = 0; i < len; i++)
				count += Integer.parseInt(Character.toString(FactorialNum[n-1].charAt(i)));
			System.out.println(count);
		}
		sc.close();
	}
}
