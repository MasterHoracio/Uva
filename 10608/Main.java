import java.util.Scanner;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

class Main{

	private static class Nodo{
		boolean visited = false;
		List <Nodo> nod = new LinkedList <Nodo>();
	}


	public static void main(String[] agrs){
		Scanner sc = new Scanner(System.in);
		int TC, N, M, A, B, ans;


		TC = sc.nextInt();

		while(TC-- > 0){

			N = sc.nextInt();
			M = sc.nextInt();

			Nodo Grafo[] = new Nodo[N + 1];

			for(int i = 1; i <= N; i++)
				Grafo[i] = new Nodo();

			for(int i = 0; i < M; i++){
				A = sc.nextInt();
				B = sc.nextInt();
				Grafo[A].nod.add(Grafo[B]);
				Grafo[B].nod.add(Grafo[A]);
			}

			ans = 0;

			for(int i = 1; i <= N; i++){
				if(!Grafo[i].visited)
					ans = Math.max(ans, BFS(Grafo[i]));
			}

			System.out.println(ans);
		}
	}

	private static int BFS(Nodo nodo){
		Queue <Nodo> cola = new LinkedList <Nodo>();
		cola.add(nodo);
		Nodo temp;
		int tam = 0;
		while(!cola.isEmpty()){
			temp = cola.poll();
			if(!temp.visited){
				tam++;
				temp.visited = true;
				for(Nodo a : temp.nod)
					cola.add(a);
			}
		}
		return tam;
	}

}