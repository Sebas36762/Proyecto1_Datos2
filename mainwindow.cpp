#include "mainwindow.h"
#include "qcoreapplication.h"
#include "qglobal.h"
#include "qmessagebox.h"
#include "qobject.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <random>

//Creacion de la ventana con sus tarjetas
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{

    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actEstado()));
    connect(ui->Tarjeta01,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta02,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta03,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta04,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta05,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta06,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta07,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta08,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta09,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta10,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta11,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta12,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta13,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta14,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta15,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta16,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta17,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta18,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta19,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta20,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta21,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta22,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta23,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta24,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta25,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta26,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta27,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta28,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta29,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta30,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta31,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta32,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta33,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta34,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta35,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta36,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta37,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta38,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta39,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta40,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta41,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta42,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta43,SIGNAL(clicked()),this,SLOT(vuelta()));
    connect(ui->Tarjeta44,SIGNAL(clicked()),this,SLOT(vuelta()));
    iniciarjuego();



}
void MainWindow::resultadoF(){
    msgbox.setWindowTitle("Fin de la Partida.");
    msgbox.setIcon(QMessageBox::Information);   //Se crean los botones para cuando termine la partida
    msgbox.setStandardButtons(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::Yes);
    msgbox.setEscapeButton(QMessageBox::No);

    if (restantes==0){//Detiene el tiempo cuando se armaron todas las parejas del juego
        timer->stop();
        msgbox.setText("Ganaste! Puntuaje:" +QString::number(puntaje)+ "Volver a Jugar?"); //Se crea un cuadro de texto para saber si el usuario quiere volver a jugar
        if(QMessageBox::Yes== msgbox.exec()){ //Accion del boton Si para volver a iniciar el juego
            iniciarjuego();

        }else{
            QCoreApplication::quit();
        }

    }
    else{
        if(time.toString()=="00:00:00"){ //Accion por si el tiempo termina
            timer->stop();//Parar temporizador
            ui->frame->setEnabled(false); //Deshabilitamos el Frame
            msgbox.setText("Perdiste! Volver a intentar?");
            if(QMessageBox::Yes== msgbox.exec()){
                iniciarjuego();
            }else{
                QCoreApplication::quit();
            }

        }
    }

}



void MainWindow::vuelta(){
    tarjetaActual=qobject_cast<QPushButton*>(sender()); //Accion que detecta la tarjeta clickeada
    mostrarimagen(); //Funcion para mostar la imagen de la tarjeta clickeada
    tarjetaActual->setEnabled(false); //Deshabilitar la tarjeta clickeada
    if(!jugadainiciada){
        tarjetaAnterior=tarjetaActual;
        jugadainiciada=true;
    }else{
        resultadoParcial();
        jugadainiciada=false;
    }

}

void MainWindow::mostrarimagen(){
    QString nombre_tarjeta=tarjetaActual->objectName();
    QString img=reparto[nombre_tarjeta];
    tarjetaActual->setStyleSheet("#"+ nombre_tarjeta +"{ background-image: url(://" + img + ") }");
}

void MainWindow::resultadoParcial(){
    if(reparto[tarjetaActual->objectName()] == reparto[tarjetaAnterior->objectName()]){
        puntaje+=10;
        ui->Score->setText(QString::number(puntaje));
        restantes--;
        resultadoF();

    }else{
        puntaje-=3;
        ui->Score->setText(QString::number(puntaje));
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000,this, SLOT(reiniciarTarjetas()));



    }
}
void MainWindow::reiniciarTarjetas(){
    tarjetaActual->setStyleSheet("#" +tarjetaActual->objectName()+ "{}");
    tarjetaAnterior->setStyleSheet("#" +tarjetaAnterior->objectName()+ "{}");
    tarjetaActual->setEnabled(true);
    tarjetaAnterior->setEnabled(true);
    ui->frame->setEnabled(true);


}






void MainWindow::iniciarjuego(){
    jugadainiciada=false;  //Jugadainiciada se establece como false porque no se ha hecho ninguna pareja
    puntaje=0;             //Se establece el puntuaje en 0
    ui->Score->setText(QString::number(puntaje));
    restantes=22;           //Parejas restantes o iniciales al comenzar el juego
    time.setHMS(0,6,30); //Tiempo de juego
    ui->Tiempo->setText(time.toString("m:ss"));
    timer->start(1000);
    mezclar(tarjetas);
    repartir(tarjetas, reparto);
    ui->frame->setEnabled(true);//Habilitamos el frame
    QList<QPushButton*> botones = ui->centralwidget->findChildren<QPushButton*>(); //Se buscan todos los botones de centralwidget
    foreach (QPushButton* b, botones){       //Se recoore toda la lista de los botones
        b->setEnabled(true);
        b->setStyleSheet("#"+b->objectName()+"{}");
    }

}

void MainWindow::actCronometro(){ //Funcion de tiempo para el cronometro
    time=time.addSecs(-1);//Disminuye el tiempo en 1 segundo
    ui->Tiempo->setText(time.toString("m:ss"));//Actualiza el estado del cronometro en ese momento
}
void MainWindow::actEstado(){
    actCronometro();
    resultadoF();

}

void MainWindow::mezclar(QVector<QString> &tarjetas){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Valor aleatorio para inicializar al generador de numeros

    shuffle(tarjetas.begin(),tarjetas.end(),std::default_random_engine(seed));
}


void MainWindow::repartir(QVector<QString> &tarjetas, QHash<QString, QString> &reparto){
    auto iterador=tarjetas.begin();
    for (int i=1; i<=20; i++){
        QString file_name="0"+QString::number(i)+".jpg";                //Agrega las tarjetas que cominzan con 0 y les suma i para agregarlas
        reparto[(*iterador)]=file_name;                                 //referenciando iterador con la tarjeta y el archivo de imagen
        iterador++;
        reparto[(*iterador)]=file_name;
        iterador++;
    }



}



MainWindow::~MainWindow()
{

    delete ui;
}

