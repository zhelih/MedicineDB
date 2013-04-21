#ifndef TRANSLATE_LOAD_H
#define TRANSLATE_LOAD_H

#include <QString>
#include <QHash>
#include <QFile>

typedef QHash<QString,QString> Hash;

class translation
{
private:
    Hash data;
public:
    translation();
    void reread();
    QString get(QString) const;
    ~translation() {}
    void print() const;
};

#endif // TRANSLATE_LOAD_H
