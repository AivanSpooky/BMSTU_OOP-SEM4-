#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QIntValidator>
#include <QFileDialog>
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QDoubleValidator *validator = new QDoubleValidator(this);
    validator->setLocale(QLocale::C);
    ui->le_dx->setValidator(validator);
    ui->le_dy->setValidator(validator);
    ui->le_dz->setValidator(validator);
    ui->le_kx->setValidator(validator);
    ui->le_ky->setValidator(validator);
    ui->le_kz->setValidator(validator);
    ui->le_ax->setValidator(validator);
    ui->le_ay->setValidator(validator);
    ui->le_az->setValidator(validator);
    QGraphicsScene *scene = new QGraphicsScene;

    params->drawer.canvas.canvas_field = ui->canvas;
    params->drawer.canvas.canvas_field->setScene(scene);
    params->centralwidget = ui->centralwidget;

    les->move.dx = ui->le_dx;
    les->move.dy = ui->le_dy;
    les->move.dz = ui->le_dz;
    les->scale.kx = ui->le_kx;
    les->scale.ky = ui->le_ky;
    les->scale.kz = ui->le_kz;
    les->rotate.ax = ui->le_ax;
    les->rotate.ay = ui->le_ay;
    les->rotate.az = ui->le_az;
    les->rotate.center = new rotate_c_le_t;
    // les->rotate.center->cx = ui->le_cX;
    // les->rotate.center->cy = ui->le_cY;
    // les->rotate.center->cz = ui->le_cZ;

    // Если функция не выполнилась, она не должна изменять var-параметр
    static err_t rc = OK;
    connect(ui->btn_load, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Выберите файл"), QDir::homePath(), QObject::tr("Текстовые файлы (*.txt)"));
        params->filename = filePath.toLocal8Bit().constData();
        rc = make_action(LOAD, *params);
        if (rc == OK)
            rc = make_action(DRAW, *params);
        if (rc != OK)
            error_handler(rc);
    });
    connect(ui->btn_draw, &QPushButton::clicked, [=]() {
        rc = make_action(DRAW, *params);
        if (rc != OK)
            error_handler(rc);
    });
    connect(ui->btn_save, &QPushButton::clicked, [=]() {
        QWidget *parent = params->centralwidget;
        QString filePath = QFileDialog::getSaveFileName(parent, "Сохранить фигуру", QDir::currentPath(), "Text Files (*.txt);;All Files (*)");
        params->filename = filePath.toLocal8Bit().constData();
        rc = make_action(SAVE, *params);
        if (rc != OK)
            error_handler(rc);
    });
    connect(ui->btn_move, &QPushButton::clicked, [=]() {
        rc = read_params_for_move(params->move, les->move);
        if (rc == OK)
            rc = make_action(MOVE, *params);
        if (rc == OK)
            rc = make_action(DRAW, *params);
        if (rc != OK)
            error_handler(rc);
    });
    connect(ui->btn_scale, &QPushButton::clicked, [=]() {
        rc = read_params_for_scale(params->scale, les->scale);
        if (rc == OK)
            rc = make_action(SCALE, *params);
        if (rc == OK)
            rc = make_action(DRAW, *params);
        if (rc != OK)
            error_handler(rc);
    });
    connect(ui->btn_rotate, &QPushButton::clicked, [=]() {
        rc = read_params_for_rotate(params->rotate, les->rotate);
        if (rc == OK)
            rc = make_action(ROTATE, *params);
        if (rc == OK)
            rc = make_action(DRAW, *params);
        if (rc != OK)
            error_handler(rc);
    });
}

MainWindow::~MainWindow()
{
    delete params;
    delete les;
    delete ui;
}
