#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdatetime.h"
#include "qpushbutton.h"
#include "qwindowdefs.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QVector>
#include <QHash>
#include <QString>
#include <random>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer=new QTimer();//Se establece QTimer() para el tiempo
    QTime time; //Inicializa el tiempo
    int restantes;
    QMessageBox msgbox;
    QVector<QString> tarjetas{"Tarjeta01","Tarjeta02","Tarjeta03","Tarjeta04","Tarjeta05","Tarjeta06","Tarjeta07","Tarjeta08", "Tarjeta09",
                             "Tarjeta10","Tarjeta11","Tarjeta12","Tarjeta13","Tarjeta14","Tarjeta15","Tarjeta16","Tarjeta17","Tarjeta18"
                             "Tarjeta19","Tarjeta20","Tarjeta21","Tarjeta22","Tarjeta23","Tarjeta24","Tarjeta25","Tarjeta26","Tarjeta27"
                             "Tarjeta28","Tarjeta29","Tarjeta30","Tarjeta31","Tarjeta32","Tarjeta33","Tarjeta34","Tarjeta35","Tarjeta36"
                             "Tarjeta37","Tarjeta38","Tarjeta39","Tarjeta40","Tarjeta41","Tarjeta42","Tarjeta43","Tarjeta44"}; //Matriz de las tarjetas
    QHash<QString, QString> reparto; //Mapa de las tarjetas
    int puntaje;
    bool jugadainiciada;
    QPushButton* tarjetaAnterior;
    QPushButton* tarjetaActual;



private slots:      //Se crean funciones para cada momento del juego
    void actEstado();
    void actCronometro();
    void resultadoF();
    void iniciarjuego();
    void vuelta();
    void mezclar(QVector<QString> &tarjetas);
    void repartir(QVector<QString> &tarjetas, QHash<QString, QString> &reparto);
    void mostrarimagen();
    void resultadoParcial();
    void reiniciarTarjetas();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
