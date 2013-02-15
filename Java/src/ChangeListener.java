import javax.swing.event.*;
import javax.swing.table.TableModel;

public class ChangeListener implements TableModelListener {

	public void tableChanged(TableModelEvent e) {
		int row = e.getFirstRow();
        int column = e.getColumn();
        TableModel model = (TableModel)e.getSource();
        String columnName = model.getColumnName(column);
        Object data = model.getValueAt(row, column);
	}

}
