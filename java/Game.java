import java.util.Random;

public class Game {
	//  Variáveis
	private Snake s;
	private Food f;
	private Matrix m;
	//  Métodos públicos	
	public void play() {
		if(s.isAlive()) {
			s.move();
			s.setDirection(new Random().nextInt(4));
			if(s.getXPos(0)==f.getXPos() && s.getYPos(0)==f.getYPos()) {
				s.eat();
				generate();
			}
			plotMatrix();
		}
	}
	public void generate() {
		int xPos;
		int yPos;
		boolean p;
		do {
			p = false;
			xPos = new Random().nextInt(8);		
			yPos = new Random().nextInt(8);		
			for(int i=0; i<64; i++) {
				if(xPos==s.getXPos(i)&&yPos==s.getYPos(i)) {
					p = true;
					break;
				}
			}
		} while(p);
		f.setXPos(xPos);
		f.setYPos(yPos);
	}
	public void plotMatrix() {
		m.setAllLines(s.toBinary());
		m.setLine(f.getYPos(), m.getLine(f.getYPos()) | (0b10000000 >> f.getXPos()));
	}
	//  Métodos especiais
	public Game() {
		s = new Snake();
		f = new Food();
		m = new Matrix();
		generate();
		plotMatrix();
	}
	public Snake getSnake() {return this.s;}
	public void setSnake(Snake s) {this.s = s;}
	public Food getFood() {return this.f;}
	public void setFood(Food f) {this.f = f;}
	public Matrix getMatrix() {return this.m;}
	public void setMatrix(Matrix x) {this.m = m;}
}
