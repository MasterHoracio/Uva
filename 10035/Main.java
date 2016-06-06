import java.util.Scanner;

public class Main {
	
	public static void main(String[] agrs){
		Scanner sc = new Scanner(System.in);
		long carry, a, b, carries, sum;
		while(sc.hasNext()){
			a = sc.nextLong();
			b = sc.nextLong();
			if(a == 0 && b == 0)
				break;
			sum = carries = carry = 0;
			while(a != 0 || b != 0){
				sum = (a % 10) + (b % 10) + carry;
				if(sum > 9)
					carries++;
				carry = sum / 10;
				a /= 10;
				b /= 10;
			}
			if(carries == 0)
				System.out.println("No carry operation.");
			else if(carries == 1)
				System.out.println("1 carry operation.");
			else
				System.out.println(carries+" carry operations.");
		}
		sc.close();
	}
}
