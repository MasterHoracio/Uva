import java.util.Scanner;

public class Main {
	
	private static final double C = 12.01;
	private static final double H = 1.008;
	private static final double O = 16.00;
	private static final double N = 14.01;
	
	public static void main(String[] agrs){
		Scanner sc = new Scanner(System.in);
		int tam, j;
		String str, aux;
		char caracter = ' ';
		boolean car;
		double res;
		int cases = sc.nextInt();
		
		while(cases-- > 0){
			str = sc.next();
			tam = str.length();
			car = false;
			res = 0.0;
			for(int i = 0; i < tam; i++){
				if( (str.charAt(i) == 'C' || str.charAt(i) == 'H' || str.charAt(i) == 'O' || str.charAt(i) == 'N') && !car ){
					car = true;
					caracter = str.charAt(i);
					continue;
				}
				if( (str.charAt(i) == 'C' || str.charAt(i) == 'H' || str.charAt(i) == 'O' || str.charAt(i) == 'N') && car ){
					if(str.charAt(i - 1) == 'C')
						res += C * 1;
					else if(str.charAt(i - 1) == 'H')
						res += H * 1;
					else if(str.charAt(i - 1) == 'O')
						res += O * 1;
					else
						res += N * 1;
					caracter = str.charAt(i);
					continue;
				}
				if(str.charAt(i) != 'C' || str.charAt(i) != 'H' || str.charAt(i) != 'O' || str.charAt(i) != 'N'){
					aux = "";
					j = i;
					while(str.charAt(j) != 'C' && str.charAt(j) != 'H' && str.charAt(j) != 'O' && str.charAt(j) != 'N'){
						aux += str.charAt(j);
						j++;
						if(j >= tam)
							break;
					}
					if(caracter == 'C')
						res += C * Integer.parseInt(aux);
					else if(caracter == 'H')
						res += H * Integer.parseInt(aux);
					else if(caracter == 'O')
						res += O * Integer.parseInt(aux);
					else
						res += N * Integer.parseInt(aux);
					car = false;
					i = --j;
				}
			}
			if(str.charAt(tam - 1) == 'C' || str.charAt(tam - 1) == 'H' || str.charAt(tam - 1) == 'O' || str.charAt(tam - 1) == 'N'){
				if(str.charAt(tam - 1) == 'C')
					res += C * 1;
				else if(str.charAt(tam - 1) == 'H')
					res += H * 1;
				else if(str.charAt(tam - 1) == 'O')
					res += O * 1;
				else
					res += N * 1;
			}
			System.out.printf("%.3f\n",res);
		}
		sc.close();
	}
}
