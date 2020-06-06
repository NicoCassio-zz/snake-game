public class Main {
	public static void main(String[] args) {
		Game g = new Game();
		System.out.println(g.getMatrix().toString());
		do {
			limpa();
			g.play();
			System.out.println(g.getMatrix().toString());
		} while(g.getSnake().isAlive());
		System.out.println("...Finalizando");
	}
	public static void limpa() {
		sleep(1000);
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}
	public static void sleep(int s) {
		try {
			Thread.sleep(s);
		} catch(InterruptedException e) {}
	}
}
