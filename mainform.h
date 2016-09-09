#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QMenu>
#include <QAction>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void onMove(QPoint);
    void onOrn();
    void onAlign();

private:
    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::MainForm *ui;
    QMenu *m_Menu;
    QAction *m_actOrn, *m_actAlign;
};

#endif // MAINFORM_H
