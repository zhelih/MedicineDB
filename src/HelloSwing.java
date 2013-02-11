import javax.swing.*;

public class HelloSwing {

	public static void main(String[] args) {
		JFrame frame = new JFrame("HelloSwing");
		final JLabel label = new JLabel("Hello Swing bla");
		frame.getContentPane().add(label); //different from AWT
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.pack(); //make compact size
		frame.setVisible(true);
	}
}
