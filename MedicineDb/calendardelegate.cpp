#include "calendardelegate.h"
#include <QDateEdit>
#include <QModelIndex>
#include <QStyledItemDelegate>

CalendarDelegate::CalendarDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *CalendarDelegate::createEditor(QWidget *parent,
     const QStyleOptionViewItem & option,
     const QModelIndex & index) const
{
    if(index.data().type() == QVariant::Date)
    {
        QDateEdit* editor_;
        editor_ = new QDateEdit(parent);
        editor_->setCalendarPopup(true);
        editor_->setDate(QDate::currentDate());
        return editor_;
    }
    else
         return QStyledItemDelegate::createEditor(parent, option, index);
}

void CalendarDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    if(index.model()->data(index, Qt::EditRole).type() != QVariant::Date)
        QStyledItemDelegate::setEditorData(editor,index);
    else
    {
        QDate value = index.model()->data(index, Qt::EditRole).toDate();

        QDateEdit *calendar = static_cast<QDateEdit*>(editor);
        calendar->setDate(value);
    }
}

void CalendarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
 {
    if(index.data() == QVariant::Date)
    {
        QDateEdit *calendar = static_cast<QDateEdit*>(editor);
        QVariant value = QVariant(calendar->date());

        model->setData(index, value, Qt::EditRole);
    } else
        QStyledItemDelegate::setModelData(editor, model, index);
 }

void CalendarDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
