public class Snake {
	//  Variáveis
	private int[] xPos;
	private int[] yPos;
	private int size;
	private int direction; // 0 - up, 1 -down, 2 - right, 3 - left
	private boolean alive;
	//  Métodos públicos
	public void move() {
		if(!checkCollision()) {
			for(int i=getSize(); i>0; i--) {
				setXPos(i, getXPos(i-1));
				setYPos(i, getYPos(i-1));
			}
			switch(getDirection()) {
				case 0:
					setYPos(0, getYPos(0)+1);
					break;
				case 1:
					setYPos(0, getYPos(0)-1);
					break;
				case 2:
					setXPos(0, getXPos(0)+1);
					break;
				case 3:
					setXPos(0, getXPos(0)-1);
					break;
			}
		}
	}
	public void eat() {setSize(getSize()+1);}
	public boolean checkCollision() {
		for(int i=getSize(); i>0; i--) {
			if(
				(i>4) &&
				(getXPos(0) == getXPos(i)) &&
				(getYPos(0) == getYPos(i))
			) {
				setAlive(false);
				return true;
			}
		}
		return false;
	}
	//  Métodos especiais
	public Snake() {
		xPos = new int[64];
		yPos = new int[64];
		setSize(3);
		for(int i=0; i<getSize(); i++) {
			setXPos(i, 2-i);
			setYPos(i, 2);
		}
		setDirection(2);
		setAlive(true);
	}
	public int getXPos(int i) {return this.xPos[i];}
	public void setXPos(int i, int xPos) {
		if(xPos >= 0 && xPos < 8) {
			this.xPos[i] = xPos;
		} else {
			setAlive(false);
		}
	}
	public int getYPos(int i) {return this.yPos[i];}
	public void setYPos(int i, int yPos) {
		if(yPos >= 0 && yPos < 8) {
			this.yPos[i] = yPos;
		} else {
			setAlive(false);
		}
	}
	public int getSize() {return this.size;}
	public void setSize(int size) {this.size = size;}
	public int getDirection() {return this.direction;}
	public void setDirection(int direction) {
		if(
			(direction==0 && !(getDirection()==1)) ||
			(direction==1 && !(getDirection()==0)) ||
			(direction==2 && !(getDirection()==3)) ||
			(direction==3 && !(getDirection()==2))
		) {
			this.direction = direction;
		}
	}
	public boolean isAlive() {return this.alive;}
	public void setAlive(boolean alive) {this.alive = alive;}
	public int[] toBinary() {
		int[] m = new int[8];
		for(int i=0; i<8; i++) {
			for(int j=0; j<getSize(); j++) {
				if(getYPos(j)==i) {
					m[i] |= (0b10000000 >> getXPos(j));
				}
			}
		}
		return m;
	}
}
