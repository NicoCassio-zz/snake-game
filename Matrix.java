public class Matrix {
	//  Variáveis
	private int[] m = new int[8];
	//  Métodos públicos
	public void toRight() {
		int n;
		for(int i=0; i<8; i++) {
			n = (lineToString(i).charAt(lineToString(i).length() - 1) == '1') ? 0b10000000 : 0;
			setLine(i, (getLine(i) >> 1) ^ n);
		}	
	}
	public void toLeft() {
		int n;
		for(int i=0; i<8; i++) {
			n = (lineToString(i).charAt(0) == '1') ? 0b100000001 : 0;
			setLine(i, (getLine(i) << 1) ^ n);
		}
	}
	public void toTop() {
		int firstLine = getLine(0);
		for(int i=0; i<7; i++) {
			setLine(i, getLine(i+1));
		}
		setLine(7, firstLine);
	}
	public void toBottom() {
		int auxLine = getLine(0);
		int auxLine2;
		int lastLine = getLine(7);
		for(int i=1; i<8; i++) {
			auxLine2 = getLine(i);
			setLine(i, auxLine);
			auxLine = auxLine2;
		}
		setLine(0, lastLine);
	}
	//  Métodos especiais
	public Matrix() {
		for(int i = 0; i < 8; i++) {
			setLine(i, 0b00000000 >> i);
		}
	}
	public int getLine(int line) {
		return this.m[line];
	}
	public void setLine(int line, int v) {
		this.m[line] = v;
	}
	public int[] getAllLines() {return this.m;}
	public void setAllLines(int[] m) {this.m = m;}
	public String toString() {
		String res = "";
		for(int i=0; i<8; i++) {
			res += String.format("%8s\n", Integer.toBinaryString(m[i])).replace(' ', '0');
		}
		return res;
	}
	public String lineToString(int line) {
		return String.format("%8s", Integer.toBinaryString(m[line])).replace(' ', '0');	
	}
}
