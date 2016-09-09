#include "mainform.h"
#include "ui_mainform.h"
#include <QKeyEvent>

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    setWindowOpacity(0.8);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    m_actOrn = new QAction("垂直", this);
    connect(m_actOrn, SIGNAL(triggered()), SLOT(onOrn()));
    m_actAlign = new QAction("对齐", this);
    connect(m_actAlign, SIGNAL(triggered()), SLOT(onAlign()));
    addAction(m_actOrn);
    addAction(m_actAlign);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    ui->ruler->setOrientation(Qt::Horizontal);
    resize(ui->ruler->sizeHint());

    connect(ui->ruler, SIGNAL(moved(QPoint)), SLOT(onMove(QPoint)));
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::onMove(QPoint p)
{
    move(pos()+p);
}

void MainForm::onOrn()
{
    if (m_actOrn->text() == "垂直") {
        ui->ruler->setOrientation(Qt::Vertical);
        m_actOrn->setText("水平");
    }
    else {
        ui->ruler->setOrientation(Qt::Horizontal);
        m_actOrn->setText("垂直");
    }

    resize(ui->ruler->sizeHint());
    update();
}

void MainForm::onAlign()
{
    m_actOrn->text() == "垂直" ? move(0, pos().y()) : move(pos().x(), 0);
}

void MainForm::keyReleaseEvent(QKeyEvent *e)
{
    QPoint p = pos();
    if (e->key() == Qt::Key_Left) p += QPoint(-1,0);
    else if (e->key() == Qt::Key_Right) p += QPoint(1,0);
    else if (e->key() == Qt::Key_Up) p += QPoint(0,-1);
    else if (e->key() == Qt::Key_Down) p += QPoint(0,1);
    move(p);
}
