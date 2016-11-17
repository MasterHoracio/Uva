import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class Main{


	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Map <String, Integer> meses = new HashMap <String,Integer>();
		Map <String, Integer> dias = new HashMap <String, Integer>();
		String mes, dia;
		int TC, ndia, ans;

		meses.put("JAN", 31); meses.put("FEB", 28); meses.put("MAR", 31); 
		meses.put("APR", 30); meses.put("MAY", 31); meses.put("JUN", 30);
		meses.put("JUL", 31); meses.put("AUG", 31); meses.put("SEP", 30);
		meses.put("OCT", 31); meses.put("NOV", 30); meses.put("DEC", 31);

		dias.put("SUN", 1); dias.put("MON", 2); dias.put("TUE", 3);
		dias.put("WED", 4); dias.put("THU", 5); dias.put("FRI", 6);
		dias.put("SAT", 7);


		TC = sc.nextInt();


		while(TC-- > 0){

			mes = sc.next();
			dia = sc.next();

			ans = 0;

			ndia = dias.get(dia);

			for(int i = 0; i < meses.get(mes); i++)
				if( ((ndia + i) % 7 == 6) ||  ((ndia + i) % 7 == 0) )
					ans++;

			System.out.println(ans);
		}
	}
}