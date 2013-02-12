import java.sql.*;
import java.util.*;

import javax.swing.table.AbstractTableModel;

public class RowModel extends AbstractTableModel {

	private static final long serialVersionUID = 7675427992997523793L;
	private List<String> data;
	public RowModel(Connection conn, String tname) {
		data = new ArrayList<String>();
		try {
			Statement st = conn.createStatement();
			ResultSet rs = st.executeQuery("select * from \'" + tname + "\'");
			while(rs.next()) {
				data.add(rs.getString(1));
			}
			st.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	public String getColumnName(int col)  {
		return "Table name";
	}
	public int getRowCount() { return data.size(); }
	public int getColumnCount() { return 1; }
	public boolean isCellEditable(int row, int col) {
		return false;
	}
	public Object getValueAt(int row, int col) {
        return data.get(row);
    }
}
