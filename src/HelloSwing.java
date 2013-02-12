import javax.swing.*;
import java.sql.*;
import java.util.*;

public class HelloSwing {

	public static void main(String[] args) {
		String url = "jdbc:db2://127.0.0.1:50000/Medicine";
		String user = "db2admin";
		String password = "db2admin";
		Connection conn = null;
		List<String> data_tables = new ArrayList<String>();
		List<String> data_owners = new ArrayList<String>();
		TableModel tables = null;
		try {
			// Load the DB2 JDBC Type 2 Driver with DriverManager
			// Attention!!!
			// Add this jars to you build path libraries (extenal jars)
			// IBM/SQLLIB/java/db2jcc.jar
			// IBM/SQLLIB/java/db2jcc_licence_cu.jar
			
			Class.forName("com.ibm.db2.jcc.DB2Driver");
			conn = DriverManager.getConnection(url, user, password);
			conn.setAutoCommit(false);
			System.out.printf("Successfully connected to \"%s\"\n", url);
			System.out.printf("Retrieving information... ");

			Statement st = conn.createStatement();
			//ResultSet rs = st.executeQuery("select INST_NAME from SYSIBMADM.ENV_INST_INFO");
			ResultSet rs = st.executeQuery("select tabname, owner from syscat.tables where owner = \'DB2ADMIN\'");
			System.out.printf("done\n");
			tables = new TableModel(conn);
			while(rs.next())
			{
				data_tables.add(rs.getString(1));
				data_owners.add(rs.getString(2));
			}
			/* do some work */
			conn.commit();
			conn.close();
			System.out.print("Connection closed\n");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
		//String head[] = { "Table name", "Owner" };
		JFrame frame = new JFrame("HelloSwing");
		Object [][] array = new Object[data_tables.size()][2];
		int i;
		for(i=0; i<data_tables.size(); ++i)
		{
			array[i][0] = data_tables.get(i);
			array[i][1] = data_owners.get(i);
		}
		
		JTable table = new JTable(tables);
		table.setAutoCreateRowSorter(true);
		JScrollPane scroll = new JScrollPane(table);
		frame.getContentPane().add(scroll);
		//final JLabel label = new JLabel("Hello Swing bla");
		//frame.getContentPane().add(label); //different from AWT
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500,300);
		//frame.pack(); //make compact size
		frame.setVisible(true);
		
	}
}
