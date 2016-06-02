import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		int [] numeros = new int [10];
		while(cases-- > 0){
			Arrays.fill(numeros, 0);
			int number = sc.nextInt();
			for(int i = 1; i <= number; i++){
				String str = Integer.toString(i);
				int tam = str.length();
				for(int j = 0; j < tam; j++){
					char c = str.charAt(j);
					int pos = Character.getNumericValue(c);
					numeros[pos]++;
				}
			}
			for(int i = 0; i < 10; i++){
				if(i != 9)
					System.out.print(numeros[i] + " ");
				else
					System.out.println(numeros[i]);
			}
		}
		sc.close();
	}
}
