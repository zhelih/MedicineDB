#ifndef TRANSLATE_LOAD_CPP
#define TRANSLATE_LOAD_CPP

#include <QString>
#include <QHash>
#include <QFile>

#include "translate_load.h"

translation::translation() {}

void translation::reread()
{
    QFile f("translate.txt");
    QString buf;
    if(!f.open(f.ReadOnly))
    {
        // show error
        printf("cannot open translate.txt : %s\n", f.errorString().toStdString().c_str());
    }
    else
    {
        //try to read directly
        //QTextStream s;
        //s.setDevice(f);
        while(!f.atEnd())
        {
            buf = f.readLine();
            if(buf.contains(' ')&&(!buf.startsWith("#")))
            {
                int space = buf.indexOf(' '); //space is index
                QString key = buf.left(space); //param is len
                QString val = buf.right(buf.size() - space - 1);//same
                //hack
                val.chop(2); //remove\n
                data.insert(key.toLower(),val);
            }
        }
    }
    f.close();
}

QString translation::get(QString attr) const
{
    // better then operator[] - default insert
    // calls are annoying
    if (data.contains(attr.toLower()))
        return data.value(attr.toLower());
    else
        return attr;
}

void translation::print() const
{
    Hash::const_iterator i;
    for(i=data.constBegin();i!=data.constEnd();++i)
        printf("%s : %s",
               i.key().toStdString().c_str(),
               i.value().toStdString().c_str());
}

#endif // TRANSLATE_LOAD_CPP
