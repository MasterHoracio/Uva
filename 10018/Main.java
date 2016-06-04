import java.util.Scanner;

public class Main {
	
	public static void main(String[] agrs){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		long num, a, b;
		int acum;
		String numero, numeror;
		boolean reverse;
		while(cases-- > 0){
			num = sc.nextLong();
			reverse = false;
			acum = 0;
			while(!reverse){
				numeror = "";
				numero = Long.toString(num);
				for(int i = numero.length() - 1; i >= 0; i--)
					numeror += numero.charAt(i);
				if(numero.compareTo(numeror) == 0)
					reverse = true;
				else{
					a = Long.parseLong(numero);
					b = Long.parseLong(numeror);
					num = a + b;
					acum++;
				}
			}
			System.out.println(acum+" "+num);
		}
		sc.close();
	}
	
}
