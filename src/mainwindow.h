#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDomDocument>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonRefresh_clicked();    

    void on_pushButtonDelete_clicked();

    void on_pushButtonDaysRefresh_clicked();

    void on_pushButtonShowDayCurve_clicked();    

    void on_tabWidget_tabBarClicked(int index);

    void setId(int row, int column);
    void showCoordinates(QMouseEvent *me);
    void trigerMenu(QAction* act);

private:
    Ui::MainWindow *ui;
    QSqlDatabase mSql;
    QString ip, port, dataBaseVersion, dataBaseName, userName, passWord;
    QVector<double> xHour, yCentigrade;

    void drawData(QString curDate);
    void dbInit();
    void plotPaint();
    void saveTemperaturePicture();
    void aboutTriggered();

    bool readXML();
};

#endif // MAINWINDOW_H
