#ifndef CLONFIG_H
#define CLONFIG_H

#include <QApplication>
#include <QString>
#include <QSettings>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardPaths>

#include <QDebug>

#ifdef Q_OS_LINUX
#   include <QDir>
#endif

class Config
{
public:
    Config();
    ~Config();

    struct Layout {
        QString name;
        QString title;
        QString symbols;
    };

    struct Lesson {
        QString title;
        QString author;
        QString version;
        QString content;
    };

    QString lastLayoutFile() const;
    void setLastLayoutFile(const QString &lastLayoutFile);

    int fontSize() const;
    void setFontSize(int fontSize);

    bool separateKeyboard() const;
    void setSeparateKeyboard(bool separateKeyboard);

    QString resourcesPath();

    QString lastLayout() const;
    void setLastLayout(const QString &lastLayout);

    Layout *currentLayout() const;
    bool setCurrentLayout(const int layoutIndex);

    QList<Layout *> layouts() const;
    QList<Lesson *> lessons() const;
    QList<Lesson *> generatedLessons() const;
public slots:
    void lessonsGenerated();
private:
    QSettings *m_settings;
    QString m_lastLayoutFile;
    QString m_lastLayout;
    int m_fontSize;
    bool m_separateKeyboard;

    QList<Layout*> m_layouts;
    Layout *m_currentLayout;

    QList<Lesson*> m_lessons;
    QList<Lesson*> m_generatedLessons;

    void loadLayouts();
    void loadLessons();
    void loadGeneratedLessons();
    void clearLessons();
    void clearGeneratedLessons();
};

#endif // CLONFIG_H
