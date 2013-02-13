import javax.swing.*;
import javax.swing.event.*;

import java.awt.GridLayout;
import java.sql.*;
import java.util.*;

public class MedicineMain extends JFrame {

	private static final long serialVersionUID = -601614414196435470L;
	private JTable table_row;
	private JScrollPane scroll_row;
	private Connection conn;

	public MedicineMain() {
		super("Medicine Database");
		
		
		String url = "jdbc:db2://127.0.0.1:50000/Medicine";
		String user = "db2admin";
		String password = "db2admin";
		conn = null;
		table_row = null;
		
		try {
			// Load the DB2 JDBC Type 2 Driver with DriverManager
			// Attention!!!
			// Add this jars to you build path libraries (external jars)
			// IBM/SQLLIB/java/db2jcc.jar
			// IBM/SQLLIB/java/db2jcc_licence_cu.jar
			
			Class.forName("com.ibm.db2.jcc.DB2Driver");
			conn = DriverManager.getConnection(url, user, password);
			System.out.printf("Successfully connected to \"%s\"\n", url);
		}
		catch(Exception e)
		{
			e.printStackTrace();
			JOptionPane.showMessageDialog(this, e.toString());
		}

		//loading tables
		List<String> data_tables = new ArrayList<String>();
		List<String> data_owners = new ArrayList<String>();
		TableModel tables = null;
		try {
			Statement st = conn.createStatement();
			ResultSet rs = st.executeQuery("select tabname, owner from syscat.tables where owner = \'DB2ADMIN\'");
			System.out.printf("Retrieving information... ");
			System.out.printf("done\n");
			tables = new TableModel(conn);
			while(rs.next())
			{
				data_tables.add(rs.getString(1));
				data_owners.add(rs.getString(2));
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
			JOptionPane.showMessageDialog(this, e.toString());
		}
		
		setLayout(new GridLayout());
		Object [][] array = new Object[data_tables.size()][2];
		int i;
		for(i=0; i<data_tables.size(); ++i)
		{
			array[i][0] = data_tables.get(i);
			array[i][1] = data_owners.get(i);
		}
		
		final JTable table = new JTable(tables);
		ListSelectionModel lsm = table.getSelectionModel();
		lsm.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		lsm.addListSelectionListener(new ListSelectionListener() {
			public void valueChanged(ListSelectionEvent e) {
				if(!e.getValueIsAdjusting())
				{
					int row = table.getSelectedRows()[0];
					String table_name = (String)table.getValueAt(row, 0);
					if(table_row != null)
					{
						scroll_row.remove(table_row);
						getContentPane().remove(scroll_row);
					}
					table_row = new JTable(new RowModel(conn, table_name));
					scroll_row = new JScrollPane(table_row);
					getContentPane().add(scroll_row);
					validate();
				}
			}
		});
		table.setAutoCreateRowSorter(true);
		//table.getModel().addTableModelListener(new ChangeListener());
		JScrollPane scroll_tables = new JScrollPane(table);
		getContentPane().add(scroll_tables);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(640,480);
		setVisible(true);
		
	}
	
	protected void finalize() {
		try { conn.close(); } catch(Exception e) { e.printStackTrace(); }
		System.out.print("Connection closed\n");
	}

	public static void main(String[] args) {
		new MedicineMain();
	}
}
