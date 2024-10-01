#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QTableWidget>
#include <QLabel>
#include <QPalette>
#include <QFontDialog>
#include <QFileDialog>
#include <QTabWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window=new QWidget;
    window->setWindowTitle("Group7");


    QTabWidget *tabWidget = new QTabWidget;

    // leader
    QWidget *tab1 = new QWidget();
    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->setSpacing(1);
    QLabel *label1 = new QLabel("Leader");
    QLabel *label2 = new QLabel("Member 1");
    QLabel *label3 = new QLabel("Member 2");
    QLabel *label4 = new QLabel("Member 3");

    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);
    tab1->setLayout(layout1);

    // member 1
    QWidget *tab2 = new QWidget();
    QVBoxLayout *layout2 = new QVBoxLayout();
    QLabel *member1Label = new QLabel("This is Member 1's tab");
    QPushButton *member1Button = new QPushButton("Button 1");
    layout2->addWidget(member1Label);
    layout2->addWidget(member1Button);
    tab2->setLayout(layout2);

    // member 2
    QWidget *tab3 = new QWidget();
    QVBoxLayout *layout3 = new QVBoxLayout();
    QLabel *member2Label = new QLabel("This is Member 2's tab");
    QPushButton *member2Button = new QPushButton("Button 2");
    layout3->addWidget(member2Label);
    layout3->addWidget(member2Button);
    tab3->setLayout(layout3);

    // member 3
    QWidget *tab4 = new QWidget();
    QVBoxLayout *layout4 = new QVBoxLayout();
    QLabel *member3Label = new QLabel("This is Member 3's tab");
    QPushButton *member3Button = new QPushButton("Button 3");
    layout4->addWidget(member3Label);
    layout4->addWidget(member3Button);
    tab4->setLayout(layout4);


    tabWidget->addTab(tab1, "Leader");
    tabWidget->addTab(tab2, "Member 1");
    tabWidget->addTab(tab3, "Member 2");
    tabWidget->addTab(tab4, "Member 3");

    // 主窗口布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(tabWidget);
    window->setLayout(mainLayout);

    window->resize(300, 300);
    window->show();

    return app.exec();
}
