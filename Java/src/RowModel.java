import java.sql.*;
import java.util.*;

import javax.swing.table.AbstractTableModel;

public class RowModel extends AbstractTableModel {

	private static final long serialVersionUID = 7675427992997523793L;
	private List<String[]> data;
	private int column_count;
	private String[] header;
	public RowModel(Connection conn, String tname) {
		data = new ArrayList<String[]>();
		int i;
		try {
			Statement st = conn.createStatement();
			String query = "select * from " + tname + "";
			System.out.print(query + "\n");
			ResultSet rs = st.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();

			column_count = rsmd.getColumnCount();
			header = new String[column_count];
			for(i=1;i<=column_count;++i)
				header[i-1] = rsmd.getColumnName(i);
			while(rs.next()) {
				String[] row = new String[column_count];
				for(i=1;i<=column_count;++i)
					row[i-1] = rs.getString(i);
				data.add(row);
			}
			st.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public String getColumnName(int col)  {
		return header[col];
	}
	public int getRowCount() { return data.size(); }
	public int getColumnCount() { return column_count; }
	public boolean isCellEditable(int row, int col) {
		return false;
	}
	public Object getValueAt(int row, int col) {
        return data.get(row)[col];
    }
}
