import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String [] agrs){
		Scanner sc = new Scanner(System.in);
		int cases;boolean zero;
		cases = sc.nextInt();
		while(cases-- > 0){
			zero = false;
			String A,B,Areverse = "",Breverse = "",R,Rreverse = "";
			A = sc.next();B = sc.next();
			for(int i = A.length() - 1; i >= 0; i--)
				Areverse += A.charAt(i);
			for(int i = B.length() - 1; i >= 0; i--)
				Breverse += B.charAt(i);
			BigInteger num1 = new BigInteger(Areverse);
			BigInteger num2 = new BigInteger(Breverse);
			num1 = num1.add(num2);
			R = num1.toString();
			if(R.charAt(R.length() - 1) == '0')
				zero = true;
			for(int i = R.length() - 1; i >= 0; i--){
				if(zero){
					if(R.charAt(i) == '0')
						continue;
					else
						zero = false;
				}
				Rreverse += R.charAt(i);
			}

			System.out.println(Rreverse);
		}
		sc.close();
	}
}
